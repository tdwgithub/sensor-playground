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
**  Air-Quality Monitor Demonstration Code. 
**  Copyright 2021,2022 by TDW
**  
**  Supports various processor modules, with and without
**  WiFi/Adaftuit IO support.
**  
**  Relies heavily on I2C devices/sensors.
** 
**  Example code only.  You mileage may vary.
*/
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

#include "credentials.h"

/*
 * Switches for enabling/disabling various features.
 */
#define USE_ADAFRUIT_IO             (1)
#define USE_PM25_SENSOR             (1)
#define USE_DISPLAY                 (1)
#define USE_SERIAL                  (0)
#define USE_PUSHOVER                (0)

/*
 * What processor module are we using?  Define
 * "CPU" to one of these (or add definitions for
 * cpu's you use.
 */
#define ESP8266                     (1)
#define ESP32S2                     (2)
#define ESP32S1                     (3)
#define CORTEX_M0                   (4)
#define CORTEX_M1                   (5)
#define CORECT_M4                   (6)

//
// Which CPU are we using from the above list?
//
#define CPU                         (ESP8266)
    
//
// If using the CO2 sensor, use altitude adjustment
//
#if (LOCATION==HOME)
    #define LOCATION_ALTITUDE                                ((uint16_t)365)
#elif (LOCATION==MOMDAD)
    #define LOCATION_ALTITUDE                                ((uint16_t)879)
#endif

// Header Includes
#include "SparkFun_SCD4x_Arduino_Library.h"
#include "SparkFun_SGP40_Arduino_Library.h"
#include "Adafruit_PM25AQI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>
#include <HardwareSerial.h>
#include <Wire.h>

#if (USE_ADAFRUIT_IO==1)
    #include <AdafruitIO_MQTT.h>
    #include <AdafruitIO_Definitions.h>
    #include <AdafruitIO_Feed.h>
    #include <AdafruitIO_Time.h>
    #include <AdafruitIO_WiFi.h>
    #include <AdafruitIO.h>
    #include <AdafruitIO_Group.h>
    #include <AdafruitIO_Data.h>
    #include <AdafruitIO_Dashboard.h>
#else
    //
    // Spoofs the Adafruit.IO objects for controllers that don't
    // have WiFi or another way to reach the Internet.
    //
    #include "faux_io.h"    
#endif

#if (CPU==ESP8266)
    //#include <ESP8266WiFi.h>
#endif

//
// If USE_SERIAL is defined for a processor that only has a single
// UART, we undef the macro, so that that UART can be used for
// things like the PM2.5 sensor.  If your module has another UART,
// you can allow it to be used for console serial 
//
#if ( (CPU==ESP8266) || (CPU==ESP32S2) )
    #if (USE_PM25_SENSOR==1)
        #ifdef USE_SERIAL
            #undef USE_SERIAL
        #endif            
        #define USE_SERIAL          (0)
    #else
        #ifdef USE_SERIAL
            #undef USE_SERIAL
        #endif
        #define USE_SERIAL          (1)
    #endif
#else
    // OTHER CPU CONFIGURATION...
#endif

//
// Display Configurations
//
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
//
#define OLED_RESET     -1 //4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#if (USE_DISPLAY==1)
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#endif    

//
// WiFi Configuration
//
const char                              *ssid           = NET_SSID;
const char                              *password       = NET_PW;

//
// PUSHOVER DEFINITIONS
//
#if (USE_PUSHOVER==1)
    // Token & Key for my account
    String                                  apitoken        = PUSHOVER_API_TOKEN;
    String                                  userkey         = PUSHOVER_USER;

    //
    // Wifi connection object for PUSHOVER
    //
    WiFiClient                              pushoverClient;
    const char                              pushoversite[]  = "api.pushover.net";
    char                                    pushoverMsg[128];
    WiFiClient                              client;
    int                                     length;
#endif    

//
// ADAFRUIT.IO Feed Names    
//
#define AIO_FEED_CO2                    ("CO2")
#define AIO_FEED_VOC                    ("VOC")
#define AIO_FEED_PM25                   ("PM2.5")
#define AIO_FEED_TEMPERATURE            ("House Temperature")
#define AIO_FEED_HUMIDITY               ("House Humidity")

//
// Primary Adafruit object
//
AdafruitIO_WiFi io(AIO_USERNAME, AIO_KEY, NET_SSID, NET_PW);

