# A little utility for brewing

## Contents

1. Description
2. Needed Materials
3. Hardware Wiring
4. Installation of the Firmware
5. Customization
6. latest News

## 1. Description

This utility is made to measure the frequency of bubbles produced by brewing in the standard Hardware. 

It works by counting the sound hits produced by the bubbles over a period of time and savind the data to a standard Micro-SD card.

The cost of the Hardware should come in at about 20 EUR. 

Currently only Arduino Unos are supported. More boards will follow, if some bord is specifically needed, please open an Ticket in the Issues tab.

## 2. Needed Materials

PCBs and Sensors/Modules: (non-paid links of example items)

- Arduino Uno (~7 EUR)
- SPI Reader Micro SD Memory Card Shield (~2 EUR)
    https://www.amazon.de/gp/product/B077MCQS9P/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1
- Real Time Clock RTC DS3231 I2C (~6 EUR)
    https://www.amazon.de/gp/product/B01M2B7HQB/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1
- KY-037 Microphone Sensor module (~2 EUR)
    https://www.amazon.de/gp/product/B07CN3D77S/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1

Other Materials:
- Wires (thin ones will do)
- Dupond Connectors (or solder)
- Arduino USB cable, mostly shipped with the Arduino
- A powerbank, can also be powered by a 5V USB power plug

Software you need: 
- Arduino IDE (Available on Windows/Mac/Linux for free): https://www.arduino.cc/en/Main/Software


Optional Materials:
- 3D printer for the mount, not nessesary, the STL Files ar in the Folder "Hardware Models"

## 3. Hardware Wiring

Upload will follow shortly

## 4. Installation of the Firmware

Download the latest Release from this repository (Master Branch contains the latest Stable release).

Open the file "detection_firmware.ino" in the "detection_firmware" Folter in the Arduino IDE and connect the Arduino via USB to the PC.

On linux, you might have to give yourself Rights on the Serial Connection:
- run the command: sudo chmod a+rw /dev/tty*
- the * in the path has to be replaced by the port used by the Arduino on the PC, the right path can be identified by the command: sudo ls -l /dev/tty*

In the Arduino IDE:
1. Import the ZIP File "DS3231.zip" in the Sketch tab by using the "Manage Librarys". This Library comes directy from http://www.rinkydinkelectronics.com/library.php?id=73
2. In the "Tools" menu choose the Correct Board you are using and the port it is connected to
3. Upload the Firmware to the Arduino by Clicking the Upload-Button or pressing Control & U

## 5. Customization

Will be added shortly

## 6. latest News

| Date | News |
| --- | --- |
| 19. April 2020 | Adding hitcount in the Datasave |
| 18. April 2020 | First Prototype is measuring! |
