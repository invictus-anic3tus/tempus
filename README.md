
<div align="center" width=100%>

  ![Tempus Title Image](https://github.com/user-attachments/assets/8ff0b6ed-382e-4ab1-a680-015a6d90c699#gh-dark-mode-only)

  ![Tempus Title Image](https://github.com/user-attachments/assets/55e69d57-5103-4176-8eda-3a325154d405#gh-light-mode-only)

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

My name is Anicetus, and I love hardware. The Anicept Tempus is my newest addition to my brand, and the first devboard PCB! There are others out there, and many are probably much better. But I felt it was high time I had one of my _own._ It might not beat the competition in price, features, quality, you name it; but there comes a certain satisfaction when you can wear (more like tout at this point) a semi-stylish, functional, and helpful item that you can point to and confidently say: "I created this from scratch."

And so, the Tempus is a small yet powerful ESP32 devboard PCB + case, equipped with all the features that a modern digital smartwatch would need. Fully able to track steps and gestures, voice text, make beeps and alerts with a buzzer, power a round touchscreen, and, of course, tell time, it's the ideal replacement for a multi-hundred-dollar smartwatch with the same features.

## Features

Speaking of features, this watch is equipped with the following:
- A precise, quick gyroscope/accelerometer for hand tracking
- WiFi and Bluetooth for connecting to your phone to receive texts and calls, as well as control music apps such as Spotify
- An RTC (Real Time Clock) chip capable of maintaining incredibly accurate time
- A vibration motor for alerts and ringtones
- A microphone for voice messaging or reminders. (Note: the watch doesn't have a speaker, so playing music, receiving calls, etc. must be done through headphones connected to a phone connected to the watch. Also, unfortunately the ESP32-S3 cannot be used as a microphone during calls, so for that you'll need to use your phone's built-in mic.)
- Two reprogrammable buttons, perfect for quick text replies, controlling music, or navigating to apps.
- A modern USB-C charging and programming recepticle
- A 500mAh battery, to ensure minimal charging time
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
- Main 3v3 Buck-Boost Converter: TPS63031

## Bill of Materials

|     Item      |  Price  |                                         Link                                      | Shipping |
|---------------|---------|-----------------------------------------------------------------------------------|----------|
| PCB           | ~$2     | <https://jlcpcb.com>                                                              | $4       |
| Components    | ~$54    | <https://digikey.com>                                                             | ~$7      |
| Screen        | $8.85   | <https://www.ebay.com/itm/305668452899?var=604666595108>                          | $8.12    |
| Battery       | ~$8     | <https://www.digikey.com/en/products/detail/adafruit-industries-llc/1578/5054539> | $0       |
| Total         | ~$72.85 |                                                                                   | ~$19.12  |

### Grand Total: ~$91.97

## Contributing

<sub>aha somebody wishes to help me i see</sub>

If you'd like to request changes, suggest additions, or forcefully make me edit things, feel free to contact me via email (`me at anicetus dot dev`, preferred) or Discord (anic3tus).
