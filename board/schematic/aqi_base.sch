EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP32-DEVKITC-32D:ESP32-DEVKITC-32D U1
U 1 1 6142636E
P 5050 6200
F 0 "U1" H 5050 7367 50  0000 C CNN
F 1 "ESP32-DEVKITC-32D" H 5050 7276 50  0000 C CNN
F 2 "MODULE_ESP32-DEVKITC-32D" H 5050 6200 50  0001 L BNN
F 3 "" H 5050 6200 50  0001 L BNN
F 4 "4" H 5050 6200 50  0001 L BNN "PARTREV"
F 5 "Espressif Systems" H 5050 6200 50  0001 L BNN "MANUFACTURER"
	1    5050 6200
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U2
U 1 1 6145294E
P 2400 1100
F 0 "U2" H 2400 1342 50  0000 C CNN
F 1 "LM1117-3.3" H 2400 1251 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 2400 1100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 2400 1100 50  0001 C CNN
	1    2400 1100
	1    0    0    -1  
$EndComp
$Comp
L 2821:2821 U3
U 1 1 6150488C
P 2050 6100
F 0 "U3" H 2000 7275 50  0000 C CNN
F 1 "2821" H 2050 6100 50  0001 L BNN
F 2 "XCVR_2821" H 2050 6100 50  0001 L BNN
F 3 "" H 2050 6100 50  0001 L BNN
F 4 "Adafruit" H 2050 6100 50  0001 L BNN "MANUFACTURER"
	1    2050 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 5300 3000 5300
Wire Wire Line
	5850 5500 6150 5500
Wire Wire Line
	2750 5400 3000 5400
Wire Wire Line
	5850 5800 6150 5800
Wire Wire Line
	2750 7100 3000 7100
Wire Wire Line
	5850 5300 6150 5300
Text GLabel 6150 5500 2    50   Output ~ 0
SCL
Text GLabel 6150 5800 2    50   BiDi ~ 0
SDA
Text GLabel 3000 5300 2    50   Input ~ 0
SCL
Text GLabel 3000 5400 2    50   BiDi ~ 0
SDA
Wire Wire Line
	5850 5400 6150 5400
Text GLabel 6150 5400 2    50   Output ~ 0
MOSI
Wire Wire Line
	2750 6700 3000 6700
Text GLabel 3000 6700 2    50   Output ~ 0
MOSI
Wire Wire Line
	2750 6800 3000 6800
Text GLabel 3000 6800 2    50   Input ~ 0
MISO
Wire Wire Line
	5850 6000 6150 6000
Text GLabel 6150 6000 2    50   Input ~ 0
MISO
Wire Wire Line
	2750 6600 3000 6600
Text GLabel 3000 6600 2    50   Output ~ 0
SCK
Wire Wire Line
	5850 6100 6150 6100
Text GLabel 6150 6100 2    50   Output ~ 0
SCK
Wire Wire Line
	1250 6600 1050 6600
Text GLabel 1050 6600 0    50   Output ~ 0
TXD
Wire Wire Line
	1250 6700 1050 6700
Text GLabel 1050 6700 0    50   Input ~ 0
RXD
Text GLabel 3000 7100 2    50   UnSpc ~ 0
GND
Text GLabel 6150 5300 2    50   UnSpc ~ 0
GND
Wire Wire Line
	2750 6300 3000 6300
Text GLabel 3000 6300 2    50   Output ~ 0
SPI_SEL1
Wire Wire Line
	4250 5800 4000 5800
Text GLabel 4000 5800 0    50   Output ~ 0
SPI_SEL1
Text GLabel 4000 6600 0    50   UnSpc ~ 0
GND
Wire Wire Line
	5850 5900 6150 5900
Text GLabel 6150 5900 2    50   UnSpc ~ 0
GND
Wire Wire Line
	2750 6200 3000 6200
Text GLabel 3000 6200 2    50   Output ~ 0
SPI_SEL2
Wire Wire Line
	4250 5700 4000 5700
Text GLabel 4000 5700 0    50   Output ~ 0
SPI_SEL2
$Comp
L Connector:Conn_01x03_Male PJ2
U 1 1 615586C8
P 1500 2150
F 0 "PJ2" V 1350 2050 50  0000 L CNN
F 1 "Conn_01x03_Male" V 1653 2294 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 1500 2150 50  0001 C CNN
F 3 "~" H 1500 2150 50  0001 C CNN
	1    1500 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 2350 1400 2500
Text GLabel 1400 2500 0    50   UnSpc ~ 0
3.3V
Wire Wire Line
	1600 2350 1600 2500
