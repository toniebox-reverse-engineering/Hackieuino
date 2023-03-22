
#include "settings.h"

#if (LANGUAGE == EN)
	#include "Log.h"

	const char tryConnectMqttS[] = "Trying to connect to MQTT-broker: %s";
	const char mqttOk[] = "MQTT-connection established.";
	const char sleepTimerEOP[] = "Sleep-timer: after last track of playlist.";
	const char sleepTimerEOT[] = "Sleep-timer: after end of current track.";
	const char sleepTimerStop[] = "Sleep-timer has been disabled.";
	const char sleepTimerEO5[] = "Sleep-timer: after five track or end of playlist - whatever is reached first";
	const char sleepTimerAlreadyStopped[] = "sleep-timer is already disabled.";
	const char sleepTimerSetTo[] = "sleep-timer adjusted to %u minute(s)";
	const char allowButtons[] = "Unlocking all keys.";
	const char lockButtons[] = "Locking all keys.";
	const char noPlaylistNotAllowedMqtt[] = "Playmode cannot be adjusted to 'no playlist' via MQTT.";
	const char playmodeChangedMQtt[] = "Playlist adjusted via MQTT.";
	const char noPlaymodeChangeIfIdle[] = "Playlist cannot be adjusted while no playlist is active.";
	const char noValidTopic[] = "No valid MQTT-topic: %s";
	const char freePtr[] = "Releasing Pointer: %s (0x%04x)";
	const char freeMemory[] = "Free memory: %u";
	const char writeEntryToNvs[] = "[%u] Storing data to NVS: %s => %s";
	const char freeMemoryAfterFree[] = "Free memory after cleaning: %u";
	const char releaseMemoryOfOldPlaylist[] = "Releasing memory of old playlist.";
	const char dirOrFileDoesNotExist[] = "File of directory does not exist: %s";
	const char unableToAllocateMemForPlaylist[] = "Unable to allocate memory for playlist!";
	const char unableToAllocateMem[] = "Unable to allocate memory!";
	const char fileModeDetected[] = "File-mode detected.";
	const char nameOfFileFound[] = "File found: %s";
	const char reallocCalled[] = "Reallocated memory.";
	const char unableToAllocateMemForLinearPlaylist[] = "Unable to allocate memory for linear playlist!";
	const char numberOfValidFiles[] = "Number of valid files/webstreams: %u";
	const char newLoudnessReceivedQueue[] = "New volume received via queue: %u";
	const char newCntrlReceivedQueue[] = "Control-command received via queue: %u";
	const char newPlaylistReceived[] = "New playlist received with %d track(s)";
	const char repeatTrackDueToPlaymode[] = "Repeating track due to playmode configured.";
	const char repeatPlaylistDueToPlaymode[] = "Repeating playlist due to playmode configured.";
	const char cmndStop[] = "Command: stop";
	const char cmndPause[] = "Command: pause";
	const char cmndNextTrack[] = "Command: next track";
	const char cmndPrevTrack[] = "Command: previous track";
	const char cmndFirstTrack[] = "Command: first track of playlist";
	const char cmndLastTrack[] = "Command: last track of playlist";
	const char cmndDoesNotExist[] = "Command requested does not exist.";
	const char lastTrackAlreadyActive[] = "Already playing last track.";
	const char trackStartAudiobook[] = "Starting track in playmode from the very beginning.";
	const char trackStart[] = "Starting track from the very beginning.";
	const char trackChangeWebstream[] = "Playing from the very beginning is not possible while webradio-mode is active.";
	const char endOfPlaylistReached[] = "Reached end of playlist.";
	const char trackStartatPos[] = "Starting track at position %u";
	const char waitingForTaskQueues[] = "Task Queue for RFID does not exist yet, waiting...";
	const char rfidScannerReady[] = "RFID-tags can now be applied...";
	const char rfidTagDetected[] = "RFID-tag detected: %s";
	const char rfid15693TagDetected[] = "RFID-ta (ISO-15693) detected: ";
	const char rfidTagReceived[] = "RFID-tag received";
	const char dontAccepctSameRfid[] = "Reapplied same rfid-tag - rejected! (%s)";
	const char rfidTagUnknownInNvs[] = "RFID-tag is unkown to NVS.";
	const char goToSleepDueToIdle[] = "Going to deepsleep due to inactivity-timer...";
	const char goToSleepDueToTimer[] = "Going to deepsleep due to sleep timer...";
	const char goToSleepNow[] = "Going to deepsleep now!";
	const char maxLoudnessReached[] = "Already reached max volume!";
	const char minLoudnessReached[] = "Already reached min volume!";
	const char errorOccured[] = "Error occured!";
	const char noMp3FilesInDir[] = "Directory does not contain mp3-files.";
	const char modeSingleTrack[] = "Mode: Single track";
	const char modeSingleTrackLoop[] = "Mode: single track as infinite loop";
	const char modeSingleTrackRandom[] = "Mode: single track (random) of directory";
	const char modeSingleAudiobook[] = "Mode: audiobook";
	const char modeSingleAudiobookLoop[] = "Mode: audiobook as infinite loop";
	const char modeAllTrackAlphSorted[] = "Mode: all tracks (in alph. order) of directory '%s'";
	const char modeAllTrackRandom[] = "Mode: all tracks (in random. order) of directory '%s";
	const char modeAllTrackAlphSortedLoop[] = "Mode: all tracks (in alph. order) of directory as infinite loop";
	const char modeAllTrackRandomLoop[] = "Mode: all tracks (in random order) of directory as infinite loop";
	const char modeWebstream[] = "Mode: webstream";
	const char modeWebstreamM3u[] = "Mode: Webstream (local .m3u-file)";
	const char webstreamNotAvailable[] = "Unable to access webstream as no wifi-connection is available!";
	const char modeDoesNotExist[] = "Playmode does not exist!";
	const char modeRepeatNone[] = "Repeatmode: no repeat";
	const char modeRepeatTrack[] = "Repeatmode: current track";
	const char modeRepeatPlaylist[] = "Repeatmode: whole playlist";
	const char modeRepeatTracknPlaylist[] = "Repeatmode: track and playlist";
	const char modificatorAllButtonsLocked[] = "Modificator: locking all keys via RFID-tag.";
	const char modificatorAllButtonsUnlocked[] = "Modificator: unlocking all keys via RFID-tag.";
	const char modificatorSleepd[] = "Modificator: sleep-Timer deactivated.";
	const char modificatorSleepTimer15[] = "Modificator: sleep-Timer enabled via RFID (15 minutes).";
	const char modificatorSleepTimer30[] = "Modificator: sleep-Timer enabled via RFID (30 minutes).";
	const char modificatorSleepTimer60[] = "Modificator: sleep-Timer enabled via RFID (60 minutes).";
	const char modificatorSleepTimer120[] = "Modificator: sleep-Timer enabled via RFID (2 hours).";
	const char ledsDimmedToNightmode[] = "Dimmed LEDs to nightmode.";
	const char ledsDimmedToInitialValue[] = "Dimmed LEDs to initial value.";
	const char modificatorNotallowedWhenIdle[] = "Modificator cannot be applied while playlist is inactive.";
	const char modificatorSleepAtEOT[] = "Modificator: adjusted sleep-timer to after end of current track.";
	const char modificatorSleepAtEOTd[] = "Modificator: disabled sleep-timer after end of current track.";
	const char modificatorSleepAtEOP[] = "Modificator: adjusted sleep-timer to after end of playlist.";
	const char modificatorSleepAtEOPd[] = "Modificator: disabled sleep-timer after end of playlist.";
	const char modificatorAllTrackAlphSortedLoop[] = "Modificator: adjusted to all tracks (in alph. order) as infinite loop.";
	const char modificatorAllTrackRandomLoop[] = "Modificator: adjusted to all tracks (in random order) as infinite loop.";
	const char modificatorCurTrackLoop[] = "Modificator: adjusted to current track as infinite loop.";
	const char modificatorCurAudiobookLoop[] = "Modificator: adjusted to current audiobook as infinite loop.";
	const char modificatorPlaylistLoopActive[] = "Modificator: adjusted to all tracks as infinite loop.";
	const char modificatorPlaylistLoopDeactive[] = "Modificator: disabled all tracks as infinite loop.";
	const char modificatorTrackActive[] = "Modificator: adjusted to current track as infinite loop.";
	const char modificatorTrackDeactive[] = "Modificator: disabled current track as infinite loop.";
	const char modificatorNotAllowed[] = "Unable to apply modificator.";
	const char modificatorLoopRev[] = "Modificator: infinite loop ended.";
	const char modificatorDoesNotExist[] = "This type of card-modificator does not exist %d!";
	const char errorOccuredNvs[] = "Error occured while reading from NVS!";
	const char statementsReceivedByServer[] = "Data received from server";
	const char apReady[] = "Started wifi-access-point";
	const char httpReady[] = "Started HTTP-server.";
	const char unableToMountSd[] = "Unable to mount sd-card.";
	const char unableToCreateVolQ[] = "Unable to create volume-queue.";
	const char unableToCreateRfidQ[] = "Unable to create RFID-queue.";
	const char unableToCreateMgmtQ[] = "Unable to play-management-queue.";
	const char unableToCreatePlayQ[] = "Unable to create track-queue..";
	const char initialBrightnessfromNvs[] = "Restoring initial LED-brightness from NVS: %u";
	const char wroteInitialBrightnessToNvs[] = "Storing initial LED-brightness to NVS.";
	const char restoredInitialBrightnessForNmFromNvs[] = "Restored LED-brightness for nightmode from NVS: %u";
	const char wroteNmBrightnessToNvs[] = "Stored LED-brightness for nightmode to NVS.";
	const char wroteFtpUserToNvs[] = "Stored FTP-user to NVS.";
	const char restoredFtpUserFromNvs[] = "Restored FTP-user from NVS: %s";
	const char wroteFtpPwdToNvs[] = "Stored FTP-password to NVS.";
	const char restoredFtpPwdFromNvs[] = "Restored FTP-password from NVS: %s";
	const char restoredMaxInactivityFromNvs[] = "Restored maximum inactivity-time from NVS: %u minutes";
	const char wroteMaxInactivityToNvs[] = "Stored maximum inactivity-time to NVS.";
	const char restoredInitialLoudnessFromNvs[] = "Restored initial volume from NVS: %u";
	const char wroteInitialLoudnessToNvs[] = "Stored initial volume to NVS.";
	const char restoredMaxLoudnessForSpeakerFromNvs[] = "Restored maximum volume for speaker from NVS: %u";
	const char restoredMaxLoudnessForHeadphoneFromNvs[] = "Restored maximum volume for headphone from NVS: %u";
	const char wroteMaxLoudnessForSpeakerToNvs[] = "Wrote maximum volume for speaker to NVS.";
	const char wroteMaxLoudnessForHeadphoneToNvs[] = "Wrote maximum volume for headphone to NVS.";
	const char maxVolumeSet[] = "Maximum volume set to: %u";
	const char wroteMqttFlagToNvs[] = "Stored MQTT-flag to NVS.";
	const char restoredMqttActiveFromNvs[] = "Restored MQTT-flag (enabled) from NVS: %u";
	const char restoredMqttDeactiveFromNvs[] = "Restored MQTT-flag (disabled) from NVS: %u";
	const char wroteMqttClientIdToNvs[] = "Stored MQTT-clientid to NVS.";
	const char restoredMqttClientIdFromNvs[] = "Restored MQTT-clientid from NVS: %s";
	const char wroteMqttServerToNvs[] = "Stored MQTT-server to NVS.";
	const char restoredMqttServerFromNvs[] = "Restored MQTT-Server from NVS: %s";
	const char wroteMqttUserToNvs[] = "Stored MQTT-user to NVS.";
	const char restoredMqttUserFromNvs[] = "Restored MQTT-user from NVS: %s";
	const char wroteMqttPwdToNvs[] = "Stored MQTT-password to NVS.";
	const char restoredMqttPwdFromNvs[] = "Restored MQTT-password from NVS: %s";
	const char restoredMqttPortFromNvs[] = "Restored MQTT-port from NVS: %u";
	const char mqttWithPwd[] = "Try to connect to MQTT-server with user und password";
	const char mqttWithoutPwd[] = "Try to connect to MQTT-server without user und password";
	const char ssidNotFoundInNvs[] = "Unable to find SSID to NVS.";
	const char wifiStaticIpConfigNotFoundInNvs[] = "Unable to find wifi-ip-configuration to NVS.";
	const char wifiHostnameNotSet[] = "Unable to find hostname-configuration to NVS.";
	const char mqttConnFailed[] = "Unable to establish mqtt-connection, trying again: rc=%i (%d / %d)";
	const char restoredHostnameFromNvs[] = "Restored hostname from NVS: %s";
	const char currentVoltageMsg[] = "Current battery-voltage: %.2f V";
	const char currentChargeMsg[] = "Current battery charge: %.2f %%";
	const char batteryCurrentMsg[] = "Power usage (Battery): %.2f mA";
	const char batteryTempMsg[] = "Battery temperature: %.2f °C";
	const char batteryCyclesMsg[] = "Seen battery cycles: %.2f";
	const char batteryLowMsg[] = "Battery charge low";
	const char batteryCriticalMsg[] = "Battery charge critical. Will go to deepsleep...";
	const char sdBootFailedDeepsleep[] = "Failed to boot due to SD. Will go to deepsleep...";
	const char wifiEnabledMsg[] = "WiFi will be enabled.";
	const char wifiDisabledMsg[] = "WiFi will be disabled .";
	const char voltageIndicatorLowFromNVS[] = "Restored lower voltage-level for Neopixel-display from NVS: %.2fV";
	const char voltageIndicatorHighFromNVS[] = "Restored upper voltage-level for Neopixel-display from NVS: %.2fV";
	const char batteryCheckIntervalFromNVS[] = "Restored interval of battery-measurement or Neopixel-display from NVS: %u minutes";
	const char warningLowVoltageFromNVS[] = "Restored low battery-voltage-level for warning via Neopixel from NVS: %.2fV";
	const char warningCriticalVoltageFromNVS[] = "Restored critical battery-voltage-level for warning via Neopixel from NVS: %.2fV";
	const char batteryLowFromNVS[] = "Restored low battery level from NVS: %.2f %%";
	const char batteryCriticalFromNVS[] = "Restored critical battery level from NVS: %.2f %%";
	const char unableToRestoreLastRfidFromNVS[] = "Unable to restore last RFID from NVS";
	const char restoredLastRfidFromNVS[] = "Restored last RFID from NVS: %s";
	const char failedOpenFileForWrite[] = "Failed to open file for writing";
	const char fileWritten[] = "File written: %s => %zu bytes in %lu ms (%lu kiB/s)";
	const char writeFailed[] = "Write failed";
	const char writingFile[] = "Writing file: %s";
	const char failedToOpenFileForAppending[] = "Failed to open file for appending";
	const char listingDirectory[] = "Listing directory";
	const char failedToOpenDirectory[] = "Failed to open directory";
	const char notADirectory[] = "Not a directory";
	const char sdMountedMmc1BitMode[] = "SD card mounted in SD-MMC 1-Bit mode...";
	const char sdMountedMmc4BitMode[] = "SD card mounted in SD-MMC 4-Bit mode...";
	const char sdMountedSpiMode[] = "Mounting SD card in SPI-mode...";
	const char backupRecoveryWebsite[] = "<p>Backup-file is being applied...<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char restartWebsite[] = "<p>ESPuino is being restarted...<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char shutdownWebsite[] = "<p>Der ESPuino is being shutdown...</p>";
	const char mqttMsgReceived[] = "MQTT-message received: [Topic: %s] [Command: %s]";
	const char trackPausedAtPos[] = "Track paused at position: %u (%u)";
	const char freeHeapWithoutFtp[] = "Free heap before FTP-allocation: %u";
	const char freeHeapWithFtp[] = "Free heap after FTP-allocation: %u";
	const char freeHeapAfterSetup[] = "Free heap after setup";
	const char ftpServerStarted[] = "FTP-Server started";
	const char tryStaticIpConfig[] = "Performing IP-configuration...";
	const char staticIPConfigFailed[] = "IP-configuration failed";
	const char wakeUpRfidNoIso14443[] = "Wakeup caused by low power card-detection. RF-field changed but no ISO-14443 card on reader was found. So I'll return back to sleep now...";
	const char lowPowerCardSuccess[] = "Switch to low power card-detection: success";
	const char rememberLastVolume[] = "Restored volume used before last shutdown. This overwrites the initial volume configured via webgui.";
	const char unableToStartFtpServer[] = "FTP-server cannot be started. This is because FTP-service is already active or because WiFi is unavailable.";
	const char unableToTellIpAddress[] = "IP-address can't be announced as there's no WiFi-connection available.";
	const char newPlayModeStereo[] = "New mode: stereo";
	const char newPlayModeMono[] = "New mode: mono";
	const char portExpanderFound[] = "Port-expander found";
	const char portExpanderNotFound[] = "Unable to detect port-expander";
	const char portExpanderInterruptEnabled[] = "Enabled interrupt-handling for port-expander";
	const char playlistGen[] = "Playlist-generation";
	const char bootLoopDetected[] = "Bootloop detected! Last RFID won't be restored.";
	const char noBootLoopDetected[] = "No bootloop detected. Great :-)";
	const char importCountNokNvs[] = "Number of invalid import-entries: %u";
	const char errorReadingTmpfile[] = "Error occured while reading from import-tmpfile";
	const char errorWritingTmpfile[] = "Error occured while writing to import-tmpfile";
	const char eraseRfidNvsWeb[] = "<p>NVS-RFID-assignments are being deleted...<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char eraseRfidNvs[] = "NVS-RFID-assignments are being deleted...";
	const char fwStart[] = "Starting firmware-update via OTA...";
	const char fwEnd[] = "Firmware-update finished";
	const char otaNotSupported[] = "Firmware-update isn't supported by this ESPuino!";
	const char otaNotSupportedWebsite[] = "<p>FFirmware-update isn't supported by this ESPuino!<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char noPlaylist[] = "No active playlist.";
	const char rfidTagRemoved[] = "RFID-tag removed";
	const char rfidTagReapplied[] = "RFID-tag reapplied";
	const char ftpEnableTooLate[] = "FTP can only be enabled within the first 30s after ESPuino-start. Child-protection :-)";
	const char syncingViaNtp[] = "Getting current time via NTP...";
	const char sdInfo[] = "SD card size / free space: %llu MB / %llu MB";
	const char paOn[] = "Loudspeaker on";
	const char paOff[] = "Loudspeaker off";
	const char hpOn[] = "Headphones on";
	const char hpOff[] = "Headphones off";
	const char webTxCanceled[] = "Webtransfer canceled due to inactivity-timer.";
	const char tryToPickRandomDir[] = "Try to pick randon subdirectory out of: %s";
	const char pickedRandomDir[] = "Randomly picked subdirectory: %s";
	const char wrongWakeUpGpio[] = "GPIO choosen as wakeup-pin isn't of type RTC and that reason for can't wake up ESP32! (GPIO: %u)";
	const char currentlyPlaying[] = "'%s' is being played (%d of %d)";
	const char secondsJumpForward[] = "Jumped %d seconds forwards";
	const char secondsJumpBackward[] = "Jumped %d seconds backward";
	const char wroteLastTrackToNvs[] = "Write '%s' to NVS for RFID-Card-ID %s with playmode %d and last track %u";
	const char wifiConnectionInProgress[] = "Try to connect to WiFi with SSID '%s'...";
	const char wifiConnectionSuccess[] = "Connected with WiFi '%s' (signal strength: %d dBm, channel: %d, BSSID: %s)";
	const char wifiCurrentIp[] = "Current IP: %s";
	const char jsonErrorMsg[] = "deserializeJson() failed: %s";
	const char wifiDeleteNetwork[] = "Deleting saved WiFi %s";
	const char wifiNetworkLoaded[] = "Loaded SSID %d from NVS: %s";
	const char wifiTooManyNetworks[] = "Number of networks in NVS is %d, but that's more than the allowed %d";
	const char wifiAddTooManyNetworks[] = "No space left to add another WiFi network!";
	const char wifiAddNetwork[] = "Add WiFi network %s";
	const char wifiUpdateNetwork[] = "Update WiFi network %s";
	const char wifiScanResult[] = "Found WiFi with SSID %s and signal strength %d dBm on channel %d,  BSSID %s.";
	const char cantConnectToWifi[] = "Failed to connect to WiFi.";
	const char wifiSetLastSSID[] = "Write last successful SSID to NVS for WiFi fast-path: %s";
#endif
