EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RocketLaunch"
Date "2020-04-07"
Rev ""
Comp "De Bibliotheek Eindhoven - MakersClub"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x02 J15
U 1 1 5E6E483D
P 6500 7150
F 0 "J15" V 6450 6850 50  0000 L CNN
F 1 "Screw_Terminal_01x02" V 6600 6650 50  0000 L CNN
F 2 "" H 6500 7150 50  0001 C CNN
F 3 "~" H 6500 7150 50  0001 C CNN
	1    6500 7150
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW2
U 1 1 5E6E85BB
P 8500 2100
F 0 "SW2" H 8500 2400 50  0000 L CNN
F 1 "SW_Player_Count" H 8250 2300 50  0000 L CNN
F 2 "" H 8500 2100 50  0001 C CNN
F 3 "~" H 8500 2100 50  0001 C CNN
	1    8500 2100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5E707618
P 2150 3300
F 0 "#PWR011" H 2150 3050 50  0001 C CNN
F 1 "GND" H 2155 3127 50  0000 C CNN
F 2 "" H 2150 3300 50  0001 C CNN
F 3 "" H 2150 3300 50  0001 C CNN
	1    2150 3300
	1    0    0    -1  
$EndComp
Text Label 6500 6350 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	2400 2700 3000 2700
Text Label 3000 2700 2    50   ~ 0
5V_PowerSupply
$Comp
L Connector_Generic:Conn_01x03 J9
U 1 1 5E6A9AF2
P 4950 700
F 0 "J9" V 4914 512 50  0000 R CNN
F 1 "JST-SM_3P_Male_LedMatrix" V 4823 512 50  0000 R CNN
F 2 "" H 4950 700 50  0001 C CNN
F 3 "~" H 4950 700 50  0001 C CNN
	1    4950 700 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Counter_Clockwise J2
U 1 1 5E6AB262
P 3350 2300
F 0 "J2" H 3400 2617 50  0000 C CNN
F 1 "Arduino_Serial_And_5V" H 3400 2526 50  0000 C CNN
F 2 "" H 3350 2300 50  0001 C CNN
F 3 "~" H 3350 2300 50  0001 C CNN
	1    3350 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J1
U 1 1 5E6AC440
P 3500 1300
F 0 "J1" H 3550 1717 50  0000 C CNN
F 1 "Arduino_GPIO" H 3550 1626 50  0000 C CNN
F 2 "" H 3500 1300 50  0001 C CNN
F 3 "~" H 3500 1300 50  0001 C CNN
	1    3500 1300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Row_Letter_Last J3
U 1 1 5E6AC8BC
P 3200 4950
F 0 "J3" H 3250 6067 50  0000 C CNN
F 1 "MicroBit_40PinExtender" H 3250 5976 50  0000 C CNN
F 2 "" H 3200 4950 50  0001 C CNN
F 3 "~" H 3200 4950 50  0001 C CNN
	1    3200 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2000 7950 2000
$Comp
L power:GND #PWR017
U 1 1 5E6AFC6B
P 8050 2200
F 0 "#PWR017" H 8050 1950 50  0001 C CNN
F 1 "GND" H 8055 2027 50  0000 C CNN
F 2 "" H 8050 2200 50  0001 C CNN
F 3 "" H 8050 2200 50  0001 C CNN
	1    8050 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2200 8300 2200
Text Label 7950 2000 0    50   ~ 0
Arduino_5V
Wire Wire Line
	8750 1900 7950 1900
Text Label 7950 1900 0    50   ~ 0
PlayerCountSignal
$Comp
L Switch:SW_DPDT_x2 SW3
U 1 1 5E6B920E
P 8500 2850
F 0 "SW3" H 8500 3150 50  0000 L CNN
F 1 "SW_Game_Mode" H 8250 3050 50  0000 L CNN
F 2 "" H 8500 2850 50  0001 C CNN
F 3 "~" H 8500 2850 50  0001 C CNN
	1    8500 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 2750 7950 2750
$Comp
L power:GND #PWR018
U 1 1 5E6B9215
P 8050 2950
F 0 "#PWR018" H 8050 2700 50  0001 C CNN
F 1 "GND" H 8055 2777 50  0000 C CNN
F 2 "" H 8050 2950 50  0001 C CNN
F 3 "" H 8050 2950 50  0001 C CNN
	1    8050 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2950 8300 2950
Text Label 7950 2750 0    50   ~ 0
Arduino_5V
Wire Wire Line
	8750 2650 7950 2650
Text Label 7950 2650 0    50   ~ 0
GameModeSignal
Wire Wire Line
	4850 900  4850 1500
Wire Wire Line
	4950 900  4950 1500
Wire Wire Line
	5050 900  5050 1300
Text Label 4950 1500 1    50   ~ 0
LedMatrixData
$Comp
L power:GND #PWR07
U 1 1 5E6CDC4C
P 5050 1300
F 0 "#PWR07" H 5050 1050 50  0001 C CNN
F 1 "GND" H 5055 1127 50  0000 C CNN
F 2 "" H 5050 1300 50  0001 C CNN
F 3 "" H 5050 1300 50  0001 C CNN
	1    5050 1300
	1    0    0    -1  
$EndComp
Text Label 4850 1500 1    50   ~ 0
5V_PowerSupply
$Comp
L power:GND #PWR019
U 1 1 5E73009E
P 6300 6800
F 0 "#PWR019" H 6300 6550 50  0001 C CNN
F 1 "GND" H 6305 6627 50  0000 C CNN
F 2 "" H 6300 6800 50  0001 C CNN
F 3 "" H 6300 6800 50  0001 C CNN
	1    6300 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 6800 6400 6800
Wire Wire Line
	6400 6800 6400 6950
