int led1 = 6;
int button = 8;
int buttonstatus = 0;     //initial state of button is not pushed
int led2 = 7;
int tempsensor = A0;
float tempc;              //for integer, celcius. Float is for floating-point numbers, a number that has a decimal point
float tempf;              //for integer, fahrenheit. Float is for floating-point numbers, a number that has a decimal point
float vout;               //(v output) Cannot use int because it stores the above values. The above values are float, so this has to be float too.

int a = 0;


void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(tempsensor, INPUT);
}


void loop() {
  buttonstatus = digitalRead(button);       //read the button status
  if(buttonstatus == HIGH){                 //push to on & push to off
                                            //When button is pressed, surrounding temperature is read and the rest of the coding will be processed.
                                            //If button is not pressed at all, surrounding temperature is not read and nothing will happen.
  if(a == 0){
    a = 1;                                  //
  }
  
  vout = analogRead(tempsensor);            //read the original value
  vout = (vout*500)/1023;                   //store celcius value inside new vout

  tempc = vout;                             //store new vout inside tempc for celcius
  tempf = (tempc*1.8)+32;                   //convert degree celcius to fahrenheit
  
  delay(500);                               //to set it to receive data in manners(every 0.5 seconds)

  if(tempc >= 25 && tempc < 35){            //range 25 to 34 degree celcius, led1 will on
    digitalWrite(led1, HIGH);
    delay(1000);                            //in order to receive data in manners (Receive data every 1 second)
    digitalWrite(led1, LOW);
    Serial.print("\n");
    Serial.print("in celcius led1 = ");
    Serial.print("\t");
    Serial.print(tempc);
  }
  else if(tempc > 22 && tempc < 25){        //range 23 to 24 degree celcius, led2 will on
                                            //if there are multiple "if" conditions in the program, we must use "else if"
                                            //1st one use "if", and 2nd one onwards except for the last one, use "else if"
    digitalWrite(led2, HIGH);
    delay(1000);                            //in order to receive data in manners (Receive data every 1 second)
    digitalWrite(led2, LOW);
    Serial.print("\n");
    Serial.print("in celcius led2 = "); 
    Serial.print("\t");
    Serial.print(tempc);
  }
  else{
    digitalWrite(led1, LOW);                //if it doesn't fulfill any of the above loops, both LED's are off
    digitalWrite(led2, LOW);
  }
  }
  else{
    a = 0;                                  //
    return 0;                               //Terminate a function and return a value from a function to the calling function. break the system
  }                                         //returns the LED to it's original state which is OFF
}

    // The tab function ("\t") causes the display to look like how your word would look like after pressing tab button in microsoft word, and then typing,e.g. "Farenheit")
    // "\n" for new line
    // "\t" for tab
    // connect ground to the negative, 5V to the positive
    // syntax runs once each time the button is pressed (Press button 1 time, temp sensor reads surrounding temp once, and displays reading on serial monitor once)

    // LED lights up accordingly to Temperature sensed and shows reading on serial monitor
 
