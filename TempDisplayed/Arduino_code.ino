#include <LiquidCrystal.h>

// Initialize the LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// TMP36 sensor pin
const int tmpPin = A0;
float temperature;

void setup() {
  lcd.begin(16, 2);           // Set up the LCD's number of columns and rows
  lcd.print("Temp Monitor");  // Display welcome message
  delay(2000);                // Wait 2 seconds
  lcd.clear();                // Clear the screen

  Serial.begin(9600);         // Start serial monitor for debugging
}

void loop() {
  int sensorValue = analogRead(tmpPin);

  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1024.0);

  // Convert voltage to temperature in Celsius (TMP36)
  temperature = (voltage - 0.5) * 100.0;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1); // Show 1 decimal
  lcd.print((char)223);      // Print degree symbol
  lcd.print("C    ");        // Clear leftover chars

  // Display on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000); // Wait 1 second
}
