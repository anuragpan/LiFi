import base64
import serial
ser = serial.Serial("/dev/ttyUSB0",4800,timeout=0)

with open("img.png","rb") as imgfile:
	str1 = base64.b64encode(imgfile.read())
	ser.write(str1);
	print(str1)
	ser.write("~");

ser.close()
