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
L Connector:Screw_Terminal_01x02 J15
U 1 1 5E6E483D
P 6400 7400
F 0 "J15" V 6350 7100 50  0000 L CNN
F 1 "Screw_Terminal_01x02" V 6500 6950 50  0000 L CNN
F 2 "" H 6400 7400 50  0001 C CNN
F 3 "~" H 6400 7400 50  0001 C CNN
	1    6400 7400
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW2
U 1 1 5E6E85BB
P 8700 2050
F 0 "SW2" H 8700 2350 50  0000 L CNN
F 1 "SW_Player_Count" H 8450 2250 50  0000 L CNN
F 2 "" H 8700 2050 50  0001 C CNN
F 3 "~" H 8700 2050 50  0001 C CNN
	1    8700 2050
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Counter_Clockwise J12
U 1 1 5E6FD45C
P 5650 2400
F 0 "J12" H 5700 2617 50  0000 C CNN
F 1 "XL6009E1_Module_StepUp" H 5700 2526 50  0000 C CNN
F 2 "" H 5650 2400 50  0001 C CNN
F 3 "~" H 5650 2400 50  0001 C CNN
	1    5650 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4750 5950 4750
$Comp
L power:GND #PWR011
U 1 1 5E707618
P 6100 4750
F 0 "#PWR011" H 6100 4500 50  0001 C CNN
F 1 "GND" H 6105 4577 50  0000 C CNN
F 2 "" H 6100 4750 50  0001 C CNN
F 3 "" H 6100 4750 50  0001 C CNN
	1    6100 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 4750 4900 4750
Wire Wire Line
	5450 4650 4900 4650
$Comp
L Connector_Generic:Conn_02x02_Counter_Clockwise J11
U 1 1 5E6F75DE
P 5650 4650
F 0 "J11" H 5700 4867 50  0000 C CNN
F 1 "LM2596_Module_StepDown" H 5700 4776 50  0000 C CNN
F 2 "" H 5650 4650 50  0001 C CNN
F 3 "~" H 5650 4650 50  0001 C CNN
	1    5650 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5E70E9F1
P 4700 4650
F 0 "J5" H 4700 4350 50  0000 C CNN
F 1 "JST-PH_2P_Female" H 4750 4450 50  0000 C CNN
F 2 "" H 4700 4650 50  0001 C CNN
F 3 "~" H 4700 4650 50  0001 C CNN
	1    4700 4650
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5E71BCED
P 5150 5700
F 0 "#PWR08" H 5150 5450 50  0001 C CNN
F 1 "GND" H 5155 5527 50  0000 C CNN
F 2 "" H 5150 5700 50  0001 C CNN
F 3 "" H 5150 5700 50  0001 C CNN
	1    5150 5700
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 5700 5150 5700
$Comp
L power:GND #PWR09
U 1 1 5E71BCF4
P 7000 5700
F 0 "#PWR09" H 7000 5450 50  0001 C CNN
F 1 "GND" H 7005 5527 50  0000 C CNN
F 2 "" H 7000 5700 50  0001 C CNN
F 3 "" H 7000 5700 50  0001 C CNN
	1    7000 5700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7000 5700 6350 5700
$Comp
L Connector_Generic:Conn_02x06_Row_Letter_Last J10
U 1 1 5E71BCFB
P 6050 5700
F 0 "J10" H 6150 6000 50  0000 R CNN
F 1 "LogicConverter_BiDirectional" H 6650 5300 50  0000 R CNN
F 2 "" H 6050 5700 50  0001 C CNN
F 3 "~" H 6050 5700 50  0001 C CNN
	1    6050 5700
	1    0    0    -1  
$EndComp
Text Label 6950 5800 2    50   ~ 0
5V_PowerSupply
Wire Wire Line
	6950 5800 6350 5800
Text Label 5350 5800 0    50   ~ 0
3V3_MicroBit
Wire Wire Line
	5850 5800 5350 5800
Text Label 6400 6650 3    50   ~ 0
5V_PowerSupply
$Comp
L Connector_Generic:Conn_01x04 J13
U 1 1 5E722EED
P 4200 7400
F 0 "J13" V 4400 7300 50  0000 L CNN
F 1 "ConnectorTarget3" V 4300 7100 50  0000 L CNN
F 2 "" H 4200 7400 50  0001 C CNN
F 3 "~" H 4200 7400 50  0001 C CNN
	1    4200 7400
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J14
U 1 1 5E7238C0
P 5300 7400
F 0 "J14" V 5500 7300 50  0000 L CNN
F 1 "ConnectorTarget4" V 5400 7100 50  0000 L CNN
F 2 "" H 5300 7400 50  0001 C CNN
F 3 "~" H 5300 7400 50  0001 C CNN
	1    5300 7400
	0    1    1    0   
$EndComp
Text Label 4900 4650 0    50   ~ 0
3V3_ToMicroBit
Wire Wire Line
	5450 4750 5450 4850
Wire Wire Line
	5450 4850 5950 4850
Wire Wire Line
	5950 4850 5950 4750
Connection ~ 5450 4750
Connection ~ 5950 4750
Wire Wire Line
	5950 4650 6550 4650
