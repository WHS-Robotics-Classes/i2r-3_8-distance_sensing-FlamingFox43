#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  delay(150);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
if (distance <= 30) {
  digitalWrite(8, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(12, LOW);
  }
if (distance > 30) {
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
}
  if (distance < 10) {
  digitalWrite(8, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  }
}

