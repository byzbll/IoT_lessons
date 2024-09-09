byte pinler[7]={D7,D6,D5,D4,D3,D2,D1};  // seven segment pinleri

void setup() {
  // put your setup code here, to run once:
  for(byte i=0;i<7;i++)
    pinMode(pinler[i],OUTPUT);  // seven segmente gidien pinler çıkış
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0 rakamını yaz
  digitalWrite(D7,HIGH);
  digitalWrite(D6,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D1,LOW);
  delay(1000);
  // 1 rakamını yaz
  digitalWrite(D7,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D1,LOW);
  delay(1000);
  // 2 rakamını yaz
  digitalWrite(D7,HIGH);
  digitalWrite(D6,HIGH);
  digitalWrite(D5,LOW);
  digitalWrite(D4,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D1,HIGH);
  delay(1000);
}
