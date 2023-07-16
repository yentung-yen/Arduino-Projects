int led1 = 4;
int beep = 5;
int led2 = 3;


void setup() {
  pinMode(led1,OUTPUT);    //pin 4 (led) is an output
  pinMode(beep,OUTPUT);    //pin 5 (beep) is an output
  pinMode(led2,OUTPUT);    //pin 3 (beep) is an output
}


void loop() {
  digitalWrite(led1,HIGH);    //turn on led
  digitalWrite(beep,HIGH);    //turn on speaker
  delay(1000);                //wait for 1000 milliseconds (Sound and light) 
  digitalWrite(led1,LOW);     //turn off led
  digitalWrite(beep,LOW);     //turn off speaker
  delay(1000);                //wait for 1000 milliseconds (no sound and no light)
  
  digitalWrite(led2,HIGH);    //turn on led
  digitalWrite(beep,HIGH);    //turn on speaker
  delay(1000);                //wait for 1000 milliseconds (sound and light)
  digitalWrite(led2,LOW);     //turn off led
  digitalWrite(beep,LOW);     //turn off speaker
  delay(1000);                //wait for 1000 milliseconds (no Sound and no light)
}
