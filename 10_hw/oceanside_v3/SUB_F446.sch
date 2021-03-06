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
Sheet 2 5
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
L GND #PWR01
U 1 1 5914ADDF
P 2400 5350
F 0 "#PWR01" H 2400 5100 50  0001 C CNN
F 1 "GND" H 2400 5200 50  0000 C CNN
F 2 "" H 2400 5350 50  0001 C CNN
F 3 "" H 2400 5350 50  0001 C CNN
	1    2400 5350
	1    0    0    -1  
$EndComp
$Comp
L C CC3
U 1 1 5914AF50
P 2400 5000
F 0 "CC3" H 2425 5100 50  0000 L CNN
F 1 "2.2uF" H 2425 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2438 4850 50  0001 C CNN
F 3 "" H 2400 5000 50  0001 C CNN
	1    2400 5000
	1    0    0    -1  
$EndComp
Text Label 2500 3450 0    60   ~ 0
OSC_1
Text Label 2500 3550 0    60   ~ 0
OSC_2
$Comp
L R R3
U 1 1 5914E8A8
P 3750 6850
F 0 "R3" H 3900 6950 50  0000 C CNN
F 1 "10k" H 3900 6850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3680 6850 50  0001 C CNN
F 3 "" H 3750 6850 50  0001 C CNN
	1    3750 6850
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y2
U 1 1 5914EF2E
P 1350 7000
F 0 "Y2" H 1250 7200 50  0000 C CNN
F 1 "8M" H 1400 7200 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-SD_SMD" H 1350 7000 50  0001 C CNN
F 3 "" H 1350 7000 50  0001 C CNN
	1    1350 7000
	1    0    0    -1  
$EndComp
$Comp
L C CC1
U 1 1 5914EFE6
P 1000 7200
F 0 "CC1" H 1025 7300 50  0000 L CNN
F 1 "15pF" H 1025 7100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1038 7050 50  0001 C CNN
F 3 "" H 1000 7200 50  0001 C CNN
	1    1000 7200
	1    0    0    -1  
$EndComp
$Comp
L C CC2
U 1 1 5914F05D
P 1650 7200
F 0 "CC2" H 1675 7300 50  0000 L CNN
F 1 "15pF" H 1675 7100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1688 7050 50  0001 C CNN
F 3 "" H 1650 7200 50  0001 C CNN
	1    1650 7200
	1    0    0    -1  
$EndComp
Text Label 1850 6500 0    60   ~ 0
OSC_1
Text Label 1850 6700 0    60   ~ 0
OSC_2
$Comp
L R R5
U 1 1 5914D563
P 10700 1150
F 0 "R5" H 10850 1150 50  0000 C CNN
F 1 "200" H 10850 1050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 10630 1150 50  0001 C CNN
F 3 "" H 10700 1150 50  0001 C CNN
	1    10700 1150
	1    0    0    -1  
$EndComp
$Comp
L LED LED3
U 1 1 5914D626
P 10700 1600
F 0 "LED3" V 10750 1350 50  0000 C CNN
F 1 "LED" V 10650 1350 50  0000 C CNN
F 2 "LEDs:LED_1206" H 10700 1600 50  0001 C CNN
F 3 "" H 10700 1600 50  0001 C CNN
	1    10700 1600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5914FCE1
P 1650 7450
F 0 "#PWR02" H 1650 7200 50  0001 C CNN
F 1 "GND" H 1650 7300 50  0000 C CNN
F 2 "" H 1650 7450 50  0001 C CNN
F 3 "" H 1650 7450 50  0001 C CNN
	1    1650 7450
	1    0    0    -1  
$EndComp
Text Label 2500 2000 0    60   ~ 0
NRST
Text HLabel 8250 1400 2    60   Input ~ 0
STM_RD1
Text HLabel 8250 1500 2    60   Input ~ 0
STM_RD0
$Comp
L +3V3 #PWR03
U 1 1 591B7077
P 3750 6600
F 0 "#PWR03" H 3750 6450 50  0001 C CNN
F 1 "+3V3" H 3750 6740 50  0000 C CNN
F 2 "" H 3750 6600 50  0000 C CNN
F 3 "" H 3750 6600 50  0000 C CNN
	1    3750 6600
	-1   0    0    -1  
