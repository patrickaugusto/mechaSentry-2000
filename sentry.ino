#include <Servo.h>

//declaração dos servos
Servo servoX;
Servo servoY;
Servo servoShoot;

int led = 3;

//definição dos pinos dos servos
int servoXPin = 5;
int servoYPin = 6;
int servoShootPin = 3;

//variaveis de posição dos servos
int posX = 0;
int posY = 0;

//sensor
int trigPin = 9;
int echoPin = 10;

int duration;
double distance;


void setup() {
  
  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
  servoShoot.attach(servoShootPin);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servoX.write(posX); 
  servoY.write(posY);
  
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
    
    String data = Serial.readStringUntil('\n');
    Serial.println(data);
    
    if (data == "d") {
      posX = min(posX + 10, 180);
      servoX.write(posX);
    }
    
    else if (data == "a") {
      posX = max(posX - 10, 0);
      servoX.write(posX);
    }
    
    if (data == "w") {
      posY = min(posY + 10, 180);
      servoY.write(posY);
    }

    else if (data == "s") {
      posY = max(posY - 10, 0);
      servoY.write(posY);
    }
  }
  
  digitalWrite(trigPin, LOW);
  delay(5);
  digitalWrite(trigPin, HIGH);
  delay(5);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  servoShoot.write(distance <= 100 ? 180 : 90);

  delay(10);
}
