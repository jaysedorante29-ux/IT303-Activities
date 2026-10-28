int buttonPin = 2;
int led1Pin = 13;
int led2Pin = 12;

int buttonState = LOW;
int lastReading = LOW;
int pressCount = 0;

unsigned long lastChangeTime = 0;
const unsigned long debounceTime = 30;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);

  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastReading) {
    lastChangeTime = millis();
    lastReading = reading;
  }

  if (millis() - lastChangeTime >= debounceTime) {
    if (reading != buttonState) {
      buttonState = reading;
      digitalWrite(led1Pin, buttonState);

      if (buttonState == HIGH) {
        pressCount++;

        Serial.print("Press Count = ");
        Serial.println(pressCount);

        if (pressCount % 3 == 0) {
          digitalWrite(led2Pin, HIGH);
        } else {
          digitalWrite(led2Pin, LOW);
        }
      }
    }
  }

  delay(50);
}
