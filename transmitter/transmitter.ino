#include<SoftwareSerial.h>
SoftwareSerial Serial2(0,2);
void setup() 
{
  Serial2.begin(300);
  pinMode(2,OUTPUT);
}

void loop() 
{
  Serial2.println("a");
}
