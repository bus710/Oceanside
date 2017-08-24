EESchema Schematic File Version 2
LIBS:main-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:stm32
LIBS:oceanside_components
LIBS:main-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
L SN65HVD233-HT U1
U 1 1 599F5E02
P 5150 2300
F 0 "U1" H 5150 2250 60  0000 C CNN
F 1 "SN65HVD233-HT" H 5150 2350 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5150 2300 60  0001 C CNN
F 3 "" H 5150 2300 60  0000 C CNN
	1    5150 2300
	1    0    0    -1  
$EndComp
NoConn ~ 6100 2450
Wire Wire Line
	3200 2150 4200 2150
Wire Wire Line
	4200 2250 4000 2250
Wire Wire Line
	4000 2250 4000 3050
Wire Wire Line
	4100 2350 4200 2350
Wire Wire Line
	4100 1900 4100 2350
$Comp
L +3V3 #PWR01
U 1 1 599F5E10
P 4100 1900
F 0 "#PWR01" H 4100 1750 50  0001 C CNN
F 1 "+3V3" H 4100 2040 50  0000 C CNN
F 2 "" H 4100 1900 50  0000 C CNN
F 3 "" H 4100 1900 50  0000 C CNN
	1    4100 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 599F5E16
P 4000 3050
F 0 "#PWR02" H 4000 2800 50  0001 C CNN
F 1 "GND" H 4000 2900 50  0000 C CNN
F 2 "" H 4000 3050 50  0001 C CNN
F 3 "" H 4000 3050 50  0001 C CNN
	1    4000 3050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 J2
U 1 1 599F5E1C
P 7500 2200
F 0 "J2" H 7500 2850 50  0000 C CNN
F 1 "VehicleCON" H 7500 2750 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 6800 2650 50  0000 C CNN
F 3 "" H 7500 2200 50  0000 C CNN
	1    7500 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2250 7300 2250
Wire Wire Line
	6100 2350 7300 2350
Wire Wire Line
	6100 2150 6200 2150
Wire Wire Line
	6200 2150 6200 3050
$Comp
L GND #PWR03
U 1 1 599F5E30
P 6200 3050
F 0 "#PWR03" H 6200 2800 50  0001 C CNN
F 1 "GND" H 6200 2900 50  0000 C CNN
F 2 "" H 6200 3050 50  0001 C CNN
F 3 "" H 6200 3050 50  0001 C CNN
	1    6200 3050
	1    0    0    -1  
$EndComp
$Comp
L C CC3
U 1 1 599F5E59
P 8400 2600
F 0 "CC3" H 8425 2700 50  0000 L CNN
F 1 "1uF" H 8425 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8438 2450 50  0001 C CNN
F 3 "" H 8400 2600 50  0000 C CNN
	1    8400 2600
	1    0    0    -1  
$EndComp
$Comp
L C CC4
U 1 1 599F5E60
P 8800 2600
F 0 "CC4" H 8825 2700 50  0000 L CNN
F 1 "4.7uF" H 8825 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8838 2450 50  0001 C CNN
F 3 "" H 8800 2600 50  0000 C CNN
	1    8800 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 2250 8400 2450
Wire Wire Line
	8400 2350 8800 2350
Wire Wire Line
	8800 2350 8800 2450
Wire Wire Line
	8400 2750 8400 2950
Wire Wire Line
	8400 2850 8800 2850
Wire Wire Line
	8800 2850 8800 2750
$Comp
L GND #PWR04
U 1 1 599F5E6D
P 8400 2950
F 0 "#PWR04" H 8400 2700 50  0001 C CNN
F 1 "GND" H 8400 2800 50  0000 C CNN
F 2 "" H 8400 2950 50  0001 C CNN
F 3 "" H 8400 2950 50  0001 C CNN
	1    8400 2950
	1    0    0    -1  