Text Label 6550 4650 2    50   ~ 0
5V_PowerSupply
Wire Wire Line
	5950 2400 6550 2400
Text Label 6550 2400 2    50   ~ 0
5V_PowerSupply
$Comp
L power:GND #PWR012
U 1 1 5E730E4A
P 6100 2500
F 0 "#PWR012" H 6100 2250 50  0001 C CNN
F 1 "GND" H 6105 2327 50  0000 C CNN
F 2 "" H 6100 2500 50  0001 C CNN
F 3 "" H 6100 2500 50  0001 C CNN
	1    6100 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2500 6100 2500
Wire Wire Line
	5950 2500 5950 2600
Wire Wire Line
	5950 2600 5450 2600
Wire Wire Line
	5450 2600 5450 2500
Connection ~ 5950 2500
Connection ~ 5450 2500
Text Label 4900 2400 0    50   ~ 0
9V_ToArduino
$Comp
L Connector_Generic:Conn_01x03 J9
U 1 1 5E6A9AF2
P 4850 800
F 0 "J9" V 4814 612 50  0000 R CNN
F 1 "JST-SM_3P_Male_LedMatrix" V 4723 612 50  0000 R CNN
F 2 "" H 4850 800 50  0001 C CNN
F 3 "~" H 4850 800 50  0001 C CNN
	1    4850 800 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Counter_Clockwise J2
U 1 1 5E6AB262
P 3000 2100
F 0 "J2" H 3050 2417 50  0000 C CNN
F 1 "Arduino_Serial_And_5V" H 3050 2326 50  0000 C CNN
F 2 "" H 3000 2100 50  0001 C CNN
F 3 "~" H 3000 2100 50  0001 C CNN
	1    3000 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J1
U 1 1 5E6AC440
P 3000 1300
F 0 "J1" H 3050 1717 50  0000 C CNN
F 1 "Arduino_GPIO" H 3050 1626 50  0000 C CNN
F 2 "" H 3000 1300 50  0001 C CNN
F 3 "~" H 3000 1300 50  0001 C CNN
	1    3000 1300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Row_Letter_Last J3
U 1 1 5E6AC8BC
P 3000 4950
F 0 "J3" H 3050 6067 50  0000 C CNN
F 1 "MicroBit_40PinExtender" H 3050 5976 50  0000 C CNN
F 2 "" H 3000 4950 50  0001 C CNN
F 3 "~" H 3000 4950 50  0001 C CNN
	1    3000 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1950 8150 1950
$Comp
L power:GND #PWR017
U 1 1 5E6AFC6B
P 8250 2150
F 0 "#PWR017" H 8250 1900 50  0001 C CNN
F 1 "GND" H 8255 1977 50  0000 C CNN
F 2 "" H 8250 2150 50  0001 C CNN
F 3 "" H 8250 2150 50  0001 C CNN
	1    8250 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2150 8500 2150
Text Label 8150 1950 0    50   ~ 0
Arduino_5V
Wire Wire Line
	8950 1750 8150 1750
Text Label 8150 1750 0    50   ~ 0
PlayerCountSignal
$Comp
L Switch:SW_DPDT_x2 SW3
U 1 1 5E6B920E
P 8700 2800
F 0 "SW3" H 8700 3100 50  0000 L CNN
F 1 "SW_Game_Mode" H 8450 3000 50  0000 L CNN
F 2 "" H 8700 2800 50  0001 C CNN
F 3 "~" H 8700 2800 50  0001 C CNN
	1    8700 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	8500 2700 8150 2700
$Comp
L power:GND #PWR018
U 1 1 5E6B9215
P 8250 2900
F 0 "#PWR018" H 8250 2650 50  0001 C CNN
F 1 "GND" H 8255 2727 50  0000 C CNN
F 2 "" H 8250 2900 50  0001 C CNN
F 3 "" H 8250 2900 50  0001 C CNN
	1    8250 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2900 8500 2900
Text Label 8150 2700 0    50   ~ 0
Arduino_5V
Wire Wire Line
	8950 2500 8150 2500
Text Label 8150 2500 0    50   ~ 0
GameModeSignal
Wire Wire Line
	4850 2500 5450 2500
Wire Wire Line
	4850 2400 5450 2400
Wire Wire Line
	4850 2500 4850 2550
Wire Wire Line
	4850 2400 4850 2350
$Comp
L Connector:Barrel_Jack J6
U 1 1 5E6BE15C
P 4550 2450
F 0 "J6" H 4607 2775 50  0000 C CNN
F 1 "Barrel_Jack_5.5mm_Male" H 4607 2684 50  0000 C CNN
F 2 "" H 4600 2410 50  0001 C CNN
F 3 "~" H 4600 2410 50  0001 C CNN
	1    4550 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1000 4750 1600
Wire Wire Line
	4850 1000 4850 1600
Wire Wire Line
	4950 1000 4950 1400
Text Label 4850 1600 1    50   ~ 0
LedMatrixData
$Comp
L power:GND #PWR07
U 1 1 5E6CDC4C
P 4950 1400
F 0 "#PWR07" H 4950 1150 50  0001 C CNN
F 1 "GND" H 4955 1227 50  0000 C CNN
F 2 "" H 4950 1400 50  0001 C CNN
F 3 "" H 4950 1400 50  0001 C CNN
	1    4950 1400
	1    0    0    -1  