Text GLabel 1600 2500 2    50   UnSpc ~ 0
5V
Wire Wire Line
	1500 2350 1500 2600
Text GLabel 1500 2600 3    50   UnSpc ~ 0
GND
$Comp
L Connector:Conn_01x05_Male SJ1
U 1 1 615617D3
P 2550 2150
F 0 "SJ1" V 2400 2100 50  0000 L CNN
F 1 "Conn_01x05_Male" V 2703 2394 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2550 2150 50  0001 C CNN
F 3 "~" H 2550 2150 50  0001 C CNN
	1    2550 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 2350 2350 2450
Wire Wire Line
	2450 2350 2450 2450
Wire Wire Line
	2550 2350 2550 2450
Wire Wire Line
	2650 2350 2650 2450
Wire Wire Line
	2750 2350 2750 2450
Text GLabel 2350 2450 3    50   Input ~ 0
SCK
Text GLabel 2450 2450 3    50   Input ~ 0
MOSI
Text GLabel 2550 2450 3    50   Output ~ 0
MISO
Text GLabel 2650 2450 3    50   Input ~ 0
SPI_SEL1
Text GLabel 2750 2450 3    50   Input ~ 0
SPI_SEL2
$Comp
L Connector:Conn_01x05_Male SJ2
U 1 1 61569283
P 3300 2150
F 0 "SJ2" V 3150 2100 50  0000 L CNN
F 1 "Conn_01x05_Male" V 3453 2394 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3300 2150 50  0001 C CNN
F 3 "~" H 3300 2150 50  0001 C CNN
	1    3300 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 2350 3100 2450
Wire Wire Line
	3200 2350 3200 2450
Wire Wire Line
	3300 2350 3300 2450
Wire Wire Line
	3400 2350 3400 2450
Wire Wire Line
	3500 2350 3500 2450
Text GLabel 3100 2450 3    50   Input ~ 0
SCK
Text GLabel 3200 2450 3    50   Input ~ 0
MOSI
Text GLabel 3300 2450 3    50   Output ~ 0
MISO
Text GLabel 3400 2450 3    50   Input ~ 0
SPI_SEL1
Text GLabel 3500 2450 3    50   Input ~ 0
SPI_SEL2
$Comp
L Connector:Conn_01x05_Male USB_Power1
U 1 1 61540DBD
P 700 1250
F 0 "USB_Power1" H 800 1600 50  0000 C CNN
F 1 "Conn_01x05_Male" H 808 1540 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 700 1250 50  0001 C CNN
F 3 "~" H 700 1250 50  0001 C CNN
	1    700  1250
	1    0    0    1   
$EndComp
Wire Wire Line
	1000 1100 1000 1050
Wire Wire Line
	1000 1400 1000 1450
$Comp
L Device:CP1 C1
U 1 1 6154FC15
P 1900 1250
F 0 "C1" H 2015 1296 50  0000 L CNN
F 1 "33uF" H 2015 1205 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D4.5mm_P5.00mm" H 1900 1250 50  0001 C CNN
F 3 "~" H 1900 1250 50  0001 C CNN
	1    1900 1250
	1    0    0    -1  
$EndComp
Connection ~ 1900 1100
$Comp
L power:GND #PWR0101
U 1 1 61550DBF
P 2400 1400
F 0 "#PWR0101" H 2400 1150 50  0001 C CNN
F 1 "GND" H 2405 1227 50  0000 C CNN
F 2 "" H 2400 1400 50  0001 C CNN
F 3 "" H 2400 1400 50  0001 C CNN
	1    2400 1400
	1    0    0    -1  
$EndComp
Text GLabel 3150 1100 2    50   Output ~ 0
3.3V
$Comp
L Device:CP1 C2
U 1 1 615532CC
P 2900 1250
F 0 "C2" H 3015 1296 50  0000 L CNN
F 1 "33uF" H 3015 1205 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D4.5mm_P5.00mm" H 2900 1250 50  0001 C CNN
F 3 "~" H 2900 1250 50  0001 C CNN
	1    2900 1250
	1    0    0    -1  
$EndComp
Text GLabel 3150 1400 2    50   UnSpc ~ 0
GND
$Comp
L Device:LED LED1
U 1 1 61562C28
P 4550 1100
F 0 "LED1" H 4543 937 50  0000 C CNN
F 1 "LED" H 4543 936 50  0001 C CNN
F 2 "LED_THT:LED_D5.0mm" H 4550 1100 50  0001 C CNN
F 3 "~" H 4550 1100 50  0001 C CNN
	1    4550 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 1100 4150 1100
