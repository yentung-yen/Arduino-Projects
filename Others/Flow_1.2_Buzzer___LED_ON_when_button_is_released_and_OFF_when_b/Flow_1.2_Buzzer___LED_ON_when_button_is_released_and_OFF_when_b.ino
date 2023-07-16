int button = 7;
int buttonstatus = 0;
int vout = 0;
int buzzer = 6;
int led = 8;


void setup() {
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}


void loop() {
  digitalWrite(buzzer, LOW);               //if change both of this to HIGH, the LED's will ON when button is released, and OFF when button is pressed
  digitalWrite(led, LOW);                  //both the LED and buzzer is off initially
  
  buttonstatus = digitalRead(button);      //reads the status of the button
  
  if(buttonstatus == HIGH){                //if they read that the button status is "HIGH", meaning that it's pressed,
    digitalWrite(buzzer, HIGH);            //ON the buzzer and the LED
    digitalWrite(led, HIGH);
  }
  delay(100);                              //can turn the LED's ON & OFF faster when delay is lower
}

   // LED ON's when button is pressed. However, need to hold the button in roder for the LED to remain ON.
   // Once button is released, LED will OFF
   // coding same as Flow 2.2
