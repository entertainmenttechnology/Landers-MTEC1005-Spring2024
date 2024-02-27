const int LED = 11;
const int buttonPin = 2;

int LEDState = LOW;
int buttonState = LOW;
int lastButtonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  delay(10);

  if (buttonState == HIGH && lastButtonState == LOW) {
    LEDState = !LEDState;
  } else {
  }
  lastButtonState = buttonState;
  if (LEDState == 1) {
    analogWrite(LED, 127);
  } else {
    analogWrite(LED, 0);
  }
 }
