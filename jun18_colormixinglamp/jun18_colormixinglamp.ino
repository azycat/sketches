// 4-pin RGB LED PWM input
const int redLEDPin = 9;
const int greenLEDPin = 10;
const int blueLEDPin = 11;

// analog phototransistor input
const int redSensorPin = A0;
const int greenSensorPin = A2;
const int blueSensorPin = A1;

// variables to store the sensor readings
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

// light levels of each LED
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int sensorDelay = 5;
  
void setup() {
  // set the values of the sensors in the serial monitor
  Serial.begin(9600);

  // define the LED pins as outputs
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

}

void loop() {
  readSensorPins();
  printRawValues();

  // convert the sensor readings to update the LEDs
  updateLED(&redLEDPin, &redValue, redSensorValue);
  updateLED(&greenLEDPin, &greenValue, greenSensorValue);
  updateLED(&blueLEDPin, &blueValue, blueSensorValue);

}

void updateLED(int *LEDPin, int *LEDValue, int sensorValue) {
  // convert analog sensor reading to digital
  *LEDValue = sensorValue/4;
  // set the LED light values
  analogWrite(*LEDPin, *LEDValue);
}

void readSensorPins() {
  // read the analog sensor values
  redSensorValue = analogRead(redSensorPin);
  delay(sensorDelay);
  greenSensorValue = analogRead(greenSensorPin);
  delay(sensorDelay);
  blueSensorValue = analogRead(blueSensorPin);
  delay(sensorDelay);
}

void printRawValues() {
  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("Raw Sensor Values \t green: ");
  Serial.print(greenSensorValue);
  Serial.print("Raw Sensor Values \t blue: ");
  Serial.print(blueSensorValue);
}
