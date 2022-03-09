# sensor-playground
Indoor Air-Quality / Sensor Playground Project

Copyright Notice

Copyright (c) 2022, tdwgithub
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

INTRODUCTION

The Sensor Playground was designed to be a fun, easy-to-build platform for you
to experiment with software, sensors, displays, the IoT, etc.  It grew out of
a project I started after my wife suggested that some of the reasons for how
we had been feeling might be related to our indoor air-quality. 

It has been intentionally structured to make is straightforward for anyone 
with modest soldering skills and a bit of experience with tools like Arduino, 
to be able to construct a project that suits their ideas.

See: https://hackaday.io/project/182619-sensor-playground for more information.


It takes a kind-of "landing pad" approach, where you can build up the board 
and plug-in different kinds of processor modules, sensor sub-modules, displays,
etc. without the need to solder them directly to the board.  The number and 
variety of things you can plug in is virtually entirely up to you.

BUILDING YOUR OWN

There aren't a lot of "required" components, short of perhaps the power supply
section & the processor module and even that has been designed to give you a
wide range of choices.  

For example if you don't have a need for an encoder you don't need to install
it or its supporting pull-up resistors.  Same holds for the PCB-mount buttons.  As for
the sensors, I designed the PCB so that the processor I2C bus, SPI bus and a UART
are available via sockets or pins at a number of locations across the board.
This lets you connect the devices you choose at the points that make sense to
your particular application.  While there are outlines for some of the sensors
that I chose to use, these are by no means the ones you have to select.

3.3V, 5.0V & GND are made available on most connectors, so that it's easy to 
find a nearby power connection.

The component mounting types are all through-hole, making it pretty simple to
solder in what you want and there is a fair amount of space to get your soldering
iron into the places you need it to go.

SURFACE MOUNT COMPONENTS...! (relax, they're optional!)

I did add one (optional) surface-mount component: A processor reset controller.

If the processor module you choose doesn't already provide a power-on reset, or
perhaps its unreliable, then you can elect to install this component.  It's only
three pins and should be relatively easy for those with basic soldering skills and
a reasonably steady hand to install.  The only other component needed for the reset
circuit is a 100K, through-hole resistor.  See?  Not so hard after all!

PROCESSORS

I mentioned that you have flexibility in terms of your choice of processors.  This
is due to fact that the board has been designed to take one of two common processor
module types:

1. The ESP32 "DevKit"-style modules, from Esprssif, Inc.
2. A host of "Feather" form-factor modules.

The ESP32 modules are dual-core powerhouses, with WiFi, Bluetooth, large memory, etc.
If you have a processor-intensive application, the ESP32 is a great choice.

The "Feather" modules are a form-factor and pin-functionality specification created
by AdaFruit.  These modules are available with a wide range of processors, memory, 
IO, etc. and the pin-out is nearly identical across them all.  To date, I've used
ESP8266 Feather modules, ESP32 modules (same processor as the ESP32 DevKit, 
different form-factor), & ARM Cortex M0.  Given the circuit design I've chosen, 
all of these work on the Sensor Playground board.

I chose to focus on I2C, SPI and UART as the primary mechanism for connecting with the
sensors, displays, and other IO.  This allows for a wide range of devices to be 
connected, while limiting the amount of digital IO that would otherwise need to be
provided across the PCB.  There are a few  GPIO pins available on one of 
the headers (the same pins I use for the encoder and its button, along with the PCB-
mount push buttons).  

What if I want other IO than just SPI, I2C or UART?

Glad you asked!  If you elect to use a Feather form-factor processor module, you could
be in luck!  That specification also allows for the addition of "Feather Wing" expansion
modules to be plugged onto the top of Feather processor modules.  You can find a
pretty wide range of IO option boards that should satisfy a pretty wide range of requirements.

How do I build this thing?

I'll be adding some construction guides soon.  These will give you hints about how to go
about building the version of the Sensor Playground that best suits your application 
needs.

To find the construction guides, along with tips, etc., look in the "doc" folder at the
top level of this project.
