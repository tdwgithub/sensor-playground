#ifndef __FAUX_IO_H_INCLUDED
#define __FAUX_IO_H_INCLUDED

#include "Arduino.h"

class AdafruitIO_Feed
{
    public:
        AdafruitIO_Feed(String feedName);
        void saveParent(void *parent);
        void save(float value);
        void save(int value);
        void save(byte value);
        void save(uint16_t value);
        void save(uint32_t value);  

    private:
        void *parent;
        String feedName;
};

typedef enum
{
    AIO_CONNECTED,
    AIO_NOT_CONNECTED,
    AIO_CONNECTION_ERROR
}ADAFRUIT_CONNECT_STATUS;

class AdafruitIO_WiFi
{
    public:
        AdafruitIO_WiFi(String userName, String io_key, String ssid, String pw);
        AdafruitIO_Feed *feed(String feedName);           
        void run(void);
        int connect(void);
        ADAFRUIT_CONNECT_STATUS status(void);
};



#endif // FAUX_IO_H_INCLUDED
