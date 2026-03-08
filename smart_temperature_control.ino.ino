int tempPin = A0;
int ledPin = 8;
int buzzerPin = 9;

float temperature;
int threshold = 30;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(tempPin);
  temperature = (sensorValue * 5.0 * 100.0) / 1024.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > threshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("ALERT: Temperature High!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Temperature Normal");
  }

  delay(1000);
}