byte pinler[8]={D0,D1,D2,D3,D4,D5,D6,D7};   // LEDleri yakmak için dizi
//********************************************************************
void setup() {
  // put your setup code here, to run once:
  pinMode(D8, INPUT);                       // D8 portunu giriş yap
 
  for(byte i=0;i<8;i++)                     // ledleri yakmak için
  {  
    pinMode(pinler[i],OUTPUT);
    digitalWrite(pinler[i],LOW);
  }
}
//********************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(D8)==HIGH)					  // butona basıldı mı?
  {
    for(byte i=0;i<8;i++)                     // ledleri yakmak için
      digitalWrite(pinler[i],HIGH);
  }
  else
  {
    for(byte i=0;i<8;i++)                     // ledleri söndürmek için
      digitalWrite(pinler[i],LOW);     
  }
  delay(250);                   			  // 250 ms buton arkları geçmesi için gecikme  
}
