// Pin assignments
const int BUTTON_PIN = 2;  // Push button connected to Pin 2
const int LED_PIN = 13;    // LED connected to Pin 13

int buttonState = 0;       // Variable to store the button state

void setup() {
  // Initialize digital pin 13 as an output for the LED
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize digital pin 2 as an input for the push button
  pinMode(BUTTON_PIN, INPUT);
  
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read the state of the push button (HIGH or LOW)
  buttonState = digitalRead(BUTTON_PIN);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);  // Turn LED on
    Serial.println("Button: ON");
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn LED off
    Serial.println("Button: OFF");
  }

  delay(50); // Small delay to stabilize serial output readings
}