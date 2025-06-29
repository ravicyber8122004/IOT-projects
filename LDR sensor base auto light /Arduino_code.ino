// Pin Definitions
const int ldrPin = A0;   // LDR sensor connected to analog pin A0
const int ledPin = 13;   // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);      // Set LED pin as OUTPUT
  Serial.begin(9600);           // Start serial monitor for debugging
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);          // Print it for observation

  if (ldrValue < 500) {              // Adjust threshold as per room light
    digitalWrite(ledPin, HIGH);      // Turn ON LED when dark
  } else {
    digitalWrite(ledPin, LOW);       // Turn OFF LED when bright
  }

  delay(200); // Slight delay for stability
}

