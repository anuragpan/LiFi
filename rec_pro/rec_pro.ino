byte START = 0x45; //the start of frame
//byte STOP = 0x54;  //the end of frame/
byte ACK = 0x6;   //the acknowledgement
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
  
  if(Serial2.available()>=8)
  {   
     Serial.println("inside available");
     uart[0] = Serial2.read();
     Serial.println((char)uart[0]);
     
     if(uart[0]==START)
     {
      Serial.println("inside start");
      uart[1] = Serial2.read();  //size
      Serial.println(uart[1],DEC);
      for(int i=0 ; i < (int)uart[1] ; i++)
      {
        Serial.println("inside packet");
        uart[i+2]=Serial2.read();
        packet+=(char)uart[i+2]; 
        Serial.println((char)uart[i+2]);     
      }
      uart[8] = Serial2.read();
      Serial.println(uart[8],HEX);
      
      for(int i=0;i<8;i++){ // add
        Serial.println("summing");
        CHECK += uart[i]; //sum on the receiving side
        uart[i]=0;    
      }
//
//      for(int i=0;i<9;i++){
//        Serial.print((char)uart[i]); // upar daal
//        uart[i] = 0;
//      }
        
      Serial.println();

      
      Serial.println(CHECK,HEX);
      
      
      if(CHECK==uart[8])
      {
          Serial.println("check is right");
          Serial2.write(ACK);
          Serial.print(ACK,HEX);
         
          text+=packet;
          packet = "";
      }
     }
      uart[8] = 0;
      CHECK = 0;
      Serial2.flush();
  
  }
   
} 