Wire Wire Line
	6500 6350 6500 6950
Text Label 900  5950 0    50   ~ 0
MicroBit_P3
Text Label 900  5850 0    50   ~ 0
MicroBit_P0
Text Notes 2900 5450 1    50   ~ 0
Notch connector on this side
Text Label 900  5750 0    50   ~ 0
MicroBit_P4
Text Label 900  5650 0    50   ~ 0
MicroBit_P5
Wire Wire Line
	900  5650 2050 5650
Text Label 900  5550 0    50   ~ 0
MicroBit_P6
Text Label 900  5450 0    50   ~ 0
MicroBit_P7
Wire Wire Line
	900  5450 1400 5450
Text Label 900  5350 0    50   ~ 0
MicroBit_P1
Text Label 900  5250 0    50   ~ 0
MicroBit_P8
Text Label 900  5150 0    50   ~ 0
MicroBit_P9
Text Label 900  5050 0    50   ~ 0
MicroBit_P10
Wire Wire Line
	900  5050 1400 5050
Text Label 900  4950 0    50   ~ 0
MicroBit_P11
Text Label 900  4850 0    50   ~ 0
MicroBit_P12
Wire Wire Line
	900  4850 1400 4850
Text Label 900  4750 0    50   ~ 0
MicroBit_P2
Text Label 900  4650 0    50   ~ 0
MicroBit_P13
Text Label 900  4550 0    50   ~ 0
MicroBit_P14
Text Label 900  4450 0    50   ~ 0
MicroBit_P15
Text Label 900  4350 0    50   ~ 0
MicroBit_P16
$Comp
L power:GND #PWR021
U 1 1 5E98B09B
P 3500 4150
F 0 "#PWR021" H 3500 3900 50  0001 C CNN
F 1 "GND" V 3505 4022 50  0000 R CNN
F 2 "" H 3500 4150 50  0001 C CNN
F 3 "" H 3500 4150 50  0001 C CNN
	1    3500 4150
	0    -1   -1   0   
$EndComp
Text Label 4300 4550 2    50   ~ 0
LedDataTarget4_3V3
Text Label 4300 4650 2    50   ~ 0
LedDataTarget3_3V3
Text Label 4300 4750 2    50   ~ 0
LedDataTarget2_3V3
Text Label 4300 5250 2    50   ~ 0
LedDataTarget1_3V3
Text Label 4050 5850 2    50   ~ 0
SwitchTarget1
Text Label 4050 5650 2    50   ~ 0
SwitchTarget2
Text Label 4050 5350 2    50   ~ 0
SwitchTarget3
Text Label 4050 4950 2    50   ~ 0
SwitchTarget4
Text Label 4650 5950 2    50   ~ 0
Serial_Arduino_RX_Enable_3V3
Wire Wire Line
	2750 2400 3150 2400
Text Label 2750 2400 0    50   ~ 0
Arduino_5V
$Comp
L power:GND #PWR022
U 1 1 5EBDEE77
P 3700 2400
F 0 "#PWR022" H 3700 2150 50  0001 C CNN
F 1 "GND" H 3705 2227 50  0000 C CNN
F 2 "" H 3700 2400 50  0001 C CNN
F 3 "" H 3700 2400 50  0001 C CNN
	1    3700 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2400 3700 2400
Text Label 4700 5550 2    50   ~ 0
Serial_MicroBit_RX_Enable_3V3
Text Label 4400 4450 2    50   ~ 0
Serial_MicroBit_RX_3V3
Text Label 4400 4350 2    50   ~ 0
Serial_MicroBit_TX_3V3
Wire Wire Line
	3800 1500 4500 1500
Text Label 4500 1500 2    50   ~ 0
PlayerCountSignal
Wire Wire Line
	3800 1100 4500 1100
Text Label 4500 1100 2    50   ~ 0
LedMatrixData
Wire Wire Line
	3800 1400 4500 1400
Text Label 4500 1400 2    50   ~ 0
GameModeSignal
Wire Wire Line
	3800 1300 4500 1300
Text Label 4500 1300 2    50   ~ 0
StartResetSignal
Text Notes 1850 7500 0    50   ~ 0
All SwitchTarget<n> are connected to the Micro:Bit pins which have an internal pull-up resistor of 13K ohm.
Text Notes 7250 4050 0    50   ~ 0
The start/reset switch is connected to the Arduino pin which has \nan internal pull-up resistor with \na value between 20K-50K ohm. (Some measured around 35K)
Wire Wire Line
	8200 3450 7550 3450
Text Label 7550 3450 0    50   ~ 0
StartResetSignal
$Comp
L power:GND #PWR016
U 1 1 5ED7A6E1
P 8650 3450
F 0 "#PWR016" H 8650 3200 50  0001 C CNN
F 1 "GND" H 8655 3277 50  0000 C CNN
F 2 "" H 8650 3450 50  0001 C CNN
F 3 "" H 8650 3450 50  0001 C CNN
	1    8650 3450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPST_x2 SW1
U 1 1 5E6EA688
P 8400 3450
F 0 "SW1" H 8400 3350 50  0000 C CNN
F 1 "SW_Start_Reset" H 8450 3550 50  0000 C CNN
F 2 "" H 8400 3450 50  0001 C CNN
F 3 "~" H 8400 3450 50  0001 C CNN
	1    8400 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3450 8650 3450
Text Label 550  1400 0    50   ~ 0
Arduino_P4
Wire Wire Line
	3800 1200 4500 1200
