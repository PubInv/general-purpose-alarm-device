EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 5
Title "GeneralPurposeAlarmDevicePCB"
Date "2022-06-20"
Rev "0.0"
Comp "PublicInvention"
Comment1 "GNU Affero General Public License v3.0"
Comment2 "DrawnBy: (Forrest) Lee Erickson"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R?
U 1 1 62B5A2AE
P 3000 3700
F 0 "R?" H 2900 3650 50  0000 C CNN
F 1 "4K7" H 2850 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2930 3700 50  0001 C CNN
F 3 "~" H 3000 3700 50  0001 C CNN
F 4 "JLCPCB" V 3000 3700 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 3000 3700 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 3000 3700 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 3000 3700 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 3000 3700 50  0001 C CNN "Description"
	1    3000 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B5A2B4
P 3500 4200
F 0 "#PWR?" H 3500 3950 50  0001 C CNN
F 1 "GND" H 3505 4027 50  0000 C CNN
F 2 "" H 3500 4200 50  0001 C CNN
F 3 "" H 3500 4200 50  0001 C CNN
	1    3500 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A2BF
P 3500 3100
F 0 "R?" H 3400 3050 50  0000 C CNN
F 1 "330R" H 3350 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3430 3100 50  0001 C CNN
F 3 "~" H 3500 3100 50  0001 C CNN
F 4 "JLCPCB" V 3500 3100 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 3500 3100 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 3500 3100 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 3500 3100 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 3500 3100 50  0001 C CNN "Description"
	1    3500 3100
	-1   0    0    1   
$EndComp
$Comp
L dk_Transistors-Bipolar-BJT-Single:MMBT2222A-7-F Q?
U 1 1 62B5A2CE
P 3400 3950
F 0 "Q?" H 3588 4003 60  0000 L CNN
F 1 "MMBT2222A-7-F" H 3588 3897 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 3600 4150 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 3600 4250 60  0001 L CNN
F 4 "MMBT2222A-FDICT-ND" H 3600 4350 60  0001 L CNN "Digi-Key_PN"
F 5 "MMBT2222A-7-F" H 3600 4450 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 3600 4550 60  0001 L CNN "Category"
F 7 "Transistors - Bipolar (BJT) - Single" H 3600 4650 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 3600 4750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/MMBT2222A-7-F/MMBT2222A-FDICT-ND/815723" H 3600 4850 60  0001 L CNN "DK_Detail_Page"
F 10 "TRANS NPN 40V 0.6A SMD SOT23-3" H 3600 4950 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 3600 5050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3600 5150 60  0001 L CNN "Status"
	1    3400 3950
	1    0    0    -1  
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C171KRKT D?
U 1 1 62B5A2DC
P 3500 3550
F 0 "D?" V 3450 3800 60  0000 C CNN
F 1 "RED 0603" V 3600 3850 60  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 3700 3750 60  0001 L CNN
F 3 "" H 3700 3850 60  0001 L CNN
F 4 "JLCPCB" H 3500 3550 50  0001 C CNN "Distributor 1"
F 5 "C2286" H 3700 3950 60  0001 L CNN "Distributor 1 PN"
F 6 "KT-0603R" H 3700 4050 60  0001 L CNN "MPN"
F 7 "Optoelectronics" H 3700 4150 60  0001 L CNN "Category"
F 8 "LED Indication - Discrete" H 3700 4250 60  0001 L CNN "Family"
F 9 "LED RED CLEAR SMD" H 3700 4550 60  0001 L CNN "Description"
F 10 "Hubei KENTO Elec" H 3700 4650 60  0001 L CNN "Manufacturer"
F 11 "Active" H 3700 4750 60  0001 L CNN "Status"
	1    3500 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A2E7
P 4200 3700
F 0 "R?" H 4100 3650 50  0000 C CNN
F 1 "4K7" H 4050 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4130 3700 50  0001 C CNN
F 3 "~" H 4200 3700 50  0001 C CNN
F 4 "JLCPCB" V 4200 3700 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 4200 3700 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4200 3700 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 4200 3700 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 4200 3700 50  0001 C CNN "Description"
	1    4200 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B5A2ED
P 4700 4200
F 0 "#PWR?" H 4700 3950 50  0001 C CNN
F 1 "GND" H 4705 4027 50  0000 C CNN
F 2 "" H 4700 4200 50  0001 C CNN
F 3 "" H 4700 4200 50  0001 C CNN
	1    4700 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A2F8
