#define BLYNK_TEMPLATE_ID "TMPL6z7v013Sg"
#define BLYNK_DEVICE_NAME "Papan Informasi Otomatis berbasis LCD dan Blynk"
#define BLYNK_TEMPLATE_NAME "Papan Informasi Otomatis berbasis LCD dan Blynk"
#define BLYNK_AUTH_TOKEN "6_nKU8EGgh_Ahp0p3-tLht7CndyMEkTa"

#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS1307 rtc;
BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

bool modeManual = false;
String pesanAktif = "";
int scrollPos = 0;

void resetBarisDua() {
  modeManual = false;
  lcd.setCursor(0, 1);
  lcd.print("No Information  ");
}

void scrollPesan() {
  if (modeManual) {
    if (pesanAktif.length() > 16) {
      lcd.setCursor(0, 1);
      lcd.print(pesanAktif.substring(scrollPos, scrollPos + 16));
      scrollPos++;
      if (scrollPos > pesanAktif.length() - 16) scrollPos = 0;
    } else {
      // Tampilkan pesan pendek tanpa bergerak
      lcd.setCursor(0, 1);
      lcd.print(pesanAktif);
    }
  }
}

BLYNK_WRITE(V0) {
  pesanAktif = param.asStr();
  modeManual = true;
  scrollPos = 0; // Reset posisi ke awal
  
  // Tambahan: Bersihkan baris kedua secara manual dengan spasi sebelum teks baru
  lcd.setCursor(0, 1);
  lcd.print("                "); 
  
  timer.setTimeout(30000L, resetBarisDua);
}

void setup() {
  lcd.init();
  lcd.backlight();
  rtc.begin();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(300L, scrollPesan); // Animasi berjalan tiap 300ms
  lcd.setCursor(0, 1);
  lcd.print("No Information  ");
}

void loop() {
  Blynk.run();
  timer.run();
  
  if (!modeManual) {
    static int lastMinute = -1;
    DateTime now = rtc.now();
    if (now.minute() != lastMinute) {
      lcd.setCursor(0, 0);
      lcd.print("Jam: ");
      if (now.hour() < 10) lcd.print('0');
      lcd.print(now.hour());
      lcd.print(":");
      if (now.minute() < 10) lcd.print('0');
      lcd.print(now.minute());
      lcd.print("    ");
      lastMinute = now.minute();
    }
  }
}