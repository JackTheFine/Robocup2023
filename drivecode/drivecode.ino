//motor 1 - left on L298N - front left motor
int m1p1 = 2;
int m1p2 = 3;
int enA = 10;
//motor 2 - right on L298N - front right motor
int m2p1 = 4;
int m2p2 = 5;
int enB = 11;
//motor 3 - left on L298N - back right motor
int m3p1 = 6;
int m3p2 = 7;
int enC = 12;
//motor 4 - right on L298N - back left motor
int m4p1 = 8;
int m4p2 = 9;
int enD = 13;
//speed, angle, and rotation to be varied
double gSpeed;
double gAngle;
double gRotation;
bool abc = true;

#define Pi 3.14159

double drivex(double speed, double angle, double rotation) {
  angle = radians(angle);
  return (speed * sin(angle - 45) + rotation );
}

double drivey(double speed, double angle, double rotation) {
  angle = radians(angle);
  return (speed * sin(angle + 45) + rotation );
}

void setup() {
  // put your setup code here, to run once:
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(m3p1, OUTPUT);
  pinMode(m3p2, OUTPUT);
  pinMode(m4p1, OUTPUT);
  pinMode(m4p2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
}

double drivex(byte speed, int angle) {
  double nAngle = (angle/180.0)*Pi;
  return ((speed/2) * sin(nAngle - Pi/4));
}

double drivey(byte speed, int angle) {
  double nAngle = (angle/180.0)*Pi;
  return ((speed/2) * sin(nAngle + Pi/4));
}

void drive(int gSpeed, int gAngle, int gRotation) {
  Serial.print("Angle:");
  Serial.print(gAngle);
  Serial.print(" DriveX:");
  Serial.print(drivex(gSpeed,gAngle));
  Serial.print(" DriveY:");
  Serial.print(drivey(gSpeed,gAngle));
  Serial.print(" Rotation:");
  Serial.println(gRotation);
  analogWrite(enA, abs(drivex(gSpeed,gAngle)+gRotation)*2);
  analogWrite(enB, abs(drivey(gSpeed,gAngle)+gRotation)*2);
  analogWrite(enC, abs(drivex(gSpeed,gAngle)-gRotation)*2);
  analogWrite(enD, abs(drivey(gSpeed,gAngle)-gRotation)*2);

  //directions ALL MOTORS MIGHT BE TURNING WRONG DIR!!!!!! CALIBRATE!!!!!
  if( drivex(gSpeed,gAngle) + gRotation >= 0 ) {
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, HIGH);
  }
   else{
    digitalWrite(m1p1, HIGH);
    digitalWrite(m1p2, LOW);
  }
  if( drivex(gSpeed,gAngle) - gRotation >= 0 ) {
    digitalWrite(m3p1, HIGH);
    digitalWrite(m3p2, LOW);
  }
  else{
    digitalWrite(m3p1, LOW);
    digitalWrite(m3p2, HIGH);
  }
  if( drivey(gSpeed,gAngle) + gRotation >= 0) {
    digitalWrite(m2p1, HIGH);
    digitalWrite(m2p2, LOW);
  }
  else {
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, HIGH);
  }
  if( drivey(gSpeed,gAngle) - gRotation >= 0) {
    digitalWrite(m4p1, LOW);
    digitalWrite(m4p2, HIGH);
  }
  else {
    digitalWrite(m4p1, HIGH);
    digitalWrite(m4p2, LOW);
  } 
}


void loop() {
  // put your main code here, to run repeatedly:
      drive(100, 0, 0);
      delay(500);
      drive(0,0,0);
  }