Text Label 4500 1200 2    50   ~ 0
ConfettiCannon
Text Label 550  1300 0    50   ~ 0
Arduino_P5
Text Label 550  1500 0    50   ~ 0
Arduino_P3
Text Label 550  1600 0    50   ~ 0
Arduino_P2
Text Label 550  1100 0    50   ~ 0
Arduino_P7
Text Label 550  1000 0    50   ~ 0
Arduino_P8
Text Label 550  1200 0    50   ~ 0
Arduino_P6
Text Label 1900 1300 2    50   ~ 0
GameModeSignal
Text Label 1900 1200 2    50   ~ 0
StartResetSignal
Text Label 1900 1100 2    50   ~ 0
ConfettiCannon
Text Label 2300 1600 2    50   ~ 0
Serial_Arduino_RX_Enable_5V
Text Label 2300 1500 2    50   ~ 0
Serial_MicroBit_RX_Enable_5V
Wire Wire Line
	550  1600 2300 1600
Wire Wire Line
	550  1400 1900 1400
Wire Wire Line
	550  1200 1900 1200
Wire Wire Line
	550  1100 1900 1100
Wire Wire Line
	550  1000 1900 1000
Wire Wire Line
	8700 2100 8750 2100
Wire Wire Line
	8700 2850 8750 2850
Wire Wire Line
	2100 3300 2150 3300
$Comp
L Connector:USB_A J5
U 1 1 5E70F829
P 2100 2900
F 0 "J5" H 2157 3367 50  0000 C CNN
F 1 "USB_A_PowerArduino" H 2157 3276 50  0000 C CNN
F 2 "" H 2250 2850 50  0001 C CNN
F 3 " ~" H 2250 2850 50  0001 C CNN
	1    2100 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5E77BF6C
P 2750 3900
F 0 "#PWR012" H 2750 3650 50  0001 C CNN
F 1 "GND" H 2755 3727 50  0000 C CNN
F 2 "" H 2750 3900 50  0001 C CNN
F 3 "" H 2750 3900 50  0001 C CNN
	1    2750 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3300 3600 3300
Text Label 3600 3300 2    50   ~ 0
5V_PowerSupply
Wire Wire Line
	2700 3900 2750 3900
$Comp
L Connector:USB_A J6
U 1 1 5E77BF75
P 2700 3500
F 0 "J6" H 2757 3967 50  0000 C CNN
F 1 "USB_A_PowerMicroBit" H 2757 3876 50  0000 C CNN
F 2 "" H 2850 3450 50  0001 C CNN
F 3 " ~" H 2850 3450 50  0001 C CNN
	1    2700 3500
	1    0    0    -1  
$EndComp
Connection ~ 3500 5250
Text Label 2300 4550 2    50   ~ 0
LedDataTarget4_3V3
Text Label 2300 4650 2    50   ~ 0
LedDataTarget3_3V3
Text Label 2300 4750 2    50   ~ 0
LedDataTarget2_3V3
Text Label 2300 5250 2    50   ~ 0
LedDataTarget1_3V3
Text Label 2050 5850 2    50   ~ 0
SwitchTarget1
Text Label 2050 5650 2    50   ~ 0
SwitchTarget2
Text Label 2050 5350 2    50   ~ 0
SwitchTarget3
Text Label 2050 4950 2    50   ~ 0
SwitchTarget4
Text Label 2650 5950 2    50   ~ 0
Serial_Arduino_RX_Enable_3V3
Text Label 2700 5550 2    50   ~ 0
Serial_MicroBit_RX_Enable_3V3
Text Label 2400 4450 2    50   ~ 0
Serial_MicroBit_RX_3V3
Text Label 2400 4350 2    50   ~ 0
Serial_MicroBit_TX_3V3
Wire Wire Line
	900  4350 2400 4350
Wire Wire Line
	900  4450 2400 4450
Wire Wire Line
	900  4550 2300 4550
Wire Wire Line
	900  4650 2300 4650
Wire Wire Line
	900  4750 2300 4750
Wire Wire Line
	900  5250 2300 5250
Wire Wire Line
	900  5350 2050 5350
Wire Wire Line
	900  5550 2700 5550
Wire Wire Line
	900  5750 1400 5750
Wire Wire Line
	900  5850 2050 5850
Wire Wire Line
	900  5950 2650 5950
Wire Wire Line
	3500 4050 3500 4150
$Comp
L Connector_Generic:Conn_01x05 J4
U 1 1 5E7ECC5B
P 2450 7150
F 0 "J4" V 2650 7100 50  0000 L CNN
F 1 "ConnectorTarget1" V 2550 6800 50  0000 L CNN
F 2 "" H 2450 7150 50  0001 C CNN
F 3 "~" H 2450 7150 50  0001 C CNN
	1    2450 7150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5E7EF8C8
P 2750 6850
F 0 "#PWR02" H 2750 6600 50  0001 C CNN
F 1 "GND" H 2755 6677 50  0000 C CNN
F 2 "" H 2750 6850 50  0001 C CNN
F 3 "" H 2750 6850 50  0001 C CNN
	1    2750 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 6950 2650 6850
Wire Wire Line
	2650 6850 2750 6850
Wire Wire Line
	2550 6950 2550 6350
Text Label 2550 6350 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	2450 6950 2450 6250
Text Label 2450 6250 3    50   ~ 0
LedDataTarget1_5V
$Comp
L Device:R R1
U 1 1 5E7EF8D4
P 2300 6500
F 0 "R1" H 2150 6550 50  0000 L CNN
F 1 "1K" H 2150 6450 50  0000 L CNN
F 2 "" V 2230 6500 50  0001 C CNN
F 3 "~" H 2300 6500 50  0001 C CNN
	1    2300 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5E7EF8DA
P 2050 6500
F 0 "C1" H 1900 6600 50  0000 L CNN
F 1 "0.1uF" H 1800 6400 50  0000 L CNN
F 2 "" H 2088 6350 50  0001 C CNN
F 3 "~" H 2050 6500 50  0001 C CNN
	1    2050 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 6350 2050 6350
