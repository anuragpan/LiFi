byte START = 0x45; //the start of frame
byte STOP = 0x54;
byte ACK = 0x99;
byte CHECK;
byte ID;
int data = 6;    //info packet size for a frame
String text = "popeye";
int i=0,a=0;      //a-on which letter of the string you are currently

#include<SoftwareSerial.h>// soft serial port header file
SoftwareSerial Serial2(0,2); // define the soft serial port as Serial2, D3 as RX, and D4 as TX

void setup()
{
  Serial2.begin(4800);
  Serial.begin(4800);
} 

void loop()
{
  if(a<text.length())  
    
    { 
      CHECK = START;
      Serial2.write(START);
      Serial.write(START);
      for(i=0;i<min(((int)text.length()-a),data);i++)
       {
        Serial2.write(text[a+i]);
        Serial.write(text[a+i]);
        CHECK += text[a+i];
       }
      Serial2.write(CHECK);
      Serial.write(CHECK);
      while(!Serial2.available())
        delay(100); // wait till ack
      if(Serial2.read()==ACK)
        a+=i;
    }
    else
    {
    Serial2.write(STOP);
    Serial.write(STOP);
    }
    
}