$EndComp
Text Label 4750 1600 1    50   ~ 0
5V_PowerSupply
Wire Wire Line
	5500 3200 6000 3200
Text Label 6000 3200 2    50   ~ 0
MicroBit_3V3
Wire Wire Line
	4600 3200 5000 3200
Text Label 4600 3200 0    50   ~ 0
Arduino_5V
Wire Wire Line
	3950 3300 5000 3300
$Comp
L power:GND #PWR04
U 1 1 5E7065B4
P 3950 3300
F 0 "#PWR04" H 3950 3050 50  0001 C CNN
F 1 "GND" H 3955 3127 50  0000 C CNN
F 2 "" H 3950 3300 50  0001 C CNN
F 3 "" H 3950 3300 50  0001 C CNN
	1    3950 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 3300 6600 3300
$Comp
L power:GND #PWR05
U 1 1 5E701E25
P 6600 3300
F 0 "#PWR05" H 6600 3050 50  0001 C CNN
F 1 "GND" H 6605 3127 50  0000 C CNN
F 2 "" H 6600 3300 50  0001 C CNN
F 3 "" H 6600 3300 50  0001 C CNN
	1    6600 3300
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x06_Row_Letter_Last J8
U 1 1 5E7120BA
P 5300 3300
F 0 "J8" H 5396 2912 50  0000 R CNN
F 1 "LogicConverter_BiDirectional" H 5900 3600 50  0000 R CNN
F 2 "" H 5300 3300 50  0001 C CNN
F 3 "~" H 5300 3300 50  0001 C CNN
	1    5300 3300
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J7
U 1 1 5E7227AB
P 3100 7400
F 0 "J7" V 3300 7300 50  0000 L CNN
F 1 "ConnectorTarget2" V 3200 7100 50  0000 L CNN
F 2 "" H 3100 7400 50  0001 C CNN
F 3 "~" H 3100 7400 50  0001 C CNN
	1    3100 7400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5E6DB20E
P 2200 7100
F 0 "#PWR02" H 2200 6850 50  0001 C CNN
F 1 "GND" H 2205 6927 50  0000 C CNN
F 2 "" H 2200 7100 50  0001 C CNN
F 3 "" H 2200 7100 50  0001 C CNN
	1    2200 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 7200 2100 7100
Wire Wire Line
	2100 7100 2200 7100
$Comp
L power:GND #PWR06
U 1 1 5E6DC6AB
P 3300 7100
F 0 "#PWR06" H 3300 6850 50  0001 C CNN
F 1 "GND" H 3305 6927 50  0000 C CNN
F 2 "" H 3300 7100 50  0001 C CNN
F 3 "" H 3300 7100 50  0001 C CNN
	1    3300 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 7100 3200 7100
Wire Wire Line
	3200 7100 3200 7200
$Comp
L power:GND #PWR013
U 1 1 5E6DDA4D
P 4400 7100
F 0 "#PWR013" H 4400 6850 50  0001 C CNN
F 1 "GND" H 4405 6927 50  0000 C CNN
F 2 "" H 4400 7100 50  0001 C CNN
F 3 "" H 4400 7100 50  0001 C CNN
	1    4400 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 7100 4300 7100
Wire Wire Line
	4300 7100 4300 7200
$Comp
L power:GND #PWR015
U 1 1 5E6DF96B
P 5500 7100
F 0 "#PWR015" H 5500 6850 50  0001 C CNN
F 1 "GND" H 5505 6927 50  0000 C CNN
F 2 "" H 5500 7100 50  0001 C CNN
F 3 "" H 5500 7100 50  0001 C CNN
	1    5500 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 7100 5400 7100
Wire Wire Line
	5400 7100 5400 7200
Wire Wire Line
	5300 7200 5300 6600
Text Label 5300 6600 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	4200 7200 4200 6600
Text Label 4200 6600 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	3100 7200 3100 6600
Text Label 3100 6600 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	2000 7200 2000 6600
Text Label 2000 6600 3    50   ~ 0
5V_PowerSupply
Wire Wire Line
	1900 7200 1900 6500
Text Label 1900 6500 3    50   ~ 0
LedDataTarget1_5V
Wire Wire Line
	3000 7200 3000 6500
Text Label 3000 6500 3    50   ~ 0
LedDataTarget2_5V
Wire Wire Line
	4100 7200 4100 6500
Text Label 4100 6500 3    50   ~ 0
LedDataTarget3_5V
Wire Wire Line
	5200 7200 5200 6500
Text Label 5200 6500 3    50   ~ 0
LedDataTarget4_5V
Text Label 7050 6000 2    50   ~ 0
LedDataTarget1_5V
Wire Wire Line
	7050 6000 6350 6000
Text Label 7050 5900 2    50   ~ 0
LedDataTarget2_5V
Wire Wire Line
	7050 5900 6350 5900
Text Label 7050 5600 2    50   ~ 0
LedDataTarget3_5V
Wire Wire Line
	7050 5600 6350 5600
