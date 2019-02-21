byte START = 0x45; //the start of frame
byte STOP = 0x54;  //the end of frame
byte CHECK;
byte ID;
int packet = 6;    //info packet size for a frame
String text = "1) Po is the Dragon-Warrior!";
String ack = "";
int i=0,a=0;      //a-on which letter of the string you are currently

void setup()
{
  Serial.begin(9600);
} 

void loop()
{
  while(a<text.length())  
    
    { 
      Serial.write(START);

      for(i=0;i<min(((int)text.length()-a),packet);i++)
       {
        Serial.write(text[a+i]);
       }
    
      a+=i;
    }
    
}



