int led = 4;
int beep = 5;


void setup() {
  pinMode(led,OUTPUT);     //pin 4 (led) is an output
  pinMode(beep,OUTPUT);    //pin 5 (beep) is an output
}


void loop() {
  digitalWrite(led,HIGH);     //turn on led
  digitalWrite(beep,HIGH);    //turn on speaker
  delay(1000);                //wait for 1000 milliseconds (Sound and light) 
  digitalWrite(led,LOW);      //turn off led
  digitalWrite(beep,LOW);     //turn off speaker
  delay(1000);                //wait for 1000 milliseconds (no sound and no light)
}
