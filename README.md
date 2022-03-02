# sensor-playground
Indoor Air-Quality / Sensor Playground Project

This project is a system that with the appropriate sensors and software can be used to track indoor air-quality.  However in a larger sense, it's design is such that you can use it to host applications for a variety of sensors and interface devices.

It tends to target I2C & SPI connected devices (sensors such as Temperature/Humidity, CO2, PM2.5, or things like SPI/I2C displays, etc...) and attempts to make it straightforward to try out new devices.

It also attempts to make selection of a processing module simple, in that it can host various "Feather" form-factor modules, or ESP32-compatible modules.  This design choice opens the door to many different platforms, including ARM, ESP8266/ESP32, etc.  There are a wide variety of programming environments available for both the ESP32 and Feather boards, allowing you to choose the platform that most suits your skills and preferences.

One particular goal of this project is to make it simple to build.  To that end, I have used through-hole construction whereever possible.  If you have even modest soldering skills, you should be able to assemble a functional version of this system.   The majority of connections (with respect to both the processing elements and the sensors, etc.) is done via sockets, as opposed to having to solder components directly.  The main bits that must be soldered directly on the PCB are things like resistors, capacitors and the headers/sockets themselves.  There is a small power-supply section that provides up to 1A at 3.3V (and dependent upon the source 5V supply).  All in all, it should be pretty easy to build what you want.

The project provides the following elements:

1. The KiCad schematic.
2. The KiCad PCB layout and associated files.
3. Sample Arduino code for an indoor air-quality monitor.
4. Examples of how I use the system with the Adafruit.IO IoT system.
5. Bill of Materials for the basic board and some of the sensors I've used.
6. Suggestions about how you can use this beyond my own application(s).


