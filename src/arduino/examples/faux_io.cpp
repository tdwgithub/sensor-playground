/*
 * faux_io.cpp - Non-functional emulation of Adafruit.io client library.
 */


#include "Arduino.h"
#include "faux_io.h"


//###############################################################

AdafruitIO_Feed::AdafruitIO_Feed(String feedName)
{
    this->feedName = feedName;
}

void AdafruitIO_Feed::saveParent(void *parent)
{
    return;
}

void AdafruitIO_Feed::save(float value)
{
    return;
}

void AdafruitIO_Feed::save(int value)
{
    return;
}

void AdafruitIO_Feed::save(byte value)
{
    return;
}

void AdafruitIO_Feed::save(uint16_t value)
{
    return;
}

void AdafruitIO_Feed::save(uint32_t value)
{
    return;
}


//###############################################################

// Constructor
AdafruitIO_WiFi::AdafruitIO_WiFi(String userName, String io_key, String ssid, String pw)
{
    return;
}

// "feed" method
AdafruitIO_Feed *AdafruitIO_WiFi::feed(String feedName)
{
    AdafruitIO_Feed         *ret = new AdafruitIO_Feed(feedName);
    if (ret)
        ret->saveParent((void *)this);

    return (ret);
}

void AdafruitIO_WiFi::run(void)
{
    return;
}

int AdafruitIO_WiFi::connect(void)
{
    return (1);
}

ADAFRUIT_CONNECT_STATUS AdafruitIO_WiFi::status(void)
{
    return AIO_CONNECTED;
}

//###############################################################
