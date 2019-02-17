import serial
ser=serial.Serial('/dev/ttyUSB0',19200,timeout=0)
f=open("lifi.txt","r")
f1=f.readlines()
while True:
    for x in f1:
         ser.write(x)
