byte pinler[7]={D7,D6,D5,D4,D3,D2,D1};  // seven segment pinleri
byte rakamlar[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
byte sayac=0;                           // 0 ile 9 arasında saydırma için kullanılacak
//**********************************************************************
void goster(byte sayi)
{
  byte deger= rakamlar[sayi];
  for(int i=0;i<7;i++)
  {
      byte sonuc=(deger >>i) & 0b00000001;
      if (sonuc==1)
        digitalWrite(pinler[i],HIGH);
      else
        digitalWrite(pinler[i],LOW);
  }
}
//**********************************************************************
void setup() {
  // put your setup code here, to run once:
  for(byte i=0;i<7;i++)
    pinMode(pinler[i],OUTPUT);  // seven segmente gidien pinler çıkış
}
//**********************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  goster(sayac);
  sayac++;
  if(sayac==10)
    sayac=0;
  delay(1000);
}
