---
title: "Vial"
author: "Anicetus"
description: "A flashy, powerful ESP32-based smartwatch"
created_at: "2025-07-21"
---

## total time: 24.5 hrs

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

### day seven - july 27

uh oh. today i realized that i built the entire display part of the schematic around a display without a touchscreen! i had to delete it, do more research to find an actual touchscreen, and replace it. All in all it wasn't too difficult, though. I found the new display on <https://buydisplay.com>, which seems to be a fairly legit Chinese display seller. I did a bunch of PCB work too!

#### 2 hrs

### day eight - july 28

ok welp yesterday was kinda useless. Turns out when you make a circle in Kicad for the board outline, you're defining the radius, not the diameter like I'm used to in f360. Basically i made the watch 4x as big as it should be and the entire pcb has to be scrapped. Now normally this would be devastating, especially with the july 31st highway deadline. However, I've decided to submit it for [Grounded](https://grounded.hackclub.com) instead! The grounded deadline is _August_ 31st, meaning I have an entire extra month to make this thing. I also decided that instead of a round display like I found yesterday, I'm gonna try to find a square display with rounded corners, since I think they look better. I deleted everything in the PCB, which, by the way, I had just completed, and reimported from the schematic.

I have a few minor changes in mind, such as removing the RTC battery and just using the one lipo battery, and I was informed that I need a pullup resistor on GPIO0 and a schottky diode to prevent current backflow from the battery to the USB port. I also have to connect both D+ and D-'s of the usb receptacle, and I might remove the 3.3V -> 3V voltage converter for the display backlight. We'll see!

#### 3 hrs

### days nine and ten - august 8 and 9

i added the changes i said on day eight, and did a few more. I added four programmable buttons and some other stuff, and nearly finished routing the PCB! (again).

But an image is worth a thousand words, so here's four images: (worth 4000 words?)

<img width="3507" height="2480" alt="image" src="https://github.com/user-attachments/assets/0d37bfdb-3327-4199-82ad-d05d227fe8f3" />

<img width="732" height="904" alt="image" src="https://github.com/user-attachments/assets/54a393f8-e590-47af-ba16-e93667cbc47b" />

<img width="732" height="904" alt="image" src="https://github.com/user-attachments/assets/cb417de8-099e-47fd-80dc-a1067f50dd50" />

<img width="1201" height="845" alt="image" src="https://github.com/user-attachments/assets/2766d74c-a07d-405d-ac24-4768ca8c79cf" />

#### 4.5 hrs total

### day eleven - september 1

phew! that was a big gap! i've been doing a lot of work on [my drone](https://github.com/invictus-anic3tus/v4) and haven't had much time for this. But today I added a silkscreen and finished routing! pics tmrw probably :3

#### 3 hrs
