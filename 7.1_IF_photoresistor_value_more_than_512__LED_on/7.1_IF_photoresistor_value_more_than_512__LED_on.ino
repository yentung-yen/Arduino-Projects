int led = 10;                      //using digital pin
int photoresistor = A0;            //using analog pin (pin A0 = pin 14)
int sensorvalue = 0;               //dummy variable for the sensor value with "0" as the starting value


void setup() {
  Serial.begin(9600);              //starts communcation with the serial port. We need this to obtain the reading value of the photoresistor on the serial monitor. 
                                   //need to put this to see values appear in serial monitor. 
                                   //Without this, the arduino will not communicate with the serial port and no readings would appear on the serial monitor.
  pinMode(led, OUTPUT);            //pin connected to the LED is defined as an output
  pinMode(photoresistor, INPUT);   //it's an input because it measures the surrounding. 
                                   //Even if we don't define this, it's okay. We don't need to define the analog pin
}


void loop() {
  sensorvalue = analogRead(photoresistor);   //Reads value of photoresistor
  Serial.print("\n");                        //Inserts every reading in a new line
  Serial.print("Sensor value = ");           //Prints ""Sensor value = " in the serial monitor
  Serial.print(sensorvalue);                 //Prints the value of "sensorvalue" measured by the photoresistor

  if(sensorvalue > 15){                      //if the sensor value is higher than 15
    digitalWrite(led, HIGH);                 //the LED lights up
  }
  else{                                      //else, the LED should not light up / should be turned off
    digitalWrite(led, LOW);
  }
  delay(500);                                //Delays the rate at which the reading is taken. A result is showed every 0.5 seconds. 
                                             //It's also a short break where the LED is turned on or off.
}

   //IF photoresistor value is more than 512, LED will ON
   //ELSE, LED will be OFF
