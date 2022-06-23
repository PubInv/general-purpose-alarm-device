EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 5
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
U 1 1 62B90F17
P 7300 3050
AR Path="/62B90F17" Ref="U?"  Part="1" 
AR Path="/62B871EE/62B90F17" Ref="U?"  Part="1" 
F 0 "U?" H 6950 4200 50  0000 C CNN
F 1 "LCD_20x4_Character" H 7300 4100 50  0000 C CNN
F 2 "Display:NHD-0420H1Z" H 7300 2150 50  0001 C CNN
F 3 "http://www.newhavendisplay.com/specs/NHD-0420H1Z-FSW-GBW-33V3.pdf" H 7400 2950 50  0001 C CNN
F 4 "Aliexpress" H 6220 2360 50  0001 C CNN "Distributor 1"
F 5 "https://www.aliexpress.com/item/3256803213374992.html" H 7200 2260 50  0001 C CNN "Distributor 1 PN"
F 6 "Amazon" H 6180 2140 50  0001 C CNN "Distributor 2"
F 7 "https://www.amazon.com/GeeekPi-Interface-Adapter-Backlight-Raspberry/dp/B07QLRD3TM/ref=sr_1_2" H 8090 2050 50  0001 C CNN "Distributor 2 PN"
	1    7300 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B90F1D
P 7300 3950
AR Path="/62B90F1D" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B90F1D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7300 3700 50  0001 C CNN
F 1 "GND" H 7305 3777 50  0000 C CNN
F 2 "" H 7300 3950 50  0001 C CNN
F 3 "" H 7300 3950 50  0001 C CNN
	1    7300 3950
	1    0    0    -1  
$EndComp
$Comp
L Interface_Expansion:PCF8574A U?
U 1 1 62B90F36
P 6150 3350
AR Path="/62B90F36" Ref="U?"  Part="1" 
AR Path="/62B871EE/62B90F36" Ref="U?"  Part="1" 
F 0 "U?" H 6150 4231 50  0000 C CNN
F 1 "PCF8574AT" H 6150 4140 50  0000 C CNN
F 2 "Package_SO:SOIC-16W_5.3x10.2mm_P1.27mm" H 6150 3350 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PCF8574_PCF8574A.pdf" H 6150 3350 50  0001 C CNN
F 4 "JLCPCB" H 6150 3350 50  0001 C CNN "Distributor 1"
F 5 "C83193" H 6150 3350 50  0001 C CNN "Distributor 1 PN"
F 6 "NXP Semicon" H 6150 3350 50  0001 C CNN "Manufacturier"
F 7 "Remote 8-bit I/O expander for I2C-bus with interrupt" H 6150 3350 50  0001 C CNN "Descirption"
F 8 "PCF8574AT/3,512" H 6150 3350 50  0001 C CNN "MPN"
	1    6150 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B90F41
P 4250 2500
AR Path="/62B90F41" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90F41" Ref="R?"  Part="1" 
F 0 "R?" H 4150 2450 50  0000 C CNN
F 1 "4K7" H 4100 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4180 2500 50  0001 C CNN
F 3 "~" H 4250 2500 50  0001 C CNN
F 4 "JLCPCB" V 4250 2500 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 4250 2500 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4250 2500 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 4250 2500 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 4250 2500 50  0001 C CNN "Description"
	1    4250 2500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62B90F4C
P 4600 2500
AR Path="/62B90F4C" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90F4C" Ref="R?"  Part="1" 
F 0 "R?" H 4500 2450 50  0000 C CNN
F 1 "1K" H 4450 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4530 2500 50  0001 C CNN
F 3 "~" H 4600 2500 50  0001 C CNN
F 4 "JLCPCB" V 4600 2500 50  0001 C CNN "Distributor 1"
F 5 "C269704" V 4600 2500 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4600 2500 50  0001 C CNN "Manufacturer"
F 7 "RMC06031K1%N" V 4600 2500 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 1kΩ 0603 Chip Resistor - Surface Mount ROHS" H 4600 2500 50  0001 C CNN "Description"
	1    4600 2500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62B90F83
