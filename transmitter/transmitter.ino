int a=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRC = 0b10000000;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTC = 0b00000000;
 _delay_us(500);
  PORTC = 0b10000000;
  _delay_us(500);
  
}
