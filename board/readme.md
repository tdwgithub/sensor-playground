
Board Files

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

The board schematic and PCB layout were created using KiCad V5.1.x.

Since the project design targets being a "landing pad" for various add-ons
like sensor boards, displays, etc., the schematic doesn't call out or 
include any specific sensor, etc.  This implies that the bill of materials
doesn't specify them either.  Rather, the schematic calls out the contact
points that I've made available (via 0.0" header pins or sockets).  With 
regard to the BOM, I will add elements to the BOM for the sensors and 
displays that I chose for my own application(s).

PCB

The PCB has been designed as a 2-layer board, using through-hole components
wherever possible (there are only a few potential exceptions).  The bottom of
the board floods the unused space with a ground plane, to help avoid noise or
ground-path issues.  If you choose to modify the PCB layout, I recommend that 
you remove the ground plane flood first, do you mods, then re-flood.  Also
remember that there are multiple connection points to that plane and so you want
to be sure those connections are maintained to it.  If you intend to remove the 
ground flood, you must re-create the GND connections that originally used it.
