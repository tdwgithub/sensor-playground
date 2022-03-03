//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/*
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
*/
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/*
** faux_io.cpp - Non-functional emulation of Adafruit.io client library.
** Copyright 2021, 2022 by TDW
**
** This provides a non-functional implementation of the Adafruit.IO client object.  It allows
** the example air-quality software to act as though it has a connection to AIO, for devices
** that don't have a network connection, or for cases where there is no AIO account.
*/
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#include "Arduino.h"
#include "faux_io.h"


/*! \fn
**
** FUNCTION: AdafruitIO_Feed
**
** DESCRIPTION: Feed object dummy implementation.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
AdafruitIO_Feed::AdafruitIO_Feed(String feedName)
{
    this->feedName = feedName;
}

/*! \fn
**
** FUNCTION: saveParent
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_Feed::saveParent(void *parent)
{
    return;
}

/*! \fn
**
** FUNCTION: save
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_Feed::save(float value)
{
    return;
}

/*! \fn
**
** FUNCTION: save
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_Feed::save(int value)
{
    return;
}

/*! \fn
**
** FUNCTION: save
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_Feed::save(byte value)
{
    return;
}

/*! \fn
**
** FUNCTION: save
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_Feed::save(uint16_t value)
{
    return;
}

/*! \fn
**
** FUNCTION:
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_Feed::save(uint32_t value)
{
    return;
}


//###############################################################

/*! \fn
**
** FUNCTION: AdafruitIO_WiFi
**
** DESCRIPTION: Dummy AIO object constuctor.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
AdafruitIO_WiFi::AdafruitIO_WiFi(String userName, String io_key, String ssid, String pw)
{
    return;
}

/*! \fn
**
** FUNCTION: feed
**
** DESCRIPTION: Dummy feed method
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
AdafruitIO_Feed *AdafruitIO_WiFi::feed(String feedName)
{
    AdafruitIO_Feed         *ret = new AdafruitIO_Feed(feedName);
    if (ret)
        ret->saveParent((void *)this);

    return (ret);
}

/*! \fn
**
** FUNCTION: run
**
** DESCRIPTION: Dummy AIO run method
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AdafruitIO_WiFi::run(void)
{
    return;
}

/*! \fn
**
** FUNCTION: connect
**
** DESCRIPTION: Dummy ADIO connect method
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
int AdafruitIO_WiFi::connect(void)
{
    return (1);
}

/*! \fn
**
** FUNCTION: status
**
** DESCRIPTION: Dummy AIO status method
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
ADAFRUIT_CONNECT_STATUS AdafruitIO_WiFi::status(void)
{
    return AIO_CONNECTED;
}

//###############################################################
