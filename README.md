<div align="center" width=100%>

  <img src="images/Tempus_TitleIMG_Caption.png">

  <p display="inline">

  <a href="https://creativecommons.org/licenses/by-nc/4.0/"><img src="https://licensebuttons.net/l/by-nc/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial 4.0 International License"></a><a href="https://hackclub.com/"><img alt="Funded by Hack Club" src="https://img.shields.io/badge/Hack_Club-Funded-ec3750?style=for-the-badge&logo=hackclub&logoColor=ec3750"></img></a>

  </p>

  <h1></h1>

  <p>
    An open source, ESP32-based smartwatch!
  </p>
</div>

<sub>This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License](https://creativecommons.org/licenses/by-nc/4.0/).
</sub>

## Table of Contents

- [About](#about)
- [Features](#features)
- [Specifications](#specifications)
- [Bill of Materials](#bill-of-materials)
- [Contributing](#contributing)

## About

The Tempus is a small yet powerful ESP32 devboard PCB, equipped with all the features that a modern digital smartwatch would need. Fully able to track steps and gestures, voice text, make beeps and alerts with a buzzer, power a round touchscreen, and, of course, tell time, it's the ideal replacement for a multi-hundred-dollar smartwatch with the same features.

## Features

Speaking of features, this watch is equipped with the following:
- A precise, quick gyroscope/accelerometer for hand tracking
- WiFi and Bluetooth for connecting to your phone to receive texts and calls, as well as control music apps such as Spotify
- An RTC (Real Time Clock) chip capable of maintaining incredibly accurate time
- A passive buzzer, capable of playing simple melodies and making beeps and alarms
- A microphone for voice messaging or reminders. (Note: the watch doesn't have a speaker, so playing music, receiving calls, etc. must be done through headphones connected to a phone connected to the watch. Also, unfortunately the ESP32-S3 cannot be used as a microphone during calls, so for that you'll need to use your phone's built-in mic.)
- Four reprogrammable buttons on all sides of the watch, perfect for quick text replies, controlling music, or navigating to apps.
- A modern USB-C charging and programming recepticle
- A battery percentage monitor to ensure the watch never dies
- A 1.28" capacitive touch display

## Specifications

Nerd info incoming
- Main processor: ESP32-S3-Wroom-1
- Gyroscope/accelerometer: LSM6DSO32
- RTC: DS3231M
- Battery Charging: TP4056-42
- Microphone: SPH0645LM4H
- Display: [1.28 inch 240x240 IPS TFT LCD Round Circle Capacitive Touch Screen](https://www.ebay.com/itm/305668452899?var=604666595108)
- USB: USB-C 2.0 16P
- Main 3v3 Voltage Converter: LM1117DT-3.3

## Bill of Materials

### Self-Assemble

```
Note: two parts on the watch are incredibly, incredibly difficult to hand-solder: the microphone and gyroscope. This means that if you choose to hand-solder the watch and you can't solder these, you cannot access the features these chips provide. If you'd like to, you can get one-sided PCBA instead, and choose either to use the microphone or gyroscope. Also note that this thing has a ton of lil tiny capacitors and stuff so be warned.
```

### Grand Self-Assemble Total: $xxxxx

|    Item   |  Price  |                           Link                            | Shipping |
|-----------|---------|-----------------------------------------------------------|----------|
| PCB       | ~$8     | <https://jlcpcb.com>                                      | $0       |
| PCB Parts | ~$30    | <https://jlcpcb.com>                                      | ~$8      |
| Screen    | $11.19  | <https://www.ebay.com/itm/305668452899?var=604666595108>  | $15      |
| Battery   | $5.92   | <https://www.aliexpress.us/item/3256808031709894.html>    | $0       |
| Total     | $       |                                                           | $        |

### PCBA

#### Grand PCBA Total: $145.11

|   Item  |  Price  |                           Link                            | Shipping |
|---------|---------|-----------------------------------------------------------|----------|
| PCB     | ~$8     | <https://jlcpcb.com>                                      | $0       |
| PCBA    | ~$65    | <https://jlcpcb.com>                                      | ~$40     |
| Screen  | $11.19  | <https://www.ebay.com/itm/305668452899?var=604666595108>  | $15      |
| Battery | $5.92   | <https://www.aliexpress.us/item/3256808031709894.html>    | $0       |
| Total   | $90.11  |                                                           | $55      |

## Contributing

<sub>aha somebody wishes to help me i see</sub>

If you'd like to request changes, suggest additions, or forcefully make me edit things, feel free to contact me via email (`me at anicetus dot dev`, preferred) or Discord (anic3tus).