Text GLabel 4150 1100 0    50   Input ~ 0
3.3V
$Comp
L Device:R_US R1
U 1 1 6156D9B2
P 4700 1250
F 0 "R1" H 4768 1296 50  0000 L CNN
F 1 "10k" H 4768 1205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4740 1240 50  0001 C CNN
F 3 "~" H 4700 1250 50  0001 C CNN
	1    4700 1250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 6156FE07
P 4700 1400
F 0 "#PWR0102" H 4700 1150 50  0001 C CNN
F 1 "GND" H 4705 1227 50  0000 C CNN
F 2 "" H 4700 1400 50  0001 C CNN
F 3 "" H 4700 1400 50  0001 C CNN
	1    4700 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 61583B35
P 8350 1250
F 0 "C3" H 8250 1350 50  0000 L CNN
F 1 ".01uF" H 8250 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 8388 1100 50  0001 C CNN
F 3 "~" H 8350 1250 50  0001 C CNN
	1    8350 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 61585B7A
P 8950 1250
F 0 "C5" H 8850 1350 50  0000 L CNN
F 1 ".01uF" H 8850 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 8988 1100 50  0001 C CNN
F 3 "~" H 8950 1250 50  0001 C CNN
	1    8950 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 615866E8
P 9250 1250
F 0 "C6" H 9150 1350 50  0000 L CNN
F 1 ".01uF" H 9150 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 9288 1100 50  0001 C CNN
F 3 "~" H 9250 1250 50  0001 C CNN
	1    9250 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 61587341
P 9550 1250
F 0 "C7" H 9450 1350 50  0000 L CNN
F 1 ".01uF" H 9450 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 9588 1100 50  0001 C CNN
F 3 "~" H 9550 1250 50  0001 C CNN
	1    9550 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 61588003
P 9850 1250
F 0 "C8" H 9750 1350 50  0000 L CNN
F 1 ".01uF" H 9700 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 9888 1100 50  0001 C CNN
F 3 "~" H 9850 1250 50  0001 C CNN
	1    9850 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 1100 9550 1100
Wire Wire Line
	9550 1100 9250 1100
Connection ~ 9550 1100
Wire Wire Line
	9250 1100 8950 1100
Connection ~ 9250 1100
Connection ~ 8950 1100
Wire Wire Line
	8350 1100 8050 1100
Connection ~ 8350 1100
Wire Wire Line
	9850 1400 9550 1400
Wire Wire Line
	9550 1400 9250 1400
Connection ~ 9550 1400
Wire Wire Line
	9250 1400 8950 1400
Connection ~ 9250 1400
Connection ~ 8950 1400
Wire Wire Line
	8350 1400 8050 1400
Connection ~ 8350 1400
$Comp
L power:GND #PWR0103
U 1 1 6159B646
P 8050 1400
F 0 "#PWR0103" H 8050 1150 50  0001 C CNN
F 1 "GND" H 8055 1227 50  0000 C CNN
F 2 "" H 8050 1400 50  0001 C CNN
F 3 "" H 8050 1400 50  0001 C CNN
	1    8050 1400
	1    0    0    -1  
$EndComp
Text GLabel 8050 1100 1    50   UnSpc ~ 0
3.3V
$Comp
L power:GND #PWR0104
U 1 1 615C52A0
P 10450 1400
F 0 "#PWR0104" H 10450 1150 50  0001 C CNN
F 1 "GND" H 10455 1227 50  0000 C CNN
F 2 "" H 10450 1400 50  0001 C CNN
F 3 "" H 10450 1400 50  0001 C CNN
	1    10450 1400
	1    0    0    -1  
$EndComp
Text GLabel 10450 1100 1    50   UnSpc ~ 0
5V
Wire Wire Line
	1900 1100 1900 900 
Text GLabel 1900 900  1    50   UnSpc ~ 0
5V
Text Notes 10900 900  2    50   ~ 0
5V Bypass Caps
Text Notes 9300 900  2    50   ~ 0
3.3V Bypass Caps
$Comp
L Connector:Conn_01x08_Male AF-PM25x1
U 1 1 615E168D
P 8650 2150
F 0 "AF-PM25x1" V 8500 2100 50  0000 C CNN
F 1 "NC" V 8576 2078 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 8650 2150 50  0001 C CNN
F 3 "~" H 8650 2150 50  0001 C CNN
	1    8650 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	8950 2350 8950 2450
Text GLabel 8950 2450 3    50   UnSpc ~ 0
5V
Wire Wire Line
	8850 2350 8850 2450
