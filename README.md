# Tonuino based on ESP32 with I2S-output

## Disclaimer
This is a fork of the popular [Tonuino-project](https://github.com/xfjx/TonUINO) which means, that it only shares the basic concept of controlling music-play by RFID-tags and buttons. Said this I want to make clear, that the code-basis is completely different. So there might be features, that a supported by my fork whereas others are missing or implemented different. For sure both share, that's it's non-profit, DIY and developed on [Arduino](https://www.arduino.cc/).

## What's different (basically)?
The original project makes use of microcontrollers (uC) like Arduino nano (which is the Microchip AVR-platform behind the scenes). Music-decoding is done in hardware using [DFPlayer mini](https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299) which also has a uSD-card-slot and an integrated amp as well. Control of this unit is done by a serial-interconnect with the uC using an api provided.

The core of my implementation is based on the popular [ESP32 by Espressif](https://www.espressif.com/en/products/hardware/esp32/overview). Having WiFi-support out of the box makes it possible to provide features like an integrated FTP-server (to feed the player with music), smarthome-integration by using MQTT and webradio. However, my aim was to port the project on a modular base which means, that music-decoding takes place in software with a dedicated uSD-card and music-output with I2S. I did all my tests on [Adafruit's MAX98357A](https://learn.adafruit.com/adafruit-max98357-i2s-class-d-mono-amp/pinouts). Hopefully, not only in theory, other DACs can be used as well.

## Basic concept/handling
The basic idea of Tonuino (and my fork as well) is to provide a way, to use the Arduino-platform for a music-control-concept that is derived from the popular Toniebox. This basically means that RFID-tags are used to direct a music-player. Even for kids is concept is simple: place an RFID-object (card, character) on top of a box and the music starts to play. Place another object on it and the player plays anything else.

## Hardware-setup
So it's about time to have a look at the hardware I used. I'm using an ESP32 on a development-board that more or less looks like [this](https://docs.zerynth.com/latest/official/board.zerynth.nodemcu_esp32/docs/index.html). If ordered in China (Aliexpress, eBay e.g.) it's pretty cheap (around 4€) but even in Europe it's only around 8€.
* [Adafruit's MAX98357A](https://learn.adafruit.com/adafruit-max98357-i2s-class-d-mono-amp/pinouts)
* [uSD-card-reader](https://www.amazon.de/AZDelivery-Reader-Speicher-Memory-Arduino/dp/B077MB17JB)
* [RFID-reader](https://www.amazon.de/AZDelivery-Reader-Arduino-Raspberry-gratis/dp/B074S8MRQ7)
* [RFID-tags](https://www.amazon.de/AZDelivery-Keycard-56MHz-Schlüsselkarte-Karte/dp/B07TVJPTM7)
* [Neopixel-ring](https://www.ebay.de/itm/16Bit-RGB-LED-Ring-WS2812-5V-ahnl-Neopixel-fur-Arduino-Raspberry-Pi/173881828935)
* [Rotary Encoder](https://www.amazon.de/gp/product/B07T3672VK)
* [Buttons](https://de.aliexpress.com/item/32697109472.html)

Most of them can be ordered cheaper directly in China. It's just a give an short impression of the hardware.

## Getting Started
I recommend Microsoft's [Visual Studio Code](https://code.visualstudio.com/) alongside with [Platformio Plugin](https://platformio.org/install/ide?install=vscode.) My project in Github contains platformio.ini, so libraries used should be fetched automatically. Please note: If you use another ESP32-develboard (Lolin32) you have to change "env:" in platformio.ini to the corresponding value. Documentation can be found [here](https://docs.platformio.org/en/latest/projectconf.html). After that it might be necessary to adjust the names of the GPIO-pins in the upper #define-section of my code.

## Wiring
| ESP32 (GPIO)  | Hardware              | Pin    | Comment                                                      |
| ------------- |:---------------------:| ------:| ------------------------------------------------------------:|
| 5 V           | SD-reader             | VCC    | Connect to p-channel MOSFET for power-saving when uC is off  |
| GND           | SD-reader             | GND    |                                                              |
| 15            | SD-reader             | CS     |                                                              |
| 13            | SD-reader             | MOSI   |                                                              |
| 16            | SD-reader             | MISO   |                                                              |
| 14            | SD-reader             | SCK    |                                                              |
| 17            | RFID-reader           | 3.3V   | Connect directly to GPIO 17 for power-saving when uC is off  |
| GND           | RFID-reader           | GND    |                                                              |
| 22            | RFID-reader           | RST    |                                                              |
| 21            | RFID-reader           | CS     |                                                              |
| 23            | RFID-reader           | MOSI   |                                                              |
| 19            | RFID-reader           | MISO   |                                                              |
| 18            | RFID-reader           | SCK    |                                                              |
| 5 V           | MAX98357              | VIN    | Connect to p-channel MOSFET for power-saving when uC is off  |
| GND           | MAX98357              | GND    |                                                              |
| 25            | MAX98357              | DIN    |                                                              |
| 27            | MAX98357              | BCLK   |                                                              |
| 26            | MAX98357              | LRC    |                                                              |
| 34            | Rotary encoder        | CLR    |                                                              |
| 35            | Rotary encoder        | DT     |                                                              |
| 32            | Rotary encoder        | BUTTON |                                                              |
| 3.3 V         | Rotary encoder        | +      |                                                              |
| GND           | Rotary encoder        | GND    |                                                              |
| 4             | Button (next)         |        |                                                              |
| GND           | Button (next)         |        |                                                              |
| 35            | Button (previous)     |        |                                                              |
| GND           | Button (previous)     |        |                                                              |
| 32            | Button (pause/play)   |        |                                                              |
| GND           | Button (pause/play)   |        |                                                              |
| 5 V           | Neopixel              | 5 V    | Connect to p-channel MOSFET for power-saving when uC is off  |
| GND           | Neopixel              | GND    |                                                              |
| 12            | Neopixel              | DI     |                                                              |
| 17            | BC337 (via R5)        | Base   | Don't forget R5!                                             |

Optionally, GPIO 17 can be used to drive an NPN-transistor (BC337-40) that pulls a p-channel MOSFET (IRF9520) to GND in order to switch off current. Transistor-circuit is described [here](https://dl6gl.de/schalten-mit-transistoren): Just have a look at Abb. 4. R1: 10k, R2: omitted(!), R4: 10k, R5: 4,7k

## Prerequisites
* For debugging-purposes serialDebug can be set (before compiling) to ERROR, NOTICE, INFO or DEBUG.
* Make decision, if MQTT should be enabled (enableMqtt)
* If yes, set the IP of the MQTT-server and check the MQTT-topics (states and commands)
* In setup() RFID-cards can be statically linked to an action/file.
* Compile and upload the sketch

## Starting Tonuino-ESP32 first time
After pluggin in it takes a few seconds until neopixel indicates that uC is ready by four (slow) rotating LEDs. If uC was not able to connect to WiFi, an access-point (named Tonuino) is opened and after connecting this WiFi, a [configuration-Interface](http://192.168.4.1) is available. Enter WiFI-credentials, save them and restart the uC. Then reconnect to your "regular" WiFi. Place to favourite RFID-tag next to the RFID-reader and the music should start to play.

## Interacting with Tonuino
### Playmodes
It's not just simply playing music; different playmodes are supported:
* single track
* single track (loop)
* audiobook (single file or playlist; last play-position is saved)
* audiobook (loop)
* folder/playlist (alph. sorted)
* folder/playlist (random order)
* folder/playlist (alph. sorted) as loop
* folder/playlist (random order) as loop
* webradio (always only one "track")

### Modification RFID-tags
There are special RFID-tags available, that don't start music by themself but can modify things. If applied a second time, the corresponding acting will be reversed. Please note: all sleep-modes do dimming automatically because it's supposed to be used in the evening when going to bed. Well, at least that's my children's indication :-)
* lock/unlock all buttons
* sleep after 5/30/60/120 minutes
* sleep after end of current track
* sleep after end of playlist
* dimm neopixel
* current track in loop-mode (is "stronger" than playlist-loop but doesn't overwrite it!)
* playlist in loop-mode
* track und playlist loop-mode can be activated in parallel, but unless track-loop isn't deactivated, playlist-loop doesn't come into "play"

### Neopixel
Indicates different things:
* IDLE: four LEDs slow rotating
* ERROR: all LEDs flashing red (1x)
* OK: all LEDs flashing green (1x)
* BUSY: violet; four fast rotating LEDs
* track-progress: rainbow; number of LEDs relative to progress
* playlist-progress: blue; appears only in playlist-mode with every new track; number of LEDs relative to progress
* loudness: green => red-gradient; number of LEDs relative from current to max loudness
* switching off: red; circle that grows until long-press-time is reached
* buttons locked: track-progress-LEDs in red
* paused: track-progress-LEDs in orange

### Buttons
* previous (short): previous track
* previous (long): first track in playlist
* next (short): next track in playlist
* next (long): last track in playlist
* pause/play (short/long): pause/play
* rotary encoder (turning): vol +/-
* rotary encoder (press long): switch off (only when on)
* rotary encoder (press short): switch on (only when off)

### Music-play
* music starts playing after valid RFID-tag was applies
* if playing a folder should be played that contains many mp3s, the playlist generation can take a few seconds
* while playlist is generated Neopixel indicates BUSY-mode
* after last track was played, Neopixel indicates IDLE-mode
* in audiobook-mode, last play-position is remembered

### Audiobook-mode
This mode is different, as the last playposition is saved. Playposition is saved when...
* next track starts
* first/previous track requested by button
* pause was pressed
* playlist is over (playposition is set back to the first track and fileposition 0)