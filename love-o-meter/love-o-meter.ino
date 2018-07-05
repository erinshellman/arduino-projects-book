const int sensorPin = A0;
const float baselineTemp = 27.0;

void setup() {
  
  Serial.begin(9600); // opens a serial port

  // initialize the digital pin directions and turn off
  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // read the temperature sensor
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - 0.50) * 100;

  // send the temperature sensor values to the computer
  Serial.print("Sensor Value: " );
  Serial.print(sensorVal);
  Serial.print("\n");


  Serial.print("Volts: ");
  Serial.print(voltage);
  Serial.print("\n");

  Serial.print("Degrees C: ");
  Serial.print(temperature);
  Serial.print("\n");

  if (temperature < baselineTemp) {

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 3 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
