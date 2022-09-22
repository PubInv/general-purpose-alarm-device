# Manufacturing and Unit Test Documentation, PCB Version 1 Protptyep#1, 20220726
Assenbly Notes

Manufacturing test procedure for every unit

Unit (Design) everification tests on some units

GPAD Theory of Opperation

Troubleshooting procedures


## Manufacturing test procedure for every unit

### Assembly Notes
Assumed that the assembly has the SMT components placed by the board manufacturier. Only through hole or other non SMT compoonents are then placed by hand.

The 16 pin header is fit and soldered on to the LCD sub module. Then the pins are placed through the GPAD PCB. Nylon spacers are placed at the four courners of the LCD sub module. Screws with nuts go through both boards and are torquted to **???4???** Inch-Pounds. 

**NOTE** on the Version 1 PCB, the cathod flat marking on J105 is backwards. Place the RED LED in so that the flat cathode side is "in board".

Solder the through hole LEDs at locations D201-D205 and D105 with a **TBD** spacer, holding them up from the PCB by TBD inches. 

**NOTE** on the Version 1 PCB, the foot print for U301 is incorrect. It is too narrow for the part. See photograph of rework method of mounting.



### Electrical Tests
Measure and record by serial number the following electrical parameters.
Investigate and correct abnormal measurements before applying power.  Remove J102 and J103 and retain if present. Note where they should be replaced.
Start with no connections to the DUT (Device Under Test).

**Power Jack** Measure resistance to ground at J101 center pin as greater than **TBD** ohms.

**SPI Interface** Measure resistance to ground at J401 pin 5 as greater than **TBD** ohms.

**VinV net** Measure resistance to ground at TP102 as greater than **TBD** ohms.

**+5V net** Measure resistance to ground at TP103 +5 as greater than **TBD** ohms.

With a current limited supply set for 12V and maximum of **TBD** mA apply power at J101 and note current.
Unprogramed first time power up current is normaly about **TBD** mA
Programmed part that has been powered up, and with display back light on, Hold the reset swithc and measure current as about **61** mA


### Load Firmware
Use an Arduino UNO as an ISP (Incircuit Serial Programer). Load the sketch "ArduinoISP". Select the serial port for the ISP, UNO and program with the "ArduinoISP". 
Connect the ISP UNO to the DUT as follows:
<table>
  <tr>
    <th>SPI UNO</th>
    <th>to DUT</th>
    <th>Note</th>
  </tr>
  <tr>
    <td>D13</td>
    <td>D13</td>
    <td>???</td>
  </tr>
<tr>
    <td>D12</td>
    <td>D12</td>
    <td>???</td>
  </tr>
<tr>
    <td>D11</td>
    <td>D11</td>
    <td>???</td>
  </tr>
<tr>
    <td>D10</td>
    <td>Reset</td>
    <td>???</td>
  </tr>
  <tr>
    <td>GND</td>
    <td>GND</td>
    <td>???</td>
  </tr>
  
</table>