P 4950 2500
AR Path="/62B90F83" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90F83" Ref="R?"  Part="1" 
F 0 "R?" H 4850 2450 50  0000 C CNN
F 1 "1K" H 4800 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4880 2500 50  0001 C CNN
F 3 "~" H 4950 2500 50  0001 C CNN
F 4 "JLCPCB" V 4950 2500 50  0001 C CNN "Distributor 1"
F 5 "C269704" V 4950 2500 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4950 2500 50  0001 C CNN "Manufacturer"
F 7 "RMC06031K1%N" V 4950 2500 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 1kΩ 0603 Chip Resistor - Surface Mount ROHS" H 4950 2500 50  0001 C CNN "Description"
	1    4950 2500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62B90F8E
P 5250 2500
AR Path="/62B90F8E" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90F8E" Ref="R?"  Part="1" 
F 0 "R?" H 5150 2450 50  0000 C CNN
F 1 "1K" H 5100 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 2500 50  0001 C CNN
F 3 "~" H 5250 2500 50  0001 C CNN
F 4 "JLCPCB" V 5250 2500 50  0001 C CNN "Distributor 1"
F 5 "C269704" V 5250 2500 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5250 2500 50  0001 C CNN "Manufacturer"
F 7 "RMC06031K1%N" V 5250 2500 50  0001 C CNN "MPN"
F 8 "0.1W ±1% 1kΩ 0603 Chip Resistor - Surface Mount ROHS" H 5250 2500 50  0001 C CNN "Description"
	1    5250 2500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62B90F99
P 3850 2500
AR Path="/62B90F99" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90F99" Ref="R?"  Part="1" 
F 0 "R?" H 3750 2450 50  0000 C CNN
F 1 "4K7" H 3700 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3780 2500 50  0001 C CNN
F 3 "~" H 3850 2500 50  0001 C CNN
F 4 "JLCPCB" V 3850 2500 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 3850 2500 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 3850 2500 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 3850 2500 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 3850 2500 50  0001 C CNN "Description"
	1    3850 2500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62B90FA4
P 3500 2500
AR Path="/62B90FA4" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90FA4" Ref="R?"  Part="1" 
F 0 "R?" H 3400 2450 50  0000 C CNN
F 1 "4K7" H 3350 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3430 2500 50  0001 C CNN
F 3 "~" H 3500 2500 50  0001 C CNN
F 4 "JLCPCB" V 3500 2500 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 3500 2500 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 3500 2500 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 3500 2500 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 3500 2500 50  0001 C CNN "Description"
	1    3500 2500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B90FAA
P 6150 4150
AR Path="/62B90FAA" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B90FAA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6150 3900 50  0001 C CNN
F 1 "GND" H 6155 3977 50  0000 C CNN
F 2 "" H 6150 4150 50  0001 C CNN
F 3 "" H 6150 4150 50  0001 C CNN
	1    6150 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B90FB0
P 8500 1950
AR Path="/62B90FB0" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B90FB0" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8500 1700 50  0001 C CNN
F 1 "GND" H 8505 1777 50  0000 C CNN
F 2 "" H 8500 1950 50  0001 C CNN
F 3 "" H 8500 1950 50  0001 C CNN
	1    8500 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B90FBB
P 7450 1600
AR Path="/62B90FBB" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90FBB" Ref="R?"  Part="1" 
F 0 "R?" V 7250 1550 50  0000 C CNN
F 1 "1R0" V 7350 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7380 1600 50  0001 C CNN
F 3 "~" H 7450 1600 50  0001 C CNN
F 4 "JLCPCB" V 7450 1600 50  0001 C CNN "Distributor 1"
F 5 "C269434" V 7450 1600 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 7450 1600 50  0001 C CNN "Manufacturer"
F 7 "RMC060315%N" V 7450 1600 50  0001 C CNN "MPN"
F 8 "0.1W ±5% 1Ω 0603 Chip Resistor - Surface Mount ROHS" H 7450 1600 50  0001 C CNN "Description"
	1    7450 1600
	0    1    1    0   
