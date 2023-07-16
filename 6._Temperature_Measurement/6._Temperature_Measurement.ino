const int tempsensor = A0;      //connects the temperature sensor to pin A0. Since the temperature sensor is an analog component, we use analog pins.
                                //A0 = pin 14, A1 = pin 15, A2 = 16... as so on. because the arduino has 13 digital pins, the continuation of numbers will be the analog pins.
                                //int is for integer (e.g. 1, 2, 3, 4,...)
float tempc;                    //variable to store temperature in degree celcius
                                //float is for floating-point numbers, a number that has a decimal point. 
                                //Floating-point numbers are often used to approximate analog and continuous values because they have greater resolution than integers.
float tempf;                    //variable to store temperature in farenheit
float a;                        //temporary variable to hold the sensor/temperature value/reading


void setup() {
  pinMode(tempsensor, INPUT);   //configuring sensor pin as input. It's an input because it reads the surrounding temperature and sends the temperature signal to the arduino.
  Serial.begin(9600);
}


void loop() {                           //main loop
  a = analogRead(tempsensor);           //Reads the analog value from the sensor(a = analog value). For digital components, use digitalRead. For Analog components, use analogRead.
  a = (a*500)/1023;                     //Converts the analog value to celcius (multiply "a" by 500, then divide by 1023). 
                                        //This is a fixed formula. It now stores "a" as a new value in degree celcius.
  tempc = a;                            //storing "a" value in degree celcius variable
  tempf = (a*1.8)+32;                   //Converts degree celcius to farenheit. This is a fixed formula. It now stores "a" as a new value in farenheit.

  Serial.print("Degree Celcius = ");    //prints "Degree Celcius = " in the serial monitor
  Serial.print("\t");                   //functions like a "tab" button in your keyboard. It prints the value/reading of "Degree Celcius" after pressing tab one time in your keyboard.
  Serial.print(tempc);                  //inputs the value of tempc = a 
  Serial.print("");
  Serial.print("\t");
  Serial.print("Farenheit = ");         // prints "Farenheit = " in the serial monitor
  Serial.print("\t");                   //functions like a "tab" button in your keyboard. It prints the value/reading of "Farenheit" after pressing tab one time in your keyboard.
  Serial.print(tempf);                  //inputs the value of tempf = (a*1.8)+32 
  Serial.print("\n");                   //to put every result in a new line (multiple lines) rather than in 1 straight line only

  delay(2000);                          //delays the printing of the readings in the serial monitor to come out every 2 second. Easier to view readings in the serial monitor.
}

    // The tab function ("\t") causes the display to look like how your word would look like after pressing tab button in microsoft word, and then typing,e.g. "Farenheit")
    // "\n" for new line
    // "\t" for tab
