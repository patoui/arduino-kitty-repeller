#define trigPin 13
#define echoPin 12
#define buzzer 11
#define led2 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 2 / 29.1; // in centimeters

  // Toggle light and sound
  if (distance < 10) {
    digitalWrite(led2,LOW); // Turn off Green light
    tone(buzzer, 10000); // Send sound...
  }
  else {
    noTone(buzzer);           // Stop sound...
    digitalWrite(led2,HIGH);  // Turn off Green light
  }

  // Outside of sensors range
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