$EndComp
$Comp
L Device:CP C?
U 1 1 62B90FC5
P 8500 1750
AR Path="/62B90FC5" Ref="C?"  Part="1" 
AR Path="/62B871EE/62B90FC5" Ref="C?"  Part="1" 
F 0 "C?" H 8618 1796 50  0000 L CNN
F 1 "47uF 16V" H 8618 1705 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_5x5.4" H 8538 1600 50  0001 C CNN
F 3 "~" H 8500 1750 50  0001 C CNN
F 4 "JLCPCB" H 8500 1750 50  0001 C CNN "Distributor 1"
F 5 "C2895272" H 8500 1750 50  0001 C CNN "Distributor 1 PN"
F 6 "KNSCHA" H 8500 1750 50  0001 C CNN "Manufacturer"
F 7 "RVT47UF16V67RV0019" H 8500 1750 50  0001 C CNN "MPN"
	1    8500 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62B90FD0
P 8000 1750
AR Path="/62B90FD0" Ref="C?"  Part="1" 
AR Path="/62B871EE/62B90FD0" Ref="C?"  Part="1" 
F 0 "C?" H 8115 1796 50  0000 L CNN
F 1 "100nF" H 8115 1705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 8038 1600 50  0001 C CNN
F 3 "~" H 8000 1750 50  0001 C CNN
F 4 "JLCPCB" H 8000 1750 50  0001 C CNN "Distributor 1"
F 5 "C14663" H 8000 1750 50  0001 C CNN "Distributor 1 PN"
F 6 "YAGEO" H 8000 1750 50  0001 C CNN "Manufacturier"
F 7 "CC0603KRX7R9BB104" H 8000 1750 50  0001 C CNN "MPN"
F 8 "50V 100nF X7R ±10% 0603 Multilayer Ceramic Capacitors MLCC - SMD/SMT ROHS" H 8000 1750 50  0001 C CNN "Description"
	1    8000 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B90FD6
P 8000 1950
AR Path="/62B90FD6" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B90FD6" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8000 1700 50  0001 C CNN
F 1 "GND" H 8005 1777 50  0000 C CNN
F 2 "" H 8000 1950 50  0001 C CNN
F 3 "" H 8000 1950 50  0001 C CNN
	1    8000 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B90FDC
P 8700 4400
AR Path="/62B90FDC" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B90FDC" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8700 4150 50  0001 C CNN
F 1 "GND" H 8705 4227 50  0000 C CNN
F 2 "" H 8700 4400 50  0001 C CNN
F 3 "" H 8700 4400 50  0001 C CNN
	1    8700 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62B90FE7
P 8000 3950
AR Path="/62B90FE7" Ref="R?"  Part="1" 
AR Path="/62B871EE/62B90FE7" Ref="R?"  Part="1" 
F 0 "R?" H 7900 3900 50  0000 C CNN
F 1 "4K7" H 7850 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7930 3950 50  0001 C CNN
F 3 "~" H 8000 3950 50  0001 C CNN
F 4 "JLCPCB" V 8000 3950 50  0001 C CNN "Distributor 1"
F 5 "C269713" V 8000 3950 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 8000 3950 50  0001 C CNN "Manufacturer"
F 7 "RMC 0603 4K7 F N" V 8000 3950 50  0001 C CNN "MPN"
F 8 "1W ±1% 4.7kΩ 0603 Chip Resistor - Surface Mount ROHS" H 8000 3950 50  0001 C CNN "Description"
	1    8000 3950
	-1   0    0    1   
$EndComp
$Comp
L Transistor_FET:BSS138 Q?
U 1 1 62B90FF3
P 8600 4100
AR Path="/62B90FF3" Ref="Q?"  Part="1" 
AR Path="/62B871EE/62B90FF3" Ref="Q?"  Part="1" 
F 0 "Q?" H 8804 4146 50  0000 L CNN
F 1 "BSS138" H 8804 4055 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8800 4025 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BSS138-D.PDF" H 8600 4100 50  0001 L CNN
F 4 "N-Channel Enhancement Mode Field Effect Transistor" H 8600 4100 50  0001 C CNN "Description"
F 5 "JLCPCB" H 8600 4100 50  0001 C CNN "Distirbutor 1"
F 6 "C400505" H 8600 4100 50  0001 C CNN "Distributor 1 PN"
F 7 "" H 8600 4100 50  0001 C CNN "Field7"
F 8 "Yangzhou Yangjie Electronic Technology Co., Ltd" H 8600 4100 50  0001 C CNN "Manufacturier"
F 9 "BSS138" H 8600 4100 50  0001 C CNN "MPN"
	1    8600 4100
	1    0    0    -1  
