//Coding:

// Define pins for left and right IR sensors
int leftSensor = 2;
int rightSensor = 3;

// Define pins for motor control via L298N
int ENA = 9; // Enable pin for motor A
int IN1 = 4; // Input 1 for motor A
int IN2 = 5; // Input 2 for motor A
int IN3 = 6; // Input 1 for motor B
int IN4 = 7; // Input 2 for motor B
int ENB = 10; // Enable pin for motor B

void setup() {
Serial.begin(9600);
// Initialize sensor pins as input
pinMode(leftSensor, INPUT);
pinMode(rightSensor, INPUT);

// Initialize motor control pins as output
pinMode(ENA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENB, OUTPUT);

// Set motor speed

25

analogWrite(ENA, 150);
analogWrite(ENB, 150);
}

void loop() {
// Read sensors
int leftState = digitalRead(leftSensor);
int rightState = digitalRead(rightSensor);

// digitalWrite(IN1, HIGH);
// digitalWrite(IN2, LOW);
// digitalWrite(IN3, HIGH);
// digitalWrite(IN4, LOW);

if (leftState == LOW && rightState == LOW) {
// Both sensors on the line - move forward
Serial.println("Move Forward");
forward();
} else if (leftState == LOW && rightState == HIGH) {
// Left sensor on the line, right sensor off - turn left
Serial.println("Turn left");
turnLeft();
} else if (leftState == HIGH && rightState == LOW) {
// Right sensor on the line, left sensor off - turn right
Serial.println("Turn Right");
turnRight();
} else {
// Both sensors off the line - stop
Serial.println("Stop motors");
// forward();
stopMotors();
}
}

26

void forward() {
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}

void turnLeft() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}

void turnRight() {
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
}

void stopMotors() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
}