//
// Create the Adafruit.IO feed objects, using the names defined
// above.
//
AdafruitIO_Feed *temperature = io.feed(AIO_FEED_TEMPERATURE);
AdafruitIO_Feed *humidity = io.feed(AIO_FEED_HUMIDITY);
AdafruitIO_Feed *co2 = io.feed(AIO_FEED_CO2);
AdafruitIO_Feed *voc = io.feed(AIO_FEED_VOC);
AdafruitIO_Feed *pm25 = io.feed(AIO_FEED_PM25);

//
// Asynchronous timer management struct
//
typedef struct
{
    uint8_t                 running;
    uint32_t                capturedTicks;
}TM_TIMER_STRUCT;

//
// TIMER Functions Prototypes
//
static int TIMER_start(TM_TIMER_STRUCT *timer);
static int TIMER_finished(TM_TIMER_STRUCT *timer, unsigned long timeoutMS);
static int TIMER_cancel(TM_TIMER_STRUCT *timer);
static int TIMER_running(TM_TIMER_STRUCT *timer);
static float CtoF(float degreesCelsius);

// Prototype for pushover notification method
byte pushover(String pushovermessage);

// Adafruit.io update timer
static TM_TIMER_STRUCT                      adafruitUpdateTimer;
#define ADAFRUIT_UPDATE_TIMEOUT_MS          (10000)

// CO2 sensor read timer
static TM_TIMER_STRUCT                      co2UpdateTimer;
#define CO2_UPDATE_TIMEOUT_MS               (5000)

// VOC sensor read timer
static TM_TIMER_STRUCT                      vocUpdateTimer;
#define VOC_UPDATE_TIMEOUT_MS               (1000)

// OLED display update timer
static TM_TIMER_STRUCT                      oledUpdateTimer;
static TM_TIMER_STRUCT                      displayShiftTimer;
#define OLED_DISPLAY_SHIFT_TIMEOUT_MS       (5000)
#define OLED_UPDATE_TIMEOUT_MS              (250)
#define CLEAR_DISPLAY_TIMEOUT_MS            (2500)

// PM 2.5 sensor update timer
static TM_TIMER_STRUCT                      pmUpdateTimer;
#define PM_UPDATE_TIMEOUT_MS                (1000)

// Other methods
static void _startPMSensor(void);
static void _startVOCSensor(void);
static void _startCO2Sensor(void);
static void _sendStartupPushover(void);
static void _startAdafruitIO(void);
static void _startDisplay(void);
static void _bannerToDisplay(void);

//
// Sensor objects
//
SCD4x mySensor;
SGP40 vocSensor;
int displayState;

#if (USE_PM25_SENSOR==1)
    #if ( (CPU==ESP8266) || (CPU==ESP32S2) )
        #define pmSerial    Serial
    #else
        HardwareSerial  pmSerial(1);
    #endif
    Adafruit_PM25AQI aqiSensor = Adafruit_PM25AQI();
#endif    

// Which IO pins are the two discrete buttons connected?
#if (CPU==ESP32S2)
    #define LEFT_BUTTON_PIN             (9)
    #define RIGHT_BUTTON_PIN            (5)
#else
    #define LEFT_BUTTON_PIN             (0)
    #define RIGHT_BUTTON_PIN            (2)
#endif

// Which IO pins are the encoder inputs connected?
#if ( (CPU==ESP8266) || (CPU==ESP32S2) )
    #define ENCODER_UP_PIN          (12)
    #define ENCODER_DN_PIN          (13)
    #define ENCODER_BTN_PIN         (14)
#else
    #define ENCODER_UP_PIN          (4)
    #define ENCODER_DN_PIN          (5)
    #define ENCODER_BTN_PIN         (15)
#endif
    
/*
 * USE THESE MACROS TO CONTROL PRINTING TO THE CONSOLE!
 */
#if (USE_SERIAL==1)
    #define PRINT            Serial.print
    #define PRINTLN          Serial.println
    #define FLUSH            Serial.flush
#else
    #define PRINT(x)         
    #define PRINTLN(x)
    #define FLUSH()
#endif