Text GLabel 8850 2450 3    50   UnSpc ~ 0
GND
Wire Wire Line
	8650 2350 8650 2450
Wire Wire Line
	8550 2350 8550 2450
Text Notes 8250 2350 3    50   ~ 0
NC
Text Notes 8750 2350 3    50   ~ 0
NC
Text Notes 8350 2350 3    50   ~ 0
NC
$Comp
L Connector:Conn_01x05_Male AF-MTU21D1
U 1 1 615FA3F3
P 5300 2150
F 0 "AF-MTU21D1" V 5200 1950 50  0000 L CNN
F 1 "Conn_01x05_Male" V 5453 2394 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 5300 2150 50  0001 C CNN
F 3 "~" H 5300 2150 50  0001 C CNN
	1    5300 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 2350 5100 2450
Text GLabel 5100 2450 3    50   Input ~ 0
3.3V
Wire Wire Line
	5300 2350 5300 2450
Text GLabel 5300 2450 3    50   UnSpc ~ 0
GND
Wire Wire Line
	5400 2350 5400 2450
Text GLabel 5400 2450 3    50   BiDi ~ 0
SDA
Wire Wire Line
	5500 2350 5500 2450
Text GLabel 5500 2450 3    50   Input ~ 0
SCL
Text Notes 5150 2450 0    50   ~ 0
NC
$Comp
L Connector:Conn_01x04_Male SF-SCD4x1
U 1 1 6160F9C0
P 6400 2150
F 0 "SF-SCD4x1" V 6250 1850 50  0000 L CNN
F 1 "Conn_01x04_Male" V 6553 2294 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6400 2150 50  0001 C CNN
F 3 "~" H 6400 2150 50  0001 C CNN
	1    6400 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 2350 6500 2450
Wire Wire Line
	6400 2350 6400 2450
Wire Wire Line
	6300 2350 6300 2450
Wire Wire Line
	6200 2350 6200 2450
$Comp
L Connector:Conn_01x04_Male SF-SGPx1
U 1 1 6161DABC
P 7450 2150
F 0 "SF-SGPx1" V 7300 1900 50  0000 L CNN
F 1 "Conn_01x04_Male" V 7603 2294 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7450 2150 50  0001 C CNN
F 3 "~" H 7450 2150 50  0001 C CNN
	1    7450 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	7550 2350 7550 2450
Wire Wire Line
	7450 2350 7450 2450
Wire Wire Line
	7350 2350 7350 2450
Wire Wire Line
	7250 2350 7250 2450
$Comp
L Switch:SW_Push_Dual_x2 PB1
U 1 1 6166E8FB
P 7400 1450
F 0 "PB1" H 7400 1643 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 7400 1644 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7400 1650 50  0001 C CNN
F 3 "~" H 7400 1650 50  0001 C CNN
	1    7400 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US RB1
U 1 1 6167114B
P 7200 1300
F 0 "RB1" H 7000 1400 50  0000 L CNN
F 1 "10k" H 7000 1300 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7240 1290 50  0001 C CNN
F 3 "~" H 7200 1300 50  0001 C CNN
	1    7200 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 61672F1F
P 7600 1450
F 0 "#PWR0105" H 7600 1200 50  0001 C CNN
F 1 "GND" H 7605 1277 50  0000 C CNN
F 2 "" H 7600 1450 50  0001 C CNN
F 3 "" H 7600 1450 50  0001 C CNN
	1    7600 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1150 7200 1050
Text GLabel 7200 1050 1    50   UnSpc ~ 0
3.3V
Wire Wire Line
	7200 1450 6850 1450
Connection ~ 7200 1450
Text GLabel 6850 1450 0    50   Output ~ 0
PB1
Wire Wire Line
	5850 6600 6150 6600
Text GLabel 6150 6600 2    50   Input ~ 0
PB1
Wire Wire Line
	2750 5700 3000 5700
Text GLabel 3000 5700 2    50   Input ~ 0
PB1
$Comp
L Switch:SW_Push_Dual_x2 PB2
U 1 1 616896D5
P 6000 1450
F 0 "PB2" H 6000 1643 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 6000 1644 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6000 1650 50  0001 C CNN
F 3 "~" H 6000 1650 50  0001 C CNN
	1    6000 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US RB2
U 1 1 616896DB
P 5800 1300
F 0 "RB2" H 5600 1400 50  0000 L CNN
F 1 "10k" H 5600 1300 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5840 1290 50  0001 C CNN
F 3 "~" H 5800 1300 50  0001 C CNN
	1    5800 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 616896E1
