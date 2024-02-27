// using PWM with analogWrite(pin, value) to dim an LED
const int buttonPin = 2; // create a variable called buttonPin on 2
const int LED = 11; //create a variable called LED, assign it a value of 11

int LEDState = LOW; // create a variable called LEDState, initial value LOW
int buttonState = LOW; // create a variable called buttonState, initial value LOW
int lastButtonState = LOW; // create a variable called lastButtonState, initial value LOW

void setup() {
  pinMode(buttonPin, INPUT); // initialize pushbutton pin as an input
  pinMode(LED, OUTPUT);  //initialize LED pin as an output
}
void loop() {
  buttonState = digitalRead(buttonPin); //read value of buttonPin, store in buttonState
  delay(10); // small delay for button debouncing

  //conditional statement: if buttonState is HIGH and lastButtonState is LOW
  if (buttonState == HIGH && lastButtonState == LOW) {
    LEDState = !LEDState;  // assign opposite value of LEDState to LEDState
  } else {  // otherwise
    //do nothing
  }

  lastButtonState = buttonState; // assign current value of buttonState to lastButtonState

  if (LEDState ==1 ) {
    analogWrite(LED, 255); // write duty cycle at 100%
    delay(1000); // delay
    analogWrite(LED, 191); //write duty cycle at 75%
    delay(1000); // delay
    analogWrite(LED, 127); //write duty cycle at 50%
    delay(1000); // delay
    analogWrite(LED, 64); //write duty cycle at 25%
    delay(1000); // delay
    analogWrite(LED, 0); //write duty cycle at 0%
    delay(2000); // delay
  }
  else {
    for (int i = 0 ; i <= 255; i += 50) { // for loop fades LED value from 0 to 255, incrementing by 1
      analogWrite(LED, i); //writes value of i to pin
      delay(50);  // short delay so LED effect is visible
    }

    for (int i = 255 ; i >= 0; i -= 50) { // for loop fades LED value from 255 to 0, de-incrementing by 1
      analogWrite(LED, i);
      delay(30);
    }
  }
}
