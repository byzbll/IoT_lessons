// D0 pinine bağlı olan LED'i 500ms aralıklarla yakıp söndürme
//-------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  pinMode(D0, OUTPUT);  // D0 pinini cikis olarak ayarla

  // deney setindeki az yanan ledleri söndür
  pinMode(D1,OUTPUT);pinMode(D2,OUTPUT);pinMode(D3,OUTPUT);pinMode(D4,OUTPUT);
}
//-------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0,HIGH);    // LED'i yaktir
  delay(500);               // 500ms yani 1sn bekle
  digitalWrite(D0,LOW);     // LED'i sondur
  delay(500);               // 500ms yani 1sn bekle
}
