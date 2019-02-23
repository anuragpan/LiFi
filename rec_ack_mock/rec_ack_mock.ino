#include<SoftwareSerial.h>// soft serial port header file
SoftwareSerial Serial2(0,2); // define the soft serial port as Serial2, D3 as RX, and D4 as TX
byte ACK = 0x95;
void setup() {
  // put your setup code here, to run once:
Serial.begin(4800);
Serial2.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial2.write(1);
Serial2.write(ACK);
}
