#define MOSFET_PIN 5

const int PWM_FREQ = 5000;
const int PWM_RESOLUTION = 8;  // 0-255

void setup() {
  Serial.begin(115200);

  // Konfigurasi PWM
  ledcAttach(MOSFET_PIN, PWM_FREQ, PWM_RESOLUTION);

  Serial.println("Testing IRLZ44N + Heater");
}

void loop() {

  // PWM 100%
  ledcWrite(MOSFET_PIN, 255);
  Serial.println("PWM: 100%");
  delay(5000);

  // PWM 75%
  ledcWrite(MOSFET_PIN, 191);
  Serial.println("PWM: 75%");
  delay(5000);

  // PWM 50%
  ledcWrite(MOSFET_PIN, 128);
  Serial.println("PWM: 50%");
  delay(5000);

  // PWM 25%
  ledcWrite(MOSFET_PIN, 64);
  Serial.println("PWM: 25%");
  delay(5000);

  // PWM 0%
  ledcWrite(MOSFET_PIN, 0);
  Serial.println("PWM: 0%");
  delay(5000);
}