$EndComp
$Comp
L +3V3 #PWR04
U 1 1 591B7245
P 2850 1150
F 0 "#PWR04" H 2850 1000 50  0001 C CNN
F 1 "+3V3" H 2850 1290 50  0000 C CNN
F 2 "" H 2850 1150 50  0000 C CNN
F 3 "" H 2850 1150 50  0000 C CNN
	1    2850 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 6700 3750 6600
Wire Wire Line
	1000 6500 1000 7050
Wire Wire Line
	1000 7000 1200 7000
Wire Wire Line
	1500 7000 1650 7000
Wire Wire Line
	1650 6700 1650 7050
Wire Wire Line
	1000 6500 1850 6500
Connection ~ 1000 7000
Wire Wire Line
	1650 6700 1850 6700
Connection ~ 1650 7000
Wire Wire Line
	10700 1800 10700 1950
Wire Wire Line
	10700 1300 10700 1400
Wire Wire Line
	2500 3450 2950 3450
Wire Wire Line
	2500 3550 2950 3550
Wire Wire Line
	2500 2000 2950 2000
Wire Wire Line
	2950 2200 2500 2200
Wire Wire Line
	2500 2300 2950 2300
Text HLabel 2700 2600 0    60   Input ~ 0
STM_UART1_TX
Text HLabel 2700 2700 0    60   Input ~ 0
STM_UART1_RX
$Comp
L STM32F446R U1
U 1 1 593BFFDB
P 4100 3650
AR Path="/593BFFDB" Ref="U1"  Part="1" 
AR Path="/59162AA2/593BFFDB" Ref="U1"  Part="1" 
F 0 "U1" H 4450 5900 50  0000 C CNN
F 1 "STM32F446R" H 4450 6000 50  0000 C CNN
F 2 "Housings_QFP:LQFP-64_10x10mm_Pitch0.5mm" H 4450 5800 50  0000 C CNN
F 3 "" H 3750 5900 50  0000 C CNN
	1    4100 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1300 2850 1300
Wire Wire Line
	2850 1150 2850 1800
Wire Wire Line
	2850 1400 2950 1400
Connection ~ 2850 1300
Wire Wire Line
	2850 1500 2950 1500
Connection ~ 2850 1400
Wire Wire Line
	2850 1600 2950 1600
Connection ~ 2850 1500
Wire Wire Line
	2850 1700 2950 1700
Connection ~ 2850 1600
Wire Wire Line
	2950 4750 2850 4750
Wire Wire Line
	2400 5250 2950 5250
Connection ~ 2850 5250
Wire Wire Line
	2950 5150 2850 5150
Connection ~ 2850 5150
Wire Wire Line
	2950 5050 2850 5050
Connection ~ 2850 5050
Wire Wire Line
	2950 4950 2850 4950
Connection ~ 2850 4950
Wire Wire Line
	2950 4850 2850 4850
Connection ~ 2850 4850
Wire Wire Line
	2400 4550 2400 4850
Wire Wire Line
	2400 5150 2400 5350
Connection ~ 2400 5250
Wire Wire Line
	2850 4650 2850 5250
Text Label 2500 3150 0    60   ~ 0
OSC32_1
Text Label 2500 3250 0    60   ~ 0
OSC32_2
Wire Wire Line
	2500 3150 2950 3150
Wire Wire Line
	2500 3250 2950 3250
$Comp
L Crystal Y1
U 1 1 593CE49C
P 1350 6050
F 0 "Y1" H 1250 6250 50  0000 C CNN
F 1 "32k" H 1400 6250 50  0000 C CNN
F 2 "Crystals:Crystal_Round_Horizontal_2mm" H 1350 6050 50  0001 C CNN
F 3 "" H 1350 6050 50  0001 C CNN
	1    1350 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 6050 1850 6050
