byte START = 0x45; //the start of frame
//byte STOP = 0x54;  //the end of frame/
byte ACK = 0x95;   //the acknowledgement
byte CHECK=0x0;      //check-sum of the packet
int SIZE;
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
  
  if(Serial2.available()>=9)    // number udane ka try kar
  {   
     Serial.println("inside available");
     uart[0] = Serial2.read();
     Serial.println((char)uart[0]);
     
     if(uart[0]==START)
     {
      Serial.println("inside start");
      uart[1] = Serial2.read();  //size
      SIZE = (int)uart[1];
      Serial.println(uart[1],DEC);

      for(int i=0 ; i < SIZE ; i++)
      {
        Serial.println("inside packet");
        uart[i+2]=Serial2.read();
        packet+=(char)uart[i+2]; 
        Serial.println((char)uart[i+2]);     
      }
      
      uart[2+SIZE] = Serial2.read();
      Serial.println(uart[2+SIZE],HEX);
      
      for(int i=0;i<(2+SIZE);i++) //add
      { 
        Serial.println("summing");
        CHECK += uart[i]; //sum on the receiving side
        uart[i] = 0;    
      }

//      for(int i=0;i<9;i++)
//      {
//        Serial.print((char)uart[i]); 
//        uart[i] = 0;
//      }
        
      Serial.println();
      Serial.println(CHECK,HEX);
      
      if(CHECK==uart[2+SIZE])
      {
          Serial.println("check is right");
          Serial2.write(ACK);
          Serial.print(ACK,HEX);
         
          text+=packet;
          Serial.println(packet);
          packet = "";
      }
     }
      
      uart[2+SIZE] = 0;
      CHECK = 0;
//      Serial2.flush();
  
  }
   
} 
