byte START = 0x45; //the start of frame
//byte STOP = 0x54;  //the end of frame/
byte SIZE = 0x6;
byte ACK = 0x6;  //the acknowledgement
byte ack;
byte CHECK;        //check-sum of the packet
byte ID;
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
  if(a<text.length())  
  // start size data[size(6)] check
    { 
      CHECK = START;
      Serial2.write(START); // start
      Serial.write(START);

//    SIZE = min(6,(int)text.length()-a);
      CHECK+=SIZE;
      Serial2.write(SIZE);
      Serial.print(SIZE,HEX);
      
      for(i=0;i<min(((int)text.length()-a),data);i++)
       {
        Serial2.write(text[a+i]); // data
        Serial.write(text[a+i]);
        CHECK += text[a+i];
       }
       
      Serial2.write(CHECK); // data
      Serial.println(CHECK,HEX);
      unsigned long Time = millis();
      while(millis()-Time < 3000)
      {
        yield();
        while(Serial2.available())
        {  
          Serial.println("inside available");
          ack = Serial2.read();
          Serial.println(ack,HEX);
          if(ack== ACK){
            a+=i;
            Serial.println("STOP");
            break;
          }
        }
//        /else
//        /Serial.println("waiting");
      }
    }
}



