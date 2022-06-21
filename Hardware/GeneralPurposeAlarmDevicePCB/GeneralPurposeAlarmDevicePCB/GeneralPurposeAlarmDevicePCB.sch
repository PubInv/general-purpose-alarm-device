EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
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
L GeneralPurposeAlarmDevicePCB-rescue:LCD_20x4_Character-GPAD_SCH_LIB U?
U 1 1 62B14E53
P 8650 2000
F 0 "U?" H 8300 3150 50  0000 C CNN
F 1 "LCD_20x4_Character" H 8650 3050 50  0000 C CNN
F 2 "Display:NHD-0420H1Z" H 8650 1100 50  0001 C CNN
F 3 "http://www.newhavendisplay.com/specs/NHD-0420H1Z-FSW-GBW-33V3.pdf" H 8750 1900 50  0001 C CNN
F 4 "Aliexpress" H 7570 1310 50  0001 C CNN "Distributor 1"
F 5 "https://www.aliexpress.com/item/3256803213374992.html" H 8550 1210 50  0001 C CNN "Distributor 1 PN"
F 6 "Amazon" H 7530 1090 50  0001 C CNN "Distributor 2"
F 7 "https://www.amazon.com/GeeekPi-Interface-Adapter-Backlight-Raspberry/dp/B07QLRD3TM/ref=sr_1_2" H 9440 1000 50  0001 C CNN "Distributor 2 PN"
	1    8650 2000
	1    0    0    -1  
$EndComp
$Comp
L GPAD_SCH_LIB:PI_ATMEGA328P-AU U?
U 1 1 62B38BF8
P 3750 4850
F 0 "U?" H 3350 6850 60  0000 C CNN
F 1 "PI_ATMEGA328P-AU" H 3750 6750 60  0000 C CNN
F 2 "digikey-footprints:TQFP-32_7x7mm" H 4040 5350 60  0001 L CNN
F 3 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 4040 5450 60  0001 L CNN
F 4 "DigiKey" H 3750 3149 50  0001 C CNN "Distributor 1"
F 5 "ATMEGA328P-AU-ND" H 3750 3050 60  0001 C CNN "Distributor 1 PN"
F 6 "ATMEGA328P-AU" H 4040 5650 60  0001 L CNN "MPN"
F 7 "Integrated Circuits (ICs)" H 4040 5750 60  0001 L CNN "Category"
F 8 "Embedded - Microcontrollers" H 4040 5850 60  0001 L CNN "Family"
F 9 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 4040 5950 60  0001 L CNN "DK_Datasheet_Link"
F 10 "/product-detail/en/microchip-technology/ATMEGA328P-AU/ATMEGA328P-AU-ND/1832260" H -2360 5770 60  0001 L CNN "DK_Detail_Page"
F 11 "IC MCU 8BIT 32KB FLASH 32TQFP" H 4040 6150 60  0001 L CNN "Description"
F 12 "Microchip Technology" H 4040 6250 60  0001 L CNN "Manufacturer"
F 13 "Active" H 4040 6350 60  0001 L CNN "Status"
	1    3750 4850
	1    0    0    -1  
$EndComp
$Comp
L dk_Crystals:NX3225GD-8MHZ-STD-CRA-3 XTAL?
U 1 1 62B3A927
P 1450 4300
F 0 "XTAL?" H 1450 4540 50  0000 C CNN
F 1 "16MHZ 20PF HC-49S/SMD" H 1450 4449 50  0000 C CNN
F 2 "" H 1650 4500 60  0001 L CNN
F 3 "1811061718_TAE-Zhejiang-Abel-Elec-TAXM16M2GLFBET2T_C111377.pdf" H 1650 4600 60  0001 L CNN
F 4 "JLCPCB" H 1450 4300 50  0001 C CNN "Distributor 1"
F 5 "TAXM16M2GLFBET2T" H 1650 4700 60  0001 L CNN "Distributor1 PN"
F 6 "TAXM16M2GLFBET2T" H 1650 4800 60  0001 L CNN "MPN"
F 7 "Crystals, Oscillators, Resonators" H 1650 4900 60  0001 L CNN "Category"
F 8 "Crystals" H 1650 5000 60  0001 L CNN "Family"
F 9 "" H 1650 5100 60  0001 L CNN "DK_Datasheet_Link"
F 10 "" H 1650 5200 60  0001 L CNN "DK_Detail_Page"
F 11 "CRYSTAL 16.0000MHZ 20PF HC49SSMD" H 1650 5300 60  0001 L CNN "Description"
F 12 "TAE" H 1650 5400 60  0001 L CNN "Manufacturer"
F 13 "Active" H 1650 5500 60  0001 L CNN "Status"
	1    1450 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62B45335