Text Label 7050 5500 2    50   ~ 0
LedDataTarget4_5V
Wire Wire Line
	7050 5500 6350 5500
$Comp
L power:GND #PWR019
U 1 1 5E73009E
P 6200 7050
F 0 "#PWR019" H 6200 6800 50  0001 C CNN
F 1 "GND" H 6205 6877 50  0000 C CNN
F 2 "" H 6200 7050 50  0001 C CNN
F 3 "" H 6200 7050 50  0001 C CNN
	1    6200 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 7050 6300 7050
Wire Wire Line
	6300 7050 6300 7200
Wire Wire Line
	6400 6650 6400 7200
Text Label 5100 6000 0    50   ~ 0
LedDataTarget1_3V3
Wire Wire Line
	5100 6000 5850 6000
Text Label 5100 5900 0    50   ~ 0
LedDataTarget2_3V3
Wire Wire Line
	5100 5900 5850 5900
Text Label 5100 5600 0    50   ~ 0
LedDataTarget3_3V3
Wire Wire Line
	5100 5600 5850 5600
Text Label 5100 5500 0    50   ~ 0
LedDataTarget4_3V3
Wire Wire Line
	5100 5500 5850 5500
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 5E720D50
P 2000 7400
F 0 "J4" V 2200 7300 50  0000 L CNN
F 1 "ConnectorTarget1" V 2100 7100 50  0000 L CNN
F 2 "" H 2000 7400 50  0001 C CNN
F 3 "~" H 2000 7400 50  0001 C CNN
	1    2000 7400
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5E75C24C
P 1750 7050
F 0 "R1" H 1600 7100 50  0000 L CNN
F 1 "1K" H 1600 7000 50  0000 L CNN
F 2 "" V 1680 7050 50  0001 C CNN
F 3 "~" H 1750 7050 50  0001 C CNN
	1    1750 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5E75D230
P 1500 7050
F 0 "C1" H 1350 7150 50  0000 L CNN
F 1 "0.1uF" H 1250 6950 50  0000 L CNN
F 2 "" H 1538 6900 50  0001 C CNN
F 3 "~" H 1500 7050 50  0001 C CNN
	1    1500 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 7200 1800 7200
$Comp
L power:GND #PWR01
U 1 1 5E7644E7
P 1500 7250
F 0 "#PWR01" H 1500 7000 50  0001 C CNN
F 1 "GND" H 1505 7077 50  0000 C CNN
F 2 "" H 1500 7250 50  0001 C CNN
F 3 "" H 1500 7250 50  0001 C CNN
	1    1500 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 7200 1500 7250
Wire Wire Line
	1750 6900 1500 6900
Wire Wire Line
	1750 6900 1750 6350
Connection ~ 1750 6900
Text Label 1750 6350 3    50   ~ 0
SwitchTarget1
$Comp
L Device:R R2
U 1 1 5E782109
P 2850 7050
F 0 "R2" H 2700 7100 50  0000 L CNN
F 1 "1K" H 2700 7000 50  0000 L CNN
F 2 "" V 2780 7050 50  0001 C CNN
F 3 "~" H 2850 7050 50  0001 C CNN
	1    2850 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E78210F
P 2600 7050
F 0 "C2" H 2450 7150 50  0000 L CNN
F 1 "0.1uF" H 2350 6950 50  0000 L CNN
F 2 "" H 2638 6900 50  0001 C CNN
F 3 "~" H 2600 7050 50  0001 C CNN
	1    2600 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 6900 2600 6900
Wire Wire Line
	2850 6900 2850 6350
Connection ~ 2850 6900
Text Label 2850 6350 3    50   ~ 0
SwitchTarget2
Wire Wire Line
	2850 7200 2900 7200
$Comp
L power:GND #PWR03
U 1 1 5E7865A7
P 2600 7250
F 0 "#PWR03" H 2600 7000 50  0001 C CNN
F 1 "GND" H 2605 7077 50  0000 C CNN
F 2 "" H 2600 7250 50  0001 C CNN
F 3 "" H 2600 7250 50  0001 C CNN
	1    2600 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 7200 2600 7250
$Comp
L Device:R R3
U 1 1 5E7955B0
P 3950 7050
F 0 "R3" H 3800 7100 50  0000 L CNN
F 1 "1K" H 3800 7000 50  0000 L CNN
F 2 "" V 3880 7050 50  0001 C CNN
F 3 "~" H 3950 7050 50  0001 C CNN
	1    3950 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5E7955B6
P 3700 7050
F 0 "C3" H 3550 7150 50  0000 L CNN
F 1 "0.1uF" H 3450 6950 50  0000 L CNN
F 2 "" H 3738 6900 50  0001 C CNN
F 3 "~" H 3700 7050 50  0001 C CNN
	1    3700 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 6900 3700 6900
Wire Wire Line
	3950 6900 3950 6350
Connection ~ 3950 6900
Text Label 3950 6350 3    50   ~ 0
SwitchTarget3
Wire Wire Line
	3950 7200 4000 7200
