#include <Servo.h>
int servop = 17;
int servon = 16;
Servo ser;
long dist, dist1;
int LMP = 6;
int LMN = 5;
int RMP = 10;
int RMN = 11;
char c, d;
int trig = 18;
int echo = 19;

void front() {
  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
}
void back() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
}
void fleft() {
  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
}
void fright() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
}
//void bleft() {
//  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
//  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
//}
//void bright() {
//  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
//  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
//}
void stopp() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 0);
}
void setup() {
  ser.write(90);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, INPUT);
  Serial.begin(9600);
  Serial.print("\nEnter a key:");
  c = 's';
  digitalWrite(17, 1);
  digitalWrite(16, 0);
  ser.attach(3);
}
long ultradis() {
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);

  long timee = pulseIn(echo, 1);

  return 344 * timee / 20000;

}
void look() {
  stopp(); delay(500); back(); delay(1000); stopp();
  for (int i = 90; i <= 180; i++) {
    ser.write(i);
    delay(15);
  }
  delay(500);
  dist1 = ultradis();


  for (int i = 180; i >= 0; i--) {
    ser.write(i);
    delay(15);
  }
  delay(500);
  dist = ultradis();
   for (int i = 0; i <= 90; i++) {
    ser.write(i);
    delay(15);
  }
  delay(500);

  int b = checkserial();
  if(b==1) return;

  if (dist1 < dist)  {
    fright();
    delay(700);
    front();
    // c='r';
  }
  else {
    fleft();
    // c='l';
    delay(700);
    front();
  }
 
}
int checkserial(){
   if (Serial.available()) {
    d = Serial.read();
    if (isalpha(d)) {
      c = tolower(d);
     // Serial.print(c);
    }
    return 1;
  }
  else return 0;
}

void decide(){
   dist = ultradis();
  if (c == 'k')  c = 'f';
  //if(c=='s')  c='s';
  else if (dist < 20) c = 'k';


  switch (c) {
    case 'f': front();
      break;
    case 'b': back();
      break;
    case 'l': fleft();
      break;
    case 'r': fright();
      break;
    case 'k': look();
      break;
    case 's': stopp();
      break;
    default: stopp();
  }
}
void loop() {
   decide();
 int a = checkserial();

}
