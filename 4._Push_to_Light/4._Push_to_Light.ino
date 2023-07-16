int led = 4;
int button = 5;
int buttonstatus = 0;      //the word "buttonstatus" stands for the value "0". Later on, it will save whether the button is pushed or not.


void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}


void loop() {
  buttonstatus = digitalRead(button);      //The value on pin 7 is read, and the result/reading will be saved under "buttonstatus".
                                           //HIGH means 5 volts, and LOW means 0 volts.
  if(buttonstatus == HIGH){                //if the button is pushed (high voltage value)
    digitalWrite(led, HIGH);               //the LED should light up
    delay(100);                            //for 0.1 seconds (100 milliseconds)
    digitalWrite(led, LOW);                //then, the LED should turn OFF
    delay(100);
  }                                        //closes "if" function
  
  else(digitalWrite(led, LOW));            //or else, the LED should not light up
}                                          //closes the whole loop function