Wire Wire Line
	1200 6050 1000 6050
Wire Wire Line
	1000 6050 1000 6250
Wire Wire Line
	1000 6250 1850 6250
Text Label 1850 6050 0    60   ~ 0
OSC32_1
Text Label 1850 6250 0    60   ~ 0
OSC32_2
$Comp
L GND #PWR05
U 1 1 593CFCC2
P 10700 1950
F 0 "#PWR05" H 10700 1700 50  0001 C CNN
F 1 "GND" H 10700 1800 50  0000 C CNN
F 2 "" H 10700 1950 50  0001 C CNN
F 3 "" H 10700 1950 50  0001 C CNN
	1    10700 1950
	1    0    0    -1  
$EndComp
Text Label 10700 900  0    60   ~ 0
SYS_LED
Text HLabel 2750 3850 0    60   Input ~ 0
STM_RS485_EN
Text HLabel 2750 3950 0    60   Input ~ 0
STM_RS485_TX
Text HLabel 2750 4050 0    60   Input ~ 0
STM_RS485_RX
Text HLabel 2750 4250 0    60   Input ~ 0
STM_CAN2_RX
Text HLabel 2750 4350 0    60   Input ~ 0
STM_CAN2_TX
Wire Wire Line
	2950 4250 2750 4250
Wire Wire Line
	2950 4350 2750 4350
Wire Wire Line
	2750 4050 2950 4050
Wire Wire Line
	2950 3950 2750 3950
Wire Wire Line
	2750 3850 2950 3850
$Comp
L CONN_02X20 J3
U 1 1 593D76E4
P 9800 3850
F 0 "J3" H 9800 5100 50  0000 C CNN
F 1 "MBEDCON" H 9800 5000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20" H 9800 2900 50  0001 C CNN
F 3 "" H 9800 2900 50  0000 C CNN
	1    9800 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X05 J2
U 1 1 593D7A99
P 2700 6900
F 0 "J2" H 2700 7300 50  0000 C CNN
F 1 "SWDCON" H 2800 7200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 2700 6250 50  0001 C CNN
F 3 "" H 2700 6900 50  0000 C CNN
	1    2700 6900
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 593D7AA0
P 3200 7250
F 0 "#PWR06" H 3200 7000 50  0001 C CNN
F 1 "GND" H 3200 7100 50  0000 C CNN
F 2 "" H 3200 7250 50  0001 C CNN
F 3 "" H 3200 7250 50  0001 C CNN
	1    3200 7250
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR07
U 1 1 593D7AA6
P 3200 6450
F 0 "#PWR07" H 3200 6300 50  0001 C CNN
F 1 "+3V3" H 3200 6590 50  0000 C CNN
F 2 "" H 3200 6450 50  0000 C CNN
F 3 "" H 3200 6450 50  0000 C CNN
	1    3200 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 6450 3200 6700
Text Label 3300 7000 0    60   ~ 0
SWCLK
Text Label 3300 7100 0    60   ~ 0
NRST
Text Label 3300 6800 0    60   ~ 0
SWDIO
Wire Wire Line
	3200 6900 3200 7250
Wire Wire Line
	8000 1900 8200 1900
Wire Wire Line
	8000 2000 8200 2000
Wire Wire Line
	8000 2100 8200 2100
Wire Wire Line
	8000 2200 8200 2200
Wire Wire Line
	8000 2300 8200 2300
Wire Wire Line
	8000 2400 8200 2400
Wire Wire Line
	8000 2500 8200 2500
Wire Wire Line
	8000 2600 8200 2600
Wire Wire Line
	8000 2700 8200 2700
Wire Wire Line
	8000 2800 8200 2800
Wire Wire Line
	8000 3100 8200 3100
Wire Wire Line
	8000 3200 8200 3200
Wire Wire Line
	8000 3300 8200 3300
Wire Wire Line
	8000 3000 8200 3000