$EndComp
Connection ~ 8400 2850
$Comp
L +3V3 #PWR05
U 1 1 599F5E74
P 8400 2250
F 0 "#PWR05" H 8400 2100 50  0001 C CNN
F 1 "+3V3" H 8400 2390 50  0000 C CNN
F 2 "" H 8400 2250 50  0000 C CNN
F 3 "" H 8400 2250 50  0000 C CNN
	1    8400 2250
	1    0    0    -1  
$EndComp
Connection ~ 8400 2350
Wire Wire Line
	6450 2750 7250 2750
Connection ~ 6450 2250
$Comp
L R R1
U 1 1 599F5E7F
P 6700 2850
F 0 "R1" V 6550 2850 50  0000 C CNN
F 1 "120" V 6450 2850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6630 2850 50  0001 C CNN
F 3 "" H 6700 2850 50  0000 C CNN
	1    6700 2850
	0    -1   -1   0   
$EndComp
Connection ~ 6450 2750
$Comp
L SM712 D2
U 1 1 599F5E87
P 7450 2850
F 0 "D2" H 7500 2550 60  0000 C CNN
F 1 "SM712" H 7500 2450 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7450 2850 60  0001 C CNN
F 3 "" H 7450 2850 60  0000 C CNN
	1    7450 2850
	1    0    0    -1  
$EndComp
Connection ~ 6950 2350
Wire Wire Line
	6850 2850 7250 2850
Connection ~ 6950 2850
$Comp
L PWR_FLAG #FLG06
U 1 1 599FDC2E
P 6200 7050
F 0 "#FLG06" H 6200 7145 50  0001 C CNN
F 1 "PWR_FLAG" H 6200 7230 50  0000 C CNN
F 2 "" H 6200 7050 50  0000 C CNN
F 3 "" H 6200 7050 50  0000 C CNN
	1    6200 7050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 599FDC34
P 6200 7250
F 0 "#PWR07" H 6200 7000 50  0001 C CNN
F 1 "GND" H 6200 7100 50  0000 C CNN
F 2 "" H 6200 7250 50  0001 C CNN
F 3 "" H 6200 7250 50  0001 C CNN
	1    6200 7250
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG08
U 1 1 599FDC3A
P 5750 7200
F 0 "#FLG08" H 5750 7295 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 7380 50  0000 C CNN
F 2 "" H 5750 7200 50  0000 C CNN
F 3 "" H 5750 7200 50  0000 C CNN
	1    5750 7200
	1    0    0    1   
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 599FDC40
P 5750 7000
F 0 "#PWR09" H 5750 6850 50  0001 C CNN
F 1 "+3V3" H 5750 7140 50  0000 C CNN
F 2 "" H 5750 7000 50  0000 C CNN
F 3 "" H 5750 7000 50  0000 C CNN
	1    5750 7000
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG010
U 1 1 599FDC46
P 5250 7200
F 0 "#FLG010" H 5250 7295 50  0001 C CNN
F 1 "PWR_FLAG" H 5250 7380 50  0000 C CNN
F 2 "" H 5250 7200 50  0000 C CNN
F 3 "" H 5250 7200 50  0000 C CNN
	1    5250 7200
	1    0    0    1   
$EndComp
$Comp
L +5V #PWR011
U 1 1 599FDC4C
P 5250 7000
F 0 "#PWR011" H 5250 6850 50  0001 C CNN
F 1 "+5V" H 5250 7140 50  0000 C CNN
F 2 "" H 5250 7000 50  0000 C CNN
F 3 "" H 5250 7000 50  0000 C CNN
	1    5250 7000
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG012
U 1 1 599FDC52
P 4750 7200
F 0 "#FLG012" H 4750 7295 50  0001 C CNN
F 1 "PWR_FLAG" H 4750 7380 50  0000 C CNN
F 2 "" H 4750 7200 50  0000 C CNN
F 3 "" H 4750 7200 50  0000 C CNN
	1    4750 7200
	1    0    0    1   
