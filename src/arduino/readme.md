Example Arduino sketches.

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

Introduction 

The samples here demonstrate various features of the Sensor Playground.  They
aren't written as "final" applications, per se.  You'll note that I've tried
to keep the code fairly straightforward, not doing much of the Computer-Sciency
stuff I'm typically tempted to do.  The idea is to understand how to use the
features of the board, not to offer an off-the-rack application solution.

Arduino Libraries

I didn't provide the various 3rd-party libraries that I use in my sketches.
If I were to do that, I'd probably be violating a ton of copyrights, plus I'd
just end up duplicating the instructions for their use that the authors have
already provided.  

I do provide the source and libraries that *I* and personally responsible for.
If you're not familiar with how to create your own libraries and how to use them
I'd suggest taking a look here: https://roboticsbackend.com/arduino-create-library/
and at other sources on the InterWebs.  The way you can tell the difference 
between the source code of my own libraries and the Arduino source code of the
sketches is the filename extensions.  If the file name ends with a ".ino", you
can assume that's a sketch source file.  If the filename ends in either ".c++",
".c", you can be pretty sure that those are my own libraries.  If a filename 
has an extension of ".h", that's a toss-up.  I'll try to document where those
should live, to limit confusion as much as possible.  So, if 
you want to use my sources, you'll need to follow the instructions from the Web
about where to locate those files and how to install them into the Arduino 
environment.

