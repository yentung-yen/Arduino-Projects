int led = 4;
int button = 5;
int buttonstatus = 0;      //dummy variable
int b = 0;                 //another dummy variable.  we know that the initial value of b is 0. -> Button not pressed


void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);     //normal baud rate used by everyone. If we change it to e.g. 300, it wont work because it's the wrong baud rate. 
                          //The baud rate is the rate at which information is transferred in a communication channel. 
                          //Baud rate is commonly used when discussing electronics that use serial communication. 
                          //In the serial port context, "9600 baud" means that the serial port is capable of transferring a maximum of 9600 bits per second.
                          //Other "standard" baud are 1200, 2400, 4800, 19200, 38400, 57600, and 115200. 
                          //The higher a baud rate is, the faster data is sent/received. But there are limits to how fast data can be transferred.
}

void loop() {
  buttonstatus = digitalRead(button);   //read the button first

  if(buttonstatus == HIGH){
    if(b == 0){                         //if they read that b=0 (since the initial value of b is 0, button not pressed), go to this first loop.
      b = 1;                            //When b=1 (b=1 when we press the button), the led will ON(HIGH).
      digitalWrite(led, HIGH);          //turn on
      Serial.print('\n');               //prints the word "LED is on" on a new line(\n) in the serial monitor. Without this, the serial monitor will print the words in one straight line.
      Serial.print("LED is on");        //prints the word "LED is on" in the serial monitor
    }

    else{                               //if they read that b=1, go to this second loop.
      b = 0;                            //When b=0 (b=0 when we press the button again), the led will OFF(LOW).
      digitalWrite(led, LOW);           //turn off
      Serial.print('\n');               //prints the word "LED is off" on a new line(\n) in the serial monitor. Without this, the serial monitor will print the words in one straight line.
      Serial.print("LED is off");       //prints the word "LED is off" in the serial monitor
    }
    delay(500);                         //add delay for the LED to work better.
}
}