$EndComp
$Comp
L +12V #PWR013
U 1 1 599FDC58
P 4750 7000
F 0 "#PWR013" H 4750 6850 50  0001 C CNN
F 1 "+12V" H 4750 7140 50  0000 C CNN
F 2 "" H 4750 7000 50  0000 C CNN
F 3 "" H 4750 7000 50  0000 C CNN
	1    4750 7000
	1    0    0    -1  
$EndComp
$Comp
L LM1084IS-3.3/NOPB U2
U 1 1 599FDC5E
P 5750 4250
F 0 "U2" H 5950 4050 50  0000 C CNN
F 1 "LM1085-3.3/TO263" H 5400 4450 50  0000 L CNN
F 2 "oceanside_footprints:TO-263-3Lead_re" H 5750 4650 50  0001 C CIN
F 3 "" H 5750 4250 50  0000 C CNN
	1    5750 4250
	1    0    0    -1  
$EndComp
$Comp
L CP1 TC1
U 1 1 599FDC65
P 4700 4550
F 0 "TC1" H 4850 4450 50  0000 L CNN
F 1 "10uF" H 4850 4350 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-A_EIA-3216-18_Wave" H 5550 4000 50  0001 C CNN
F 3 "" H 4700 4550 50  0000 C CNN
	1    4700 4550
	1    0    0    -1  
$EndComp
$Comp
L CP1 TC2
U 1 1 599FDC6C
P 6450 4550
F 0 "TC2" H 6600 4500 50  0000 L CNN
F 1 "10uF" H 6600 4400 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-A_EIA-3216-18_Wave" H 6450 4550 50  0001 C CNN
F 3 "" H 6450 4550 50  0000 C CNN
	1    6450 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 599FDC73
P 6450 4800
F 0 "#PWR014" H 6450 4550 50  0001 C CNN
F 1 "GND" H 6450 4650 50  0000 C CNN
F 2 "" H 6450 4800 50  0001 C CNN
F 3 "" H 6450 4800 50  0001 C CNN
	1    6450 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 599FDC79
P 4700 4800
F 0 "#PWR015" H 4700 4550 50  0001 C CNN
F 1 "GND" H 4700 4650 50  0000 C CNN
F 2 "" H 4700 4800 50  0001 C CNN
F 3 "" H 4700 4800 50  0001 C CNN
	1    4700 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 599FDC7F
P 5750 4800
F 0 "#PWR016" H 5750 4550 50  0001 C CNN
F 1 "GND" H 5750 4650 50  0000 C CNN
F 2 "" H 5750 4800 50  0001 C CNN
F 3 "" H 5750 4800 50  0001 C CNN
	1    5750 4800
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR017
U 1 1 599FDC85
P 7400 3950
F 0 "#PWR017" H 7400 3800 50  0001 C CNN
F 1 "+3V3" H 7400 4090 50  0000 C CNN
F 2 "" H 7400 3950 50  0000 C CNN
F 3 "" H 7400 3950 50  0000 C CNN
	1    7400 3950
	1    0    0    -1  
$EndComp
$Comp
L BARREL_JACK J1
U 1 1 599FDC8B
P 2700 6100
F 0 "J1" H 2700 6550 50  0000 C CNN
F 1 "BARREL_JACK" H 2700 6400 50  0000 C CNN
F 2 "Connectors:BARREL_JACK" H 2700 6400 50  0001 C CNN
F 3 "" H 2700 6100 50  0000 C CNN
	1    2700 6100
	1    0    0    -1  
$EndComp
$Comp
L Fuse F1
U 1 1 599FDC9F
P 7000 4200
F 0 "F1" V 6750 4200 50  0000 C CNN
F 1 "FUSE(PTS18126V300)" V 6850 3950 50  0000 C CNN
F 2 "oceanside_footprints:FusePTS1812" H 6950 4400 50  0001 C CNN
F 3 "" H 7000 4200 50  0000 C CNN
	1    7000 4200
	0    1    1    0   
$EndComp
$Comp
L C CC2
U 1 1 599FDCA6
P 7400 4550
F 0 "CC2" H 7550 4500 50  0000 L CNN
F 1 "1uF" H 7550 4400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7438 4400 50  0001 C CNN
F 3 "" H 7400 4550 50  0000 C CNN
	1    7400 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 599FDCAD
