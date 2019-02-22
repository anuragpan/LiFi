byte START = 0x45; //the start of frame
//byte STOP = 0x54;  //the end of frame/
byte ACK = 0x54;   //the acknowledgement
byte CHECK;       //check-sum of the packet
byte ID;
String packet = "";
String text = "";
byte uart[9];


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
     //uart ko 0 kar
     uart[0] = Serial2.read();
     Serial.println((char)uart[0]);
     
     if(uart[0]==START)
     {
      uart[1] = Serial2.read();  //size
      Serial.println((char)uart[1]);
      for(int i=0 ; i < (int)uart[1] ; i++)
      {
        uart[i+2]=Serial2.read();
        packet+=(char)uart[i+2]; 
        Serial.print((char)uart[i+2]);     
      }
      for(int i=0;i<8;i++){
        CHECK += uart[i]; //sum on the receiving side
        uart[i] = 0;
      }
      
      
      if(CHECK==uart[8])
      {
          Serial2.write(ACK);
          Serial.write(ACK);
          text+=packet;
          packet = "";
      }
     }
  
  }
   
} 
