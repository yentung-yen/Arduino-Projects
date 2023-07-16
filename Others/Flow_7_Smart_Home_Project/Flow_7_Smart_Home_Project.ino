#include<SPI.h>                                                               //call libraries
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4                                                          //allows us to define the OLED's status. (Fixed Command)
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);      //to tell the ardruino to turn on the function for the OLED to display any character

int led1 = 5;
int led2 = 6;
int tempsensor = A1;
float temp;
int photoresistor = A2;
float photovalue; 
int received;              //dummy variable: A dummy variable is a dichotomous variable which has been coded to represent a variable with a higher level of measurement
int state = LOW;           //state of LED is initially OFF (LOW)


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(tempsensor, INPUT);
  pinMode(photoresistor, INPUT);                 

  Serial.begin(9600);                         //this serial begin is for the OLED screen (OLED baud rate) because some components need the baud rate to work. Not for the serial monitor.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //Address 0x3C for 128x64. For the ardruino to begin to display any character
  display.setTextColor(SSD1306_WHITE);        //Determines colour of text
  display.setTextSize(2);                     //Determines text size (got size 1-8)
  display.clearDisplay();                     //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
  display.setCursor(5,0);                     //starting coordinate for the first character
  display.println("Smart Home");              //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "Smart Home"
  display.display();                          //to tell the arduino to tell the OLED screen to display what we have written
  delay(5000);
  display.clearDisplay();
}


void loop() {
  if(Serial.available()>0){                   //checks whether the bluetooth is turned on / connected or not
    received = Serial.read();                 //store the sent signal (e.g. '1') into the variable "received"
  }                                           //above command is needed to turn on and store any bluetooth signals 

    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(5,0);                   //starting coordinate for the first character
    display.println("Welcome Home");          //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "Welcome Home"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
                                              //will display "Welcome Home" when no bluetooth signals is sent
  
  if(received == '1' && state == LOW){        //use single '' for one character, and use double "" for words / more than 1 characters (e.g. hi)
    digitalWrite(led1, HIGH);                 //if receives '1', LED will light up
    state = HIGH;                             //Change the variable "state" to HIGH to indicate that the LED is ON
    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)
                                              //if we never reset it back to 0, it will forever be 1, and the LED will just ON and OFF continuously due to the first 2 IF loops

    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("LED 1 is ON");           //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "LED 1 is ON"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);
  }
  else if(received == '1' && state == HIGH){  //if we receive "1" and when the LED's state is HIGH (LED ON)
    digitalWrite(led1, LOW);                  //OFF the LED
    state = LOW;                              //change the variable "state" to LOW
    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)

    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("LED 1 is OFF");          //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "LED 1 is ON"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);
  }
  
  if(received == '2' && state == LOW){        //use single '' for one character, and use double "" for words / more than 1 characters (e.g. hi)
    digitalWrite(led2, HIGH);                 //if receives '2', LED will light up
    state = HIGH;                             //Change the variable "state" to HIGH to indicate that the LED is ON
    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)
  
    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("LED 2 is ON");           //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "LED 2 is ON"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);
  }
  else if(received == '2' && state == HIGH){  //if we receive "1" and when the LED's state is HIGH (LED ON)
    digitalWrite(led2, LOW);                  //OFF the LED
    state = LOW;                              //change the variable "state" to LOW
    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)

    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("LED 2 is OFF");          //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "LED 1 is ON"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);
  }
  
  if(received == '3'){                        //use single '' for one character, and use double "" for words / more than 1 characters (e.g. hi)
    temp = analogRead(tempsensor);
    temp = (temp*500)/1023;

    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("Temperature: ");         //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "Temperature"
    display.println(temp);
    display.setCursor(40,8);
    display.println("C");
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);

    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)
  }

  if(received == '4'){                        //use single '' for one character, and use double "" for words / more than 1 characters (e.g. hi)
    photovalue = analogRead(photoresistor);

  if(photovalue > 15){
    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("Too bright");            //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "Too bright"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);

    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)
  }
  else{
    display.setTextSize(1);                   //Determines text size (got size 1-8)
    display.clearDisplay();                   //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,0);                   //starting coordinate for the first character
    display.println("Too dark");              //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "Too dark"
    display.display();                        //to tell the arduino to tell the OLED screen to display what we have written
    delay(3000);

    received = 0;                             //defines the variable "received" to 0 to indicate that no bluetooth signal is received so that we can display "Welcome Home" (1st IF loop)
  }
}
}
