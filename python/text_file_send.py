'''f=open('list1.txt')  
f1=open('output.txt','a')
for x in f.readlines():
    f1.write(x)
f.close()
f1.close()
'''
## import the serial library
import serial

## Boolean variable that will represent 
## whether or not the arduino is connected
connected = False

## establish connection to the serial port that your arduino 
## is connected to.

locations=['/dev/ttyUSB0','/dev/ttyUSB1','/dev/ttyUSB2','/dev/ttyUSB3']

for device in locations:
    try:
        print "Trying...",device
        ser = serial.Serial(device, 9600)
        break
    except:
        print "Failed to connect on",device

## loop until the arduino tells us it is ready
while not connected:
    connected = True

## open text file to store the current 
##gps co-ordinates received from the rover    
#############################################
#text_file = open("newFile.txt", 'w')
#############################################
f=open('list1.txt')
#############################################
## read serial data from arduino and 
## write it to the text file 'position.txt'
while 1:
    '''if ser.inWaiting():
        x=ser.read()
        print(x) 
        text_file.write(x)
        if x=="n":
             text_file.seek(0)
             text_file.truncate()
        text_file.flush()'''
    for x in f.readlines():
    	ser.write(x)

## close the serial connection and text file
#text_file.close()
#####################################
f.close
ser.close()