$EndComp
Text Notes 6100 5500 0    50   ~ 0
Backlight transistor gate(base) to PCF8547 pin 7 P3.\nIf add base resistor can use MMBT2222 for transistor.
$Comp
L power:+5V #PWR?
U 1 1 62B90FFA
P 7100 1600
AR Path="/62B90FFA" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B90FFA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7100 1450 50  0001 C CNN
F 1 "+5V" H 7115 1773 50  0000 C CNN
F 2 "" H 7100 1600 50  0001 C CNN
F 3 "" H 7100 1600 50  0001 C CNN
	1    7100 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62B91000
P 8250 2950
AR Path="/62B91000" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62B91000" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8250 2700 50  0001 C CNN
F 1 "GND" H 8255 2777 50  0000 C CNN
F 2 "" H 8250 2950 50  0001 C CNN
F 3 "" H 8250 2950 50  0001 C CNN
	1    8250 2950
	1    0    0    -1  
$EndComp
$Comp
L GPAD_SCH_LIB:10K RV?
U 1 1 62B9100B
P 8250 2700
AR Path="/62B9100B" Ref="RV?"  Part="1" 
AR Path="/62B871EE/62B9100B" Ref="RV?"  Part="1" 
F 0 "RV?" H 8180 2791 50  0000 R CNN
F 1 "10K" H 8180 2700 50  0000 R CNN
F 2 "digikey-footprints:Trimpot_3.8mmx3.6mm_TC33X-2-103E" H 8250 2700 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/TC33.pdf" H 8250 2700 50  0001 C CNN
F 4 "JLCPCB" H 8250 2700 50  0001 C CNN "Distributor 1"
F 5 "C58159" H 8250 2700 50  0001 C CNN "Distributor 1 PN"
F 6 "BOURNS" H 8250 2700 50  0001 C CNN "Manufacturier"
F 7 "3362P-1-103LF" H 8250 2700 50  0001 C CNN "MPN"
F 8 "HAND" H 8180 2609 50  0000 R CNN "Assembly Type"
	1    8250 2700
	-1   0    0    -1  
$EndComp
Text Notes 3650 1350 0    50   ~ 0
LCD compnents including I2C interface.
Wire Wire Line
	8700 4300 8700 4400
Wire Wire Line
	7100 1600 7300 1600
Wire Wire Line
	7600 1600 7700 1600
Wire Wire Line
	8500 1600 8250 1600
Connection ~ 8000 1600
Wire Wire Line
	8500 1900 8500 1950
Wire Wire Line
	8000 1950 8000 1900
Wire Wire Line
	8250 2550 8250 1600
Connection ~ 8250 1600
Wire Wire Line
	8250 1600 8000 1600
Wire Wire Line
	8250 2850 8250 2950
Wire Wire Line
	7400 2250 7400 2200
Wire Wire Line
	7400 2200 7800 2200
Wire Wire Line
	7800 2200 7800 2700
Wire Wire Line
	7800 2700 8100 2700
Wire Wire Line
	8500 1600 9150 1600
Wire Wire Line
	9150 1600 9150 3350
Wire Wire Line
	9150 3350 8000 3350
Connection ~ 8500 1600
Wire Wire Line
	7700 3250 8700 3250
Wire Wire Line
	8700 3250 8700 3900
Wire Wire Line
	8000 3800 8000 3350
Connection ~ 8000 3350
Wire Wire Line
	8000 3350 7700 3350
Wire Wire Line
	8400 4100 8000 4100
Wire Wire Line
	7300 3950 7300 3850
Wire Wire Line
	6650 3250 6750 3250
Wire Wire Line
	6650 3350 6900 3350
