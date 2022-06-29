EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 4 6
Title "GeneralPurposeAlarmDevicePCB"
Date "2022-06-20"
Rev "0.0"
Comp "PublicInvention"
Comment1 "GNU Affero General Public License v3.0"
Comment2 "DrawnBy: (Forrest) Lee Erickson"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3550 4650 0    50   ~ 0
Note: Check that pin 1 is on the left when viewing the connector on layout.
$Comp
L Device:R R?
U 1 1 62B96D5B
P 5200 3950
AR Path="/62B96D5B" Ref="R?"  Part="1" 
AR Path="/62B93801/62B96D5B" Ref="R401"  Part="1" 
F 0 "R401" V 5000 3900 50  0000 C CNN
F 1 "R" V 5100 3950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5130 3950 50  0001 C CNN
F 3 "~" H 5200 3950 50  0001 C CNN
F 4 "JLCPCB" V 5200 3950 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 5200 3950 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5200 3950 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 5200 3950 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 5200 3950 50  0001 C CNN "Description"
	1    5200 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B96D66
P 5600 4200
AR Path="/62B96D66" Ref="R?"  Part="1" 
AR Path="/62B93801/62B96D66" Ref="R402"  Part="1" 
F 0 "R402" V 5400 4150 50  0000 C CNN
F 1 "R" V 5500 4200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5530 4200 50  0001 C CNN
F 3 "~" H 5600 4200 50  0001 C CNN
F 4 "JLCPCB" V 5600 4200 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 5600 4200 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5600 4200 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 5600 4200 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 5600 4200 50  0001 C CNN "Description"
	1    5600 4200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B96D71
P 6050 4450
AR Path="/62B96D71" Ref="R?"  Part="1" 
AR Path="/62B93801/62B96D71" Ref="R403"  Part="1" 
F 0 "R403" V 5850 4400 50  0000 C CNN
F 1 "R" V 5950 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5980 4450 50  0001 C CNN
F 3 "~" H 6050 4450 50  0001 C CNN
F 4 "JLCPCB" V 6050 4450 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 6050 4450 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 6050 4450 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 6050 4450 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 6050 4450 50  0001 C CNN "Description"
	1    6050 4450
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B96D7C
P 7300 4850
AR Path="/62B96D7C" Ref="R?"  Part="1" 
AR Path="/62B93801/62B96D7C" Ref="R404"  Part="1" 
F 0 "R404" V 7100 4800 50  0000 C CNN
F 1 "R" V 7200 4850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7230 4850 50  0001 C CNN
F 3 "~" H 7300 4850 50  0001 C CNN
F 4 "JLCPCB" V 7300 4850 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 7300 4850 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 7300 4850 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 7300 4850 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 7300 4850 50  0001 C CNN "Description"
	1    7300 4850
	0    1    1    0   
$EndComp
Text Notes 3800 3600 0    50   ~ 0
/* Hardware Notes Peripheral\n   SPI Line Pin in Arduino, IO setup\n  MOSI 11 or ICSP-4  Input,  ATmegaPin BP3, 17\n  MISO 12 or ICSP-1 Output, ATmegaPin BP4, 18\n  SCK 13 or ICSP-3  Input, ATmegaPin BP5, 19\n  SS 10 Input, ATmegaPin BP2, 16\n*/
$Comp
L power:GND #PWR?
U 1 1 62B96D89
P 4850 4250
AR Path="/62B96D89" Ref="#PWR?"  Part="1" 
AR Path="/62B93801/62B96D89" Ref="#PWR0401"  Part="1" 
F 0 "#PWR0401" H 4850 4000 50  0001 C CNN
F 1 "GND" H 4950 4250 50  0000 C CNN
F 2 "" H 4850 4250 50  0001 C CNN
F 3 "" H 4850 4250 50  0001 C CNN
	1    4850 4250
	1    0    0    -1  
$EndComp
Text Notes 3800 2650 0    50   ~ 0
SPI Peripherial Interface
Wire Wire Line
	4500 4250 4850 4250
Wire Wire Line
	4500 4150 5150 4150
Wire Wire Line
	5150 4150 5150 4200
Wire Wire Line
	5150 4200 5450 4200
Wire Wire Line
	4500 4350 4750 4350
Wire Wire Line
	4750 4350 4750 4450
Wire Wire Line
	4500 4450 4500 4550
Wire Wire Line
	4750 4450 5900 4450
Wire Wire Line
	4500 3950 5050 3950
Text HLabel 7750 4450 2    50   Input ~ 0
COPI
Text HLabel 7800 3850 2    50   Output ~ 0
CIPO
Text HLabel 7750 4300 2    50   Input ~ 0
SCK
Text HLabel 7750 4850 2    50   Input ~ 0
nCS
Wire Wire Line
	5750 4200 7500 4200
Wire Wire Line
	7500 4200 7500 4300
Wire Wire Line
	7500 4300 7750 4300
Wire Wire Line
	5350 3950 7500 3950
Wire Wire Line
	6200 4450 7750 4450
Wire Wire Line
	7000 4550 7000 4850
Wire Wire Line
	7000 4850 7150 4850
Wire Wire Line
	4500 4550 7000 4550
Wire Wire Line
	7450 4850 7750 4850
Wire Wire Line
	7500 3950 7500 3850
Wire Wire Line
	7500 3850 7800 3850
Wire Wire Line
	4500 4050 7800 4050
Text HLabel 7800 4050 2    50   UnSpc ~ 0
ControllerVcc
$Comp
L GPAD_SCH_LIB:RJ12_6P6C_HORZ J401
U 1 1 62D0D90D
P 4100 4250
F 0 "J401" H 4157 4907 50  0000 C CNN
F 1 "RJ12_6P6C_HORZ" H 4157 4816 50  0000 C CNN
F 2 "GeneralPurposeAlarmDevicePCB:RJ12_Amphenol_54601" V 4100 4275 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1811141146_TE-Connectivity-5555165-1_C305981.pdf" V 4100 4275 50  0001 C CNN
F 4 "JLCPCB" H 4100 4250 50  0001 C CNN "Distributor 1"
F 5 "C305981" H 4100 4250 50  0001 C CNN "Distributor 1 PN"
F 6 "Digikey" H 4100 4250 50  0001 C CNN "Distributor 2"
F 7 "A31422-ND" H 4100 4250 50  0001 C CNN "Distributor 2 PN"
F 8 "TE Connectivity" H 4100 4250 50  0001 C CNN "Manufacturer"
F 9 "Jack Modular Connector 6p6c (RJ11, RJ12, RJ14, RJ25) 90° Angle (Right) Unshielded Cat3" H 4100 4250 50  0001 C CNN "Description"
F 10 "HAND" H 4157 4725 50  0000 C CNN "AssemblyType"
F 11 "5555165-1" H 4100 4250 50  0001 C CNN "MPN"
	1    4100 4250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
