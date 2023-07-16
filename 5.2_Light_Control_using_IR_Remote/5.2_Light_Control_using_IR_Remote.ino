#include <IRremote.h>          //calls/includes the library of ir remote


const int RECV_PIN = 9;        //btw, we're using IR Remote library version 2.8.0
IRrecv irrecv(RECV_PIN);       //Create the receiver object, using a name of your choice.
decode_results information;    //creates object for result or information
const int led1 = 10;
const int led2 = 11;


void setup(){
 irrecv.enableIRIn();       //(IR receive enable IR in) Begin the receiving process. This will enable the timer interrupt which consumes a small amount of CPU every 50 µs.
 irrecv.blink13(true);      //Enables the LED to blink during reception / when receiving a signal. 
                            //It will blink when it receives infrared signals (when we press the button).
                            //Because humans can't see infrared light, blinking the LED can be useful while troubleshooting, or just to give visual feedback.
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
}


void loop(){
    if (irrecv.decode(&information)){      //Attempt to receive an IR Code. Returns "true" if s code was received, or "false" if nothing is received yet. 
                                           //When a code is received, information is stored into "results". ("information" here is the variable)
        switch(information.value){         //(switch loop) the results each time the button is pressed can be found by calling the value() method. ("information" here is the variable)
          
          case 0xFF30CF:                   //Keypad button "1"
          digitalWrite(led1, HIGH);        //light (LED 1) turns on when we press "1" on the keypad
          delay(2000);                     //turns on for 2 seconds
          digitalWrite(led1, LOW);         //then turns off
          break ;                          //break is used to exit from a "do", "for", or "while" loop, bypassing the normal loop condition. It is also used to exit from a switch statement.
          
          case 0xFF18E7:                   //Keypad button "2"
          digitalWrite(led2, HIGH);        //light (LED 2) turns on when we press "2" on the keypad
          delay(2000);                     //turns on for 2 seconds
          digitalWrite(led2, LOW);         //then turns off
          break;
        }
        irrecv.resume();                   //After receiving, this must be called to reset the receiver and prepare it to receive another code.
    }
}

  //if we use case function, we must also use break function
