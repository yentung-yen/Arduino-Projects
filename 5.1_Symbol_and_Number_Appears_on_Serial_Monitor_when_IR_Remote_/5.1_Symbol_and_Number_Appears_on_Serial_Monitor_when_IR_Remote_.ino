#include <IRremote.h>         //calls/includes the library of ir remote


const int RECV_PIN = 7;        //btw, we're using IR Remote library version 2.8.0
IRrecv irrecv(RECV_PIN);       //Create the receiver object, using a name of your choice
decode_results results;        //Creates object for result/information
unsigned long key_value = 0;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();       //(IR receive enable IR in) Begin the receiving process. This enables the timer interrupt which will consume a small amout of CPU every 50 microseconds
  irrecv.blink13(true);      //Enables the LED to blink during reception / when receiving a signal. 
                             //It will blink when it receives infrared signals (when we press the button).
                             //Because the human eye can't see infrared light, the blinking LED can be useful while troubleshooting, or just to give visual feedback.
}

void loop(){
  if (irrecv.decode(&results)){             //Attempt to receive an IR Code. Returns "true" if s code was received, or "false" if nothing is received yet. 
                                            //When a code is received, information is stored into "results". ("Result" here is the variable)
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){              //the results each time the button is pressed can be found by calling the value() method. ("Result" here is the variable)
          case 0xFFA25D:
          Serial.println("CH-");            //prints "CH-" in the serial monitor
          break;                            //break is used to exit from a "do", "for", or "while" loop, bypassing the normal loop condition. It is also used to exit from a switch statement.
          case 0xFF629D:
          Serial.println("CH");
          break;
          case 0xFFE21D:
          Serial.println("CH+");
          break;
          case 0xFF22DD:
          Serial.println("|<<");
          break;
          case 0xFF02FD:
          Serial.println(">>|");
          break ;  
          case 0xFFC23D:
          Serial.println(">|");
          break ;               
          case 0xFFE01F:
          Serial.println("-");
          break ;  
          case 0xFFA857:
          Serial.println("+");
          break ;  
          case 0xFF906F:
          Serial.println("EQ");
          break ;  
          case 0xFF6897:
          Serial.println("0");
          break ;  
          case 0xFF9867:
          Serial.println("100+");
          break ;
          case 0xFFB04F:
          Serial.println("200+");
          break ;
          case 0xFF30CF:             //corresponds to keypad button "1"
          Serial.println("1");       //prints "1" in the serial monitor
          break ;                    //break is used to exit from a "do", "for", or "while" loop, bypassing the normal loop condition. It is also used to exit from a switch statement.
          case 0xFF18E7:             //corresponds to keypad button "2"
          Serial.println("2");       //prints "2" in the serial monitor
          break ;                    //break is used to exit from a "do", "for", or "while" loop, bypassing the normal loop condition. It is also used to exit from a switch statement.
          case 0xFF7A85:
          Serial.println("3");
          break ;
          case 0xFF10EF:
          Serial.println("4");
          break ;
          case 0xFF38C7:
          Serial.println("5");
          break ;
          case 0xFF5AA5:
          Serial.println("6");
          break ;
          case 0xFF42BD:
          Serial.println("7");
          break ;
          case 0xFF4AB5:
          Serial.println("8");
          break ;
          case 0xFF52AD:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume();              //after receiving, this must be called to reset the receiver and prepare it to receive another code/signal.
  }
}

     //if we use case function, we must also use break function
