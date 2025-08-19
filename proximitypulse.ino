#define trigPin 9  // Trig on pin 9
#define echoPin 10 // Echo on pin 10

int leds[3] = {5, 6, 7};

void setup() {
  Serial.begin(9600); 
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set each LED pin as OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us HIGH pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes to receive the echo
  long duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance in cm; speed of sound assumed to be 340m/s
  long distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn off all LEDs
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }

  // Light up LEDs based on distance from sensor
  if (distance > 20) {
    digitalWrite(leds[2], HIGH); // Farther than 20 cm
  } 
  else if (distance > 9 && distance <= 20) {
    digitalWrite(leds[1], HIGH); // Between 10 and 20 cm
  } 
  else if (distance > 4 && distance <= 9){
    digitalWrite(leds[0], HIGH);// Less than or equal to 10 cm
  }
  else {
    digitalWrite(leds[0], HIGH); 
    delay(200);
    digitalWrite(leds[0], LOW);
    delay(20);
  }

  // Small delay between readings
  delay(500);
}
