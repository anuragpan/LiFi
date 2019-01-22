 /*
  ADC Testing
  Reads Analog value of the Sensor connected on the PIN 0,of PORT A, of the SRA Development Board and displays the
  value on the SERIAL MONITOR .PORT A is the Analog Port on Atmega 16 and has 8 ADC pins from 0 to 7.

  By Society of Robotics and Automation, VJTI
*/

#include <SRA16.h>      //The SRA16.h header file is included allowing us to use the library functions

int sensorData;      //An array of type int to store the data returned by the sensor

/** Put your setup code here, to run once
*/
void setup() {
  Serial.begin(115200);   //Begin Serial Communication at mentioned baud rate (bits per second)
  adc_init();           //Initialization of ADC registers
  PORTA = 0xFF;
}

/** Put your main code here which you want to run repeatedly
*/
void loop() {
  readSensors();
  printData();
}

/** Reads the values of the sensors
*/
void readSensors()
{
  unsigned char i;

  ADCH = 0x00;

  i = 0 & 0x07;
  ADMUX = i | 0x60;    //i|0x40 for 10 bits
  ADCSRA |= 1 << ADSC;

  while (ADCSRA & (1 << ADSC));    // wait for conv. to complete
  sensorData = ADCH;   //The function returns the value returned by the sensor connected to pin i of port A (i.e. A0 A1 A2 A3)
}

/** Prints the sensorData on the serial monitor
*/
void printData()
{
  if(sensorData>100)
    Serial.println(1);  // "\t" gives a tab space
  else
    Serial.println(0);  // "\t" gives a tab spac

}
