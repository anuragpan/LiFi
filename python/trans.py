import serial
import time
ser=serial.Serial('/dev/ttyUSB0',9600,timeout=0)


f=open("lifi.txt","r")
f1=f.readlines()
while True:
	ser.write("~")
	for x in f1:
		ser.write(x)
	ser.write("$")


	
