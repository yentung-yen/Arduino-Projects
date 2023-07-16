#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);


const int tempsensor = A0;     //assigning analog pin A5 to variable "tempsensor"
float tempc;                   //variable to store temperature reading in degree celcius
float tempf;                   //variable to store temperature reading in fahrenheit
float vout;                    //temporary variable to hold sensor reading (variable output?)


void setup() {
  pinMode(tempsensor,INPUT);                          //configuring sensor pin as input 
  Serial.begin(9600);                                 //
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);          //address 0x3C for 128x64
  display.clearDisplay();                             //
  display.setTextColor(SSD1306_WHITE);                //
  display.setTextSize(1);                             //
  display.setCursor(10,30);                           //
  display.println("Temperature Sensor");              //
  display.display();                                  //
  delay(5000);                                        //
}


void loop() {
  vout = analogRead(tempsensor);          //reads the value from the sensor
  vout = (vout*500)/1023;                 //

  tempc = vout;                           //storing the value in degree celcius
  tempf = (vout*1.8)+32;                  //converting to fahrenheit
  
  display.clearDisplay();                 //
  
  display.setCursor(30,20);               //
  display.setTextSize(1);                 //
  display.print("Temp:");                 //
  display.println(tempc);                 //
  display.setCursor(100,20);              //
  display.println("C");                   //
  
  display.setCursor(30,40);               //
  display.setTextSize(1);                 //
  display.print("Temp:");                 //
  display.println(tempf);                 //
  display.setCursor(100,40);              //
  display.println("F");                   //

  display.display();                      //
  delay(1000);                            //

  Serial.print("in DegreeC = ");          //
  Serial.print("\t");                     //
  Serial.print(tempc);                    //
  Serial.print("");                       //
  Serial.print("in Fahrenheit = ");       //
  Serial.print("\t");                     //
  Serial.print(tempf);                    //
  Serial.println();                       //
  delay(500);                             //delay of 0.5 seconds for ease of viewing 
}