Wire Wire Line
	6650 3450 6900 3450
Wire Wire Line
	6650 3550 6900 3550
Wire Wire Line
	6650 3650 6900 3650
Wire Wire Line
	6750 3250 6750 4200
Wire Wire Line
	6750 4200 8000 4200
Wire Wire Line
	8000 4200 8000 4100
Connection ~ 8000 4100
Wire Wire Line
	6150 4150 6150 4050
Wire Wire Line
	5650 2950 5250 2950
Wire Wire Line
	5250 2950 5250 2650
Wire Wire Line
	5650 3050 4950 3050
Wire Wire Line
	4950 3050 4950 2650
Wire Wire Line
	5450 3750 5450 3150
Wire Wire Line
	5450 3150 4600 3150
Wire Wire Line
	5650 3250 5250 3250
Wire Wire Line
	4250 3250 4250 2650
Wire Wire Line
	5650 3350 4950 3350
Wire Wire Line
	3850 3350 3850 2650
Wire Wire Line
	5650 3450 4600 3450
Wire Wire Line
	3500 3450 3500 2650
Wire Wire Line
	5250 3600 5250 3250
Connection ~ 5250 3250
Wire Wire Line
	5250 3250 4250 3250
Wire Wire Line
	4950 3600 4950 3350
Connection ~ 4950 3350
Wire Wire Line
	4950 3350 3850 3350
Wire Wire Line
	4600 3600 4600 3450
Connection ~ 4600 3450
Wire Wire Line
	4600 3450 3500 3450
$Comp
L power:GND #PWR?
U 1 1 62C558F4
P 5100 4100
AR Path="/62C558F4" Ref="#PWR?"  Part="1" 
AR Path="/62B871EE/62C558F4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5100 3850 50  0001 C CNN
F 1 "GND" H 5105 3927 50  0000 C CNN
F 2 "" H 5100 4100 50  0001 C CNN
F 3 "" H 5100 4100 50  0001 C CNN
	1    5100 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3900 4600 4000
Wire Wire Line
	4600 4000 4950 4000
Wire Wire Line
	5250 4000 5250 3900
Wire Wire Line
	4950 3900 4950 4000
Connection ~ 4950 4000
Wire Wire Line
	4950 4000 5100 4000
Wire Wire Line
	5100 4100 5100 4000
Connection ~ 5100 4000
Wire Wire Line
	5100 4000 5250 4000
Wire Wire Line
	7700 1600 7700 2050
Wire Wire Line
	7700 2050 7300 2050
Wire Wire Line
	7300 2050 7300 2250
Connection ~ 7700 1600
Wire Wire Line
	7700 1600 8000 1600
Wire Wire Line
	5250 2350 5250 2050
Wire Wire Line
	5250 2050 7300 2050
Connection ~ 7300 2050
Wire Wire Line
	4950 2350 4950 2050
Wire Wire Line
	4950 2050 5250 2050
Connection ~ 5250 2050
Wire Wire Line
	4600 2350 4600 2050
Wire Wire Line
	4600 2050 4950 2050
Connection ~ 4950 2050
Wire Wire Line
	4250 2350 4250 2050
Wire Wire Line
	4250 2050 4600 2050
Connection ~ 4600 2050
Wire Wire Line
	3850 2350 3850 2050
Wire Wire Line
	3850 2050 4250 2050
Connection ~ 4250 2050
Wire Wire Line
	3500 2350 3500 2050
Wire Wire Line
	3500 2050 3850 2050
Connection ~ 3850 2050
$Comp
L Device:R R?
U 1 1 62C6D2FC
P 4600 3750
AR Path="/62C6D2FC" Ref="R?"  Part="1" 
AR Path="/62B871EE/62C6D2FC" Ref="R?"  Part="1" 
F 0 "R?" H 4700 3800 50  0000 C CNN
F 1 "1R0" H 4750 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4530 3750 50  0001 C CNN
F 3 "~" H 4600 3750 50  0001 C CNN
F 4 "JLCPCB" V 4600 3750 50  0001 C CNN "Distributor 1"
F 5 "C269434" V 4600 3750 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4600 3750 50  0001 C CNN "Manufacturer"
F 7 "RMC060315%N" V 4600 3750 50  0001 C CNN "MPN"
F 8 "0.1W ±5% 1Ω 0603 Chip Resistor - Surface Mount ROHS" H 4600 3750 50  0001 C CNN "Description"
	1    4600 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62C73C08
