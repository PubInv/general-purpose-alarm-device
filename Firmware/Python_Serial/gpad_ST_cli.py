#!/usr/bin/python3
"""
  gpad_ST_cli.py - Python code for serial connect.

  Copyright (C) 2023 Robert L. Read

  This program includes free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  See the GNU Affero General Public License for more details.
  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
"""

import sys,getopt
from time import sleep
import serial


file = 'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestib'
fileSize = len(file)
fileName = 'test.txt'




def main(argv):
    serialport = ''
    try:
        opts, args = getopt.getopt(argv,"h:s:",["sport="])
    except getopt.GetoptError:
        print ('gpad_ST_cli.py -s <serialportpath>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print ('gpad_ST_cli.py -s <serialportpath>')
            sys.exit()
        elif opt in ("-s", "--sport"):
            serialport = arg
    print ('seriaport is ', serialport)

    try:

        for line in sys.stdin:
            ser = serial.Serial(port=serialport,timeout=.1,parity='N', stopbits=1)
            ser.baudrate = 115200
            ser.parity = 'N'
            ser.bytesize=8
            if 'q' == line.rstrip():
                break
            print(f'Input : {line}')

            b = bytes(line, 'utf-8')
            print(f'sending : {b}')
            ser.write(b)
            ser.write(bytes('\n','utf-8'))
            ser.close()


    except KeyboardInterrupt:
        link.close()

if __name__ == "__main__":
   main(sys.argv[1:])
