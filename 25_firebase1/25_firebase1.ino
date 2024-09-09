// firebase realtime database'e bağlanıp String ve int deger yazma
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>                        // firebase kütüphanesini ekle

const char *ssid = "xxxxxxxxxxxxxx";                 // bağlanılacak olan kablosuz ağın SSID si
const char *password = "xxxxxxxxxxxx";                  // bağlanılacak olan kablosuz ağın şifresi

#define FIREBASE_HOST "xxxxxxxxxxxxxxxxx.firebaseio.com"     // veritabanının linki
#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"              // veritabanı secret key
//------------------------------------------------------------------------------------
void setup() 
{
  Serial.begin(9600);                             //Seri iletişim hızı 9600 bps olarak ayarlanarak başlatılıyor.
  delay(1000);
  Serial.println("Wifi agina baglaniliyor");

  WiFi.mode(WIFI_STA);                           //ESP8266 istasyon moduna alınıyor. 
  WiFi.begin(ssid, password);                    //SSID ve şifre girilierek wifi başlatılıyor.

  //------- Wifi ağına bağlanıncaya kadar beklenilen kısım ------------
  while (WiFi.status() != WL_CONNECTED) 
  { 
    delay(500);                                 // Bu arada her 500 ms de bir seri ekrana yan yana noktalar yazdırılarak
    Serial.print(".");                          //görsellik sağlanıyor.
  }
  //-------------------------------------------------------------------

  Serial.println("");                           //Bir alt satıra geçiliyor.
  Serial.println("Bağlantı sağlandı...");       //seri ekrana bağlantının kurulduğu bilgisi gönderiliyor.

  Serial.print("Alınan IP addresi: ");          // kablosuz ağdan alınan IP adresi
  Serial.println(WiFi.localIP());               // kablosuz ağdan alınan IP adresi

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // firabase i başlat
}
//------------------------------------------------------------------------------------
void loop() 
{
  // set String value
  Firebase.setString("Merhaba", "Dunya");
  // handle error
  if (Firebase.failed()) {
      Serial.print("yazdirma hatasi:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set int value
  Firebase.setInt("Int Deger", 69);
  // handle error
  if (Firebase.failed()) {
      Serial.print("yazdirma hatasi:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}
