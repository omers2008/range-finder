#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
long duration;
int distance;
const int BUZZ_PIN = 7;
const char* LOW_STATUS = "LOW";
const char* MID_STATUS = "MID";
const char* HIGH_STATUS = "HIGH";
const char* VALUE_LABEL = "Distance:";
const int TIMEOUT = 25000; // 25 milliseconds, a bit more than the round trip at max range

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(BUZZ_PIN, OUTPUT); // Sets the trigPin as an Output
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  delay(150);
  // Clears the trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT);

  if (duration == 0) {  // Check if timeout occurred
    distance = -1;  // Use -1 or another sentinel value to indicate no valid echo was received
  } else {
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and return)
  }

  lcd.setCursor(0, 1);
  if (distance == -1) {
    lcd.print("Out of range ");
  } else {
    lcd.print(VALUE_LABEL);
    lcd.print(distance);
    lcd.print(" cm  ");
  }

  if (distance < 50 && distance != -1) {
    lcd.setCursor(0, 0);
    lcd.print(LOW_STATUS);
    lcd.print("   ");
    digitalWrite(BUZZ_PIN, HIGH);
  } else if (distance >= 50 && distance < 100) {
    lcd.setCursor(0, 0);
    lcd.print(MID_STATUS);
    lcd.print("   ");
    digitalWrite(BUZZ_PIN, LOW);
  } else if (distance >= 100) {
    lcd.setCursor(0, 0);
    lcd.print(HIGH_STATUS);
    lcd.print("   ");
    digitalWrite(BUZZ_PIN, LOW);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("ERROR      ");
    digitalWrite(BUZZ_PIN, LOW);
  }
  Serial.println(distance);
}
