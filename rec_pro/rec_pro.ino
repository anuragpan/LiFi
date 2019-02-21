byte START = 0x45;
byte STOP = 0x54;
byte ACK = 0x99;
String packet = "";
String text = "";
char uart[8];
byte CHECK; 

#include<SoftwareSerial.h>// soft serial port header file
SoftwareSerial Serial2(0,2); // define the soft serial port as Serial2, D3 as RX, and D4 as TX

void setup() 
{
  Serial2.begin(4800);
  Serial.begin(4800);
}

void loop() 
{
  if(Serial2.available())
  {
     if(Serial2.peek()==STOP)
     {
      Serial2.println(text);
     }
     uart[0] = Serial2.read();
     Serial.print(uart[0]);
     if(uart[0]==START)
     {
      for(int i=1;i<8;i++)
      {
        uart[i]=Serial2.read();
        Serial.print(uart[i]);     
      }
      CHECK = uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6];
      if(CHECK==uart[7])
      {
          for(int i=1;i<7;i++)
          {
            packet+=uart[i]; 
            Serial.print(packet);    
          }
          Serial2.write(ACK);
          Serial.write(ACK);
          text+=packet;
          packet = "";
      }
     }
  
  }
   
} 
