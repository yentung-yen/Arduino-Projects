int received;
int led = 5;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(Serial.available()>0){      //checks whether the bluetooth is turned on / connected or not
    received = Serial.read();    //store the sent signal (e.g. '1') into the variable "received"
  }
  if(received == '1'){           //use single '' for one character, and use double "" for words / more than 1 characters (e.g. hi)
  digitalWrite(led, HIGH);       //if receives '2', LED will light up
  }
  else{                          //if receive anything other than 1
    digitalWrite(led, LOW);      //LED will be OFF
  }
}

  // connect VCC to 5V
  // connect GND to GND
  // connect RXD to TX pin in arduino (pin 1)
  // connect TXD to RX pin in arduino (pin 0)
  // EN -> enable

  // IMPORTANT STEPS:
  // 1. connect arduino to computer port first, and all the other pins (5V, GND, pin 5) except for TX & RX pin
  // 2. upload the code to the arduino 
  // 3. lastly, connect the TX and RX pins
  // This is because the arduino cannot be connected to any TX or RX pins when uploading

  // A red light on the bluetooth module will blink. This tells us that it's waiting to be connected to something (e.g. a device / smartphone)
  // ON phone's bluetooth and connect to the bluetooth module (HC-06). 
  // The red light will stop blinking. This tells us that the bluetooth module is connected to our phone.
  // Iphone may have problems with the bluetooth module sometimes
  // Password is either 0000 or 1234 (mine is 1234)
  // Download "Arduino bluetooth controller" app by Giumig Apps to use phone to control the bluetooth module
  // Pair it with "HC-06" and choose "Terminal mode"
  // Type "1" and enter -> the LED will ON. Other character's will turn OFF the LED.
  
  // Controller mode:
  // Top right corner -> click on settings -> configure the buttons with what we want (e.g. setting "1" to triangle)
  // Must remember to press "done" button after configuring 
  // When we press the triangle button, the LED will ON. Other buttons, the LED will OFF

  // Switch mode:
  // Top right corner -> click on settings -> configure the buttons with what we want (e.g. setting "1" to green button(ON), and "0" to red button(OFF))
  // Must remember to press "done" button after configuring 
  // When we press the button, the LED will ON, and the switch will turn green. 
  // When we press the button again, the LED will OFF, and the switch will turn red. 

  // Dimmer mode cannot be used for this code -> can be used for fan (to choose speed) and LED (to vary the brightness)