Wire Wire Line
	8000 3400 8200 3400
Wire Wire Line
	8000 3500 8200 3500
Wire Wire Line
	8000 3600 8200 3600
Wire Wire Line
	8000 3800 8200 3800
Wire Wire Line
	8000 4000 8200 4000
Wire Wire Line
	8000 4100 8200 4100
Wire Wire Line
	8000 4200 8200 4200
Wire Wire Line
	8000 4300 8200 4300
Wire Wire Line
	8000 4400 8200 4400
Text Label 8200 1900 0    60   ~ 0
P0
Text Label 8200 2000 0    60   ~ 0
P1
Text Label 8200 2100 0    60   ~ 0
P2
Text Label 8200 2200 0    60   ~ 0
P3
Text Label 8200 2300 0    60   ~ 0
P4
Text Label 8200 2400 0    60   ~ 0
P5
Text Label 8200 2500 0    60   ~ 0
P6
Text Label 8200 2600 0    60   ~ 0
P7
Text Label 8200 2700 0    60   ~ 0
P8
Text Label 8200 2800 0    60   ~ 0
P9
Text Label 8200 3000 0    60   ~ 0
P10
Text Label 8200 3100 0    60   ~ 0
P11
Text Label 8200 3200 0    60   ~ 0
P12
Text Label 8200 3300 0    60   ~ 0
P13
Text Label 8200 3400 0    60   ~ 0
P14
Text Label 8200 3500 0    60   ~ 0
P15
Text Label 8200 3600 0    60   ~ 0
P16
Text Label 8200 3700 0    60   ~ 0
P17
Text Label 8200 3800 0    60   ~ 0
P18
Text Label 8200 4000 0    60   ~ 0
P19
Text Label 8200 4100 0    60   ~ 0
P20
Text Label 8200 4200 0    60   ~ 0
P21
Text Label 8200 4300 0    60   ~ 0
P22
Wire Wire Line
	9450 3000 9550 3000
Wire Wire Line
	9450 2700 9450 3000
Wire Wire Line
	9450 2900 9550 2900
Connection ~ 9450 2900
Wire Wire Line
	10150 3000 10050 3000
Wire Wire Line
	10150 2700 10150 3000
Wire Wire Line
	10150 2900 10050 2900
Connection ~ 10150 2900
Wire Wire Line
	9550 3100 9250 3100
Wire Wire Line
	9550 3200 9250 3200
Wire Wire Line
	9550 3300 9250 3300
Wire Wire Line
	9550 3400 9250 3400
Wire Wire Line
	9550 3500 9250 3500
Wire Wire Line
	9550 3600 9250 3600
Wire Wire Line
	9550 3700 9250 3700
Wire Wire Line
	9550 3800 9250 3800
Wire Wire Line
	9550 3900 9250 3900
Wire Wire Line
	9550 4000 9250 4000
Wire Wire Line
	9550 4100 9250 4100
Wire Wire Line
	9550 4200 9250 4200
Wire Wire Line
	10350 3100 10050 3100
Wire Wire Line
	10350 3200 10050 3200
Wire Wire Line
	10350 3300 10050 3300
Wire Wire Line
	10350 3400 10050 3400
Wire Wire Line
	10350 3500 10050 3500
Wire Wire Line
	10350 3600 10050 3600
Wire Wire Line
	10350 3700 10050 3700
Wire Wire Line
	10350 3800 10050 3800
Wire Wire Line
	10350 3900 10050 3900
Wire Wire Line
	10350 4000 10050 4000
Wire Wire Line
	10350 4100 10050 4100
