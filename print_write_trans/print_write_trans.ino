#include<SoftwareSerial.h> // soft serial port header file
SoftwareSerial Serial2(0, 2); // define the soft serial port as Serial2, D3 as RX, and D4 as TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("sending");
  Serial2.print("65");

  //Serial2.write(1);
}