Text Label 2300 6350 2    50   ~ 0
SwitchTarget1
$Comp
L power:GND #PWR01
U 1 1 5E80F09C
P 2100 6650
F 0 "#PWR01" H 2100 6400 50  0001 C CNN
F 1 "GND" H 1950 6550 50  0000 C CNN
F 2 "" H 2100 6650 50  0001 C CNN
F 3 "" H 2100 6650 50  0001 C CNN
	1    2100 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 6650 2100 6650
Wire Wire Line
	2300 6650 2350 6650
Wire Wire Line
	2350 6650 2350 6950
Wire Wire Line
	2250 6950 1850 6950
Text Label 1850 6950 0    50   ~ 0
SizeTarget1
$Comp
L Connector_Generic:Conn_01x05 J7
U 1 1 5E87FD51
P 3500 7150
F 0 "J7" V 3700 7100 50  0000 L CNN
F 1 "ConnectorTarget2" V 3600 6800 50  0000 L CNN
F 2 "" H 3500 7150 50  0001 C CNN
F 3 "~" H 3500 7150 50  0001 C CNN
	1    3500 7150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5E87FD57
P 3800 6850
F 0 "#PWR06" H 3800 6600 50  0001 C CNN
F 1 "GND" H 3805 6677 50  0000 C CNN
F 2 "" H 3800 6850 50  0001 C CNN
F 3 "" H 3800 6850 50  0001 C CNN
	1    3800 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 6950 3700 6850
Wire Wire Line
	3700 6850 3800 6850
Wire Wire Line
	3600 6950 3600 6350
Text Label 3600 6350 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	3500 6950 3500 6250
Text Label 3500 6250 3    50   ~ 0
LedDataTarget1_5V
$Comp
L Device:R R2
U 1 1 5E87FD63
P 3350 6500
F 0 "R2" H 3200 6550 50  0000 L CNN
F 1 "1K" H 3200 6450 50  0000 L CNN
F 2 "" V 3280 6500 50  0001 C CNN
F 3 "~" H 3350 6500 50  0001 C CNN
	1    3350 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E87FD69
P 3100 6500
F 0 "C2" H 2950 6600 50  0000 L CNN
F 1 "0.1uF" H 2850 6400 50  0000 L CNN
F 2 "" H 3138 6350 50  0001 C CNN
F 3 "~" H 3100 6500 50  0001 C CNN
	1    3100 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6350 3100 6350
Text Label 3350 6350 2    50   ~ 0
SwitchTarget2
$Comp
L power:GND #PWR03
U 1 1 5E87FD71
P 3150 6650
F 0 "#PWR03" H 3150 6400 50  0001 C CNN
F 1 "GND" H 3000 6550 50  0000 C CNN
F 2 "" H 3150 6650 50  0001 C CNN
F 3 "" H 3150 6650 50  0001 C CNN
	1    3150 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 6650 3150 6650
Wire Wire Line
	3350 6650 3400 6650
Wire Wire Line
	3400 6650 3400 6950
Wire Wire Line
	3300 6950 2900 6950
Text Label 2900 6950 0    50   ~ 0
SizeTarget2
$Comp
L Connector_Generic:Conn_01x05 J11
U 1 1 5E88B164
P 4550 7150
F 0 "J11" V 4750 7100 50  0000 L CNN
F 1 "ConnectorTarget3" V 4650 6800 50  0000 L CNN
F 2 "" H 4550 7150 50  0001 C CNN
F 3 "~" H 4550 7150 50  0001 C CNN
	1    4550 7150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5E88B16A
P 4850 6850
F 0 "#PWR013" H 4850 6600 50  0001 C CNN
F 1 "GND" H 4855 6677 50  0000 C CNN
F 2 "" H 4850 6850 50  0001 C CNN
F 3 "" H 4850 6850 50  0001 C CNN
	1    4850 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 6950 4750 6850
Wire Wire Line
	4750 6850 4850 6850
Wire Wire Line
	4650 6950 4650 6350
Text Label 4650 6350 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	4550 6950 4550 6250
Text Label 4550 6250 3    50   ~ 0
LedDataTarget1_5V
$Comp
L Device:R R3
U 1 1 5E88B176
P 4400 6500
F 0 "R3" H 4250 6550 50  0000 L CNN
F 1 "1K" H 4250 6450 50  0000 L CNN
F 2 "" V 4330 6500 50  0001 C CNN
F 3 "~" H 4400 6500 50  0001 C CNN
	1    4400 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5E88B17C
P 4150 6500
F 0 "C3" H 4000 6600 50  0000 L CNN
F 1 "0.1uF" H 3900 6400 50  0000 L CNN
F 2 "" H 4188 6350 50  0001 C CNN
F 3 "~" H 4150 6500 50  0001 C CNN
	1    4150 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6350 4150 6350
Text Label 4400 6350 2    50   ~ 0
SwitchTarget3
$Comp
L power:GND #PWR010
U 1 1 5E88B184
P 4200 6650
F 0 "#PWR010" H 4200 6400 50  0001 C CNN
F 1 "GND" H 4050 6550 50  0000 C CNN
F 2 "" H 4200 6650 50  0001 C CNN
F 3 "" H 4200 6650 50  0001 C CNN
	1    4200 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 6650 4200 6650
Wire Wire Line
	4400 6650 4450 6650
Wire Wire Line
	4450 6650 4450 6950
Wire Wire Line
	4350 6950 3950 6950
Text Label 3950 6950 0    50   ~ 0
SizeTarget3
$Comp
L Connector_Generic:Conn_01x05 J12
U 1 1 5E897B46
P 5600 7150
F 0 "J12" V 5800 7100 50  0000 L CNN
F 1 "ConnectorTarget4" V 5700 6800 50  0000 L CNN
F 2 "" H 5600 7150 50  0001 C CNN
F 3 "~" H 5600 7150 50  0001 C CNN
	1    5600 7150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5E897B4C