Text Label 10350 3100 0    60   ~ 0
P1
Text Label 9250 3200 2    60   ~ 0
P2
Text Label 10350 3200 0    60   ~ 0
P3
Text Label 9250 3300 2    60   ~ 0
P4
Text Label 10350 3300 0    60   ~ 0
P5
Text Label 9250 3400 2    60   ~ 0
P6
Text Label 10350 3400 0    60   ~ 0
P7
Text Label 9250 3500 2    60   ~ 0
P8
Text Label 10350 3500 0    60   ~ 0
P9
Text Label 9250 3600 2    60   ~ 0
P10
Text Label 10350 3600 0    60   ~ 0
P11
Text Label 9250 3700 2    60   ~ 0
P12
Text Label 10350 3700 0    60   ~ 0
P13
Text Label 9250 3800 2    60   ~ 0
P14
Text Label 10350 3800 0    60   ~ 0
P15
Text Label 9250 3900 2    60   ~ 0
P16
Text Label 10350 3900 0    60   ~ 0
P17
Text Label 9250 4000 2    60   ~ 0
P18
Text Label 10350 4000 0    60   ~ 0
P19
Text Label 10350 4100 0    60   ~ 0
P21
Text Label 9250 4200 2    60   ~ 0
P22
Text Label 9250 4100 2    60   ~ 0
P20
Text Label 9250 3100 2    60   ~ 0
P0
Wire Wire Line
	9550 4800 9450 4800
Wire Wire Line
	9450 4800 9450 4900
Wire Wire Line
	10050 4800 10150 4800
Wire Wire Line
	10150 4800 10150 4900
NoConn ~ 10050 4600
NoConn ~ 10050 4700
NoConn ~ 9550 4600
NoConn ~ 9550 4700
$Comp
L GND #PWR08
U 1 1 593E86D9
P 10150 4900
F 0 "#PWR08" H 10150 4650 50  0001 C CNN
F 1 "GND" H 10150 4750 50  0000 C CNN
F 2 "" H 10150 4900 50  0001 C CNN
F 3 "" H 10150 4900 50  0001 C CNN
	1    10150 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 593E8726
P 9450 4900
F 0 "#PWR09" H 9450 4650 50  0001 C CNN
F 1 "GND" H 9450 4750 50  0000 C CNN
F 2 "" H 9450 4900 50  0001 C CNN
F 3 "" H 9450 4900 50  0001 C CNN
	1    9450 4900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 593E97FB
P 10150 2700
F 0 "#PWR010" H 10150 2550 50  0001 C CNN
F 1 "+5V" H 10150 2840 50  0000 C CNN
F 2 "" H 10150 2700 50  0000 C CNN
F 3 "" H 10150 2700 50  0000 C CNN
	1    10150 2700
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR011
U 1 1 593E9848
P 9450 2700
F 0 "#PWR011" H 9450 2550 50  0001 C CNN
F 1 "+3V3" H 9450 2840 50  0000 C CNN
F 2 "" H 9450 2700 50  0000 C CNN
F 3 "" H 9450 2700 50  0000 C CNN
	1    9450 2700
	1    0    0    -1  
$EndComp
Text Label 2500 2200 0    60   ~ 0
SWDIO
Text Label 2500 2300 0    60   ~ 0
SWCLK
$Comp
L R R1
U 1 1 593E9A19
P 1500 2600
F 0 "R1" H 1350 2650 50  0000 C CNN
F 1 "4k7" H 1350 2550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1430 2600 50  0001 C CNN
F 3 "" H 1500 2600 50  0001 C CNN
	1    1500 2600
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 593E9A92
P 1600 2600
F 0 "R2" H 1450 2650 50  0000 C CNN
F 1 "4k7" H 1450 2550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1530 2600 50  0001 C CNN
F 3 "" H 1600 2600 50  0001 C CNN
	1    1600 2600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1500 2250 1500 2450
Wire Wire Line
	1500 2350 1600 2350
Wire Wire Line
	1600 2350 1600 2450
Connection ~ 1500 2350
$Comp
L +3V3 #PWR012
U 1 1 593EA446
P 1500 2250
F 0 "#PWR012" H 1500 2100 50  0001 C CNN
F 1 "+3V3" H 1500 2390 50  0000 C CNN
F 2 "" H 1500 2250 50  0000 C CNN
F 3 "" H 1500 2250 50  0000 C CNN
	1    1500 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 2600 2950 2600
