int button = 7;
int buttonstatus = 0;
int a = 0;                   //another dummy variable. we know that the initial value of a is 0. -> Button not pressed
int buzzer = 6;
int led = 8;


void setup() {
  pinMode(7,INPUT);          //define pin 7 as output
  pinMode(6,OUTPUT);         //define pin 8 as output
  pinMode(8,OUTPUT);         //define pin 8 as output
}


void loop() {
  buttonstatus = digitalRead(button);      //it's gonna read the button
  if(buttonstatus == HIGH){
    if(a == 0){                            //if they read that a=0 (since the initial value of a is 0, button not pressed), go to this first loop.
      a = 1;                               //When a=1 (a=1 when we press the button), the buzzer will ON(HIGH), the LED will OFF(LOW).
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, LOW);
    }
    else{                                  //if they read that a=1 (a=1 when the button is already pressed), go to this second loop.
      a = 0;                               //When a=0 (a=0 when we press the button again), the led will OFF(LOW).
      digitalWrite(buzzer, LOW);
      digitalWrite(led, HIGH);
    }
  }
  delay(500);
}

   //press button
   //buzzer on when LED off
   //press button again
   //buzzer off when LED on
   //one component ON's when one component OFF's
   
   //press the button, then wait for 1-2 seconds because the pushbutton cannot sense the "pressing" that fast
   //coding is the same as Flow 2
