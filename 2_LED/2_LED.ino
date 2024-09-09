// D2 ve D5 pinlerine bağlı olan LED'leri ters bi şekilde 1sn aralıklarla yakıp söndürme
//-------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  pinMode(D2, OUTPUT);      // D2 pinini cikis olarak ayarla
  pinMode(D5, OUTPUT);      // D5 pinini cikis olarak ayarla  
  pinMode(D1, OUTPUT);      // D1 pinini cikis olarak ayarla 
  pinMode(D3, OUTPUT);      // D3 pinini cikis olarak ayarla 
  pinMode(D4, OUTPUT);      // D4 pinini cikis olarak ayarla
  digitalWrite(D1,LOW);     // D1,D3 ve D4 deki LED'ler yarim yaniyordu, sondurmek icin
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
}
//-------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D2,HIGH);    // LED'i yaktir
  digitalWrite(D5,LOW);     // LED'i sondur
  delay(1000);              // 1000ms yani 1sn bekle
  digitalWrite(D2,LOW);     // LED'i sondur
  digitalWrite(D5,HIGH);    // LED'i yaktir
  delay(1000);              // 1000ms yani 1sn bekle
}