P 6200 1450
F 0 "#PWR0106" H 6200 1200 50  0001 C CNN
F 1 "GND" H 6205 1277 50  0000 C CNN
F 2 "" H 6200 1450 50  0001 C CNN
F 3 "" H 6200 1450 50  0001 C CNN
	1    6200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1150 5800 1050
Text GLabel 5800 1050 1    50   UnSpc ~ 0
3.3V
Wire Wire Line
	5800 1450 5450 1450
Connection ~ 5800 1450
Text GLabel 5450 1450 0    50   Output ~ 0
PB2
Wire Wire Line
	2750 5800 3000 5800
Text GLabel 3000 5800 2    50   Input ~ 0
PB2
Wire Wire Line
	5850 6700 6150 6700
Text GLabel 6150 6700 2    50   Input ~ 0
PB2
$Comp
L Connector:Conn_01x04_Male GPIO_HDR1
U 1 1 616ED092
P 4250 2100
F 0 "GPIO_HDR1" V 4150 1850 50  0000 L CNN
F 1 "Conn_01x04_Male" V 4403 2344 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 4250 2100 50  0001 C CNN
F 3 "~" H 4250 2100 50  0001 C CNN
	1    4250 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 2300 4050 2400
Wire Wire Line
	4150 2300 4150 2400
Wire Wire Line
	2750 5900 3000 5900
Text GLabel 3000 5900 2    50   BiDi ~ 0
GPIO1
Wire Wire Line
	2750 6000 3000 6000
Text GLabel 3000 6000 2    50   BiDi ~ 0
GPIO2
Wire Wire Line
	2750 6100 3000 6100
Text GLabel 3000 6100 2    50   BiDi ~ 0
GPIO3
Wire Wire Line
	5850 6500 6150 6500
Text GLabel 6150 6500 2    50   BiDi ~ 0
GPIO1
Wire Wire Line
	5850 6200 6150 6200
Text GLabel 6150 6200 2    50   BiDi ~ 0
GPIO2
Wire Wire Line
	5850 6400 6150 6400
Wire Wire Line
	4350 2300 4350 2400
Wire Wire Line
	4250 2300 4250 2400
Text Notes 5050 1950 0    50   ~ 0
Temp/Humidity
Text Notes 6100 1950 0    50   ~ 0
CO2 Sensor
Text Notes 7150 1950 0    50   ~ 0
TVOC Sensor
Text Notes 8350 1950 0    50   ~ 0
PM2.5 Sensor
Text Notes 1100 1950 0    50   ~ 0
Power Supply Access
Text Notes 2350 1950 0    50   ~ 0
SPI Communications Access
Text Notes 3950 1950 0    50   ~ 0
GPIO Access
$Comp
L Device:D D1
U 1 1 615EB375
P 1700 1100
F 0 "D1" H 1700 1000 50  0000 C CNN
F 1 "1N4007" H 1750 1200 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 1700 1100 50  0001 C CNN
F 3 "~" H 1700 1100 50  0001 C CNN
	1    1700 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	1850 1100 1900 1100
$Comp
L Connector:Conn_01x08_Male AF-OLED091
U 1 1 6161131E
P 10050 2150
F 0 "AF-OLED091" V 9900 2100 50  0000 C CNN
F 1 "Conn_01x08_Male" V 9976 2078 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 10050 2150 50  0001 C CNN
F 3 "~" H 10050 2150 50  0001 C CNN
	1    10050 2150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 6161B43C
P 9650 2350
F 0 "#PWR0107" H 9650 2100 50  0001 C CNN
F 1 "GND" H 9655 2177 50  0000 C CNN
F 2 "" H 9650 2350 50  0001 C CNN
F 3 "" H 9650 2350 50  0001 C CNN
	1    9650 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 2350 9750 2450
Text GLabel 9750 2450 3    50   UnSpc ~ 0
3.3V
Wire Wire Line
	10250 2350 10250 2450
Text GLabel 10250 2450 3    50   Input ~ 0
SCL
Wire Wire Line
	10350 2350 10350 2450
Text GLabel 10350 2450 3    50   BiDi ~ 0
SDA
Text Notes 9750 1950 0    50   ~ 0
Adafruit OLED
$Comp
L Device:Rotary_Encoder_Switch ENC1
U 1 1 6169C187
P 9000 5050
F 0 "ENC1" H 9000 5325 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 9000 5326 50  0001 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 8850 5210 50  0001 C CNN
F 3 "~" H 9000 5310 50  0001 C CNN
	1    9000 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US ER1
