//#include <IRremote.h>
//IRrecv irrecv(12);
//int val;
//decode_results results;

//volatile unsigned long lastTime = 0;
//volatile int npulses = 0;
//volatile int distance = 0;
//String howFar;
//int pulses;
//long elapsed;

/*
void dopulse() {
  unsigned long now;
  now = micros();
  elapsed = now - lastTime;
  lastTime = now;
  if (elapsed > 300) {
    distance = npulses;
    npulses = 1;
  }
  else {
    npulses += 1;
  }
}
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(18, INPUT);
  
  //attachInterrupt(18, dopulse, RISING);
  
   //irrecv.enableIRIn();
  //Serial.println("Enabled IRin");
}


void loop() {
  // put your main code here, to run repeatedly:
  //if (irrecv.decode(&results)) {
    //val = results.value, HEX;
    //Serial.println(val);
    //irrecv.resume();
   //}
  //delay(10);
  //Serial.println(analogRead(12));
  Serial.println(pulseIn(18, LOW));
  delay(3);
}
