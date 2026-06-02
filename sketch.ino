#define RAIN_SENSOR_PIN 34
#define LED_PIN 2
#define BUZZER_PIN 15

int threshold = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int rainValue = analogRead(RAIN_SENSOR_PIN);

  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < threshold) {
    Serial.println("Rain Detected!");

    digitalWrite(LED_PIN, HIGH);

    // Buzzer ON
    for (int i = 0; i < 100; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(BUZZER_PIN, LOW);
      delayMicroseconds(500);
    }
  }
  else {
    Serial.println("No Rain");

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500);
}
