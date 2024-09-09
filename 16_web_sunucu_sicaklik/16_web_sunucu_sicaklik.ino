// ESP modlununu erisim noktasi olarak ayarla ve uzerinde WEB sunucu calistir
// anasayfada sıcaklık sensöründen okuduğun degeri göster
// evde denerken sicaklik_olc() fonsiyonun son satırının oraya sicaklik değerini 20 ile 25 
// derece arasında rastgele bir değer olarak belirleten random fonksiyonunu koyarak deneme
// yapınız. Sınavda istenirse bu şekilde yapılacaktır.
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *agin_adi = "xxxxxxxxxxxx";// olusturulan wifi aginin adi
const char *sifre = "xxxxxxxx";     // olusturulan wifi aginin sifresi,min 8 karakter

int ADC_okunan=0;           // adc'den okunana ham değer
float sensor_gerilim=0.0;   // sensorden okunan degerin gerilim karsiligi mV cinsinden
float sicaklik=0.0;         // okunan sıcaklık değeri

ESP8266WebServer sunucu(80);        // sunucu nesnensini olusturup, 80 portunu kullan
//****************************************************************
void anasayfa() {
  sicaklik_olc();
  sunucu.send(200, "text/html", "<h1>Baglandiniz.Sicaklik degeri:"+String(sicaklik)+"</h1>");
}
//****************************************************************
void bilinmeyen() {
  sunucu.send(404, "text/html", "<h1>Sayfa Bulunamadi</h1>");
}
//****************************************************************
void sicaklik_olc()
{
  ADC_okunan=analogRead(A0);              // ADC yi oku, A0 girişine bağlı LM35
  sensor_gerilim=(ADC_okunan*1000.0)/1023.0; //bu kismin açıklaması en alttadır
  sicaklik=sensor_gerilim/10.0;
}
//****************************************************************
void setup() 
{
  Serial.begin(9600);   // seri portu başlat
  Serial.println("Erisim noktasi baslatiliyor...");
  
  WiFi.softAP(agin_adi, sifre);    // erisim noktası olarak baslat

  IPAddress myIP = WiFi.softAPIP();   // erisim noktasının IP adresini bul
  Serial.print("Erisim noktasi IPsi: ");
  Serial.println(myIP);
  
  sunucu.on("/", anasayfa);
  sunucu.onNotFound(bilinmeyen);
  sunucu.begin();
}
//****************************************************************
void loop() {
  sunucu.handleClient();            // sunucuya baglanan istemcileri karsila
}