Wire Wire Line
	2950 2700 2700 2700
Wire Wire Line
	1500 2750 1500 2850
Wire Wire Line
	1600 2750 1600 2950
Wire Wire Line
	2900 6800 3300 6800
Wire Wire Line
	3300 7000 2900 7000
Wire Wire Line
	3200 6700 2900 6700
Wire Wire Line
	2900 6900 3200 6900
Wire Wire Line
	8000 4500 8200 4500
Wire Wire Line
	8000 3700 8200 3700
Text Label 8200 4400 0    60   ~ 0
P23
Text Label 8200 4500 0    60   ~ 0
P24
Wire Wire Line
	10050 4200 10350 4200
Wire Wire Line
	9550 4300 9250 4300
Text Label 9250 4300 2    60   ~ 0
P24
Text Label 10350 4200 0    60   ~ 0
P23
Wire Wire Line
	2850 1800 2950 1800
Connection ~ 2850 1700
Wire Wire Line
	8250 1400 8000 1400
Wire Wire Line
	8000 1500 8250 1500
$Comp
L C CC4
U 1 1 595204B7
P 4300 6900
F 0 "CC4" H 4325 7000 50  0000 L CNN
F 1 "1uF" H 4325 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4338 6750 50  0001 C CNN
F 3 "" H 4300 6900 50  0001 C CNN
	1    4300 6900
	1    0    0    -1  
$EndComp
$Comp
L C CC5
U 1 1 595204BE
P 4600 6900
F 0 "CC5" H 4625 7000 50  0000 L CNN
F 1 "1uF" H 4625 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4638 6750 50  0001 C CNN
F 3 "" H 4600 6900 50  0001 C CNN
	1    4600 6900
	1    0    0    -1  
$EndComp
$Comp
L C CC6
U 1 1 595204C5
P 4900 6900
F 0 "CC6" H 4925 7000 50  0000 L CNN
F 1 "1uF" H 4925 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4938 6750 50  0001 C CNN
F 3 "" H 4900 6900 50  0001 C CNN
	1    4900 6900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 595204CC
P 4600 7250
F 0 "#PWR013" H 4600 7000 50  0001 C CNN
F 1 "GND" H 4600 7100 50  0000 C CNN
F 2 "" H 4600 7250 50  0001 C CNN
F 3 "" H 4600 7250 50  0001 C CNN
	1    4600 7250
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR014
U 1 1 595204D2
P 4600 6550
F 0 "#PWR014" H 4600 6400 50  0001 C CNN
F 1 "+3V3" H 4600 6690 50  0000 C CNN
F 2 "" H 4600 6550 50  0000 C CNN
F 3 "" H 4600 6550 50  0000 C CNN
	1    4600 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 7150 5200 7150
Wire Wire Line
	4600 7050 4600 7250
Connection ~ 4600 7150
Wire Wire Line
	4300 6650 5200 6650
Wire Wire Line
	4600 6550 4600 6750
Connection ~ 4600 6650
Wire Wire Line
	4300 6650 4300 6750
Wire Wire Line
	4900 6650 4900 6750
Wire Wire Line
	4900 7150 4900 7050
Wire Wire Line
	4300 7150 4300 7050
Wire Wire Line
	10700 1000 10700 900 
Wire Wire Line
	8000 1600 8750 1600
Text Label 8750 1600 0    60   ~ 0
SYS_LED
$Comp
L SW_PUSH SW1
U 1 1 5952EEC4
P 9800 1300
F 0 "SW1" H 10100 1350 50  0000 C CNN
F 1 "A" H 10250 1350 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_FSMSM" H 9800 1300 50  0001 C CNN
F 3 "" H 9800 1300 50  0000 C CNN
	1    9800 1300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 59531A89
P 9400 1800
F 0 "#PWR015" H 9400 1550 50  0001 C CNN
F 1 "GND" H 9400 1650 50  0000 C CNN
F 2 "" H 9400 1800 50  0001 C CNN
F 3 "" H 9400 1800 50  0001 C CNN
	1    9400 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1300 9500 1300
