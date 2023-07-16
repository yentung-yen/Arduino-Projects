int led1 = 4;
int led2 = 3;
int button = 5;
int buttonstatus = 0;               //the word "buttonstatus" stands for the value "0". Later on, it will save whether the button is pushed or not.


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
}


void loop() {
  buttonstatus = digitalRead(button);   //The value on pin 7 is read, and the result/reading will be saved under "buttonstatus".
                                        //HIGH means 5 volts, and LOW means 0 volts.
  if(buttonstatus == HIGH){             //opens "if" function. If the button is pushed (high voltage value)
    digitalWrite(led1, HIGH);           //both LED's should light up
    digitalWrite(led2, HIGH);
    delay(100);                         //for 0.1 seconds (100 milliseconds)
    digitalWrite(led1, LOW);            //then, both LED's should turn OFF
    digitalWrite(led2, LOW);
    delay(100);
  }                                     //closes "if" function

  else{                                 //opens "else" function
  digitalWrite(led1, LOW);              //or else, both LED's should not light up
  digitalWrite(led2, LOW);
}                                       //closes "else" function
}                                       //closes the whole loop function

   //must push and hold the button fot it to light up
