#include <Arduino.h>
#include "settings.h"
#include "Rfid.h"
#include "Log.h"
#include "MemX.h"
#include "Queues.h"
#include "System.h"
#include <esp_task_wdt.h>
#include "AudioPlayer.h"
#include "HallEffectSensor.h"

#if defined(RFID_READER_TYPE_TRF7962A)
	#include <TRF7962A.h>

	extern unsigned long Rfid_LastRfidCheckTimestamp;
	static void Rfid_Task(void *parameter);

	static TRF7962A rfid = TRF7962A();

	void Rfid_Init(void) {
		rfid.begin(1, 13);
		Log_Println((char *) FPSTR(rfidScannerReady), LOGLEVEL_DEBUG);

		xTaskCreatePinnedToCore(
			Rfid_Task,              /* Function to implement the task */
			"rfid",                 /* Name of the task */
			2048,                   /* Stack size in words */
			NULL,                   /* Task input parameter */
			2 | portPRIVILEGE_BIT,  /* Priority of the task */
			NULL,                   /* Task handle. */
			1                       /* Core where the task should run */
		);
	}

	void Rfid_Task(void *parameter) {
		#ifdef PAUSE_WHEN_RFID_REMOVED
			byte lastValidcardId[cardIdSize];
			bool cardAppliedCurrentRun = false;
			bool cardAppliedLastRun = false;
		#endif
		static byte cardId[cardIdSize], lastCardId[cardIdSize];
		uint8_t uid[7];
		bool showDisablePrivacyNotification = true;

		// wait until queues are created
		while (gRfidCardQueue == NULL) {
			Log_Println((char *) FPSTR(waitingForTaskQueues), LOGLEVEL_DEBUG);
			vTaskDelay(50);
		}
		TRF7962A::TAG_EVENT tagEvent;
		for (;;) {
			vTaskDelay(portTICK_RATE_MS * 10u);
			String cardIdString;
			bool cardReceived = false;
			#ifdef PAUSE_WHEN_RFID_REMOVED
				bool sameCardReapplied = false;
			#endif
			tagEvent = rfid.loop();

			if (tagEvent == TRF7962A::TAG_EVENT::TAG_PLACED) {
				cardReceived = true;
				rfid.getUID(uid);

				#ifdef PAUSE_WHEN_RFID_REMOVED
					cardAppliedCurrentRun = true;
				#endif
			} else if (tagEvent == TRF7962A::TAG_EVENT::TAG_REMOVED) {
				#ifdef PAUSE_WHEN_RFID_REMOVED
					cardAppliedCurrentRun = false;
				#endif
				for (uint8_t i=0; i<cardIdSize; i++) {
					lastCardId[i] = 0;
				}
			}

			#ifdef PAUSE_WHEN_RFID_REMOVED
				if (!cardAppliedCurrentRun && cardAppliedLastRun && !gPlayProperties.pausePlay && System_GetOperationMode() != OPMODE_BLUETOOTH_SINK) {   // Card removed => pause
					AudioPlayer_TrackControlToQueueSender(PAUSEPLAY);
					Log_Println((char *) FPSTR(rfidTagRemoved), LOGLEVEL_NOTICE);
				}
				cardAppliedLastRun = cardAppliedCurrentRun;
			#endif

			// send card to queue
			if (cardReceived) {
				memcpy(cardId, uid, cardIdSize);

				// check for different card id
				if (memcmp((const void *)cardId, (const void *)lastCardId, sizeof(cardId)) == 0) {

				}

				memcpy(lastCardId, cardId, cardIdSize);
				showDisablePrivacyNotification = true;
                #ifdef HALLEFFECT_SENSOR_ENABLE
                    cardId[cardIdSize-1]   = cardId[cardIdSize-1] + gHallEffectSensor.waitForState(HallEffectWaitMS);  
                #endif

				#ifdef PAUSE_WHEN_RFID_REMOVED
					if (memcmp((const void *)lastValidcardId, (const void *)cardId, sizeof(cardId)) == 0) {
						sameCardReapplied = true;
					}
				#endif

				Log_Print((char *) FPSTR(rfidTagDetected), LOGLEVEL_NOTICE, true);
				Log_Print(Log_Buffer, LOGLEVEL_NOTICE, false);

				for (uint8_t i = 0u; i < cardIdSize; i++) {
					snprintf(Log_Buffer, Log_BufferLength, "%02x%s", cardId[i], (i < cardIdSize - 1u) ? "-" : "\n");
					Log_Print(Log_Buffer, LOGLEVEL_NOTICE, false);
				}

				for (uint8_t i = 0u; i < cardIdSize; i++) {
					char num[4];
					snprintf(num, sizeof(num), "%03d", cardId[i]);
					cardIdString += num;
				}

				#ifdef PAUSE_WHEN_RFID_REMOVED
					#ifdef ACCEPT_SAME_RFID_AFTER_TRACK_END
						if (!sameCardReapplied || gPlayProperties.trackFinished || gPlayProperties.playlistFinished) {       // Don't allow to send card to queue if it's the same card again if track or playlist is unfnished 
					#else	
						if (!sameCardReapplied){		// Don't allow to send card to queue if it's the same card again... 
					#endif
						xQueueSend(gRfidCardQueue, cardIdString.c_str(), 0);
					} else {
						// If pause-button was pressed while card was not applied, playback could be active. If so: don't pause when card is reapplied again as the desired functionality would be reversed in this case.
						if (gPlayProperties.pausePlay && System_GetOperationMode() != OPMODE_BLUETOOTH_SINK) {
							AudioPlayer_TrackControlToQueueSender(PAUSEPLAY);       // ... play/pause instead
							Log_Println((char *) FPSTR(rfidTagReapplied), LOGLEVEL_NOTICE);
						}
					}
					memcpy(lastValidcardId, uid, cardIdSize);
				#else
					xQueueSend(gRfidCardQueue, cardIdString.c_str(), 0);        // If PAUSE_WHEN_RFID_REMOVED isn't active, every card-apply leads to new playlist-generation
				#endif
			}
		}
	}

	void Rfid_Cyclic(void) {
		// Not necessary as cyclic stuff performed by task Rfid_Task()
	}

	void Rfid_Exit(void) {

	}

	void Rfid_WakeupCheck(void) {
	}

#endif