$Comp
L power:GND #PWR010
U 1 1 5E7994FE
P 3700 7250
F 0 "#PWR010" H 3700 7000 50  0001 C CNN
F 1 "GND" H 3705 7077 50  0000 C CNN
F 2 "" H 3700 7250 50  0001 C CNN
F 3 "" H 3700 7250 50  0001 C CNN
	1    3700 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 7200 3700 7250
$Comp
L Device:R R4
U 1 1 5E79C230
P 5050 7050
F 0 "R4" H 4900 7100 50  0000 L CNN
F 1 "1K" H 4900 7000 50  0000 L CNN
F 2 "" V 4980 7050 50  0001 C CNN
F 3 "~" H 5050 7050 50  0001 C CNN
	1    5050 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5E79C236
P 4800 7050
F 0 "C4" H 4650 7150 50  0000 L CNN
F 1 "0.1uF" H 4550 6950 50  0000 L CNN
F 2 "" H 4838 6900 50  0001 C CNN
F 3 "~" H 4800 7050 50  0001 C CNN
	1    4800 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 6900 4800 6900
Wire Wire Line
	5050 6900 5050 6350
Connection ~ 5050 6900
Text Label 5050 6350 3    50   ~ 0
SwitchTarget4
Wire Wire Line
	5050 7200 5100 7200
$Comp
L power:GND #PWR014
U 1 1 5E7A07C1
P 4800 7250
F 0 "#PWR014" H 4800 7000 50  0001 C CNN
F 1 "GND" H 4805 7077 50  0000 C CNN
F 2 "" H 4800 7250 50  0001 C CNN
F 3 "" H 4800 7250 50  0001 C CNN
	1    4800 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 7200 4800 7250
$Comp
L MicroBit:microbit_edge_connector J16
U 1 1 5E7CAC18
P 1050 4150
F 0 "J16" H 1050 6175 50  0000 C CNN
F 1 "microbit_edge_connector" H 1050 6084 50  0000 C CNN
F 2 "" H 950 4050 50  0001 C CNN
F 3 "https://www.microbit.co.uk/device/pins" H 950 4050 50  0001 C CNN
	1    1050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5850 3300 5850
Wire Wire Line
	2800 5650 3300 5650
Wire Wire Line
	2800 5550 3300 5550
Wire Wire Line
	2800 5450 3300 5450
Wire Wire Line
	2800 5350 3300 5350
Wire Wire Line
	2800 5250 3300 5250
Wire Wire Line
	2800 5150 3300 5150
Wire Wire Line
	2800 5050 3300 5050
Wire Wire Line
	2800 4950 3300 4950
Wire Wire Line
	2800 4850 3300 4850
Wire Wire Line
	2800 4750 3300 4750
Wire Wire Line
	2800 4650 3300 4650
Wire Wire Line
	2800 4450 3300 4450
Wire Wire Line
	2800 4350 3300 4350
Wire Wire Line
	2800 4250 3300 4250
Wire Wire Line
	2800 4150 3300 4150
Wire Wire Line
	2800 4050 3300 4050
Wire Wire Line
	2800 5950 3300 5950
Wire Wire Line
	1550 2350 1550 2450
Connection ~ 1550 2450
Wire Wire Line
	1550 2450 1550 2550
Connection ~ 1550 2550
Wire Wire Line
	1550 2550 1550 2650
Connection ~ 1550 2650
Wire Wire Line
	1550 2650 1550 2750
Connection ~ 1550 2750
Wire Wire Line
	1550 2750 1550 2850
$Comp
L power:GND #PWR020
U 1 1 5E82B833
P 1700 2550
F 0 "#PWR020" H 1700 2300 50  0001 C CNN
F 1 "GND" H 1705 2377 50  0000 C CNN
F 2 "" H 1700 2550 50  0001 C CNN
F 3 "" H 1700 2550 50  0001 C CNN
	1    1700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2550 1700 2550
Text Label 2050 2950 2    50   ~ 0
MicroBit_P20
Wire Wire Line
	2050 2950 1550 2950
Text Label 2050 3050 2    50   ~ 0
MicroBit_P19
Wire Wire Line
	2050 3050 1550 3050
Text Label 2050 3850 2    50   ~ 0
MicroBit_P15
Wire Wire Line
	2050 3850 1550 3850
Text Label 2050 3950 2    50   ~ 0
MicroBit_P14
Wire Wire Line
	2050 3950 1550 3950
Text Label 2050 4050 2    50   ~ 0
MicroBit_P13
Wire Wire Line
	2050 4050 1550 4050
Text Label 2050 4350 2    50   ~ 0
MicroBit_P2
Wire Wire Line
	2050 4350 1550 4350
Text Label 2050 4550 2    50   ~ 0
MicroBit_P12
Wire Wire Line
	2050 4550 1550 4550
Text Label 2050 4650 2    50   ~ 0
MicroBit_P11
Wire Wire Line
	2050 4650 1550 4650
Text Label 2050 4750 2    50   ~ 0
MicroBit_P10
Wire Wire Line
	2050 4750 1550 4750
Text Label 2050 4850 2    50   ~ 0
MicroBit_P9
Wire Wire Line
	2050 4850 1550 4850
Text Label 2050 4950 2    50   ~ 0
MicroBit_P8
Wire Wire Line
	2050 4950 1550 4950
