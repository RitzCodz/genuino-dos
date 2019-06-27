int LMP = 6;
int LMN = 5;
int RMP = 10;
int RMN = 11;
char c;
char d;


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
void bleft() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
}
void bright() {
  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
}
void stopp() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 0);
}
void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  Serial.print("\nEnter a key:");
}


void loop() {
  if (Serial.available()) {
     d = Serial.read();
     if(isalpha(d)){
     c=tolower(d);
    Serial.print(c);
    Serial.print("\nEnter next key:");
  }
  }
    switch(c){
      case 'f':front();
      break;
      case 'b': back();
      break;
      case 'l':fleft();
      break;
      case 'r': fright();
      break;
     default: stopp();   
    }
    delay(1000);

  }
