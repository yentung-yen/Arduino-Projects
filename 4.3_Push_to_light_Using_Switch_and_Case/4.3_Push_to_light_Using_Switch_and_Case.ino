int led = 4;
int button = 5;
int buttonstatus = 0;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonstatus = digitalRead(button);
  
  switch(buttonstatus){

    case HIGH:                     //since there's only 2 cases for the buttonstatus, high and low, we don't need to define the last one (LOW). 
                                   //If there is 3 cases, e.g. HIGH, MIDDLE & LOW, we would need to define HIGH & MIDDLE.
                                   //in the case the buttonstatus is HIGH, ON the LED (HIGH)
    digitalWrite(led, HIGH);
    break;                         //break is used to exit from a "do", "for", or "while" loop, bypassing the normal loop condition. 
                                   //It is also used to exit from a switch statement.
    default:                       //the default setting for the LED should be OFF(LOW)
                                   //since there are only 2 cases, the other case other than HIGH would only be LOW
    digitalWrite(led, LOW);
    break;                         //break is used to exit from a "do", "for", or "while" loop, bypassing the normal loop condition. 
                                   //It is also used to exit from a switch statement.
  }
}