P 950 4650
F 0 "C?" H 1065 4696 50  0000 L CNN
F 1 "39pF" H 1065 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 988 4500 50  0001 C CNN
F 3 "~" H 950 4650 50  0001 C CNN
	1    950  4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62B46140
P 1800 4650
F 0 "C?" H 1915 4696 50  0000 L CNN
F 1 "39pF" H 1915 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 1838 4500 50  0001 C CNN
F 3 "~" H 1800 4650 50  0001 C CNN
	1    1800 4650
	1    0    0    -1  
$EndComp
Text Notes 600  4700 0    50   ~ 0
Note: Check pad sized for 0603 and 0603HandSolder
$Comp
L GPAD_SCH_LIB:PJ-202A J?
U 1 1 62B49032
P 950 1000
F 0 "J?" H 883 1225 50  0000 C CNN
F 1 "PJ-202A" H 883 1134 50  0000 C CNN
F 2 "digikey-footprints:Barrel_Jack_5.5mmODx2.1mmID_PJ-202A" H 1150 1200 60  0001 L CNN
F 3 "https://www.cui.com/product/resource/digikeypdf/pj-202a.pdf" H 1150 1300 60  0001 L CNN
F 4 "CP-202A-ND" H 1150 1400 60  0001 L CNN "Digi-Key_PN"
F 5 "PJ-202A" H 1150 1500 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 1150 1600 60  0001 L CNN "Category"
F 7 "Barrel - Power Connectors" H 1150 1700 60  0001 L CNN "Family"
F 8 "https://www.cui.com/product/resource/digikeypdf/pj-202a.pdf" H 1150 1800 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cui-inc/PJ-202A/CP-202A-ND/252007" H 1150 1900 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN PWR JACK 2X5.5MM KINKED PIN" H 1150 2000 60  0001 L CNN "Description"
F 11 "CUI Inc." H 1150 2100 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1150 2200 60  0001 L CNN "Status"
	1    950  1000
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 62B4A83F
P 1600 1000
F 0 "D?" H 1600 783 50  0000 C CNN
F 1 "Schottky 2A" H 1600 874 50  0000 C CNN
F 2 "Diode_SMD:D_SMB" H 1600 1000 50  0001 C CNN
F 3 "~" H 1600 1000 50  0001 C CNN
F 4 "JLCPCB" H 1600 1000 50  0001 C CNN "Distributor 1"
F 5 "C14996" H 1600 1000 50  0001 C CNN "Distirbutor 1 PN"
F 6 "SS210" H 1600 1000 50  0001 C CNN "MPN"
F 7 "MDD（Microdiode Electronics）" H 1600 1000 50  0001 C CNN "Manufacturer"
	1    1600 1000
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 62B4BD4B
P 1300 1450
F 0 "C?" H 1415 1496 50  0000 L CNN
F 1 "39pF" H 1415 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 1338 1300 50  0001 C CNN
F 3 "~" H 1300 1450 50  0001 C CNN
	1    1300 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B4D791
P 1300 1700
F 0 "#PWR?" H 1300 1450 50  0001 C CNN
F 1 "GND" H 1305 1527 50  0000 C CNN
F 2 "" H 1300 1700 50  0001 C CNN
F 3 "" H 1300 1700 50  0001 C CNN
	1    1300 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B4DABB
