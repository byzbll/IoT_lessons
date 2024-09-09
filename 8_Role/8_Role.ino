#define Role_pin D6		// rölenin bağlı olduğu pin tanımı
#define buton_pin D8	// butonun bağlı olduğu pin tanımı
//*******************************************************
void setup() {
  pinMode(Role_pin,OUTPUT);		// röle pinini çıkış yap
  pinMode(buton_pin,INPUT);		// buton pinini giriş yap
}
//*******************************************************
void loop() {
  if(digitalRead(buton_pin)==HIGH)	// butona basıldı mı?
    digitalWrite(Role_pin,HIGH);	// butona basıldı röleyi çektir
  else
    digitalWrite(Role_pin,LOW);		// hayır basılmadı röleyi bıraktır
  
  delay(200);						// buton arkları için 200ms bekleme
}