U 1 1 616A6A51
P 9300 4800
F 0 "ER1" H 9350 4900 50  0000 L CNN
F 1 "10k" H 9350 4800 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9340 4790 50  0001 C CNN
F 3 "~" H 9300 4800 50  0001 C CNN
	1    9300 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 4650 9300 4550
Text GLabel 9300 4550 1    50   BiDi ~ 0
3.3V
Wire Wire Line
	9300 5150 9300 5300
$Comp
L power:GND #PWR0108
U 1 1 616B8124
P 9300 5300
F 0 "#PWR0108" H 9300 5050 50  0001 C CNN
F 1 "GND" H 9305 5127 50  0000 C CNN
F 2 "" H 9300 5300 50  0001 C CNN
F 3 "" H 9300 5300 50  0001 C CNN
	1    9300 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 4950 9600 4950
Connection ~ 9300 4950
Text GLabel 9600 4950 2    50   Output ~ 0
GPIO3
Wire Wire Line
	8700 4950 8650 4950
Text GLabel 8350 4950 0    50   Output ~ 0
GPIO1
Wire Wire Line
	8700 5150 8650 5150
Text GLabel 8350 5150 0    50   Output ~ 0
GPIO2
Wire Wire Line
	8700 5050 7950 5050
Wire Wire Line
	7950 5050 7950 5100
$Comp
L power:GND #PWR0109
U 1 1 616FA6FB
P 7950 5100
F 0 "#PWR0109" H 7950 4850 50  0001 C CNN
F 1 "GND" H 7955 4927 50  0000 C CNN
F 2 "" H 7950 5100 50  0001 C CNN
F 3 "" H 7950 5100 50  0001 C CNN
	1    7950 5100
	1    0    0    -1  
$EndComp
Text GLabel 4350 2400 3    50   BiDi ~ 0
GPIO1
Text GLabel 4250 2400 3    50   BiDi ~ 0
GPIO2
Text GLabel 4150 2400 3    50   BiDi ~ 0
GPIO3
$Comp
L power:GND #PWR0110
U 1 1 61740589
P 4050 2400
F 0 "#PWR0110" H 4050 2150 50  0001 C CNN
F 1 "GND" H 4055 2227 50  0000 C CNN
F 2 "" H 4050 2400 50  0001 C CNN
F 3 "" H 4050 2400 50  0001 C CNN
	1    4050 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US ER2
U 1 1 616B7AA7
P 8650 4800
F 0 "ER2" H 8450 4900 50  0000 L CNN
F 1 "10k" H 8450 4800 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8690 4790 50  0001 C CNN
F 3 "~" H 8650 4800 50  0001 C CNN
	1    8650 4800
	1    0    0    -1  
$EndComp
Connection ~ 8650 4950
Wire Wire Line
	8650 4950 8350 4950
Wire Wire Line
	8650 4650 8650 4550
Text GLabel 8650 4550 1    50   BiDi ~ 0
3.3V
$Comp
L Device:R_US ER3
U 1 1 616C2ABD
P 8650 5300
F 0 "ER3" H 8450 5350 50  0000 L CNN
F 1 "10k" H 8450 5250 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8690 5290 50  0001 C CNN
F 3 "~" H 8650 5300 50  0001 C CNN
	1    8650 5300
	1    0    0    -1  
$EndComp
Connection ~ 8650 5150
Wire Wire Line
	8650 5150 8350 5150
Wire Wire Line
	8650 5450 8650 5550
Text GLabel 8650 5550 3    50   BiDi ~ 0
3.3V
Wire Wire Line
	10450 1100 10650 1100
Wire Wire Line
	10450 1400 10650 1400
$Comp
L Device:C C9
U 1 1 617314E4
P 10650 1250
F 0 "C9" H 10500 1350 50  0000 L CNN
F 1 ".01uF" H 10550 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 10688 1100 50  0001 C CNN
F 3 "~" H 10650 1250 50  0001 C CNN
	1    10650 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 1100 8650 1100
Wire Wire Line
	8350 1400 8650 1400
NoConn ~ 4250 5500
NoConn ~ 4250 5600
NoConn ~ 4250 5900
NoConn ~ 4250 6000
NoConn ~ 4250 6100
NoConn ~ 4250 6200
NoConn ~ 4250 6300
NoConn ~ 4250 6500
NoConn ~ 4250 6700
NoConn ~ 4250 6800
NoConn ~ 4250 6900
NoConn ~ 4250 7000
NoConn ~ 5850 7100
NoConn ~ 5850 7000
NoConn ~ 5850 6900
NoConn ~ 1250 5400
NoConn ~ 1250 5500
NoConn ~ 1250 5700
NoConn ~ 1250 6900
NoConn ~ 4250 6400
NoConn ~ 900  1150
NoConn ~ 900  1250
NoConn ~ 900  1350
NoConn ~ 5200 2350
NoConn ~ 8350 2350
NoConn ~ 8250 2350
NoConn ~ 8750 2350
NoConn ~ 9850 2350
Wire Wire Line
	4000 6600 4250 6600