P 950 4900
F 0 "#PWR?" H 950 4650 50  0001 C CNN
F 1 "GND" H 955 4727 50  0000 C CNN
F 2 "" H 950 4900 50  0001 C CNN
F 3 "" H 950 4900 50  0001 C CNN
	1    950  4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B4E34C
P 1800 4950
F 0 "#PWR?" H 1800 4700 50  0001 C CNN
F 1 "GND" H 1805 4777 50  0000 C CNN
F 2 "" H 1800 4950 50  0001 C CNN
F 3 "" H 1800 4950 50  0001 C CNN
	1    1800 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B4F12F
P 3750 6300
F 0 "#PWR?" H 3750 6050 50  0001 C CNN
F 1 "GND" H 3755 6127 50  0000 C CNN
F 2 "" H 3750 6300 50  0001 C CNN
F 3 "" H 3750 6300 50  0001 C CNN
	1    3750 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B5068A
P 8650 2900
F 0 "#PWR?" H 8650 2650 50  0001 C CNN
F 1 "GND" H 8655 2727 50  0000 C CNN
F 2 "" H 8650 2900 50  0001 C CNN
F 3 "" H 8650 2900 50  0001 C CNN
	1    8650 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B51224
P 5450 4050
F 0 "R?" V 5243 4050 50  0000 C CNN
F 1 "330R" V 5334 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5380 4050 50  0001 C CNN
F 3 "~" H 5450 4050 50  0001 C CNN
F 4 "JLCPCB" V 5450 4050 50  0001 C CNN "Distributor 1"
F 5 "C325611" V 5450 4050 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5450 4050 50  0001 C CNN "Manufacturer"
F 7 "RMC06033001%N" V 5450 4050 50  0001 C CNN "MPN"
	1    5450 4050
	0    1    1    0   
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C171KRKT D?
U 1 1 62B52665
P 6150 4050
F 0 "D?" H 6100 4387 60  0000 C CNN
F 1 "RED 0603" H 6100 4281 60  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6350 4250 60  0001 L CNN
F 3 "" H 6350 4350 60  0001 L CNN
F 4 "JLCPCB" H 6150 4050 50  0001 C CNN "Distributor 1"
F 5 "C2286" H 6350 4450 60  0001 L CNN "Distributor 1 PN"
F 6 "KT-0603R" H 6350 4550 60  0001 L CNN "MPN"
F 7 "Optoelectronics" H 6350 4650 60  0001 L CNN "Category"
F 8 "LED Indication - Discrete" H 6350 4750 60  0001 L CNN "Family"
F 9 "LED RED CLEAR SMD" H 6350 5050 60  0001 L CNN "Description"
F 10 "Hubei KENTO Elec" H 6350 5150 60  0001 L CNN "Manufacturer"
F 11 "Active" H 6350 5250 60  0001 L CNN "Status"
	1    6150 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B53159
P 6500 4050
F 0 "#PWR?" H 6500 3800 50  0001 C CNN
F 1 "GND" H 6505 3877 50  0000 C CNN
F 2 "" H 6500 4050 50  0001 C CNN
F 3 "" H 6500 4050 50  0001 C CNN
	1    6500 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 62B5ACAD
P 2300 1300
F 0 "C?" H 2418 1346 50  0000 L CNN
F 1 "47uF 16V" H 2418 1255 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_5x5.4" H 2338 1150 50  0001 C CNN
F 3 "~" H 2300 1300 50  0001 C CNN
F 4 "JLCPCB" H 2300 1300 50  0001 C CNN "Distributor 1"
F 5 "C2895272" H 2300 1300 50  0001 C CNN "Distributor 1 PN"
F 6 "KNSCHA" H 2300 1300 50  0001 C CNN "Manufacturer"
F 7 "RVT47UF16V67RV0019" H 2300 1300 50  0001 C CNN "MPN"
	1    2300 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 62B5B741
