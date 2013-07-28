#include "HeadAxisControl.h"
#include "Test_Head.h"

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  
  setupPositionControl();

delay(3000);
//moveHeadByAmount(+4000);

}

// the loop routine runs over and over again forever:
void loop() {
/*
  moveHeadByAmount(200);
  delay(500);

  moveHeadByAmount(-500);
  delay(500);

  moveHeadByAmount(600);
  delay(500);

  moveHeadByAmount(-300);
  delay(500);
  
  moveHeadToPosition(0);
  Serial.println("==========================================================");
  Serial.print("Reset ot origin ;POS=");Serial.println(mHeadPos);
  Serial.println("");
  
  delay(5000);
*/
  if (Serial.available()){
    byte vChar = Serial.read();
    
    switch (vChar){
      case 'L':
      case 'l':
        moveHeadByAmount(-100);
        break;
      case 'R':
      case 'r':
        moveHeadByAmount(100);
        break;
    }
  }
}

/*
void testMove (){
   while (1) {
    // change the analog out value:
    if (vLeftRight){
      analogWrite(3, PMWSPEED);           
    }
    else {
      analogWrite(PWM_PIN_LEFT, PMWSPEED);           
    }
    
    while (mPos < abs(200)) {
      delay(PWMSTEP);
    }
    
    //stop
    analogWrite(3, 0);           
    analogWrite(PWM_PIN_LEFT, 0);   
      
    vLeftRight = !vLeftRight;

    Serial.print("POS=");Serial.println(mPos);
    delay(1000);  
  }  
}
*/




