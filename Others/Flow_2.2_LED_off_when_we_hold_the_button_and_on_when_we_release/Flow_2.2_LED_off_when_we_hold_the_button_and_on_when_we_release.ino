int button = 7;
int buttonstatus = 0;
int led1 = 6;
int led = 8;


void setup(){
  pinMode(button,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led,OUTPUT);
}


void loop(){
  digitalWrite(led1, HIGH);               //if change both of this to LOW, the LED's will OFF when button is released, and ON when button is pressed
  digitalWrite(led, HIGH);                //both LEDs are off initially
  
  buttonstatus = digitalRead(button);     //reads the status of the button
  
  if(buttonstatus == HIGH){               //if they read that the button status is "HIGH", meaning that it's pressed,
  digitalWrite(led1, LOW);                //OFF both LEDs
  digitalWrite(led, LOW);
  }
  delay(500);                             //can turn the LED's ON & OFF faster when delay is lower
}

   //led off when we hold the button, and on when we release the button
   //coding same as Flow 1.2