//
// Flag controls whether or not to update the display
//
static int displayOK = 1;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                                   APPLICATION CODE
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*! \fn
**
** FUNCTION: setup
**
** DESCRIPTION: Arduino initialization method.  Do any 
**              set up here that needs to be done prior to 
**              entering the main loop function of the application.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void setup() 
{    
    displayState = 0;

    // Get I2C configured
    Wire.begin();  

#if (USE_SERIAL==1)
    Serial.begin(9600);
    PRINTLN(F("Home Air-Quality Monitor."));
#endif

    //
    // Set up GPIO for buttons and encoder.
    //
    pinMode(LEFT_BUTTON_PIN, INPUT);
    pinMode(RIGHT_BUTTON_PIN, INPUT);
    pinMode(ENCODER_UP_PIN, INPUT);
    pinMode(ENCODER_DN_PIN, INPUT);
    pinMode(ENCODER_BTN_PIN,INPUT);

    //
    // Set up the display
    //
    _startDisplay();

    //
    // Connect to Adafruit.io
    //
    _startAdafruitIO();

    //
    // Send startup message via PUSHOVER
    //
    _sendStartupPushover();

    //
    // Set up the second UART & PM 2.5 sensor
    //
    _startPMSensor();            
    
    //
    // Start up the CO2 sensor
    //
    _startCO2Sensor();

    //
    // Start up the VOC sensor
    //
    _startVOCSensor();

    //
    // Final messages (on Serial and display)
    //
    PRINTLN("");
    PRINTLN("Starting sensor loop...");
    FLUSH();
    
    _bannerToDisplay();     
}

