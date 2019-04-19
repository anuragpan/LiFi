import serial
import time
ser=serial.Serial('/dev/ttyUSB0',9600,timeout=0)

while True:
	ser.write('a')
	


	