P 5900 6850
F 0 "#PWR015" H 5900 6600 50  0001 C CNN
F 1 "GND" H 5905 6677 50  0000 C CNN
F 2 "" H 5900 6850 50  0001 C CNN
F 3 "" H 5900 6850 50  0001 C CNN
	1    5900 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 6950 5800 6850
Wire Wire Line
	5800 6850 5900 6850
Wire Wire Line
	5700 6950 5700 6350
Text Label 5700 6350 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	5600 6950 5600 6250
Text Label 5600 6250 3    50   ~ 0
LedDataTarget1_5V
$Comp
L Device:R R4
U 1 1 5E897B58
P 5450 6500
F 0 "R4" H 5300 6550 50  0000 L CNN
F 1 "1K" H 5300 6450 50  0000 L CNN
F 2 "" V 5380 6500 50  0001 C CNN
F 3 "~" H 5450 6500 50  0001 C CNN
	1    5450 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5E897B5E
P 5200 6500
F 0 "C4" H 5050 6600 50  0000 L CNN
F 1 "0.1uF" H 4950 6400 50  0000 L CNN
F 2 "" H 5238 6350 50  0001 C CNN
F 3 "~" H 5200 6500 50  0001 C CNN
	1    5200 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 6350 5200 6350
Text Label 5450 6350 2    50   ~ 0
SwitchTarget4
$Comp
L power:GND #PWR014
U 1 1 5E897B66
P 5250 6650
F 0 "#PWR014" H 5250 6400 50  0001 C CNN
F 1 "GND" H 5100 6550 50  0000 C CNN
F 2 "" H 5250 6650 50  0001 C CNN
F 3 "" H 5250 6650 50  0001 C CNN
	1    5250 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 6650 5250 6650
Wire Wire Line
	5450 6650 5500 6650
Wire Wire Line
	5500 6650 5500 6950
Wire Wire Line
	5400 6950 5000 6950
Text Label 5000 6950 0    50   ~ 0
SizeTarget4
$Comp
L power:GND #PWR024
U 1 1 5E8F3D2E
P 8000 1400
F 0 "#PWR024" H 8000 1150 50  0001 C CNN
F 1 "GND" V 7950 1300 50  0000 R CNN
F 2 "" H 8000 1400 50  0001 C CNN
F 3 "" H 8000 1400 50  0001 C CNN
	1    8000 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 1400 8050 1400
Wire Wire Line
	8050 1300 7200 1300
Text Label 7200 1300 0    50   ~ 0
PointSelectorEncoderA
Wire Wire Line
	8050 1500 7200 1500
Text Label 7200 1500 0    50   ~ 0
PointSelectorEncoderB
$Comp
L power:GND #PWR025
U 1 1 5E942130
P 8700 1500
F 0 "#PWR025" H 8700 1250 50  0001 C CNN
F 1 "GND" V 8705 1372 50  0000 R CNN
F 2 "" H 8700 1500 50  0001 C CNN
F 3 "" H 8700 1500 50  0001 C CNN
	1    8700 1500
	0    -1   -1   0   
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW4
U 1 1 5E8F157E
P 8350 1400
F 0 "SW4" H 8350 1767 50  0000 C CNN
F 1 "Rotary_Encoder_Switch_MaxPointSelector" H 8350 1676 50  0000 C CNN
F 2 "" H 8200 1560 50  0001 C CNN
F 3 "~" H 8350 1660 50  0001 C CNN
	1    8350 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 1500 8700 1500
Text Label 9400 1300 2    50   ~ 0
PointSelectorSwitch
Wire Wire Line
	9400 1300 8650 1300
Text Notes 1500 4050 1    50   ~ 0
Notch of the IDC connectors (see list) on this side:\n- Arduino_GPIO\n- Arduino_Serial_and_5V\n- MicroBit_40PinExtender
Wire Notes Line
	2750 6100 1600 6100
Wire Notes Line
	1600 6100 1600 7600
Text Notes 5700 1350 0    50   ~ 0
Inside this space means the\ncomponents are on the main\nboard
Text Label 5600 1600 0    50   ~ 0
Arduino_5V
Wire Wire Line
	5600 1600 6000 1600
$Comp
L power:GND #PWR023
U 1 1 5EB8702E
P 5850 1900
F 0 "#PWR023" H 5850 1650 50  0001 C CNN
F 1 "GND" H 5855 1772 50  0000 R CNN
F 2 "" H 5850 1900 50  0001 C CNN
F 3 "" H 5850 1900 50  0001 C CNN
	1    5850 1900
	1    0    0    -1  
$EndComp
Text Label 5250 1700 0    50   ~ 0
ConfettiCannon
Wire Wire Line
	5250 1700 5850 1700
Text Label 2500 4250 0    50   ~ 0
MicroBit_3V3
Wire Notes Line
	1750 4100 2450 4100
Wire Notes Line
	2450 4100 2450 5400
Wire Notes Line
	2450 5400 2750 5400
Wire Notes Line
	2750 5400 2750 6100
Wire Wire Line
	3650 2300 4450 2300
Text Label 4450 2300 2    50   ~ 0
Serial_Arduino_RX_5V
Wire Wire Line
	3650 2200 4450 2200
Text Label 4450 2200 2    50   ~ 0
Serial_Arduino_TX_5V
Text Label 2050 2200 0    50   ~ 0
Serial_MicroBit_RX_Enable_5V
Wire Wire Line
	3150 2200 2050 2200
Text Label 2050 2300 0    50   ~ 0
Serial_Arduino_RX_Enable_5V
Wire Wire Line
	3150 2300 2050 2300
