// permanent info

byte START = 0x45;  //the start of frame
byte STOP = 0x54;
byte ACK = 0x95;    //the acknowledgement
byte ID;
int n = 9;          // pulse width

// calculated for every pulse

int SIZE;
byte CHECK;        //check-sum of the packet
String packet = "";
String text = "";
unsigned long Time;

// the pulse

byte uart[9];

#include<SoftwareSerial.h>// soft serial port header file
SoftwareSerial Serial2(0,2); // define the soft serial port as Serial2, D3 as RX, and D4 as TX

void setup() 
{
  Serial2.begin(4800);
  Serial.begin(4800);
  text = "";
}

void loop() 
{
  // resets

   SIZE = 0;
   CHECK = 0;
   packet = "";
  
  
  if(Serial2.available()>n)    // number udane ka try kar
  {  
 // pulse detection
     
     // start
     
     uart[0] = Serial2.read(); 
     if(uart[0]==START)
     {
      
      //controls
      
      uart[1] = Serial2.read();
      SIZE = (int)uart[1];

      //data

      for(int i=0 ; i < SIZE ; i++)
      {
        uart[i+2]=Serial2.read();
        packet+=(char)uart[i+2]; 
      }

      // CHECKSUM
      
      uart[SIZE+2] = Serial2.read();
      
// error detection
      
      for(int i=0;i<( SIZE+2 );i++)
      { 
        CHECK += uart[i]; //sum on the receiving side
        uart[i] = 0;      // reset pulse
      }
      
      if(CHECK==uart[SIZE+2])
      {

// data storage

          text+=packet;
          Serial.println(packet);

// acknowledge

          Serial2.write(ACK);

// reset error

          uart[SIZE+2] = 0;
          
      }
     }
     
// end

     else if(uart[0]==STOP){
//          Serial.println(text);/
          }
  }  
} 
