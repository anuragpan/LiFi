byte START = 0x45; //the start of frame
//byte STOP = 0x54;  //the end of frame/
byte SIZE;
byte ACK = 0x95;  //the acknowledgement
byte ack=0x0;
byte CHECK;        //check-sum of the packet
byte ID;
byte uart[9];
int data = 6;    //info packet size for a frame badme badal
String text = "popeye";
int i=0,a=0;      //on which letter of the string you are currently

#include<SoftwareSerial.h> // soft serial port header file
SoftwareSerial Serial2(0,2); // define the soft serial port as Serial2, D3 as RX, and D4 as TX

void setup()
{
  Serial2.begin(4800);
  Serial.begin(4800);
} 

void loop()
{
  // resets
  
  
  
  if(a<text.length())  
  // start size data[size(6)] check
    { 
//      Serial.flush();
//      Serial2.flush();
      CHECK = START;
      SIZE = (byte)min(data,(int)text.length()-a);
      CHECK+=SIZE;
      
    for(i=0;i<min(((int)text.length()-a),data);i++)
       {
        Serial2.write(text[a+i]); // data
        Serial.write(text[a+i]);
        CHECK += text[a+i];
       }
      
      Serial2.write(START); // start
      Serial.write(START);

      
      Serial2.write(SIZE);
      Serial.print(SIZE,HEX);
      
      
       
      Serial2.write(CHECK); // data
      Serial.println(CHECK,HEX);
//      Serial2.flush();
      unsigned long Time = millis();
      while(millis()-Time < 500)
      {
        yield();
        
        while(Serial2.available()>0)
        {  
          Serial.println("inside available");
//          ack = 0;
          ack = Serial2.read();
          Serial.println(ack,HEX);
          
          if(ack== ACK)
          {
            a+=i;
            Serial.println("STOP");
            break;
          }
          
        }
//        else
//        Serial.println("waiting");
      }
    }
}



