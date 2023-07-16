int LED=9;           //The word “LED” stands for the number 9. 
                     //Only PWM~ pins work as it allows the current to vary. Digital pins (without "~") cannot work.
int brightness=0;    //The word “brightness” stands for the value that is emitted at the PWM. The number “0” is only used as an initial value. 
int fading=5;        //”fading” sets up the speed of the fading. 


void setup() { 
  pinMode(LED, OUTPUT);
} 


void loop() { 
  analogWrite(LED, brightness);           //this function is used to activate the PWM output on the pin with the LED
                                          //the value of the PWM is saved under the word "brightness". in this case, it's "0"
  brightness=brightness + fading;         //This modifies the value of the PWM output. We add the value of the fading to the value of the brightness
                                          //in this case: brightness = 0 + 5. the new value that is standing for brightness isn't 0 anymore, it's now 5.
                                          //when the program has ran through the loop part once, it will start over again. 
                                          //the next pass value will be 10. after that, 15, etc ...
  delay(25);                              //the led stays bright for 25 milliseconds. if you reduce this time, the fading will get faster
  if(brightness==0 || brightness== 255){
    fading= -fading; 
  }    
}    //Meaning: if the value of brightness reaches 0 or 255, the value of fading will change from negative to positive and the other way arouund.
     //Reason: while the program is running through the loop part, the led will shine brighter and brighter
     //But when the PWM value reaches 255, it has reached it's maximum. 
     //At this point, the led should get darker and darker, step by step. because of this, the fading will negate at this point
     //This means that the next time the program runs through the loop part, "brightness=brightness+fading" will affect the led. the led gets darker
     //Example: "brightness = 255 + (-5)= 250". the value of brightness will be 250 after that.
     //the next time, it will be 245, etc ... As the value of brightness reaches 0, the value of fading will be positve again