Wire Wire Line
	8000 4600 8200 4600
Wire Wire Line
	8000 4700 8200 4700
Text Label 8200 4600 0    60   ~ 0
P25
Wire Wire Line
	8000 4800 8200 4800
Text Label 8200 4700 0    60   ~ 0
P26
Text Label 8200 4800 0    60   ~ 0
P27
Wire Wire Line
	10050 4300 10350 4300
Wire Wire Line
	10050 4400 10350 4400
Wire Wire Line
	9550 4400 9250 4400
Text Label 10350 4300 0    60   ~ 0
P25
Text Label 10350 4400 0    60   ~ 0
P27
Text Label 9250 4400 2    60   ~ 0
P26
Wire Wire Line
	2950 4550 2400 4550
Wire Wire Line
	2950 4650 2850 4650
Connection ~ 2850 4750
$Comp
L C CC8
U 1 1 595D6FF8
P 5550 6900
F 0 "CC8" H 5575 7000 50  0000 L CNN
F 1 "4.7uF" H 5575 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5588 6750 50  0001 C CNN
F 3 "" H 5550 6900 50  0001 C CNN
	1    5550 6900
	1    0    0    -1  
$EndComp
$Comp
L C CC9
U 1 1 595D6FFE
P 5850 6900
F 0 "CC9" H 5875 7000 50  0000 L CNN
F 1 "4.7uF" H 5875 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5888 6750 50  0001 C CNN
F 3 "" H 5850 6900 50  0001 C CNN
	1    5850 6900
	1    0    0    -1  
$EndComp
$Comp
L C CC10
U 1 1 595D7004
P 6150 6900
F 0 "CC10" H 6175 7000 50  0000 L CNN
F 1 "4.7uF" H 6175 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6188 6750 50  0001 C CNN
F 3 "" H 6150 6900 50  0001 C CNN
	1    6150 6900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 595D700A
P 5850 7250
F 0 "#PWR016" H 5850 7000 50  0001 C CNN
F 1 "GND" H 5850 7100 50  0000 C CNN
F 2 "" H 5850 7250 50  0001 C CNN
F 3 "" H 5850 7250 50  0001 C CNN
	1    5850 7250
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR017
U 1 1 595D7010
P 5850 6550
F 0 "#PWR017" H 5850 6400 50  0001 C CNN
F 1 "+3V3" H 5850 6690 50  0000 C CNN
F 2 "" H 5850 6550 50  0000 C CNN
F 3 "" H 5850 6550 50  0000 C CNN
	1    5850 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 7150 6450 7150
Wire Wire Line
	5850 7050 5850 7250
Connection ~ 5850 7150
Wire Wire Line
	5550 6650 6450 6650
Wire Wire Line
	5850 6550 5850 6750
Connection ~ 5850 6650
Wire Wire Line
	5550 6650 5550 6750
Wire Wire Line
	6150 6650 6150 6750
Wire Wire Line
	6150 7150 6150 7050
Wire Wire Line
	5550 7150 5550 7050
$Comp
L CONN_01X04 J1
U 1 1 595E850B
P 900 2900
F 0 "J1" H 900 3300 50  0000 C CNN
F 1 "I2CCON" H 900 3200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 900 2900 50  0001 C CNN
F 3 "" H 900 2900 50  0000 C CNN
	1    900  2900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1100 3050 1200 3050
Wire Wire Line
	1200 3050 1200 3150
Wire Wire Line
	1100 2750 1200 2750
Wire Wire Line
	1200 2750 1200 2450
$Comp
L +3V3 #PWR018
U 1 1 595E9886
P 1200 2450
F 0 "#PWR018" H 1200 2300 50  0001 C CNN
F 1 "+3V3" H 1200 2590 50  0000 C CNN
F 2 "" H 1200 2450 50  0000 C CNN
F 3 "" H 1200 2450 50  0000 C CNN
	1    1200 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 595E98DC
