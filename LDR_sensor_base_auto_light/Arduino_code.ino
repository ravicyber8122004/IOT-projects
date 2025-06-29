const int ldrPin = A0;   // Analog pin connected to LDR
const int ledPin = 13;   // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < 500) {             // Adjust this threshold as needed
    digitalWrite(ledPin, HIGH);     // Turn LED ON in darkness
  } else {
    digitalWrite(ledPin, LOW);      // Turn LED OFF in light
  }

  delay(200); // Small delay for stability
}