/*! \fn
**
** FUNCTION: loop
**
** DESCRIPTION: This method is called by the Arduino framework, as the primary application
**              loop.  Your goal is to do your work here and exit the function.  If you 
**              do anything that takes significant time, you'll need to put "yield()" calls
**              to keep the watchdog from resetting the device.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void loop() 
{
    static float           temp;
    static float           myHumidity;
    static uint16_t        CO2;
    static uint32_t        vocIndex;
#if (USE_PM25_SENSOR==1)    
    static PM25_AQI_Data   data;
#endif

    // If LEFT button pressed, display is enabled
    if (digitalRead(LEFT_BUTTON_PIN) == LOW)
    {
        displayOK = 1;        
        TIMER_start(&oledUpdateTimer);
    }

    // If right button is pressed, display is disabled
    if (digitalRead(RIGHT_BUTTON_PIN) == LOW)
    {
        displayOK = 0;
        displayState = 0;
        display.clearDisplay();
        display.display();
    }

    // Keep Adafruit IO refreshed
    io.run();

    // Time to read the PM2.5 Sensor
    if (TIMER_finished(&pmUpdateTimer, PM_UPDATE_TIMEOUT_MS))
    {
    #if (USE_PM25_SENSOR==1)
        if (aqiSensor.read(&data))        
        {        
            // Print concentations to the console.   
            PRINTLN("PM2.5 Readings:");
            PRINTLN();
            PRINTLN(F("---------------------------------------"));
            PRINTLN(F("Concentration Units (standard)"));
            PRINTLN(F("---------------------------------------"));
            PRINTLN(F("PM 1.0: ")); PRINT(data.pm10_standard);
            PRINT(F("\t\tPM 2.5: ")); PRINT(data.pm25_standard);
            PRINT(F("\t\tPM 10: ")); PRINTLN(data.pm100_standard);
            PRINTLN(F("Concentration Units (environmental)"));
            PRINTLN(F("---------------------------------------"));
            PRINT(F("PM 1.0: ")); PRINT(data.pm10_env);
            PRINT(F("\t\tPM 2.5: ")); PRINT(data.pm25_env);
            PRINT(F("\t\tPM 10: ")); PRINT(data.pm100_env);
            PRINTLN(F("---------------------------------------"));
            PRINT(F("Particles > 0.3um / 0.1L air:")); PRINTLN(data.particles_03um);
            PRINT(F("Particles > 0.5um / 0.1L air:")); PRINTLN(data.particles_05um);
            PRINT(F("Particles > 1.0um / 0.1L air:")); PRINTLN(data.particles_10um);
            PRINT(F("Particles > 2.5um / 0.1L air:")); PRINTLN(data.particles_25um);
            PRINT(F("Particles > 5.0um / 0.1L air:")); PRINTLN(data.particles_50um);
            PRINT(F("Particles > 10 um / 0.1L air:")); PRINTLN(data.particles_100um);
            PRINTLN(F("---------------------------------------"));
        
            // Do any math that we want for reporting to Adafruit IO
        }
        else
        {
            PRINTLN("Could not read from PM2.5 sensor!");    
        }
    #endif
    
        // Restart the read timer
        TIMER_start(&pmUpdateTimer);
    }

    // Time to read the VOCs?
    if (TIMER_finished(&vocUpdateTimer, VOC_UPDATE_TIMEOUT_MS))
    {
        vocIndex = vocSensor.getVOCindex();
        TIMER_start(&vocUpdateTimer);
    }

    // Time to read the CO2?
    if (TIMER_finished(&co2UpdateTimer, CO2_UPDATE_TIMEOUT_MS))
    {
        if (mySensor.readMeasurement()) // readMeasurement will return true when fresh data is available
        {
            CO2 = mySensor.getCO2();
            myHumidity = mySensor.getHumidity();    
            temp = mySensor.getTemperature();
        }
        
        TIMER_start(&co2UpdateTimer);
    }

#if (USE_DISPLAY==1)

    //
    // If the display was disabled by the pushbutton,
    // we continuously reset the display timer, so that
    // it will NOT display anything.
    //
    if (!displayOK)
        TIMER_start(&oledUpdateTimer);
        
    //
    // Time to update the OLED?
    //
    if (TIMER_finished(&oledUpdateTimer, OLED_UPDATE_TIMEOUT_MS))
    {
        display.setTextWrap(false);
        display.clearDisplay();        

        switch (displayState)
        {
            case 0:
            {
                display.setCursor(0,0);             
                display.print("CO2: ");
                display.print(CO2);
                
                display.setCursor(0,18);
                display.print("VOC: ");
                display.print(vocIndex);          

            #if (USE_PM25_SENSOR==1)
                display.setCursor(0,36);             
                display.print(" PM: ");
                display.print(data.pm25_standard);
            #endif
            
                display.display();
    
                if (TIMER_finished(&displayShiftTimer, OLED_DISPLAY_SHIFT_TIMEOUT_MS))
                {
                    displayState = 1;
                    TIMER_start(&displayShiftTimer);
                }
            }
            break;
            
            case 1:
            {    
                display.setCursor(0,0);
                display.print("TMP: ");
                display.print(CtoF(temp));

                display.setCursor(0,18);
                display.print("HUM: ");
                display.print(myHumidity);                
    
                display.display();
    
                if (TIMER_finished(&displayShiftTimer, OLED_DISPLAY_SHIFT_TIMEOUT_MS))
                {
                    displayState = 2;
                    TIMER_start(&displayShiftTimer);
                    display.clearDisplay();
                    display.display();                
                }
            }
            break;
            
            case 2:
            {            
                if (TIMER_finished(&displayShiftTimer, CLEAR_DISPLAY_TIMEOUT_MS))
                {
                    displayState = 0;
                    TIMER_start(&displayShiftTimer);
                }
            }
            break;
        }
                
        TIMER_start(&oledUpdateTimer);
    }
#endif

    // 
    // Time to update Cloud?
    //
    if (TIMER_finished(&adafruitUpdateTimer, ADAFRUIT_UPDATE_TIMEOUT_MS))
    {
        char            msg[128];
        PRINTLN();

        PRINT("VOC Index: ");
        PRINT(vocIndex);
        PRINTLN();                         

        // Serial monitor display         
        PRINT(F("CO2(ppm):"));
        PRINT(CO2);

        sprintf(msg, "\tTemperature(F): %f", CtoF(temp));
        PRINT(msg);

        sprintf(msg, "\tHumidity(%RH): %f", myHumidity);
        PRINT(msg);

        PRINTLN("");
        PRINTLN("Updating AdafruitIO...");

        FLUSH(); 
        
        temperature->save(CtoF(temp));
        humidity->save(myHumidity);

    #if (USE_PM25_SENSOR==1)
        pm25->save(data.pm25_standard);        
    #endif
        co2->save(CO2);
        voc->save(vocIndex);     
        
        TIMER_start(&adafruitUpdateTimer);
    }    
      
    yield();    
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                            STARTUP/INITIALIZATION FUNCTIONS
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*! \fn
**
** FUNCTION: _startPMSensor
**
** DESCRIPTION: Get the PM2.5 sensor set up and ready to use.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _startPMSensor(void)
{
#if (USE_PM25_SENSOR==1)        
    #if ( (CPU==ESP8266) || (CPU==ESP32S2) )
        pmSerial.begin(9600);
    #else
        pmSerial.begin(9600, SERIAL_8N1, 16, 17);
    #endif
    delay(1000);

    if (!aqiSensor.begin_UART(&pmSerial))
    {
        PRINTLN("Could not find PM 2.5 sensor!");
        while (1) {yield(); delay(1000);}
    }    
#endif    
    TIMER_start(&pmUpdateTimer);
}

/*! \fn
**
** FUNCTION: _startCO2Sensor
**
** DESCRIPTION: Configure the code to use the CO2 sensor.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _startCO2Sensor(void)
{
    //
    // ".begin: will start periodic measurements for us (see the later examples for details on how to override this)
    //
    if (mySensor.begin() == false)
    {
        PRINTLN(F("Sensor not detected. Please check wiring. Freezing..."));
        while (1){PRINTLN("CO2 sensor startup failure!"); delay(1000); yield();}
    }
    else
    {
        uint16_t            altitude = LOCATION_ALTITUDE;

        //mySensor.enableDebugging(); // Uncomment this line to get helpful debug messages on Serial
        
        mySensor.stopPeriodicMeasurement();
        delay(500);
        PRINTLN("");
        PRINT("Verifying sensor altitude...");
        if (mySensor.getSensorAltitude() != altitude)
        {
            delay(500);
            PRINTLN("");
            PRINT("Setting sensor altitude to: " + String(altitude)+"...");
            if (mySensor.setSensorAltitude(altitude)==true)
            {
                PRINT("Success!  Saving settings...");            
                delay(500);
                if (mySensor.persistSettings())
                {
                    PRINT("Success!");
                    PRINTLN("");
                    PRINT("Verifying settings...");                    
                    delay(500);

                    if (mySensor.getSensorAltitude() == altitude)
                    {
                        delay(500);
                        PRINT("Success!");
                        mySensor.startPeriodicMeasurement();
                    }
                }
                else
                    PRINT("Failed!");
            }
            else
                PRINT("Failed!");                        
        }
        else
        {
            PRINT("Altitude is correct at: " + String(LOCATION_ALTITUDE));
            mySensor.startPeriodicMeasurement();
        }
    }

    TIMER_start(&co2UpdateTimer);
}

/*! \fn
**
** FUNCTION: _startVOCSensor
**
** DESCRIPTION: Configure the VOC sensor.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _startVOCSensor(void)
{
    if (vocSensor.begin()==false)
    {
        PRINTLN("");
        PRINTLN("VOC sensor startup failure!");
        while (1){yield();delay(1000);};
    }    

    TIMER_start(&vocUpdateTimer);
    delay(1100);
}

/*! \fn
**
** FUNCTION: _sendStartupPushover
**
** DESCRIPTION: Sends a start-up message to Pushover
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _sendStartupPushover(void)
{
#if (USE_PUSHOVER==1)    
    PRINTLN("");
    PRINT("Sending startup notification...");
    pushover("Air-quality monitor startup.\r\nCopyright (c) 2021 TDW");
    PRINT("Complete!");
    PRINTLN("");
    delay(1000);    
#endif    
}

/*! \fn
**
** FUNCTION: _startAdafruitIO
**
** DESCRIPTION: Connect to Adafruit.IO
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _startAdafruitIO(void)
{
#if (USE_ADAFRUIT_IO==1)    
    char                    msg[64];

    sprintf(msg, "%s...", ssid);
    display.setTextSize(1);                // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);   // Draw white text
    display.clearDisplay(); 
    display.setCursor(0,0);
    display.print(msg);  
    display.display();
    
    #if ( (CPU==ESP8266) || (CPU==ESP32S2) )
        PRINTLN("");
        PRINT("Connecting to WiFi"); 
        
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            PRINT("!");
            yield();
        }
    #endif
    
    PRINTLN("");
    PRINT("Connecting to Adafruit.IO");
    io.connect();
    while(io.status() < AIO_CONNECTED)
    {
        PRINT(".");
        delay(500);
        yield();
    }    
    PRINT("Connected!");
    PRINTLN("");
    delay(2000);
    yield();
#endif
    // Kick off the Adafruit update timer
    TIMER_start(&adafruitUpdateTimer);  
}

/*! \fn
**
** FUNCTION: _startDisplay
**
** DESCRIPTION: Configure the display
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _startDisplay(void)
{
#if (USE_DISPLAY==1)    
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
    {
        PRINTLN(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    display.setTextWrap(false);
    
    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds
    display.clearDisplay();    
    display.display();

    display.setTextSize(1);                // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);   // Draw white text
    display.setCursor(0,0);
    display.print("AQ monitor startup...");  
    display.display();  

    TIMER_start(&displayShiftTimer);
    TIMER_start(&oledUpdateTimer);
    delay(2000);
#endif    
}

/*! \fn
**
** FUNCTION: _bannerToDisplay
**
** DESCRIPTION: Displays a simple start-up banner on the display.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static void _bannerToDisplay(void)
{
#if (USE_DISPLAY==1)
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Startup OK.");  
    display.display();  
    delay(1000);
    display.setTextSize(2);
#endif    
}

/*! \fn
**
** FUNCTION: pushover
**
** DESCRIPTION: Given a string to send, this sends it to Pushover for notification.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
byte pushover(String pushovermessage)
{               
#if (USE_PUSHOVER==1)              
    length = 81 + pushovermessage.length();

    PRINTLN("");
    PRINT("Connecting to PUSHOVER...");
    if (pushoverClient.connect(pushoversite,80))
    {        
        PRINT("Success!");
              
        pushoverClient.println("POST /1/messages.json HTTP/1.1");
        pushoverClient.println("Host: api.pushover.net");
        pushoverClient.println("Connection: close\r\nContent-Type: application/x-www-form-urlencoded");
        pushoverClient.print("Content-Length: ");
        pushoverClient.print(length);
        pushoverClient.println("\r\n");;
        pushoverClient.print("token=");
        pushoverClient.print(apitoken);
        pushoverClient.print("&user=");
        pushoverClient.print(userkey);
        pushoverClient.print("&message=");
        pushoverClient.print(pushovermessage);

        if (pushoverClient.connected())  
        {            
            // Flush the response
            while (pushoverClient.available())
            {
                char ch = pushoverClient.read();
                yield();
            }

            yield();
        }
        
        PRINTLN("");
        PRINTLN("Pushover message sent!");      
        
        if (pushoverClient.connected())
            pushoverClient.stop();        
    }
    else
    {
        if (pushoverClient.connected())
            pushoverClient.stop();
        PRINT("Failed!");
    }

    yield();
#endif    

    return (0x00);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                                     UTILITY FUNCTIONS
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*! \fn
**
** FUNCTION: TIMER_start
**
** DESCRIPTION: Captures the system ticks when called.  Used
**              to compare later to see if the timer has expired.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static int TIMER_start(TM_TIMER_STRUCT *timer)
{
    if (timer != NULL)
    {
        timer->running = 1;
        timer->capturedTicks = millis();
        return (1);
    }

    return (0);
}

/*! \fn
**
** FUNCTION: TIMER_finished
**
** DESCRIPTION: When called, compares the captured system ticks
**              plus the expected period, with the current system
**              ticks.  If exceeded, time has expired.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static int TIMER_finished(TM_TIMER_STRUCT *timer, unsigned long timeoutMS)
{
    if ( (timer) && (timeoutMS) && (timer->running) )
    {
        uint32_t            current = millis();
        
        if ( (timer->running) && ((current - timer->capturedTicks) >= timeoutMS)  )
        {
            timer->running = 0;
            return (1);
        }
    }

    return (0);
}

/*! \fn
**
** FUNCTION: TIMER_cancel
**
** DESCRIPTION: Clears the "timer running" flag of the given timer
**              object.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static int TIMER_cancel(TM_TIMER_STRUCT *timer)
{
    if (timer)
    {
        timer->running = 0;
        return (1);
    }

    return (0);
}

/*! \fn
**
** FUNCTION: TIMER_running
**
** DESCRIPTION: Checks the "timer running" flag so callers can decide if
**              it thinks its running.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static int TIMER_running(TM_TIMER_STRUCT *timer)
{
    return (int)(timer->running != 0);
}

/*! \fn
**
** FUNCTION: CtoF
**
** DESCRIPTION: Utility to convert from degrees C to degrees F.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
static float CtoF(float degreesCelsius)
{
    return ( (degreesCelsius*1.8) + 32.0 );
}
