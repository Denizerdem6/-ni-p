// Buton ve Jumper Pinleri: D9(b2), D8(b1), D7(b0)
const int buttonPins[] = {9, 8, 7}; 

// LED Pinleri: D4(LED2), D3(LED1), D2(LED0)
const int ledPins[] = {4, 3, 2};    

void setup() {
  // Seri Port ekranını başlatıyoruz
  Serial.begin(9600);
  
  for (int i = 0; i < 3; i++) {
    // Föydeki şarta göre buton pinleri INPUT_PULLUP yapılıyor
    pinMode(buttonPins[i], INPUT_PULLUP);
    
    // LED pinleri çıkış (OUTPUT) olarak ayarlanıyor. 
    // Bu ayar sayesinde LED'ler tam parlaklığında yanacaktır.
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // INPUT_PULLUP modunda kablo/buton GND'ye değdiğinde 0, boştayken 1 değeri gelir.
  // Föydeki "basılı durumu 1, bırakılmış durumu 0" kuralını uygulamak için 
  // gelen değeri ! (DEĞİL) operatörü ile ters çeviriyoruz.
  int b2 = !digitalRead(buttonPins[0]); // D9 pini (Jumper)
  int b1 = !digitalRead(buttonPins[1]); // D8 pini (Jumper)
  int b0 = !digitalRead(buttonPins[2]); // D7 pini (Fiziksel Buton)

  // Bitsel kaydırma (<<) ve VEYA (|) operatörleri ile 3 bitlik sayıyı hesaplama
  int sayi = (b2 << 2) | (b1 << 1) | b0;

  // Hesaplanan 0-7 arası sayıya göre ilgili LED'leri yakma
  // Sayının ilgili bitini kontrol edip LED'e yolluyoruz
  digitalWrite(ledPins[0], (sayi >> 2) & 1); // D4 (LED 2 - En anlamlı bit)
  digitalWrite(ledPins[1], (sayi >> 1) & 1); // D3 (LED 1)
  digitalWrite(ledPins[2], sayi & 1);        // D2 (LED 0 - En düşük anlamlı bit)

  // Sonuçları Serial Monitor (Seri Port Ekranı) üzerine yazdırma
  Serial.print("Bitler (b2 b1 b0): ");
  Serial.print(b2); Serial.print(b1); Serial.println(b0);
  Serial.print("Onluk Deger: ");
  Serial.println(sayi);

  // Dalgalanmaları engellemek için kısa bir bekleme süresi
  delay(150); 
}