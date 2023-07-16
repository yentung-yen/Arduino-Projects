int led = 4;
int button = 5;
int buttonstatus = 0;     //a dummy variable
int b = 0;                //another dummy variable. we know that the initial value of b is 0. -> Button not pressed


void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}


void loop() {
  buttonstatus = digitalRead(button);    //it's gonna read the button

  if(buttonstatus == HIGH){ 
    if(b == 0){                          //if they read that b=0 (since the initial value of b is 0, button not pressed), go to this first loop.
      b = 1;                             //When b=1 (b=1 when we press the button), the led will ON(HIGH).
      digitalWrite(led, HIGH);           //turn on
    }

    else{                                //if b=1, go to this second loop.
      b = 0;                             //When b=0 (b=0 when we press the button again), the led will OFF(LOW).
      digitalWrite(led, LOW);            //turn off
    }
    delay(500);                          //add delay for the LED to work better.
}
}
      
