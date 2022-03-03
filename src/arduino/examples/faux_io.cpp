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
