// Define RGB LED pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);    // Red
  delay(1000);

  setColor(0, 255, 0);    // Green
  delay(1000);

  setColor(0, 0, 255);    // Blue
  delay(1000);

  setColor(255, 0, 255);  // Purple (Red + Blue)
  delay(1000);
}

void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