P 4700 3100
F 0 "R?" H 4600 3050 50  0000 C CNN
F 1 "330R" H 4550 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4630 3100 50  0001 C CNN
F 3 "~" H 4700 3100 50  0001 C CNN
F 4 "JLCPCB" V 4700 3100 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 4700 3100 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4700 3100 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 4700 3100 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 4700 3100 50  0001 C CNN "Description"
	1    4700 3100
	-1   0    0    1   
$EndComp
$Comp
L dk_Transistors-Bipolar-BJT-Single:MMBT2222A-7-F Q?
U 1 1 62B5A307
P 4600 3950
F 0 "Q?" H 4788 4003 60  0000 L CNN
F 1 "MMBT2222A-7-F" H 4788 3897 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 4800 4150 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 4800 4250 60  0001 L CNN
F 4 "MMBT2222A-FDICT-ND" H 4800 4350 60  0001 L CNN "Digi-Key_PN"
F 5 "MMBT2222A-7-F" H 4800 4450 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4800 4550 60  0001 L CNN "Category"
F 7 "Transistors - Bipolar (BJT) - Single" H 4800 4650 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 4800 4750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/MMBT2222A-7-F/MMBT2222A-FDICT-ND/815723" H 4800 4850 60  0001 L CNN "DK_Detail_Page"
F 10 "TRANS NPN 40V 0.6A SMD SOT23-3" H 4800 4950 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 4800 5050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4800 5150 60  0001 L CNN "Status"
	1    4600 3950
	1    0    0    -1  
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C171KRKT D?
U 1 1 62B5A315
P 4700 3550
F 0 "D?" V 4650 3800 60  0000 C CNN
F 1 "RED 0603" V 4800 3850 60  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 4900 3750 60  0001 L CNN
F 3 "" H 4900 3850 60  0001 L CNN
F 4 "JLCPCB" H 4700 3550 50  0001 C CNN "Distributor 1"
F 5 "C2286" H 4900 3950 60  0001 L CNN "Distributor 1 PN"
F 6 "KT-0603R" H 4900 4050 60  0001 L CNN "MPN"
F 7 "Optoelectronics" H 4900 4150 60  0001 L CNN "Category"
F 8 "LED Indication - Discrete" H 4900 4250 60  0001 L CNN "Family"
F 9 "LED RED CLEAR SMD" H 4900 4550 60  0001 L CNN "Description"
F 10 "Hubei KENTO Elec" H 4900 4650 60  0001 L CNN "Manufacturer"
F 11 "Active" H 4900 4750 60  0001 L CNN "Status"
	1    4700 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A320
P 5400 3700
F 0 "R?" H 5300 3650 50  0000 C CNN
F 1 "4K7" H 5250 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5330 3700 50  0001 C CNN
F 3 "~" H 5400 3700 50  0001 C CNN
F 4 "JLCPCB" V 5400 3700 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 5400 3700 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5400 3700 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 5400 3700 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 5400 3700 50  0001 C CNN "Description"
	1    5400 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B5A326
P 5900 4200
F 0 "#PWR?" H 5900 3950 50  0001 C CNN
F 1 "GND" H 5905 4027 50  0000 C CNN
F 2 "" H 5900 4200 50  0001 C CNN
F 3 "" H 5900 4200 50  0001 C CNN
	1    5900 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A331
P 5900 3100
F 0 "R?" H 5800 3050 50  0000 C CNN
F 1 "330R" H 5750 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5830 3100 50  0001 C CNN
F 3 "~" H 5900 3100 50  0001 C CNN
F 4 "JLCPCB" V 5900 3100 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 5900 3100 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5900 3100 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 5900 3100 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 5900 3100 50  0001 C CNN "Description"
	1    5900 3100
	-1   0    0    1   
