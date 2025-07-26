---
title: "Tempus32"
author: "Anicetus"
description: "A flashy, powerful ESP32-based smartwatch"
created_at: "2025-07-21"
---

## total time: 12 hrs

# firstly
i want to thank everybody at hack club who's making this possible. if you don't know, hack club is a 100% 501(c)(3) nonprofit run by zach latta + friends made for coders and electronics peoples 18 and under. this project is made possible through their highway to undercity program, where teens are empowered to build their dreams with up to $350 in funding!

so a big thank you out to acon, alex ren, cyao, ducc, bunnyguy, phthallo, paolo, kareem, rhys, kl, ian, tongyu, manitej, cinders, and m0hid!!

## i'm anicetus
if you're reading this on hack club, you may very well already know me. but if you dont, here's a bit of info:  
1. I live in the usa  
2. i'm ok at coding  
3. but i think im pretty good at electronics and stuff!  
4. i've designed a custom drone  
5. and a custom 3d printer  

so yeah i've got a bit to put on my resume! but anyways let's get down to business.

## log

### day one - july 21st

today i started out by googling some schematics for esp32 devkits. I don't plan to copy them line-for-line, but for necessary stuff like the power converters and whatnot I'll look at them, figure out why each component is there, then and only then add it to my own schematic. After learning what some of the parts do, I may even omit them, namely the second USB port on the ESP32 S3 DevkitC 1. I got a little done, but mostly just reviewing and researching what stuff in the schematic did.

#### 2 hrs

### day two - july 22nd

today I worked mostly on other projects, but I got a tiny bit of time in copying more of the schematic. I added the voltage converter thingy that turns 5v into 3.3v, and this was the first time I really had to improvise. I couldn't find the component the original devkit uses in stock anywhere, so I took the liberty of looking for one myself. I found the LM1117, which is a fixed-voltage outputter, meaning each one can only output a certain voltage instead of being adjustable. This is good since I don't need extra resistors or anything to control it.

<img width="1451" height="279" alt="schem" src="https://github.com/user-attachments/assets/77aa34ab-7446-4743-99cc-980a3a055b28" />

#### 0.5 hrs

### day three - july 23rd

DEADLINE APPROADCHING AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

today i copied more of the schematic. I'm using a THT USB-C 2.0 instead of a microusb to make it nicer, but it came with a _lot_ of research. Like, a _**lot**_. I got it done tho!

<img width="3507" height="2480" alt="schem" src="https://github.com/user-attachments/assets/5b4ca8c9-016a-49ea-9ac5-6f03e77c019f" />

#### 2.5 hrs

### days four through six - july 24 - 26

these days I just worked on copying the schematic more. I added an RTC clock, a gyroscope, and other miscellaneous items, and I started work on the display. It's going to take a ton of GPIOs, and I hope I'll have enough without having to use an IO expander!

#### 7 hrs total