Text Label 2050 5250 2    50   ~ 0
MicroBit_P1
Wire Wire Line
	2050 5250 1550 5250
Text Label 2050 5450 2    50   ~ 0
MicroBit_P7
Wire Wire Line
	2050 5450 1550 5450
Text Label 2050 5550 2    50   ~ 0
MicroBit_P6
Wire Wire Line
	2050 5550 1550 5550
Text Label 2050 5650 2    50   ~ 0
MicroBit_P5
Wire Wire Line
	2050 5650 1550 5650
Text Label 2050 5750 2    50   ~ 0
MicroBit_P4
Wire Wire Line
	2050 5750 1550 5750
Text Label 2050 6050 2    50   ~ 0
MicroBit_P0
Wire Wire Line
	2050 6050 1550 6050
Text Label 2050 6250 2    50   ~ 0
MicroBit_P3
Wire Wire Line
	2050 6250 1550 6250
Wire Wire Line
	1550 5850 1550 5950
Connection ~ 1550 5950
Wire Wire Line
	1550 5950 1550 6050
Connection ~ 1550 6050
Wire Wire Line
	1550 6050 1550 6150
Wire Wire Line
	1550 5050 1550 5150
Connection ~ 1550 5150
Wire Wire Line
	1550 5150 1550 5250
Connection ~ 1550 5250
Wire Wire Line
	1550 5250 1550 5350
Wire Wire Line
	1550 4150 1550 4250
Connection ~ 1550 4250
Wire Wire Line
	1550 4250 1550 4350
Connection ~ 1550 4350
Wire Wire Line
	1550 4350 1550 4450
Wire Wire Line
	1550 3250 1550 3350
Connection ~ 1550 3350
Wire Wire Line
	1550 3350 1550 3450
Connection ~ 1550 3450
Wire Wire Line
	1550 3450 1550 3550
Connection ~ 1550 3550
Wire Wire Line
	1550 3550 1550 3650
Wire Wire Line
	1550 3150 1550 3250
Connection ~ 1550 3250
Text Label 2050 3450 2    50   ~ 0
MicroBit_3V3
Wire Wire Line
	2050 3450 1550 3450
Text Label 2050 3750 2    50   ~ 0
MicroBit_P16
Wire Wire Line
	2050 3750 1550 3750
Text Label 2300 5950 0    50   ~ 0
MicroBit_P3
Wire Wire Line
	2300 5950 2800 5950
Connection ~ 2800 5950
Text Label 2300 5850 0    50   ~ 0
MicroBit_P0
Wire Wire Line
	2300 5850 2800 5850
Text Notes 2550 3700 1    50   ~ 0
Notch connector on this side
Text Label 2300 5750 0    50   ~ 0
MicroBit_P4
Wire Wire Line
	2300 5750 2800 5750
Text Label 2300 5650 0    50   ~ 0
MicroBit_P5
Wire Wire Line
	2300 5650 2800 5650
Text Label 2300 5550 0    50   ~ 0
MicroBit_P6
Wire Wire Line
	2300 5550 2800 5550
Text Label 2300 5450 0    50   ~ 0
MicroBit_P7
Wire Wire Line
	2300 5450 2800 5450
Text Label 2300 5350 0    50   ~ 0
MicroBit_P1
Wire Wire Line
	2300 5350 2800 5350
Text Label 2300 5250 0    50   ~ 0
MicroBit_P8
Wire Wire Line
	2300 5250 2800 5250
Text Label 2300 5150 0    50   ~ 0
MicroBit_P9
Wire Wire Line
	2300 5150 2800 5150
Text Label 2300 5050 0    50   ~ 0
MicroBit_P10
Wire Wire Line
	2300 5050 2800 5050
Text Label 2300 4950 0    50   ~ 0
MicroBit_P11
Wire Wire Line
	2300 4950 2800 4950
Text Label 2300 4850 0    50   ~ 0
MicroBit_P12
Wire Wire Line
	2300 4850 2800 4850
Text Label 2300 4750 0    50   ~ 0
MicroBit_P2
Wire Wire Line
	2300 4750 2800 4750
Text Label 2300 4650 0    50   ~ 0
MicroBit_P13
Wire Wire Line
	2300 4650 2800 4650
Text Label 2300 4550 0    50   ~ 0
MicroBit_P14
Wire Wire Line
	2300 4550 2800 4550
Text Label 2300 4450 0    50   ~ 0
MicroBit_P15
Wire Wire Line
	2300 4450 2800 4450
Text Label 2300 4350 0    50   ~ 0
MicroBit_P16
Wire Wire Line
	2300 4350 2800 4350
Text Label 2300 4250 0    50   ~ 0
MicroBit_3V3
Wire Wire Line
	2300 4250 2800 4250
Wire Wire Line
	2800 4050 2800 4150
Connection ~ 2800 4050
Connection ~ 2800 4150
$Comp
L power:GND #PWR021
U 1 1 5E98B09B
P 2750 4050
F 0 "#PWR021" H 2750 3800 50  0001 C CNN
F 1 "GND" V 2755 3922 50  0000 R CNN
F 2 "" H 2750 4050 50  0001 C CNN
F 3 "" H 2750 4050 50  0001 C CNN
	1    2750 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	2750 4050 2800 4050