Wire Wire Line
	2100 1100 1900 1100
NoConn ~ 9950 2350
NoConn ~ 10050 2350
NoConn ~ 10150 2350
NoConn ~ 8450 2350
$Comp
L Device:C C4
U 1 1 6172C9EC
P 8650 1250
F 0 "C4" H 8550 1350 50  0000 L CNN
F 1 ".01uF" H 8550 1450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 8688 1100 50  0001 C CNN
F 3 "~" H 8650 1250 50  0001 C CNN
	1    8650 1250
	1    0    0    -1  
$EndComp
Connection ~ 8650 1100
Wire Wire Line
	8650 1100 8950 1100
Connection ~ 8650 1400
Wire Wire Line
	8650 1400 8950 1400
Text GLabel 7550 2450 3    50   Input ~ 0
SCL
Text GLabel 7450 2450 3    50   BiDi ~ 0
SDA
Text GLabel 7350 2450 3    50   Input ~ 0
3.3V
Text GLabel 7250 2450 3    50   UnSpc ~ 0
GND
Text GLabel 6500 2450 3    50   Input ~ 0
SCL
Text GLabel 6400 2450 3    50   BiDi ~ 0
SDA
Text GLabel 6300 2450 3    50   Input ~ 0
3.3V
Text GLabel 6200 2450 3    50   UnSpc ~ 0
GND
Wire Wire Line
	4250 7100 4000 7100
Text GLabel 4000 7100 0    50   Input ~ 0
5V
Wire Wire Line
	1250 7000 1050 7000
Text GLabel 1050 7000 0    50   Input ~ 0
5V
NoConn ~ 2750 5100
NoConn ~ 4250 5300
Wire Wire Line
	900  1050 1000 1050
Wire Wire Line
	900  1450 1000 1450
Text Notes 8650 4200 0    50   ~ 0
Rotary Encoder
Wire Wire Line
	5850 6800 6150 6800
Text GLabel 6150 6800 2    50   Input ~ 0
GPIO3
Wire Wire Line
	5850 6300 6150 6300
Text GLabel 6150 6300 2    50   Output ~ 0
TXD
Text GLabel 6150 6400 2    50   Input ~ 0
RXD
NoConn ~ 5850 5600
NoConn ~ 5850 5700
$Comp
L Device:Fuse F1
U 1 1 619A9D67
P 1300 1100
F 0 "F1" H 1360 1146 50  0000 L CNN
F 1 "Fuse" H 1360 1055 50  0000 L CNN
F 2 "Fuse:Fuse_Littelfuse-LVR100" V 1230 1100 50  0001 C CNN
F 3 "~" H 1300 1100 50  0001 C CNN
	1    1300 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2900 1100 3150 1100
Connection ~ 2900 1400
Wire Wire Line
	2900 1400 3150 1400
Connection ~ 2400 1400
Wire Wire Line
	2400 1400 2900 1400
Wire Wire Line
	2700 1100 2900 1100
Connection ~ 2900 1100
Wire Wire Line
	1900 1400 2400 1400
Connection ~ 1900 1400
Wire Wire Line
	1000 1400 1900 1400
Wire Wire Line
	1000 1100 1150 1100
Wire Wire Line
	1450 1100 1550 1100
Text GLabel 8650 2450 3    50   Input ~ 0
TXD
Text GLabel 8550 2450 3    50   Output ~ 0
RXD
Text Notes 8600 2150 0    50   Italic 0
RX
Text Notes 8500 2150 0    50   Italic 0
TX
Wire Wire Line
	1250 5200 1100 5200
Text GLabel 1100 5200 0    50   Input ~ 0
RESET
Wire Wire Line
	4250 5400 4100 5400
Text GLabel 4100 5400 0    50   Input ~ 0
RESET
$Comp
L Connector:Conn_01x02_Male PP1
U 1 1 61D23E00
P 7250 3150
F 0 "PP1" H 7358 3239 50  0000 C CNN
F 1 "Conn_01x02_Male" H 7358 3240 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7250 3150 50  0001 C CNN
F 3 "~" H 7250 3150 50  0001 C CNN
	1    7250 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3150 7600 3150
