
const byte S0 =4;
const byte S1 =5;
const byte S2 =6;
const byte S3 =7;
const byte sensorOut =8;
int R = 0;
int G = 0;
int B = 0;
const byte pins[] = {S0,S1,S2,S3};
void setup(){
  // put your setup code here, to run once:
Serial.begin(9600);
for (byte i=0;i<4;i++){
  pinMode(pins[i],OUTPUT);
}
pinMode(sensorOut, INPUT);
//Setting frequency scaling to 100%
digitalWrite(S0, HIGH);
digitalWrite(S1, HIGH);
Serial.print("Colour sensor in action\n");
}

void Red(){
  digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
//Reading the output frequency
R = pulseIn(sensorOut, LOW);
//print the value on the serial monitor
//map(frequency,0,20000,0,255);
Serial.print("R = ");
Serial.print(R); Serial.print(" ");
}

void Green(){
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //Reading the output frequency
  G = pulseIn(sensorOut,LOW);
  //print the value on the serial monitor
  //map(frequency,0,20000,0,255);
  Serial.print("G = ");
  Serial.print(G); Serial.print(" ");
}

void Blue(){
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  //Reading the output frequency
  B = pulseIn(sensorOut,LOW);
  //print the value on the serial monitor
  //map(frequency,0,20000,0,255);
  Serial.print("B = ");
  Serial.print(B); Serial.print(" \n");
}

void CheckColor(){
 /* if (R>=2&&R<=22&&(G>=8&&G<=63)&&B>=2&&B<=21){
    Serial.println("White");
  }
  else if (R>=10&&R<=101&&G>=53&&G<=292&&B>=13&&B<=102){
    Serial.println("Blue");
  }
  else if (R>=8&&R<=57&&B>=8&&B<=57&&G>=37&&G<=167){
    Serial.println("Red");
  }*/
}
void loop() {
  // put your main code here, to run repeatedly:
Red();
delay(10);
Green();
delay(10);
Blue();
delay(100);
CheckColor();
}