$EndComp
$Comp
L dk_Transistors-Bipolar-BJT-Single:MMBT2222A-7-F Q?
U 1 1 62B5A340
P 5800 3950
F 0 "Q?" H 5988 4003 60  0000 L CNN
F 1 "MMBT2222A-7-F" H 5988 3897 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 6000 4150 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 6000 4250 60  0001 L CNN
F 4 "MMBT2222A-FDICT-ND" H 6000 4350 60  0001 L CNN "Digi-Key_PN"
F 5 "MMBT2222A-7-F" H 6000 4450 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 6000 4550 60  0001 L CNN "Category"
F 7 "Transistors - Bipolar (BJT) - Single" H 6000 4650 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 6000 4750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/MMBT2222A-7-F/MMBT2222A-FDICT-ND/815723" H 6000 4850 60  0001 L CNN "DK_Detail_Page"
F 10 "TRANS NPN 40V 0.6A SMD SOT23-3" H 6000 4950 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 6000 5050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6000 5150 60  0001 L CNN "Status"
	1    5800 3950
	1    0    0    -1  
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C171KRKT D?
U 1 1 62B5A34E
P 5900 3550
F 0 "D?" V 5850 3800 60  0000 C CNN
F 1 "RED 0603" V 6000 3850 60  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6100 3750 60  0001 L CNN
F 3 "" H 6100 3850 60  0001 L CNN
F 4 "JLCPCB" H 5900 3550 50  0001 C CNN "Distributor 1"
F 5 "C2286" H 6100 3950 60  0001 L CNN "Distributor 1 PN"
F 6 "KT-0603R" H 6100 4050 60  0001 L CNN "MPN"
F 7 "Optoelectronics" H 6100 4150 60  0001 L CNN "Category"
F 8 "LED Indication - Discrete" H 6100 4250 60  0001 L CNN "Family"
F 9 "LED RED CLEAR SMD" H 6100 4550 60  0001 L CNN "Description"
F 10 "Hubei KENTO Elec" H 6100 4650 60  0001 L CNN "Manufacturer"
F 11 "Active" H 6100 4750 60  0001 L CNN "Status"
	1    5900 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A359
P 6600 3700
F 0 "R?" H 6500 3650 50  0000 C CNN
F 1 "4K7" H 6450 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6530 3700 50  0001 C CNN
F 3 "~" H 6600 3700 50  0001 C CNN
F 4 "JLCPCB" V 6600 3700 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 6600 3700 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 6600 3700 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 6600 3700 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 6600 3700 50  0001 C CNN "Description"
	1    6600 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B5A35F
P 7100 4200
F 0 "#PWR?" H 7100 3950 50  0001 C CNN
F 1 "GND" H 7105 4027 50  0000 C CNN
F 2 "" H 7100 4200 50  0001 C CNN
F 3 "" H 7100 4200 50  0001 C CNN
	1    7100 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A36A
P 7100 3100
F 0 "R?" H 7000 3050 50  0000 C CNN
F 1 "330R" H 6950 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7030 3100 50  0001 C CNN
F 3 "~" H 7100 3100 50  0001 C CNN
F 4 "JLCPCB" V 7100 3100 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 7100 3100 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 7100 3100 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 7100 3100 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 7100 3100 50  0001 C CNN "Description"
	1    7100 3100
	-1   0    0    1   
$EndComp
$Comp
L dk_Transistors-Bipolar-BJT-Single:MMBT2222A-7-F Q?
U 1 1 62B5A379
P 7000 3950
F 0 "Q?" H 7188 4003 60  0000 L CNN
F 1 "MMBT2222A-7-F" H 7188 3897 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 7200 4150 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 7200 4250 60  0001 L CNN
F 4 "MMBT2222A-FDICT-ND" H 7200 4350 60  0001 L CNN "Digi-Key_PN"
F 5 "MMBT2222A-7-F" H 7200 4450 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 7200 4550 60  0001 L CNN "Category"
F 7 "Transistors - Bipolar (BJT) - Single" H 7200 4650 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 7200 4750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/MMBT2222A-7-F/MMBT2222A-FDICT-ND/815723" H 7200 4850 60  0001 L CNN "DK_Detail_Page"
F 10 "TRANS NPN 40V 0.6A SMD SOT23-3" H 7200 4950 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 7200 5050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7200 5150 60  0001 L CNN "Status"
	1    7000 3950
	1    0    0    -1  
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C171KRKT D?
U 1 1 62B5A387
P 7100 3550
F 0 "D?" V 7050 3800 60  0000 C CNN
F 1 "RED 0603" V 7200 3850 60  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 7300 3750 60  0001 L CNN
F 3 "" H 7300 3850 60  0001 L CNN
F 4 "JLCPCB" H 7100 3550 50  0001 C CNN "Distributor 1"
F 5 "C2286" H 7300 3950 60  0001 L CNN "Distributor 1 PN"
F 6 "KT-0603R" H 7300 4050 60  0001 L CNN "MPN"
F 7 "Optoelectronics" H 7300 4150 60  0001 L CNN "Category"
F 8 "LED Indication - Discrete" H 7300 4250 60  0001 L CNN "Family"
F 9 "LED RED CLEAR SMD" H 7300 4550 60  0001 L CNN "Description"
F 10 "Hubei KENTO Elec" H 7300 4650 60  0001 L CNN "Manufacturer"
F 11 "Active" H 7300 4750 60  0001 L CNN "Status"
	1    7100 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A392