Text Label 550  1700 0    50   ~ 0
Arduino_P1
Text Label 550  1800 0    50   ~ 0
Arduino_P0
Wire Wire Line
	550  1800 2300 1800
Wire Wire Line
	550  1700 2300 1700
Text Label 2300 1700 2    50   ~ 0
Serial_Arduino_TX_5V
Text Label 2300 1800 2    50   ~ 0
Serial_Arduino_RX_5V
Text Label 1900 1000 2    50   ~ 0
LedMatrixData
Text Label 1900 1400 2    50   ~ 0
PlayerCountSignal
Wire Notes Line
	2350 550  2350 2000
Wire Notes Line
	1750 2000 1750 4100
Text Label 550  800  0    50   ~ 0
Arduino_P10
Text Label 550  700  0    50   ~ 0
Arduino_P11
Text Label 550  900  0    50   ~ 0
Arduino_P9
Text Label 1900 700  2    50   ~ 0
PointSelectorEncoderA
Wire Wire Line
	550  700  1900 700 
Text Label 1900 800  2    50   ~ 0
PointSelectorEncoderB
Wire Wire Line
	550  800  1900 800 
Text Label 1900 900  2    50   ~ 0
PointSelectorSwitch
Wire Wire Line
	550  900  1900 900 
Wire Wire Line
	8750 1900 8750 2100
Wire Wire Line
	8750 2650 8750 2850
$Comp
L Connector_Generic:Conn_01x03 J14
U 1 1 5EB538A7
P 6200 1700
F 0 "J14" H 6300 1700 50  0000 L CNN
F 1 "Dupont_3Pin_Female" H 5950 1500 50  0000 L CNN
F 2 "" H 6200 1700 50  0001 C CNN
F 3 "~" H 6200 1700 50  0001 C CNN
	1    6200 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R6
U 1 1 5EB9F373
P 5850 1800
F 0 "R6" H 5700 1850 50  0000 L CNN
F 1 "1K" H 5700 1750 50  0000 L CNN
F 2 "" H 5850 1800 50  0001 C CNN
F 3 "~" H 5850 1800 50  0001 C CNN
	1    5850 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 1700 6000 1700
Connection ~ 5850 1700
Wire Wire Line
	6000 1800 5900 1800
Wire Wire Line
	5900 1800 5900 1900
Wire Wire Line
	5900 1900 5850 1900
Connection ~ 5850 1900
Wire Notes Line
	6900 7600 1600 7600
Wire Notes Line
	6900 550  6900 7600
Wire Notes Line
	1750 2000 2350 2000
Wire Notes Line
	2350 550  6900 550 
Wire Wire Line
	550  1300 1900 1300
Wire Wire Line
	550  1500 2300 1500
Wire Wire Line
	3300 1100 2400 1100
Text Label 2400 1100 0    50   ~ 0
PointSelectorEncoderA
Wire Wire Line
	3300 1200 2400 1200
Text Label 2400 1200 0    50   ~ 0
PointSelectorEncoderB
Text Label 2500 1300 0    50   ~ 0
PointSelectorSwitch
Wire Wire Line
	2500 1300 3300 1300
Wire Wire Line
	3050 5250 3500 5250
Wire Wire Line
	2500 4250 3000 4250
Connection ~ 3000 4250
Connection ~ 3500 4350
Connection ~ 3500 4450
Connection ~ 3500 4550
Connection ~ 3500 4650
Connection ~ 3500 4750
Connection ~ 3500 5350
Connection ~ 3500 5550
Connection ~ 3500 5850
Connection ~ 3500 5950
Wire Wire Line
	3000 5850 3500 5850
Wire Wire Line
	3000 5650 3500 5650
Wire Wire Line
	3000 5550 3500 5550
Wire Wire Line
	3000 5450 3500 5450
Wire Wire Line
	3000 5350 3500 5350
Wire Wire Line
	3000 5150 3500 5150
Wire Wire Line
	3000 5050 3500 5050
Wire Wire Line
	3000 4950 3500 4950
Wire Wire Line
	3000 4850 3500 4850
Wire Wire Line
	3000 4750 3500 4750
Wire Wire Line
	3000 4650 3500 4650
Wire Wire Line
	3000 4450 3500 4450
Wire Wire Line
	3000 4350 3500 4350
Wire Wire Line
	3000 4150 3500 4150
Wire Wire Line
	3000 4050 3500 4050
Wire Wire Line
	3000 5950 3500 5950
Wire Wire Line
	3500 4550 4300 4550
Wire Wire Line
	3000 4550 3500 4550
Wire Wire Line
	3500 4650 4300 4650
Wire Wire Line
	3500 4750 4300 4750
Wire Wire Line
	3500 4950 4050 4950
Wire Wire Line
	3000 5750 3500 5750
Wire Wire Line
	3000 4250 3500 4250
Wire Wire Line
	3500 4350 4400 4350
Wire Wire Line
	3500 4450 4400 4450
Wire Wire Line
	3500 5350 4050 5350
Wire Wire Line
	3500 5550 4700 5550
Wire Wire Line
	3500 5650 4050 5650
Wire Wire Line
	3500 5850 4050 5850
Wire Wire Line
	3500 5950 4650 5950
Wire Wire Line
	3500 5250 4300 5250
Wire Wire Line
	900  4950 2050 4950
Wire Wire Line
	900  5150 1400 5150
Connection ~ 3500 4950
Connection ~ 3500 5650
$Comp
L RocketLaunch_Library:Bi-Directional_logic_shifter U1
U 1 1 5E8F48B9
P 5250 3800
F 0 "U1" H 5400 4250 50  0000 C CNN
F 1 "Bi-Directional_logic_shifter" H 4600 4250 50  0000 C CNN
F 2 "" H 5250 3800 50  0001 C CNN
F 3 "" H 5250 3800 50  0001 C CNN
	1    5250 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3650 6800 3650