Connection ~ 2800 4250
Connection ~ 2800 4350
Connection ~ 2800 4450
Connection ~ 2800 4650
Connection ~ 2800 4750
Connection ~ 2800 4850
Connection ~ 2800 4950
Connection ~ 2800 5050
Connection ~ 2800 5150
Connection ~ 2800 5250
Connection ~ 2800 5350
Connection ~ 2800 5450
Connection ~ 2800 5550
Connection ~ 2800 5650
Connection ~ 2800 5750
Connection ~ 2800 5850
Wire Wire Line
	4100 4550 3300 4550
Wire Wire Line
	2800 4550 3300 4550
Connection ~ 2800 4550
Connection ~ 3300 4550
Text Label 4100 4550 2    50   ~ 0
LedDataTarget4_3V3
Text Label 4100 4650 2    50   ~ 0
LedDataTarget3_3V3
Wire Wire Line
	4100 4650 3300 4650
Connection ~ 3300 4650
Text Label 4100 4750 2    50   ~ 0
LedDataTarget2_3V3
Wire Wire Line
	4100 4750 3300 4750
Text Label 4100 5150 2    50   ~ 0
LedDataTarget1_3V3
Wire Wire Line
	4100 5150 3300 5150
Connection ~ 3300 4750
Connection ~ 3300 5150
Wire Wire Line
	3300 5850 3850 5850
Text Label 3850 5850 2    50   ~ 0
SwitchTarget1
Wire Wire Line
	2800 5750 3300 5750
Wire Wire Line
	3300 5750 3850 5750
Text Label 3850 5750 2    50   ~ 0
SwitchTarget2
Wire Wire Line
	3300 4450 3850 4450
Text Label 3850 4450 2    50   ~ 0
SwitchTarget3
Wire Wire Line
	3300 4350 3850 4350
Text Label 3850 4350 2    50   ~ 0
SwitchTarget4
Connection ~ 3300 4350
Connection ~ 3300 4450
Connection ~ 3300 5750
Connection ~ 3300 5850
Wire Wire Line
	3300 5950 4450 5950
Text Label 4450 5950 2    50   ~ 0
Serial_Arduino_RX_Enable_3V3
Connection ~ 3300 5950
Wire Wire Line
	5500 3500 6650 3500
Text Label 6650 3500 2    50   ~ 0
Serial_Arduino_RX_Enable_3V3
Wire Wire Line
	5000 3500 3900 3500
Text Label 3900 3500 0    50   ~ 0
Serial_Arduino_RX_Enable_5V
Wire Wire Line
	2800 2100 1700 2100
Text Label 1700 2100 0    50   ~ 0
Serial_Arduino_RX_Enable_5V
Wire Wire Line
	2800 2000 1700 2000
Text Label 1700 2000 0    50   ~ 0
Serial_MicroBit_RX_Enable_5V
Wire Wire Line
	5000 3400 3900 3400
Text Label 3900 3400 0    50   ~ 0
Serial_MicroBit_RX_Enable_5V
Wire Wire Line
	5500 3400 6650 3400
Text Label 6650 3400 2    50   ~ 0
Serial_MicroBit_RX_Enable_3V3
Wire Wire Line
	2400 2200 2800 2200
Text Label 2400 2200 0    50   ~ 0
Arduino_5V
$Comp
L power:GND #PWR022
U 1 1 5EBDEE77
P 3350 2200
F 0 "#PWR022" H 3350 1950 50  0001 C CNN
F 1 "GND" H 3355 2027 50  0000 C CNN
F 2 "" H 3350 2200 50  0001 C CNN
F 3 "" H 3350 2200 50  0001 C CNN
	1    3350 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2200 3350 2200
Wire Wire Line
	3300 5550 4500 5550
Text Label 4500 5550 2    50   ~ 0
Serial_MicroBit_RX_Enable_3V3
Connection ~ 3300 5550
Text Label 4100 2000 2    50   ~ 0
Serial_Arduino_TX_5V
Wire Wire Line
	3300 2000 4100 2000
Text Label 4100 2100 2    50   ~ 0
Serial_Arduino_RX_5V
Wire Wire Line
	3300 2100 4100 2100
Text Label 4200 3000 0    50   ~ 0
Serial_Arduino_TX_5V
Wire Wire Line
	5000 3000 4200 3000
Text Label 4200 3100 0    50   ~ 0
Serial_Arduino_RX_5V
Wire Wire Line
	5000 3100 4200 3100
Text Label 6400 3000 2    50   ~ 0
Serial_MicroBit_RX_3V3
Wire Wire Line
	5500 3000 6400 3000
Text Label 6400 3100 2    50   ~ 0
Serial_MicroBit_TX_3V3
Wire Wire Line
	5500 3100 6400 3100
Text Label 4200 5350 2    50   ~ 0
Serial_MicroBit_RX_3V3
Wire Wire Line
	3300 5350 4200 5350
Text Label 4200 5250 2    50   ~ 0
Serial_MicroBit_TX_3V3
Wire Wire Line
	3300 5250 4200 5250
