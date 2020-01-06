/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/

// defines pins numbers
const int trigPin1 = 11;
const int echoPin1 = 12;
const int trigPin2 = 3;
const int echoPin2 = 4;
const int r2Pin = A5;
const int gPin = A4;
const int bPin = A3;
const int yPin = 7;
const int rPin = 6;
const int sigPin = 10;
int x = 23.5;
int y = 50;
// defines variables
long duration1;
int distance1;
long duration2;
int distance2;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(r2Pin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(yPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);

  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  // Serial.print("Duration1: ");
  // Serial.println(duration1);
  Serial.println("Distance1: ");
  Serial.println(distance1);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);

  // Calculating the distance
  distance2 = duration2 * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  //Serial.print("Duration2: ");
  //Serial.println(duration2);
  Serial.println("Distance2: ");
  Serial.println(distance2);

  if (distance1 > y) {
    if (distance2 < x) {
     Serial.println("HIGH"); 
      digitalWrite(sigPin, HIGH);
      analogWrite(gPin, 255);
      delay(50);
      analogWrite(gPin, 0);
      digitalWrite(sigPin, LOW);
    }
    else if (distance2 > x and distance2 < y) {
      Serial.println("HIGH");
      digitalWrite(sigPin, HIGH);
      analogWrite(r2Pin, 255);
      analogWrite(bPin, 255);
      delay(50);
      analogWrite(r2Pin, 0);
      analogWrite(bPin, 0);
      digitalWrite(sigPin, LOW);
    }
    else if (distance2 > y) {
      Serial.println("LOW");
      digitalWrite(sigPin, LOW);
      digitalWrite(yPin, HIGH);
      delay(50);
      digitalWrite(yPin, LOW);
    }
  }
else if (distance1 < y) {
  Serial.println("LOW");
  digitalWrite(sigPin, LOW);
  digitalWrite(rPin, HIGH);
  delay(50);
  digitalWrite(rPin, LOW);
}
}
