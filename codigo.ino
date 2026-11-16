// Pines de hardware
const int trigPin = 12;
const int echoPin = 13;
const int buzzerPin = 8;

// Umbrales de deteccion (cm)
const int maxDistanceCm = 50;
const int minDistanceCm = 3;

// Parametros de calibracion del sensor y alertas
const float soundSpeedCmPerUs = 0.0343;
const int criticalFrequencyHz = 3500;
const int warningFrequencyHz = 3000;
const int beepDurationMs = 40;
const int minPauseMs = 50;
const int maxPauseMs = 600;
const int idleDelayMs = 100;
const long sensorTimeoutUs = 30000;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distanceCm = measureDistanceCm();

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  triggerProximityAlert(distanceCm);
}

// Emite el pulso ultrasonico y calcula la distancia al obstaculo en centimetros
int measureDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long echoDurationUs = pulseIn(echoPin, HIGH, sensorTimeoutUs);
  if (echoDurationUs == 0) {
    return -1;
  }

  return (echoDurationUs * soundSpeedCmPerUs) / 2;
}

// Controla la frecuencia e intermitencia del buzzer segun la proximidad
void triggerProximityAlert(int distanceCm) {
  if (distanceCm > 0 && distanceCm <= maxDistanceCm) {
    if (distanceCm <= minDistanceCm) {
      tone(buzzerPin, criticalFrequencyHz);
    } else {
      int pauseDurationMs = map(distanceCm, minDistanceCm, maxDistanceCm, minPauseMs, maxPauseMs);
      tone(buzzerPin, warningFrequencyHz);
      delay(beepDurationMs);
      noTone(buzzerPin);
      delay(pauseDurationMs);
    }
  } else {
    noTone(buzzerPin);
    delay(idleDelayMs);
  }
}