P 4950 3750
AR Path="/62C73C08" Ref="R?"  Part="1" 
AR Path="/62B871EE/62C73C08" Ref="R?"  Part="1" 
F 0 "R?" H 5050 3800 50  0000 C CNN
F 1 "1R0" H 5100 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4880 3750 50  0001 C CNN
F 3 "~" H 4950 3750 50  0001 C CNN
F 4 "JLCPCB" V 4950 3750 50  0001 C CNN "Distributor 1"
F 5 "C269434" V 4950 3750 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 4950 3750 50  0001 C CNN "Manufacturer"
F 7 "RMC060315%N" V 4950 3750 50  0001 C CNN "MPN"
F 8 "0.1W ±5% 1Ω 0603 Chip Resistor - Surface Mount ROHS" H 4950 3750 50  0001 C CNN "Description"
	1    4950 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62C74117
P 5250 3750
AR Path="/62C74117" Ref="R?"  Part="1" 
AR Path="/62B871EE/62C74117" Ref="R?"  Part="1" 
F 0 "R?" H 5350 3800 50  0000 C CNN
F 1 "1R0" H 5400 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 3750 50  0001 C CNN
F 3 "~" H 5250 3750 50  0001 C CNN
F 4 "JLCPCB" V 5250 3750 50  0001 C CNN "Distributor 1"
F 5 "C269434" V 5250 3750 50  0001 C CNN "Distributor 1 PN"
F 6 "TyoHM" V 5250 3750 50  0001 C CNN "Manufacturer"
F 7 "RMC060315%N" V 5250 3750 50  0001 C CNN "MPN"
F 8 "0.1W ±5% 1Ω 0603 Chip Resistor - Surface Mount ROHS" H 5250 3750 50  0001 C CNN "Description"
	1    5250 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2650 4600 3150
Wire Wire Line
	5450 3750 5500 3750
Wire Wire Line
	4950 3050 3050 3050
Wire Wire Line
	3050 3050 3050 3000
Connection ~ 4950 3050
Connection ~ 5250 2950
Wire Wire Line
	2850 2950 5250 2950
$Comp
L Connector:TestPoint TP?
U 1 1 62C8B28F
P 5500 4200
F 0 "TP?" H 5300 4250 50  0000 L CNN
F 1 "TestPoint" H 5100 4350 50  0000 L CNN
F 2 "" H 5700 4200 50  0001 C CNN
F 3 "~" H 5700 4200 50  0001 C CNN
	1    5500 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	5500 4200 5500 3750
Connection ~ 5500 3750
Wire Wire Line
	5500 3750 5650 3750
Wire Wire Line
	6650 3150 6800 3150
Wire Wire Line
	6800 3150 6800 2650
Wire Wire Line
	6800 2650 6900 2650
Wire Wire Line
	6650 3050 6750 3050
Wire Wire Line
	6750 3050 6750 2550
Wire Wire Line
	6750 2550 6900 2550
Wire Wire Line
	6900 2450 6700 2450
Wire Wire Line
	6700 2450 6700 2950
Wire Wire Line
	6700 2950 6650 2950
Wire Wire Line
	6900 3250 6900 3150
Wire Wire Line
	6900 3050 6900 3150
Connection ~ 6900 3150
Wire Wire Line
	6900 3050 6900 2950
Connection ~ 6900 3050
Wire Wire Line
	6900 3250 6850 3250
Wire Wire Line
	6850 3250 6850 3850
Wire Wire Line
	6850 3850 7300 3850
Connection ~ 6900 3250
Connection ~ 7300 3850
Text Notes 3650 1750 0    50   ~ 0
Wiring of I2C to LCD from:\nhttps://alselectro.wordpress.com/2016/05/12/serial-lcd-i2c-module-pcf8574/
$EndSCHEMATC
