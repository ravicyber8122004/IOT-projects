#include <LiquidCrystal.h>

// Initialize LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tmpPin = A0;
const int ledPin = 7;
const int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.print("Temp Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(tmpPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C  ");

  if (temperatureC > 30.0) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("!! ALERT HIGH !!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Normal ");
  }

  delay(1000);
}
