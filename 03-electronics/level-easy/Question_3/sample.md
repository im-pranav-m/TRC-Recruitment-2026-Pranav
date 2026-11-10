In this circuit, we simply attach 3 led to 3 pins of Arduino.  
Also, attach a LDR to pin 10 and grounded it through a 2k ohm resistor so we can adjust the high and low value of the LDR. 

The code contains a basic Delayed Loop covering by the if statement that constantly checks for the LDR Value each loop.  
We could also use Interrupt for LDR so it will turn off no matter whether the loop is being executed or not.
