int led1 = 6;
int button = 8;
int buttonstatus = 0;        //initial state of button is not pushed
int led2 = 7; 
int tempsensor = A0;
float tempc;                 //for integer, celcius. Float is for floating-point numbers, a number that has a decimal point
float tempf;                 //for integer, fahrenheit. Float is for floating-point numbers, a number that has a decimal point
float vout;                  //(v output) Cannot use int because it stores the above values. The above values are float, so this has to be float too.

int a = 0;

int photosensor = A1;
int photovalue = 0;
int led3 = 9;


void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(tempsensor, INPUT);
  pinMode(led3, OUTPUT);
  pinMode(photosensor, INPUT);
}


void loop() {
  buttonstatus = digitalRead(button);       //read the button status. (push to on & push to off)
  if(buttonstatus == HIGH){                 //If button is pressed, surrounding temperature is read and the rest of the coding will be processed.
                                            //If button is not pressed at all, surrounding temperature is not read and nothing will happen.
  if(a == 0){                               //If a=0 (button is not pressed) 
    a = 1;
  }
  
  photovalue = analogRead(photosensor);
  
  vout = analogRead(tempsensor);                              //read the original value
  vout = (vout*500)/1023;                                     //store celcius value inside new vout

  tempc = vout;                                               //store new vout inside tempc for celcius
  tempf = (tempc*1.8)+32;                                     //convert degree celcius to fahrenheit
  
  delay(500);                                                 //to set it to receive data in manners(every 0.5 seconds)

  if((tempc >= 25 && tempc < 35) || photovalue > 0){          //"||" sign -> OR. If temp is 25 to 34 degree celcius, or photovalue is more than 0,
    digitalWrite(led1, HIGH);                                 //led1 will on,
    delay(1000);                                              //[ in order to receive data in manners (Receive data every 1 second) ]
    digitalWrite(led1, LOW);
    Serial.print("\n");
    Serial.print("in celcius (led1) = ");                     //this will be printed,
    Serial.print("\t");
    Serial.print(tempc);
    digitalWrite(led3, HIGH);                                 //led3 will ON,
    delay(1000);                                              //in order to receive data in manners (Receive data every 1 second)
    digitalWrite(led3, LOW);
    Serial.print("\n");
    Serial.print("light is too intense");                     //and this will be printed
  }
  
  else if((tempc > 22 && tempc < 25) || photovalue > 0){      //"||" sign -> OR. If temp is 23 to 24 degree celcius, or photovalue is more than 0, 
                                                              //(if there are multiple "if" conditions in the program, we must use "else if")
                                                              //(1st one use "if", and 2nd one onwards except for the last one, use "else if")
    digitalWrite(led2, HIGH);                                 //led2 will on,
    delay(1000);                                              //[ in order to receive data in manners (Receive data every 1 second) ]
    digitalWrite(led2, LOW);
    Serial.print("\n");
    Serial.print("in celcius (led2) = ");                     //this will be printed,
    Serial.print("\t");
    Serial.print(tempc);
    digitalWrite(led3, HIGH);                                 //led3 will ON,
    delay(1000);                                              //in order to receive data in manners (Receive data every 1 second)
    digitalWrite(led3, LOW);
    Serial.print("\n");
    Serial.print("light is too intense");                     //and this will be printed
  }
  
  else{
    digitalWrite(led1, LOW);                                  //if it doesn't fulfill any of the above loops, all 3 LED's are off
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  }
  else{
    a = 0;
    return 0;                                                 //Terminate a function and return a value from a function to the calling function. break the system
  }                                                           //returns the LED to it's original state which is OFF
}

    // The tab function ("\t") causes the display to look like how your word would look like after pressing tab button in microsoft word, and then typing,e.g. "Farenheit")
    // "\n" for new line
    // "\t" for tab
    // connect ground to the negative, 5V to the positive
    // syntax runs once each time the button is pressed
    
    // Press button 1 time, temp sensor & photo sensor reads surrounding once, and displays reading on serial monitor once