Text Label 6800 3650 2    50   ~ 0
Serial_Arduino_RX_Enable_5V
Text Label 6800 3750 2    50   ~ 0
Serial_MicroBit_RX_Enable_5V
Wire Wire Line
	5650 3750 6800 3750
Text Label 6500 3850 2    50   ~ 0
Serial_Arduino_TX_5V
Wire Wire Line
	5650 3850 6500 3850
Wire Wire Line
	5650 3950 6500 3950
Text Label 6500 3950 2    50   ~ 0
Serial_Arduino_RX_5V
Wire Wire Line
	4800 3250 5200 3250
Text Label 4800 3250 0    50   ~ 0
Arduino_5V
Wire Wire Line
	5200 3250 5200 3300
$Comp
L power:GND #PWR04
U 1 1 5EA19618
P 5300 3250
F 0 "#PWR04" H 5300 3000 50  0001 C CNN
F 1 "GND" V 5305 3077 50  0000 C CNN
F 2 "" H 5300 3250 50  0001 C CNN
F 3 "" H 5300 3250 50  0001 C CNN
	1    5300 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5300 3250 5300 3300
$Comp
L power:GND #PWR05
U 1 1 5EA3BCA6
P 5300 4350
F 0 "#PWR05" H 5300 4100 50  0001 C CNN
F 1 "GND" H 5305 4177 50  0000 C CNN
F 2 "" H 5300 4350 50  0001 C CNN
F 3 "" H 5300 4350 50  0001 C CNN
	1    5300 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4300 5300 4350
Wire Wire Line
	5200 4400 4700 4400
Text Label 4700 4400 0    50   ~ 0
MicroBit_3V3
Wire Wire Line
	5200 4300 5200 4400
Wire Wire Line
	4850 3750 3650 3750
Text Label 3650 3750 0    50   ~ 0
Serial_MicroBit_RX_Enable_3V3
Text Label 3650 3650 0    50   ~ 0
Serial_Arduino_RX_Enable_3V3
Wire Wire Line
	4850 3650 3650 3650
Text Label 3900 3850 0    50   ~ 0
Serial_MicroBit_RX_3V3
Wire Wire Line
	4850 3850 3900 3850
Text Label 3900 3950 0    50   ~ 0
Serial_MicroBit_TX_3V3
Wire Wire Line
	4850 3950 3900 3950
$Comp
L RocketLaunch_Library:Bi-Directional_logic_shifter U2
U 1 1 5EB82D47
P 5650 5250
F 0 "U2" H 5800 5700 50  0000 C CNN
F 1 "Bi-Directional_logic_shifter" H 5000 5700 50  0000 C CNN
F 2 "" H 5650 5250 50  0001 C CNN
F 3 "" H 5650 5250 50  0001 C CNN
	1    5650 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4700 5600 4700
Text Label 5200 4700 0    50   ~ 0
Arduino_5V
Wire Wire Line
	5600 4700 5600 4750
$Comp
L power:GND #PWR08
U 1 1 5EB84976
P 5700 4700
F 0 "#PWR08" H 5700 4450 50  0001 C CNN
F 1 "GND" V 5705 4527 50  0000 C CNN
F 2 "" H 5700 4700 50  0001 C CNN
F 3 "" H 5700 4700 50  0001 C CNN
	1    5700 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5700 4700 5700 4750
$Comp
L power:GND #PWR09
U 1 1 5EB94E6F
P 5700 5800
F 0 "#PWR09" H 5700 5550 50  0001 C CNN
F 1 "GND" H 5705 5627 50  0000 C CNN
F 2 "" H 5700 5800 50  0001 C CNN
F 3 "" H 5700 5800 50  0001 C CNN
	1    5700 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5750 5700 5800
Wire Wire Line
	5600 5850 5100 5850
Text Label 5100 5850 0    50   ~ 0
MicroBit_3V3
Wire Wire Line
	5600 5750 5600 5850
Wire Wire Line
	4450 5200 5250 5200
Text Label 4450 5200 0    50   ~ 0
LedDataTarget2_3V3
Wire Wire Line
	4450 5100 5250 5100
Text Label 4450 5100 0    50   ~ 0
LedDataTarget1_3V3
Text Label 4450 5300 0    50   ~ 0
LedDataTarget3_3V3
Wire Wire Line
	4450 5300 5250 5300
Wire Wire Line
	4450 5400 5250 5400
Text Label 4450 5400 0    50   ~ 0
LedDataTarget4_3V3
Text Label 6800 5400 2    50   ~ 0
LedDataTarget4_5V
Wire Wire Line
	6800 5400 6050 5400
Text Label 6800 5300 2    50   ~ 0
LedDataTarget3_5V
Wire Wire Line
	6800 5300 6050 5300
Wire Wire Line
	6800 5100 6050 5100
Text Label 6800 5100 2    50   ~ 0
LedDataTarget1_5V
Text Label 6800 5200 2    50   ~ 0
LedDataTarget2_5V
Wire Wire Line
	6800 5200 6050 5200
Wire Wire Line
	4550 2350 6000 2350
Wire Wire Line
	6000 2350 6000 2450
Wire Wire Line
	4550 2450 4550 2350
Wire Wire Line
	4550 2450 4650 2450
Connection ~ 4550 2450
Wire Wire Line
	4450 2450 4550 2450
Wire Wire Line
	4550 2550 4550 2450
Wire Wire Line
	4650 2650 4650 2450
Connection ~ 4450 2750
Wire Wire Line
	4450 2750 4800 2750
