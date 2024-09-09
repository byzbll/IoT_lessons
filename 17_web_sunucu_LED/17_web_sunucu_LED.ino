// ESP modlununu erisim noktasi olarak ayarla ve uzerinde WEB sunucu calistir
// LED yak ve sondur sayfalarından D0 a bağlı LEDi yakıp söndüren program
// programda html sayfasında link verme eklendi
// siz evde denerken NodeMCU üzerindeki D4 ledini kullanabilirsiniz.
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *agin_adi = "xxxxxxxxxxxx";// olusturulan wifi aginin adi
const char *sifre = "xxxxxxxx";     // olusturulan wifi aginin sifresi,min 8 karakter

ESP8266WebServer sunucu(80);        // sunucu nesnensini olusturup, 80 portunu kullan
//********************** ana sayfa oluşturma **************************
void anasayfa() 
{
  String sayfa="<!DOCTYPE html>";
        sayfa+="<html>";
        sayfa+="<body>";
        sayfa+="<h1>NodeMCU sunucusuna hos geldiniz </h1>";
        sayfa+="<a href=\"/ledyak\"> LED yakma linki </a>";
        sayfa+="<a href=\"/ledsondur\"> LED sondurme linki </a>";
        sayfa+="</body>";
        sayfa+="</html>";
        
  sunucu.send(200, "text/html", sayfa);
}
//************************* led yakma sayfası oluşturma ********************
void led_yakma() 
{
    String sayfa="<!DOCTYPE html>";
        sayfa+="<html>";
        sayfa+="<body>";
        sayfa+="<h1>LED yaniyor! </h1>";
        sayfa+="<a href=\"/ledsondur\"> LED sondurme linki </a>";
        sayfa+="<a href=\"/\"> Anasayfa linki </a>";
        sayfa+="</body>";
        sayfa+="</html>";
  sunucu.send(200, "text/html", sayfa);
  digitalWrite(D0,HIGH);
}
//*********************** led sondurme sayfası oluşturma ******************
void led_sondur() 
{
  String sayfa="<!DOCTYPE html>";
        sayfa+="<html>";
        sayfa+="<body>";
        sayfa+="<h1>LED sondu! </h1>";
        sayfa+="<a href=\"/ledyak\"> LED yakma linki </a>";
        sayfa+="<a href=\"/\"> Anasayfa linki </a>";
        sayfa+="</body>";
        sayfa+="</html>";
  sunucu.send(200, "text/html", sayfa);
  digitalWrite(D0,LOW);
}
//*************** bilinmeyen sayfası oluşturma ********************
void bilinmeyen() {
  sunucu.send(404, "text/html", "<h1>Sayfa Bulunamadi</h1>");
}
//****************************************************************
void setup() 
{
  pinMode(D0,OUTPUT);
  Serial.begin(9600);   // seri portu başlat
  Serial.println("Erisim noktasi baslatiliyor...");
  
  WiFi.softAP(agin_adi, sifre);    // erisim noktası olarak baslat

  IPAddress myIP = WiFi.softAPIP();   // erisim noktasının IP adresini bul
  Serial.print("Erisim noktasi IPsi: ");
  Serial.println(myIP);
  
  sunucu.on("/", anasayfa);
  sunucu.on("/ledyak",led_yakma);
  sunucu.on("/ledsondur",led_sondur);
  sunucu.onNotFound(bilinmeyen);
  sunucu.begin();
}
//****************************************************************
void loop() {
  sunucu.handleClient();            // sunucuya baglanan istemcileri karsila
}