P 7800 3700
F 0 "R?" H 7700 3650 50  0000 C CNN
F 1 "4K7" H 7650 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7730 3700 50  0001 C CNN
F 3 "~" H 7800 3700 50  0001 C CNN
F 4 "JLCPCB" V 7800 3700 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 7800 3700 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 7800 3700 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 7800 3700 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 7800 3700 50  0001 C CNN "Description"
	1    7800 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B5A398
P 8300 4200
F 0 "#PWR?" H 8300 3950 50  0001 C CNN
F 1 "GND" H 8305 4027 50  0000 C CNN
F 2 "" H 8300 4200 50  0001 C CNN
F 3 "" H 8300 4200 50  0001 C CNN
	1    8300 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B5A3A3
P 8300 3100
F 0 "R?" H 8200 3050 50  0000 C CNN
F 1 "330R" H 8150 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8230 3100 50  0001 C CNN
F 3 "~" H 8300 3100 50  0001 C CNN
F 4 "JLCPCB" V 8300 3100 50  0001 C CNN "Distributor 1"
F 5 "C269711" V 8300 3100 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 8300 3100 50  0001 C CNN "Manufacturer"
F 7 "RMC06033301%N" V 8300 3100 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 330Ω 0603 Chip Resistor - Surface Mount ROHS" H 8300 3100 50  0001 C CNN "Description"
	1    8300 3100
	-1   0    0    1   
$EndComp
$Comp
L dk_Transistors-Bipolar-BJT-Single:MMBT2222A-7-F Q?
U 1 1 62B5A3B2
P 8200 3950
F 0 "Q?" H 8388 4003 60  0000 L CNN
F 1 "MMBT2222A-7-F" H 8388 3897 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 8400 4150 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 8400 4250 60  0001 L CNN
F 4 "MMBT2222A-FDICT-ND" H 8400 4350 60  0001 L CNN "Digi-Key_PN"
F 5 "MMBT2222A-7-F" H 8400 4450 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 8400 4550 60  0001 L CNN "Category"
F 7 "Transistors - Bipolar (BJT) - Single" H 8400 4650 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30041.pdf" H 8400 4750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/MMBT2222A-7-F/MMBT2222A-FDICT-ND/815723" H 8400 4850 60  0001 L CNN "DK_Detail_Page"
F 10 "TRANS NPN 40V 0.6A SMD SOT23-3" H 8400 4950 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 8400 5050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 8400 5150 60  0001 L CNN "Status"
	1    8200 3950
	1    0    0    -1  
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C171KRKT D?
U 1 1 62B5A3C0
P 8300 3550
F 0 "D?" V 8250 3800 60  0000 C CNN
F 1 "RED 0603" V 8400 3850 60  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 8500 3750 60  0001 L CNN
F 3 "" H 8500 3850 60  0001 L CNN
F 4 "JLCPCB" H 8300 3550 50  0001 C CNN "Distributor 1"
F 5 "C2286" H 8500 3950 60  0001 L CNN "Distributor 1 PN"
F 6 "KT-0603R" H 8500 4050 60  0001 L CNN "MPN"
F 7 "Optoelectronics" H 8500 4150 60  0001 L CNN "Category"
F 8 "LED Indication - Discrete" H 8500 4250 60  0001 L CNN "Family"
F 9 "LED RED CLEAR SMD" H 8500 4550 60  0001 L CNN "Description"
F 10 "Hubei KENTO Elec" H 8500 4650 60  0001 L CNN "Manufacturer"
F 11 "Active" H 8500 4750 60  0001 L CNN "Status"
	1    8300 3550
	0    1    1    0   
$EndComp
Text Notes 5050 2750 0    50   ~ 0
Alarm lights, 5 Levels
$EndSCHEMATC
