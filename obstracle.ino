// Ultrasonic sensor pin configuration
#define TRIGGER_PIN 2
#define ECHO_PIN 3

// LED pin
#define LED_PIN 13

// Buzzer pin
#define BUZZER_PIN 4

// Maximum distance to detect obstacles (in inches)
#define MAX_DISTANCE_INCHES 20

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int distanceInInches = measureDistanceInInches();

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceInInches);
  Serial.println(" inches");

  if (distanceInInches < MAX_DISTANCE_INCHES) {
    // Obstacle detected, turn on the LED and buzzer
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    // No obstacle, turn off the LED and buzzer
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Delay before the next measurement
  delay(1000); // Adjust the delay as needed
}

int measureDistanceInInches() {
  long duration;
  int distanceInInches;

  // Trigger ultrasonic sensor to measure distance
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure the pulse duration from the echo pin
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in inches
  distanceInInches = duration / 74 / 2;

  return distanceInInches;
}