P 4450 1200
F 0 "C?" H 4568 1246 50  0000 L CNN
F 1 "47uF 16V" H 4568 1155 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_5x5.4" H 4488 1050 50  0001 C CNN
F 3 "~" H 4450 1200 50  0001 C CNN
F 4 "JLCPCB" H 4450 1200 50  0001 C CNN "Distributor 1"
F 5 "C2895272" H 4450 1200 50  0001 C CNN "Distributor 1 PN"
F 6 "KNSCHA" H 4450 1200 50  0001 C CNN "Manufacturer"
F 7 "RVT47UF16V67RV0019" H 4450 1200 50  0001 C CNN "MPN"
	1    4450 1200
	1    0    0    -1  
$EndComp
$Comp
L dk_PMIC-Voltage-Regulators-Linear:NCP1117ST50T3G U?
U 1 1 62B5C195
P 3200 1000
F 0 "U?" H 3250 1287 60  0000 C CNN
F 1 "NCP1117ST50T3G" H 3250 1181 60  0000 C CNN
F 2 "digikey-footprints:SOT-223" H 3400 1200 60  0001 L CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCP1117-D.PDF" H 3400 1300 60  0001 L CNN
F 4 "NCP1117ST50T3GOSCT-ND" H 3400 1400 60  0001 L CNN "Digi-Key_PN"
F 5 "NCP1117ST50T3G" H 3400 1500 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 3400 1600 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 3400 1700 60  0001 L CNN "Family"
F 8 "https://www.onsemi.com/pub/Collateral/NCP1117-D.PDF" H 3400 1800 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/on-semiconductor/NCP1117ST50T3G/NCP1117ST50T3GOSCT-ND/1967217" H 3400 1900 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 5V 1A SOT223" H 3400 2000 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 3400 2100 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3400 2200 60  0001 L CNN "Status"
F 13 "JLCPCB" H 3200 1000 50  0001 C CNN "Distributor 1"
F 14 "C17314" H 3200 1000 50  0001 C CNN "Distributor 1 PN"
F 15 "" H 3200 1000 50  0001 C CNN "Field15"
	1    3200 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62B5D253
P 3900 1200
F 0 "C?" H 4015 1246 50  0000 L CNN
F 1 "100nF" H 4015 1155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3938 1050 50  0001 C CNN
F 3 "~" H 3900 1200 50  0001 C CNN
F 4 "JLCPCB" H 3900 1200 50  0001 C CNN "Distributor 1"
F 5 "C14663" H 3900 1200 50  0001 C CNN "Distributor 1 PN"
F 6 "YAGEO" H 3900 1200 50  0001 C CNN "Manufacturier"
F 7 "CC0603KRX7R9BB104" H 3900 1200 50  0001 C CNN "MPN"
F 8 "50V 100nF X7R ±10% 0603 Multilayer Ceramic Capacitors MLCC - SMD/SMT ROHS" H 3900 1200 50  0001 C CNN "Description"
	1    3900 1200
	1    0    0    -1  
$EndComp
$Comp
L GPAD_SCH_LIB:CP C?
U 1 1 62B6399A
P 9350 1400
F 0 "C?" H 9468 1446 50  0000 L CNN
F 1 "CP" H 9468 1355 50  0000 L CNN
F 2 "" H 9388 1250 50  0001 C CNN
F 3 "~" H 9350 1400 50  0001 C CNN
	1    9350 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B1C88A
P 2300 1550
F 0 "#PWR?" H 2300 1300 50  0001 C CNN
F 1 "GND" H 2305 1377 50  0000 C CNN
F 2 "" H 2300 1550 50  0001 C CNN
F 3 "" H 2300 1550 50  0001 C CNN
	1    2300 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B1CDA3
P 3900 1450
F 0 "#PWR?" H 3900 1200 50  0001 C CNN
F 1 "GND" H 3905 1277 50  0000 C CNN
F 2 "" H 3900 1450 50  0001 C CNN
F 3 "" H 3900 1450 50  0001 C CNN
	1    3900 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B1D284
P 4450 1400
F 0 "#PWR?" H 4450 1150 50  0001 C CNN
F 1 "GND" H 4455 1227 50  0000 C CNN
F 2 "" H 4450 1400 50  0001 C CNN
F 3 "" H 4450 1400 50  0001 C CNN
	1    4450 1400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
