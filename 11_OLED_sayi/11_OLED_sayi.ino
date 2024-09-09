// bir butona basılınca sayac ++, diğer butona basılınca sayac --, ekranda gösterme
#include <Wire.h>             //I2C kullanılacağı için "Wire" kütüphanesi programa dahil ediliyor.
#include <Adafruit_SSD1306.h> //SSD1306 için kullanılacak Adafruit kütüphanesi dahil ediliyor.

#define SCREEN_WIDTH 128      // OLED display width, in pixels
#define SCREEN_HEIGHT 64      // OLED display height, in pixels
int sayac=0;

Adafruit_SSD1306 ekran(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); //Displayin rst piniolmadığından '-1' yazıyoruz.
//------------------------------------------------------------------------
void setup()
{ 
  pinMode(D5,INPUT);                        // arttırma butonu
  pinMode(D6,INPUT);                        // azaltma butonu
  ekran.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //Display başlatılıyor ve adresi belirtiliyor (0x3c) 
  ekran.setTextSize(2);                     // Yazı boyutu ayarlanıyor.(10x14)
  ekran.setTextColor(WHITE);                // Yazı rengi ayarlanıyor. (white veya black)
}
//------------------------------------------------------------------------
void loop() 
{  
  if(digitalRead(D5)==HIGH)                 // arttırma butonuna basıldı mı?
    sayac++;

  if(digitalRead(D6)==HIGH)                 // azaltma butonuna basıldı mı?
    sayac--;
    
  if(sayac>100)                             // 0-100 arasında saymayı sağlama
    sayac=0;                                // 0-100 arasında saymayı sağlama
  if(sayac<0)                               // 0-100 arasında saymayı sağlama
    sayac=100;                              // 0-100 arasında saymayı sağlama  
    
  ekran.clearDisplay();                     //Display temizleniyor 
  ekran.setCursor(0,0);                     //İmleç sol üst köşeye alınıyor.
  ekran.print("Sayac:");                    // Yazımız ekrana gönderiliyor ve bir alt satıra geçiliyor.
  ekran.print(sayac);
  ekran.display();                          // Ekrana gönderilen yazıların tamamı gösteriliyor.
  delay(200);                               // 200 ms bekleme, buton arklarını söndürmek için
}
