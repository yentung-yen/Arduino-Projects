#include <IRremote.h>       //calls / includes the library of ir remote


const int RECV_PIN = 9;     //btw, we're using IR Remote library version 2.8.0
IRrecv irrecv(RECV_PIN);    //Create the receiver object, using a name of your choice."RECV_PIN" is the variable.
decode_results results;     //creates object for result or information


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();     //(IR receive enable IR in) Begin the receiving process. This will enable the timer interrupt which consumes a small amount of CPU every 50 µs.
  irrecv.blink13(true);    //Enables the LED to blink during reception / when receiving a signal. This LED is the built-in LED that's beside pin 13.
                           //It will blink when it receives infrared signals (when we press the button).
                           //Because humans can't see infrared light, blinking the LED can be useful while troubleshooting, or just to give visual feedback.
}


void loop(){
  if (irrecv.decode(&results)){                 //Attempt to receive an IR Code. Returns "true" if s code was received, or "false" if nothing is received yet. 
                                                //When a code is received, information is stored into "results". ("results" here is the variable)
        Serial.println(results.value, HEX);     //prints the value of the results in HEX Code
        irrecv.resume();                        //After receiving, this must be called to reset the receiver and prepare it to receive another code.
  }
}
