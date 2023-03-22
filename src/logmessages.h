#pragma once

extern const char tryConnectMqttS[];
extern const char mqttOk[];
extern const char sleepTimerEOP[];
extern const char sleepTimerEOT[];
extern const char sleepTimerStop[];
extern const char sleepTimerEO5[];
extern const char sleepTimerAlreadyStopped[];
extern const char sleepTimerSetTo[];
extern const char allowButtons[];
extern const char lockButtons[];
extern const char noPlaylistNotAllowedMqtt[];
extern const char playmodeChangedMQtt[];
extern const char noPlaymodeChangeIfIdle[];
extern const char noValidTopic[];
extern const char freePtr[];
extern const char freeMemory[];
extern const char writeEntryToNvs[];
extern const char freeMemoryAfterFree[];
extern const char releaseMemoryOfOldPlaylist[];
extern const char dirOrFileDoesNotExist[];
extern const char unableToAllocateMemForPlaylist[];
extern const char unableToAllocateMem[];
extern const char fileModeDetected[];
extern const char nameOfFileFound[];
extern const char reallocCalled[];
extern const char unableToAllocateMemForLinearPlaylist[];
extern const char numberOfValidFiles[];
extern const char newLoudnessReceivedQueue[];
extern const char newCntrlReceivedQueue[];
extern const char newPlaylistReceived[];
extern const char repeatTrackDueToPlaymode[];
extern const char repeatPlaylistDueToPlaymode[];
extern const char cmndStop[];
extern const char cmndPause[];
extern const char cmndNextTrack[];
extern const char cmndPrevTrack[];
extern const char cmndFirstTrack[];
extern const char cmndLastTrack[];
extern const char cmndDoesNotExist[];
extern const char lastTrackAlreadyActive[];
extern const char trackStartAudiobook[];
extern const char trackStart[];
extern const char trackChangeWebstream[];
extern const char endOfPlaylistReached[];
extern const char trackStartatPos[];
extern const char waitingForTaskQueues[];
extern const char rfidScannerReady[];
extern const char rfidTagDetected[];
extern const char rfid15693TagDetected[];
extern const char rfidTagReceived[];
extern const char dontAccepctSameRfid[];
extern const char rfidTagUnknownInNvs[];
extern const char goToSleepDueToIdle[];
extern const char goToSleepDueToTimer[];
extern const char goToSleepNow[];
extern const char maxLoudnessReached[];
extern const char minLoudnessReached[];
extern const char errorOccured[];
extern const char noMp3FilesInDir[];
extern const char modeSingleTrack[];
extern const char modeSingleTrackLoop[];
extern const char modeSingleTrackRandom[];
extern const char modeSingleAudiobook[];
extern const char modeSingleAudiobookLoop[];
extern const char modeAllTrackAlphSorted[];
extern const char modeAllTrackRandom[];
extern const char modeAllTrackAlphSortedLoop[];
extern const char modeAllTrackRandomLoop[];
extern const char modeWebstream[];
extern const char modeWebstreamM3u[];
extern const char webstreamNotAvailable[];
extern const char modeDoesNotExist[];
extern const char modeRepeatNone[];
extern const char modeRepeatTrack[];
extern const char modeRepeatPlaylist[];
extern const char modeRepeatTracknPlaylist[];
extern const char modificatorAllButtonsLocked[];
extern const char modificatorAllButtonsUnlocked[];
extern const char modificatorSleepd[];
extern const char modificatorSleepTimer15[];
extern const char modificatorSleepTimer30[];
extern const char modificatorSleepTimer60[];
extern const char modificatorSleepTimer120[];
extern const char ledsDimmedToNightmode[];
extern const char ledsDimmedToInitialValue[];
extern const char modificatorNotallowedWhenIdle[];
extern const char modificatorSleepAtEOT[];
extern const char modificatorSleepAtEOTd[];
extern const char modificatorSleepAtEOP[];
extern const char modificatorSleepAtEOPd[];
extern const char modificatorAllTrackAlphSortedLoop[];
extern const char modificatorAllTrackRandomLoop[];
extern const char modificatorCurTrackLoop[];
extern const char modificatorCurAudiobookLoop[];
extern const char modificatorPlaylistLoopActive[];
extern const char modificatorPlaylistLoopDeactive[];
extern const char modificatorTrackActive[];
extern const char modificatorTrackDeactive[];
extern const char modificatorNotAllowed[];
extern const char modificatorLoopRev[];
extern const char modificatorDoesNotExist[];
extern const char errorOccuredNvs[];
extern const char statementsReceivedByServer[];
extern const char savedSsidInNvs[];
extern const char savedWifiPwdInNvs[];
extern const char apReady[];
extern const char httpReady[];
extern const char unableToMountSd[];
extern const char unableToCreateVolQ[];
extern const char unableToCreateRfidQ[];
extern const char unableToCreateMgmtQ[];
extern const char unableToCreatePlayQ[];
extern const char initialBrightnessfromNvs[];
extern const char wroteInitialBrightnessToNvs[];
extern const char restoredInitialBrightnessForNmFromNvs[];
extern const char wroteNmBrightnessToNvs[];
extern const char wroteFtpUserToNvs[];
extern const char restoredFtpUserFromNvs[];
extern const char wroteFtpPwdToNvs[];
extern const char restoredFtpPwdFromNvs[];
extern const char restoredMaxInactivityFromNvs[];
extern const char wroteMaxInactivityToNvs[];
extern const char restoredInitialLoudnessFromNvs[];
extern const char wroteInitialLoudnessToNvs[];
extern const char restoredMaxLoudnessForSpeakerFromNvs[];
extern const char restoredMaxLoudnessForHeadphoneFromNvs[];
extern const char wroteMaxLoudnessForSpeakerToNvs[];
extern const char wroteMaxLoudnessForHeadphoneToNvs[];
extern const char maxVolumeSet[];
extern const char wroteMqttFlagToNvs[];
extern const char restoredMqttActiveFromNvs[];
extern const char restoredMqttDeactiveFromNvs[];
extern const char wroteMqttClientIdToNvs[];
extern const char restoredMqttClientIdFromNvs[];
extern const char wroteMqttServerToNvs[];
extern const char restoredMqttServerFromNvs[];
extern const char wroteMqttUserToNvs[];
extern const char restoredMqttUserFromNvs[];
extern const char wroteMqttPwdToNvs[];
extern const char restoredMqttPwdFromNvs[];
extern const char restoredMqttPortFromNvs[];
extern const char mqttWithPwd[];
extern const char mqttWithoutPwd[];
extern const char ssidNotFoundInNvs[];
extern const char wifiPwdNotFoundInNvs[];
extern const char wifiStaticIpConfigNotFoundInNvs[];
extern const char wifiHostnameNotSet[];
extern const char mqttConnFailed[];
extern const char restoredHostnameFromNvs[];
extern const char currentVoltageMsg[];
extern const char sdBootFailedDeepsleep[];
extern const char currentChargeMsg[];
extern const char batteryCurrentMsg[];
extern const char batteryTempMsg[];
extern const char batteryCyclesMsg[];
extern const char batteryLowMsg[];
extern const char batteryCriticalMsg[];
extern const char wifiEnabledAfterRestart[];
extern const char wifiDisabledAfterRestart[];
extern const char voltageIndicatorLowFromNVS[];
extern const char voltageIndicatorHighFromNVS[];
extern const char batteryCheckIntervalFromNVS[];
extern const char warningLowVoltageFromNVS[];
extern const char warningCriticalVoltageFromNVS[];
extern const char batteryLowFromNVS[];
extern const char batteryCriticalFromNVS[];
extern const char unableToRestoreLastRfidFromNVS[];
extern const char restoredLastRfidFromNVS[];
extern const char failedOpenFileForWrite[];
extern const char fileWritten[];
extern const char writeFailed[];
extern const char writingFile[];
extern const char failedToOpenFileForAppending[];
extern const char listingDirectory[];
extern const char failedToOpenDirectory[];
extern const char notADirectory[];
extern const char sdMountedMmc1BitMode[];
extern const char sdMountedMmc4BitMode[];
extern const char sdMountedSpiMode[];
extern const char backupRecoveryWebsite[];
extern const char restartWebsite[];
extern const char shutdownWebsite[];
extern const char mqttMsgReceived[];
extern const char trackPausedAtPos[];
extern const char freeHeapWithoutFtp[];
extern const char freeHeapWithFtp[];
extern const char freeHeapAfterSetup[];
extern const char tryStaticIpConfig[];
extern const char staticIPConfigFailed[];
extern const char wakeUpRfidNoIso14443[];
extern const char lowPowerCardSuccess[];
extern const char rememberLastVolume[];
extern const char unableToStartFtpServer[];
extern const char newPlayModeStereo[];
extern const char newPlayModeMono[];
extern const char portExpanderFound[];
extern const char portExpanderNotFound[];
extern const char portExpanderInterruptEnabled[];
extern const char warningRefactoring[];
extern const char playlistGenModeUncached[];
extern const char playlistGenModeCached[];
extern const char playlistCacheFoundBut0[];
extern const char bootLoopDetected[];
extern const char noBootLoopDetected[];
extern const char importCountNokNvs[];
extern const char errorReadingTmpfile[];
extern const char errorWritingTmpfile[];
extern const char eraseRfidNvsWeb[];
extern const char eraseRfidNvs[];
extern const char erasePlaylistCachefile[];
extern const char fwStart[];
extern const char fwEnd[];
extern const char otaNotSupported[];
extern const char otaNotSupportedWebsite[];
extern const char noPlaylist[];
extern const char rfidTagRemoved[];
extern const char rfidTagReapplied[];
extern const char unableToTellIpAddress[];
extern const char ftpEnableTooLate[];
extern const char syncingViaNtp[];
extern const char sdInfo[];
extern const char paOn[];
extern const char paOff[];
extern const char hpOn[];
extern const char hpOff[];
extern const char webTxCanceled[];
extern const char cantConnectToWifi[];
extern const char tryToPickRandomDir[];
extern const char pickedRandomDir[];
extern const char wrongWakeUpGpio[];
