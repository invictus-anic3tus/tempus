
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
- A modern USB-C 2.0 charging and programming recepticle
- A 500mAh battery, to ensure minimal charging time
- A battery percentage monitor to ensure the watch never dies
- A 1.28" capacitive touch display

## How do I build this?

Good question! If you'd like to make the Tempus for yourself, there's a few things you should keep in mind:
1. You must have access to a 3D printer or be willing to pay for a printing service. TPU or another flexible filament is required for the watch band.
2. You must have access to soldering equipment and be skilled in soldering. This includes a hot air gun and solder paste.
3. This design necessitates a custom PCB. These can get expensive if you need to account for shipping or tariff costs.
4. This is _not_ a professional design! I'm a random guy from the internet who made a smartwatch design; if you want to make it for yourself, go ahead! But I am not responsible for any misuse or unintended happenings due to faulty design.
5. Commercial use is not allowed. You cannot make this watch to sell to anybody.

Alright! Now we can get into how to actually build it. First, download the gerber.zip file in the PCB_Production folder, go to your favorite PCB manufacturing service (JLCPCB and PCBWay are good) and upload it in their quote system. It should say four-layer PCB. Here are the settings to select:
(Make sure you know what you're doing before changing these! The color is self-explanatory, but colors other than green can be more expensive.)

![JLCPCB settings](https://cdn.hackclub.com/019d3b94-c724-726a-873b-5d1cd7a48551/Screenshot%202026-03-29%20165027.png)

Then, order the DigiKey parts in [this cart](https://www.digikey.com/short/2mbbn5n0) and the screen from [BuyDisplay](https://www.buydisplay.com/1-28-inch-tft-lcd-display-240x240-round-circle-screen-for-smart-watch) or [eBay](https://www.ebay.com/itm/305668452899?var=604666595108).

Next, 3D print the files in the CAD folder. Detailed assembly instructions coming soon; for now, please reference the full CAD design!

![Wiring](https://cdn.hackclub.com/019d3bb2-d63f-7f48-a17c-6b90a8c8f6fe/Tempus%20Wiring%20Diagram.png)

## Specifications

Nerd info incoming
- Main processor: ESP32-S3-Wroom-1
- Gyroscope/accelerometer: LSM6DSMTR
- RTC: DS3231M+
- Battery Charging: TPB4056B (A drop-in TP4056 replacement, available on DigiKey)
- Microphone: SPH0645LM4H-B
- Display: [1.28 inch 240x240 IPS TFT LCD Round Circle Capacitive Touch Screen](https://www.buydisplay.com/1-28-inch-tft-lcd-display-240x240-round-circle-screen-for-smart-watch)
- Main 3v3 Buck-Boost Converter: TPS63031DSKR

![PCB](https://cdn.hackclub.com/019d3ba3-0f56-7da4-9f31-285cc6056e66/Screenshot%202026-03-29%20170708.png)

## Bill of Materials

|       Item       |  Price  |                                                  Link                                              | Shipping |
|------------------|---------|----------------------------------------------------------------------------------------------------|----------|
| PCB              | $2      | <https://jlcpcb.com>                                                                               | $3.18    |
| DigiKey Parts*   | $57.74  | <https://www.digikey.com/short/2mbbn5n0>                                                           | $6.99    |
| Screen           | $8.85   | <https://www.buydisplay.com/1-28-inch-tft-lcd-display-240x240-round-circle-screen-for-smart-watch> | $8.12    |
| Total            | $68.59  |                                                                                                    | $18.29   |

*Including subjective tariffs, taxes, etc. Also includes battery.

An online DigiKey cart is available at <https://www.digikey.com/short/2mbbn5n0>.

### Grand Total: ±$86.88

(Recommended planned price: $94)

## Contributing

<sub>aha somebody wishes to help me i see</sub>

If you'd like to request changes, suggest additions, or forcefully make me edit things, feel free to contact me via email (`me at anicetus dot dev`, preferred) or Discord (anic3tus).
