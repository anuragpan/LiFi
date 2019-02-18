## import the serial library
import serial
start = False

## Boolean variable that will represent 
## whether or not the arduino is connected

## establish connection to the serial port that your arduino 
## is connected to.

locations=['/dev/ttyUSB0','/dev/ttyUSB1','/dev/ttyUSB2','/dev/ttyUSB3']

for device in locations:
    try:
        print "Trying...",device
        ser = serial.Serial(device, 9600, timeout=1)
        break
    except:
        print "Failed to connect on",device

## open text file to store the current 
##gps co-ordinates received from the rover    
text_file = open("newFile.txt", 'w')
## read serial data from arduino and 
## write it to the text file 'position.txt'
while 1:
    if ser.inWaiting():
        x=ser.read()
        if start:
        	if x is '$' :
        		break 
	        text_file.write(x)
	        # if x=="\n":
	        #      text_file.seek(0)
	        #      text_file.truncate()
	        text_file.flush()
        if x is '~' :
        	start = True
        print(x)
        
        

## close the serial connection and text file
text_file.close()
ser.close()