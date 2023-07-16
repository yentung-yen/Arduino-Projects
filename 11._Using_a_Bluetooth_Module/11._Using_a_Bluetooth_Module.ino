int received;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){      //checks whether the bluetooth is turned on / connected or not
    received = Serial.read();    //stores the sent signal (e.g. '2') into the variable "received"
  }
  if(received == '2'){           //if receives '2', print in serial monitor
  Serial.print(received);
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
  // Type "2" and enter
  // "0505050505...." will appear on the serial monitor. This tells us that the bluetooth module is connected and working