Connection ~ 3300 5250
Connection ~ 3300 5350
Wire Wire Line
	3300 1500 4000 1500
Text Label 4000 1500 2    50   ~ 0
PlayerCountSignal
Wire Wire Line
	3300 1100 4000 1100
Text Label 4000 1100 2    50   ~ 0
LedMatrixData
Wire Wire Line
	3300 1400 4000 1400
Text Label 4000 1400 2    50   ~ 0
GameModeSignal
Wire Wire Line
	3300 1300 4000 1300
Text Label 4000 1300 2    50   ~ 0
StartResetSignal
Text Notes 1550 7750 0    50   ~ 0
All SwitchTarget<n> are connected to the Micro:Bit pins which have an internal pull-up resistor of 13K ohm.
Text Notes 7150 4300 0    50   ~ 0
The start/reset switch is connected to the Arduino pin which has \nan internal pull-up resistor with \na value between 20K-50K ohm. (Some measured around 35K)
$Comp
L Device:R R5
U 1 1 5ED5FAB6
P 8150 3400
F 0 "R5" H 8000 3450 50  0000 L CNN
F 1 "1K" H 8000 3350 50  0000 L CNN
F 2 "" V 8080 3400 50  0001 C CNN
F 3 "~" H 8150 3400 50  0001 C CNN
	1    8150 3400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C5
U 1 1 5ED5FABC
P 8000 3600
F 0 "C5" H 7850 3700 50  0000 L CNN
F 1 "0.1uF" H 7750 3500 50  0000 L CNN
F 2 "" H 8038 3450 50  0001 C CNN
F 3 "~" H 8000 3600 50  0001 C CNN
	1    8000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 3400 7350 3400
Text Label 7350 3400 0    50   ~ 0
StartResetSignal
$Comp
L power:GND #PWR016
U 1 1 5ED7A6E1
P 8000 3800
F 0 "#PWR016" H 8000 3550 50  0001 C CNN
F 1 "GND" H 8005 3627 50  0000 C CNN
F 2 "" H 8000 3800 50  0001 C CNN
F 3 "" H 8000 3800 50  0001 C CNN
	1    8000 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 3750 8000 3800
Wire Wire Line
	8000 3400 8000 3450
Connection ~ 8000 3400
$Comp
L Switch:SW_DPST_x2 SW1
U 1 1 5E6EA688
P 8550 3400
F 0 "SW1" H 8550 3300 50  0000 C CNN
F 1 "SW_Start_Reset" H 8600 3500 50  0000 C CNN
F 2 "" H 8550 3400 50  0001 C CNN
F 3 "~" H 8550 3400 50  0001 C CNN
	1    8550 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 3400 8350 3400
Wire Wire Line
	8750 3400 8800 3400
Wire Wire Line
	8800 3400 8800 3750
Wire Wire Line
	8800 3750 8000 3750
Connection ~ 8000 3750
Text Label 850  1150 0    50   ~ 0
Arduino_P4
Wire Wire Line
	3300 1200 4000 1200
Text Label 4000 1200 2    50   ~ 0
ConfettiCannon
Text Label 850  1250 0    50   ~ 0
Arduino_P5
Text Label 850  1050 0    50   ~ 0
Arduino_P3
Text Label 850  950  0    50   ~ 0
Arduino_P2
Text Label 850  1450 0    50   ~ 0
Arduino_P7
Text Label 850  1550 0    50   ~ 0
Arduino_P8
Text Label 850  1350 0    50   ~ 0
Arduino_P6
Text Label 2200 1550 2    50   ~ 0
PlayerCountSignal
Text Label 2200 1150 2    50   ~ 0
LedMatrixData
Text Label 2200 1450 2    50   ~ 0
GameModeSignal
Text Label 2200 1350 2    50   ~ 0
StartResetSignal
Text Label 2200 1250 2    50   ~ 0
ConfettiCannon
Text Label 2600 950  2    50   ~ 0
Serial_Arduino_RX_Enable_5V
Text Label 2600 1050 2    50   ~ 0
Serial_MicroBit_RX_Enable_5V
Wire Wire Line
	850  950  2600 950 
Wire Wire Line
	850  1050 2600 1050
Wire Wire Line
	850  1150 2200 1150
Wire Wire Line
	850  1250 2200 1250
Wire Wire Line
	850  1350 2200 1350
Wire Wire Line
	850  1450 2200 1450
Wire Wire Line
	850  1550 2200 1550
$Comp
L Device:R R6
U 1 1 5EF6137B
P 8950 1900
F 0 "R6" H 9020 1946 50  0000 L CNN
F 1 "1K" H 9020 1855 50  0000 L CNN
F 2 "" V 8880 1900 50  0001 C CNN
F 3 "~" H 8950 1900 50  0001 C CNN
	1    8950 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2050 8950 2050
$Comp
L Device:R R7
U 1 1 5EF9E01D
P 8950 2650
F 0 "R7" H 9020 2696 50  0000 L CNN
F 1 "1K" H 9020 2605 50  0000 L CNN
F 2 "" V 8880 2650 50  0001 C CNN
F 3 "~" H 8950 2650 50  0001 C CNN
	1    8950 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2800 8950 2800
$EndSCHEMATC