P 7400 4800
F 0 "#PWR018" H 7400 4550 50  0001 C CNN
F 1 "GND" H 7400 4650 50  0000 C CNN
F 2 "" H 7400 4800 50  0001 C CNN
F 3 "" H 7400 4800 50  0001 C CNN
	1    7400 4800
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 599FDCB3
P 7800 4200
F 0 "R2" V 7700 4200 50  0000 C CNN
F 1 "200" V 7900 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7730 4200 50  0001 C CNN
F 3 "" H 7800 4200 50  0001 C CNN
	1    7800 4200
	0    1    1    0   
$EndComp
$Comp
L LED LED1
U 1 1 599FDCBA
P 8200 4500
F 0 "LED1" V 8100 4250 50  0000 C CNN
F 1 "LED" V 8000 4250 50  0000 C CNN
F 2 "LEDs:LED_1206" H 8200 4500 50  0001 C CNN
F 3 "" H 8200 4500 50  0001 C CNN
	1    8200 4500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR019
U 1 1 599FDCC1
P 8200 4800
F 0 "#PWR019" H 8200 4550 50  0001 C CNN
F 1 "GND" H 8200 4650 50  0000 C CNN
F 2 "" H 8200 4800 50  0001 C CNN
F 3 "" H 8200 4800 50  0001 C CNN
	1    8200 4800
	1    0    0    -1  
$EndComp
$Comp
L CP1 EC1
U 1 1 599FDCCE
P 4350 4550
F 0 "EC1" H 4400 4450 50  0000 L CNN
F 1 "47uF" H 4400 4350 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_6.3x4.5" H 3850 4400 50  0001 C CNN
F 3 "" H 4350 4550 50  0000 C CNN
	1    4350 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 599FDCD5
P 4350 4800
F 0 "#PWR020" H 4350 4550 50  0001 C CNN
F 1 "GND" H 4350 4650 50  0000 C CNN
F 2 "" H 4350 4800 50  0001 C CNN
F 3 "" H 4350 4800 50  0001 C CNN
	1    4350 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 599FDCE9
P 4050 4800
F 0 "#PWR021" H 4050 4550 50  0001 C CNN
F 1 "GND" H 4050 4650 50  0000 C CNN
F 2 "" H 4050 4800 50  0001 C CNN
F 3 "" H 4050 4800 50  0001 C CNN
	1    4050 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 7050 6200 7250
Wire Wire Line
	5750 7200 5750 7000
Wire Wire Line
	5250 7200 5250 7000
Wire Wire Line
	4750 7200 4750 7000
Wire Wire Line
	4700 4200 4700 4400
Wire Wire Line
	4700 4700 4700 4800
Wire Wire Line
	7400 3950 7400 4400
Wire Wire Line
	6450 4700 6450 4800
Wire Wire Line
	5750 4500 5750 4800
Connection ~ 6450 4200
Connection ~ 7400 4200
Connection ~ 4700 4200
Wire Wire Line
	8200 4650 8200 4800
Wire Wire Line
	8200 4200 8200 4350
Wire Wire Line
	8200 4200 7950 4200
Wire Wire Line
	3000 6200 3400 6200
Wire Wire Line
	3200 6100 3000 6100
Connection ~ 3200 6200
Wire Wire Line
	4350 4700 4350 4800
Connection ~ 4350 4200
Wire Wire Line
	4050 4700 4050 4800
Wire Wire Line
	4350 4400 4350 4200
Wire Wire Line
	4050 4200 4050 4400
Connection ~ 4050 4200
Wire Wire Line
	6150 4200 6850 4200
$Comp
L D_Bridge_+-AA D1
U 1 1 599FFF53
P 3500 4200
F 0 "D1" H 3650 4500 50  0000 L CNN
F 1 "DF01S (OnSemi) +-AA" H 3650 4400 50  0000 L CNN
F 2 "Diodes_SMD:Diode_Bridge_DFS" H 3500 4200 50  0001 C CNN
F 3 "" H 3500 4200 50  0001 C CNN
	1    3500 4200
	1    0    0    -1  