Wire Wire Line
	7450 3250 7600 3250
Text GLabel 7600 3150 2    50   UnSpc ~ 0
5V
Text GLabel 7600 3250 2    50   UnSpc ~ 0
GND
$Comp
L Connector:Conn_01x02_Male PP2
U 1 1 61D3EB09
P 7900 3150
F 0 "PP2" H 8008 3239 50  0000 C CNN
F 1 "Conn_01x02_Male" H 8008 3240 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7900 3150 50  0001 C CNN
F 3 "~" H 7900 3150 50  0001 C CNN
	1    7900 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3150 8250 3150
Wire Wire Line
	8100 3250 8250 3250
Text GLabel 8250 3150 2    50   UnSpc ~ 0
5V
Text GLabel 8250 3250 2    50   UnSpc ~ 0
GND
$Comp
L Connector:Conn_01x02_Male PP3
U 1 1 61D444E5
P 8500 3150
F 0 "PP3" H 8608 3239 50  0000 C CNN
F 1 "Conn_01x02_Male" H 8608 3240 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8500 3150 50  0001 C CNN
F 3 "~" H 8500 3150 50  0001 C CNN
	1    8500 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3150 8850 3150
Wire Wire Line
	8700 3250 8850 3250
Text GLabel 8850 3150 2    50   UnSpc ~ 0
5V
Text GLabel 8850 3250 2    50   UnSpc ~ 0
GND
$Comp
L Connector:Conn_01x02_Male PP4
U 1 1 61D4ACBF
P 9150 3150
F 0 "PP4" H 9258 3239 50  0000 C CNN
F 1 "Conn_01x02_Male" H 9258 3240 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9150 3150 50  0001 C CNN
F 3 "~" H 9150 3150 50  0001 C CNN
	1    9150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 3150 9500 3150
Wire Wire Line
	9350 3250 9500 3250
Text GLabel 9500 3150 2    50   UnSpc ~ 0
5V
Text GLabel 9500 3250 2    50   UnSpc ~ 0
GND
Text Notes 8150 2900 0    50   ~ 0
5V Power Access
$Comp
L Connector:Conn_01x05_Male PP5
U 1 1 61E25A31
P 9850 3200
F 0 "PP5" H 9958 3489 50  0000 C CNN
F 1 "Conn_01x05_Male" H 9958 3490 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9850 3200 50  0001 C CNN
F 3 "~" H 9850 3200 50  0001 C CNN
	1    9850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 3000 10250 3000
Wire Wire Line
	10050 3400 10250 3400
Wire Wire Line
	10050 3200 10250 3200
Text GLabel 10250 3000 2    50   UnSpc ~ 0
5V
Text GLabel 10250 3200 2    50   UnSpc ~ 0
GND
Text GLabel 10250 3400 2    50   UnSpc ~ 0
3.3V
NoConn ~ 10050 3100
NoConn ~ 10050 3300
$Comp
L 2022-01-17_22-48-12:MIC803-29D3VC3-TR U5
U 1 1 61F011FE
P 2800 3750
F 0 "U5" H 4128 3603 60  0000 L CNN
F 1 "MIC803-29D3VC3-TR" H 4128 3497 60  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3600 4090 60  0001 C CNN
F 3 "" H 2800 3750 60  0000 C CNN
	1    2800 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3750 2400 3750
Text GLabel 2400 3750 0    50   Output ~ 0
RESET
Wire Wire Line
	2800 4050 2400 4050
Text GLabel 2400 4050 0    50   UnSpc ~ 0
3.3V
$Comp
L power:GND #PWR0112
U 1 1 61F21B78
P 2800 4250
F 0 "#PWR0112" H 2800 4000 50  0001 C CNN
F 1 "GND" H 2805 4077 50  0000 C CNN
F 2 "" H 2800 4250 50  0001 C CNN
F 3 "" H 2800 4250 50  0001 C CNN
	1    2800 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US RR1
U 1 1 61F29DD3
P 2800 3900
F 0 "RR1" H 2868 3900 50  0000 L CNN
F 1 "R_US" H 2868 3855 50  0001 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2840 3890 50  0001 C CNN
F 3 "~" H 2800 3900 50  0001 C CNN
	1    2800 3900
	1    0    0    -1  
$EndComp
Connection ~ 2800 3750
Connection ~ 2800 4050
Text Notes 3350 3350 0    50   ~ 0
Reset Control
Text Notes 7350 7500 0    50   ~ 0
Sensor Playground(tm).  Copyright (c) 2022 by TDW
$EndSCHEMATC