$Comp
L Device:C C6
U 1 1 5EDDB888
P 4450 2600
F 0 "C6" H 4450 2700 50  0000 L CNN
F 1 "0.1uF" H 4200 2500 50  0000 L CNN
F 2 "" H 4488 2450 50  0001 C CNN
F 3 "~" H 4450 2600 50  0001 C CNN
	1    4450 2600
	1    0    0    -1  
$EndComp
Connection ~ 4550 2850
Wire Wire Line
	4550 2850 4800 2850
Connection ~ 4650 2950
Wire Wire Line
	4650 2950 4800 2950
$Comp
L Device:C C7
U 1 1 5ED5AEFD
P 4550 2700
F 0 "C7" H 4550 2800 50  0000 L CNN
F 1 "0.1uF" H 4300 2600 50  0000 L CNN
F 2 "" H 4588 2550 50  0001 C CNN
F 3 "~" H 4550 2700 50  0001 C CNN
	1    4550 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5ED22825
P 4650 2800
F 0 "C8" H 4650 2900 50  0000 L CNN
F 1 "0.1uF" H 4400 2700 50  0000 L CNN
F 2 "" H 4688 2650 50  0001 C CNN
F 3 "~" H 4650 2800 50  0001 C CNN
	1    4650 2800
	1    0    0    -1  
$EndComp
Connection ~ 6000 2450
Wire Wire Line
	6000 2450 6150 2450
Connection ~ 6000 2750
Wire Wire Line
	6000 2750 6750 2750
$Comp
L Device:R R9
U 1 1 5ECBAF3A
P 4950 2950
F 0 "R9" V 5000 2750 50  0000 L CNN
F 1 "1K" V 4950 2900 50  0000 L CNN
F 2 "" V 4880 2950 50  0001 C CNN
F 3 "~" H 4950 2950 50  0001 C CNN
	1    4950 2950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R8
U 1 1 5ECACC72
P 4950 2850
F 0 "R8" V 5000 2650 50  0000 L CNN
F 1 "1K" V 4950 2800 50  0000 L CNN
F 2 "" V 4880 2850 50  0001 C CNN
F 3 "~" H 4950 2850 50  0001 C CNN
	1    4950 2850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 5EC9E8CF
P 4950 2750
F 0 "R7" V 5000 2550 50  0000 L CNN
F 1 "1K" V 4950 2700 50  0000 L CNN
F 2 "" V 4880 2750 50  0001 C CNN
F 3 "~" H 4950 2750 50  0001 C CNN
	1    4950 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5150 2950 5100 2950
Wire Wire Line
	5150 2850 5100 2850
Wire Wire Line
	5150 2750 5100 2750
Wire Wire Line
	5850 2450 6000 2450
Wire Wire Line
	5850 2550 5850 2450
Wire Wire Line
	5650 2550 5850 2550
Text Label 6750 2750 2    50   ~ 0
StartResetSignal
Wire Wire Line
	5650 2750 5700 2750
Wire Wire Line
	4750 2550 5150 2550
Text Label 4750 2550 0    50   ~ 0
Arduino_5V
Wire Wire Line
	3650 2950 4650 2950
Text Label 3650 2950 0    50   ~ 0
PointSelectorSwitch
Text Label 3450 2850 0    50   ~ 0
PointSelectorEncoderB
Wire Wire Line
	4550 2850 3450 2850
Text Label 3350 2750 0    50   ~ 0
PointSelectorEncoderA
Wire Wire Line
	4450 2750 3350 2750
Text Label 6600 2850 2    50   ~ 0
GameModeSignal
Wire Wire Line
	5650 2850 6600 2850
Text Label 6600 2950 2    50   ~ 0
PlayerCountSignal
Wire Wire Line
	5650 2950 6600 2950
$Comp
L power:GND #PWR020
U 1 1 5E8DAE92
P 6150 2450
F 0 "#PWR020" H 6150 2200 50  0001 C CNN
F 1 "GND" V 6155 2322 50  0000 R CNN
F 2 "" H 6150 2450 50  0001 C CNN
F 3 "" H 6150 2450 50  0001 C CNN
	1    6150 2450
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J13
U 1 1 5E8CF06C
P 5350 2750
F 0 "J13" H 5400 2450 50  0000 C CNN
F 1 "ExternalGameControlIO" H 5400 3076 50  0000 C CNN
F 2 "" H 5350 2750 50  0001 C CNN
F 3 "~" H 5350 2750 50  0001 C CNN
	1    5350 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5ED5FABC
P 6000 2600
F 0 "C5" H 6000 2700 50  0000 L CNN
F 1 "0.1uF" H 6100 2600 50  0000 L CNN
F 2 "" H 6038 2450 50  0001 C CNN
F 3 "~" H 6000 2600 50  0001 C CNN
	1    6000 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5ED5FAB6
P 5850 2750
F 0 "R5" V 5900 2850 50  0000 L CNN
F 1 "1K" V 5850 2700 50  0000 L CNN
F 2 "" V 5780 2750 50  0001 C CNN
F 3 "~" H 5850 2750 50  0001 C CNN
	1    5850 2750
	0    -1   -1   0   
$EndComp
NoConn ~ 2400 2900
NoConn ~ 2400 3000
NoConn ~ 2000 3300
NoConn ~ 3000 3500
NoConn ~ 3000 3600
NoConn ~ 2600 3900
NoConn ~ 3500 4850
NoConn ~ 3500 5050
NoConn ~ 3500 5150
NoConn ~ 3500 5450
NoConn ~ 1400 4850
NoConn ~ 1400 5050
NoConn ~ 1400 5150
NoConn ~ 1400 5450
NoConn ~ 1400 5750
Connection ~ 3500 4150
Connection ~ 3500 4050
$EndSCHEMATC