$EndComp
$Comp
L D_Zener ZD1
U 1 1 59A0287A
P 4050 4550
F 0 "ZD1" V 4150 4300 50  0000 C CNN
F 1 "BZG05C12" V 4250 4250 50  0000 C CNN
F 2 "Diodes_SMD:D_SMA_Handsoldering" H 4050 4550 50  0001 C CNN
F 3 "" H 4050 4550 50  0001 C CNN
	1    4050 4550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR022
U 1 1 59A07056
P 3100 4800
F 0 "#PWR022" H 3100 4550 50  0001 C CNN
F 1 "GND" H 3100 4650 50  0000 C CNN
F 2 "" H 3100 4800 50  0001 C CNN
F 3 "" H 3100 4800 50  0001 C CNN
	1    3100 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 4200 3100 4200
Wire Wire Line
	3100 4200 3100 4800
Wire Wire Line
	3500 4550 3500 4500
Wire Wire Line
	2650 4550 3500 4550
Wire Wire Line
	3500 3850 3500 3900
Wire Wire Line
	2650 3850 3500 3850
Text Label 2650 3850 0    60   ~ 0
Battery+
Text Label 2650 4550 0    60   ~ 0
Battery-
Wire Wire Line
	6450 4200 6450 4400
Wire Wire Line
	7150 4200 7650 4200
Wire Wire Line
	3800 4200 5350 4200
Wire Wire Line
	7400 4700 7400 4800
Wire Wire Line
	6750 2050 7300 2050
Wire Wire Line
	7300 2150 6750 2150
Text Label 6750 2050 0    60   ~ 0
Battery+
Text Label 6750 2150 0    60   ~ 0
Battery-
Wire Wire Line
	7200 2950 7250 2950
$Comp
L GND #PWR023
U 1 1 59A0F759
P 7200 3050
F 0 "#PWR023" H 7200 2800 50  0001 C CNN
F 1 "GND" H 7200 2900 50  0000 C CNN
F 2 "" H 7200 3050 50  0001 C CNN
F 3 "" H 7200 3050 50  0001 C CNN
	1    7200 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2250 6450 2850
Wire Wire Line
	6450 2850 6550 2850
Wire Wire Line
	6950 2850 6950 2350
Wire Wire Line
	7200 2150 7200 3050
Connection ~ 7200 2950
Connection ~ 7200 2150
Wire Wire Line
	3200 6200 3200 6100
Wire Wire Line
	3000 6000 3400 6000
Text Label 3400 6000 0    60   ~ 0
Battery+
Text Label 3400 6200 0    60   ~ 0
Battery-
Wire Wire Line
	4200 2450 3650 2450
Wire Wire Line
	3650 2450 3650 2250
Wire Wire Line
	3650 2250 3200 2250
$Sheet
S 2200 2050 1000 600 
U 59162AA2
F0 "SUB_F446" 60
F1 "SUB_F446.sch" 60
F2 "STM_CAN1_RX" I R 3200 2250 60 
F3 "STM_CAN1_TX" I R 3200 2150 60 
$EndSheet
$Comp
L C CC1
U 1 1 59A01B6F
P 5150 4550
F 0 "CC1" H 5250 4450 50  0000 L CNN
F 1 "1uF" H 5250 4350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5188 4400 50  0001 C CNN
F 3 "" H 5150 4550 50  0000 C CNN
	1    5150 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 59A01B75
P 5150 4800
F 0 "#PWR024" H 5150 4550 50  0001 C CNN
F 1 "GND" H 5150 4650 50  0000 C CNN
F 2 "" H 5150 4800 50  0001 C CNN
F 3 "" H 5150 4800 50  0001 C CNN
	1    5150 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4700 5150 4800
Wire Wire Line
	5150 4200 5150 4400
Connection ~ 5150 4200
$EndSCHEMATC