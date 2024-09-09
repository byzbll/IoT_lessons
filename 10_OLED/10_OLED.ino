#include <Wire.h>             //I2C kullanılacağı için "Wire" kütüphanesi programa dahil ediliyor.
#include <Adafruit_SSD1306.h> //SSD1306 için kullanılacak Adafruit kütüphanesi dahil ediliyor.

#define SCREEN_WIDTH 128      // OLED display width, in pixels
#define SCREEN_HEIGHT 64      // OLED display height, in pixels

Adafruit_SSD1306 ekran(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); //Displayin rst piniolmadığından '-1' yazıyoruz.
//------------------------------------------------------------------------
void setup()
{ 
  ekran.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //Display başlatılıyor ve adresi belirtiliyor (0x3c) 
  
  ekran.clearDisplay();                     //Display temizleniyor 
  ekran.setTextSize(2);                     // Yazı boyutu ayarlanıyor.(10x14)
  ekran.setTextColor(WHITE);                // Yazı rengi ayarlanıyor. (white veya black)
  ekran.setCursor(0,0);                     // İmleç sol üst köşeye alınıyor.
  ekran.println("IoT");                     // Yazımız ekrana gönderiliyor ve bir alt satıra geçiliyor.
  ekran.display();                          // Ekrana gönderilen yazıların tamamı gösteriliyor.
}
//------------------------------------------------------------------------
void loop() 
{  

}
