int led = 10;                  //using digital pin
int photoresistor = A0;        //using analog pin (pin A0 = pin 14)
int a = 0;                     //dummy variable for the sensor value with "0" as the starting value


void setup() {
  Serial.begin(9600);               //starts communcation with the serial port. We need this to obtain the reading value of the photoresistor on the serial monitor.
  pinMode(led, OUTPUT);             //pin connected to the LED is defined as an output
  pinMode(photoresistor, INPUT);    //it's an input because it measures the surrounding 
}


void loop() {
  a = analogRead(photoresistor);         //Reads value of photoresistor
  Serial.print("\n");                    //Inserts every reading in a new line 
  Serial.print("Sensor value = ");       //Prints "Sensor value = " in the serial monitor
  Serial.print(a);                       //Prints the value of "a" measured by the photoresistor
  delay(500);                            //Delays the rate at which the reading is taken. A result is showed every 0.5 seconds.

}

    //useful when gardening/plant projects, e.g. want to detect the sunlight
    //when light is shown / light intensity increases, reading increases
    //when it gets dimmer, reading decreases 
