int led1 = 7;
int led2 = 8;


void setup() {
  pinMode(7,OUTPUT);      //define pin 7 as output
  pinMode(8,OUTPUT);      //define pin 8 as output
}


void loop() {
  digitalWrite(7,HIGH);     //turn on led on pin 7
  delay(10000);             //wait for 10 seconds (10000 milliseconds)
  digitalWrite(7,LOW);      //turn off led on pin 7
  delay(5000);              //wait for 5 seconds (5000 milliseconds)
  digitalWrite(7,HIGH);     //turn on led on pin 7
  delay(2000);              //wait for 2 seconds (2000 milliseconds)
  digitalWrite(7,LOW);      //turn off led on pin 7
  delay(4000);              //wait for 4 seconds (4000 milliseconds)
  digitalWrite(8,HIGH);     //turn on led on pin 8
  delay(10000);             //wait for 10 seconds (10000 milliseconds)
  digitalWrite(8,LOW);      //turn off led on pin 8
  delay(5000);              //wait for 5 seconds (5000 milliseconds)
  digitalWrite(8,HIGH);     //turn on led on pin 8
  delay(2000);              //wait for 2 seconds (2000 milliseconds)
  digitalWrite(8,LOW);      //turn off led on pin 8
  delay(4000);              //wait for 4 seconds (4000 milliseconds)
}
