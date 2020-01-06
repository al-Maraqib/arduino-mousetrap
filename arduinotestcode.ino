int enA = 4;
int in1 = 5;
int in2 = 11;
int pot = A0;
int potval;
int cpotval;
int sigPin = 12;
void setup()
{
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(sigPin, INPUT_PULLUP);
  digitalWrite(sigPin, LOW);
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(sigPin, LOW);

}

void loop()
{
  if (digitalRead(sigPin) == HIGH) {
    Serial.print("HIGH");
    Serial.print('\n');
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Accelerate from zero to maximum speed
    for (int i = 0; i < 255; i++)
    {
      analogWrite(enA, i);
      delay(20);
    }
    // Decelerate from maximum speed to zero
    for (int i = 255; i >= 0; --i)
    {
      analogWrite(enA, i);
      delay(20);
    }

    // Now turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(sigPin, LOW);
  }
  else if (digitalRead(sigPin) == LOW) {
    delay(50);
    Serial.print("LOW");
    Serial.print('\n');
  }
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}

// This function lets you control spinning direction of motors
//void directionControl()
//{
// Set motors to maximum speed
// For PWM maximum possible values are 0 to 255
// analogWrite(enA, 255);

// Turn on motor A & B
// digitalWrite(in1, HIGH);
//digitalWrite(in2, LOW);
//delay(2000);

// Now change motor directions
// digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//delay(2000);

// Turn off motors
// digitalWrite(in1, LOW);
//digitalWrite(in2, LOW);
//}

// This function lets you control speed of the motors
// void speedControl()
//{
// Turn on motors
//digitalWrite(in1, LOW);
//digitalWrite(in2, HIGH);

// Accelerate from zero to maximum speed
// for (int i = 0; i < 255; i++)
//{
//  analogWrite(enA, i);
//  delay(20);
// }
//
// Decelerate from maximum speed to zero
//  for (int i = 255; i >= 0; --i)
// {
//   analogWrite(enA, i);
//   delay(20);
// }

// Now turn off motors
// digitalWrite(in1, LOW);
// digitalWrite(in2, LOW);
//}