P 1200 3150
F 0 "#PWR019" H 1200 2900 50  0001 C CNN
F 1 "GND" H 1200 3000 50  0000 C CNN
F 2 "" H 1200 3150 50  0001 C CNN
F 3 "" H 1200 3150 50  0001 C CNN
	1    1200 3150
	1    0    0    -1  
$EndComp
Connection ~ 1500 2850
Connection ~ 1600 2950
Text Label 2000 2850 0    60   ~ 0
STM_I2C1_SDA
Text Label 2000 2950 0    60   ~ 0
STM_I2C1_SCL
Wire Wire Line
	3750 7100 3750 7000
Wire Wire Line
	1650 7450 1650 7350
Wire Wire Line
	1650 7400 1000 7400
Wire Wire Line
	1000 7400 1000 7350
Connection ~ 1650 7400
Wire Wire Line
	2900 7100 3750 7100
$Comp
L C CC7
U 1 1 595EF7DB
P 5200 6900
F 0 "CC7" H 5225 7000 50  0000 L CNN
F 1 "1uF" H 5225 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5238 6750 50  0001 C CNN
F 3 "" H 5200 6900 50  0001 C CNN
	1    5200 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 6650 5200 6750
Connection ~ 4900 6650
Wire Wire Line
	5200 7150 5200 7050
Connection ~ 4900 7150
$Comp
L C CC11
U 1 1 595EFF8D
P 6450 6900
F 0 "CC11" H 6475 7000 50  0000 L CNN
F 1 "4.7uF" H 6475 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6488 6750 50  0001 C CNN
F 3 "" H 6450 6900 50  0001 C CNN
	1    6450 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 7150 6450 7050
Connection ~ 6150 7150
Wire Wire Line
	6450 6650 6450 6750
Connection ~ 6150 6650
Wire Wire Line
	8000 5000 8200 5000
Wire Wire Line
	8000 5100 8200 5100
Text Label 8200 5000 0    60   ~ 0
P28
Text Label 8200 5100 0    60   ~ 0
P29
Wire Wire Line
	9550 4500 9250 4500
Text Label 9250 4500 2    60   ~ 0
P28
Wire Wire Line
	10050 4500 10350 4500
Text Label 10350 4500 0    60   ~ 0
P29
$Comp
L R R4
U 1 1 5960FEA6
P 9400 1050
F 0 "R4" H 9550 1150 50  0000 C CNN
F 1 "10k" H 9550 1050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 9330 1050 50  0001 C CNN
F 3 "" H 9400 1050 50  0001 C CNN
	1    9400 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 1200 9400 1400
Connection ~ 9400 1300
$Comp
L C CC12
U 1 1 596107D5
P 9400 1550
F 0 "CC12" H 9425 1650 50  0000 L CNN
F 1 "4.7uF" H 9425 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9438 1400 50  0001 C CNN
F 3 "" H 9400 1550 50  0001 C CNN
	1    9400 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 1700 9400 1800
Wire Wire Line
	9400 900  9400 850 
$Comp
L +3V3 #PWR020
U 1 1 59611B42
P 9400 850
F 0 "#PWR020" H 9400 700 50  0001 C CNN
F 1 "+3V3" H 9400 990 50  0000 C CNN
F 2 "" H 9400 850 50  0000 C CNN
F 3 "" H 9400 850 50  0000 C CNN
	1    9400 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 2850 1100 2850
Wire Wire Line
	1100 2950 2950 2950
Wire Wire Line
	10100 1300 10200 1300
$Comp
L GND #PWR021
U 1 1 595E96AC
P 10200 1800
F 0 "#PWR021" H 10200 1550 50  0001 C CNN
F 1 "GND" H 10200 1650 50  0000 C CNN
F 2 "" H 10200 1800 50  0001 C CNN
F 3 "" H 10200 1800 50  0001 C CNN
	1    10200 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 1300 10200 1800
$EndSCHEMATC
