#include "LowPower.h"
#include <arm_math.h>

#include <Arduino_APDS9960.h>
#include <Arduino_HTS221.h>
#include <Arduino_LPS22HB.h>
#include <Arduino_LSM9DS1.h>
#include <PDM.h>

#include <ArduinoBLE.h>

const int VERSION = 0x00000001;
const float TEMPERATURE_CALIBRATION = -5.0;

#define SCIENCE_KIT_UUID(val) ("555a0002-" val "-467a-9538-01f0652c74e8")
#define RESISTANCE_PIN A0
#define VOLTAGE_BUFFER_SIZE 16

//#define DEBUG 0

BLEService                     service                    (SCIENCE_KIT_UUID("0000"));
BLEUnsignedIntCharacteristic   versionCharacteristic      (SCIENCE_KIT_UUID("0001"), BLERead);
BLECharacteristic              accelerationCharacteristic (SCIENCE_KIT_UUID("0011"), BLENotify, 3 * sizeof(float));
BLECharacteristic              gyroscopeCharacteristic    (SCIENCE_KIT_UUID("0012"), BLENotify, 3 * sizeof(float));
BLECharacteristic              magneticFieldCharacteristic(SCIENCE_KIT_UUID("0013"), BLENotify, 3 * sizeof(float));
BLEFloatCharacteristic         temperatureCharacteristic  (SCIENCE_KIT_UUID("0014"), BLENotify);
BLEFloatCharacteristic         pressureCharacteristic     (SCIENCE_KIT_UUID("0015"), BLENotify);
BLEFloatCharacteristic         humidityCharacteristic     (SCIENCE_KIT_UUID("0016"), BLENotify);
BLEUnsignedIntCharacteristic   proximityCharacteristic    (SCIENCE_KIT_UUID("0017"), BLENotify);
BLECharacteristic              colorCharacteristic        (SCIENCE_KIT_UUID("0018"), BLENotify, 4 * sizeof(int));
BLEUnsignedShortCharacteristic soundPressureCharacteristic(SCIENCE_KIT_UUID("0019"), BLENotify);
BLEFloatCharacteristic         resistanceCharacteristic   (SCIENCE_KIT_UUID("0020"), BLENotify);

byte voltageBufferIndex = 0;
bool voltageBufferFilled = false;
short soundSampleBuffer[256];
short voltageSampleBuffer[VOLTAGE_BUFFER_SIZE];

void onPDMdata() {
  // query the number of bytes available
  int bytesAvailable = PDM.available();

  // read into the sample buffer
  PDM.read(soundSampleBuffer, bytesAvailable);
}

uint16_t getSoundAverage() {
  uint32_t avg = 0;
  for (int i = 0; i < sizeof(soundSampleBuffer)/sizeof(soundSampleBuffer[0]); i++) {
    avg += soundSampleBuffer[i]*soundSampleBuffer[i];
  }
  return sqrt(avg);
}

void readVoltage() {
  voltageSampleBuffer[voltageBufferIndex] = analogRead(RESISTANCE_PIN);  
  if (!voltageBufferFilled && voltageBufferIndex == VOLTAGE_BUFFER_SIZE - 1) {
    voltageBufferFilled = true;
  }
  voltageBufferIndex = (++voltageBufferIndex) % VOLTAGE_BUFFER_SIZE;
}

uint16_t getVoltageAverage() {
  uint16_t avg = 0;
  byte upperBound = voltageBufferFilled ? VOLTAGE_BUFFER_SIZE : voltageBufferIndex;
  for (int i = 0; i < upperBound; i++) {
    avg += voltageSampleBuffer[i];
  }
  return avg / upperBound;
}

// String to calculate the local and device name
String name;
unsigned long lastNotify = 0;

void printSerialMsg(const char * msg) {
  #ifdef DEBUG
  if (Serial) {
    Serial.println(msg);
  }
  #endif
}

void blinkLoop() {
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");
  #endif

  delay(2000);

  pinMode(RESISTANCE_PIN, INPUT); // Used for reading resistance

  if (!APDS.begin()) {
    printSerialMsg("Failed to initialized APDS!");
    blinkLoop();
  }

  if (!HTS.begin()) {
    printSerialMsg("Failed to initialized HTS!");
    blinkLoop();
  }

  if (!BARO.begin()) {
    printSerialMsg("Failed to initialized BARO!");
    blinkLoop();
  }

  if (!IMU.begin()) {
    printSerialMsg("Failed to initialized IMU!");
    blinkLoop();
  }

  PDM.onReceive(onPDMdata);
  if (!PDM.begin(1, 16000)) {
    printSerialMsg("Failed to start PDM!");
    blinkLoop();
  }

  if (!BLE.begin()) {
    printSerialMsg("Failed to initialized BLE!");
    blinkLoop();
  }

  String address = BLE.address();
  #ifdef DEBUG
  if (Serial) {
    Serial.print("address = ");
    Serial.println(address);
  }
  #endif
  address.toUpperCase();

  name = "BLE Sense - ";
  name += address[address.length() - 5];
  name += address[address.length() - 4];
  name += address[address.length() - 2];
  name += address[address.length() - 1];

  #ifdef DEBUG
  if (Serial) {
    Serial.print("name = ");
    Serial.println(name);
  }
  #endif

  BLE.setLocalName(name.c_str());
  BLE.setDeviceName(name.c_str());
  BLE.setAdvertisedService(service);

  service.addCharacteristic(versionCharacteristic);
  service.addCharacteristic(accelerationCharacteristic);
  service.addCharacteristic(gyroscopeCharacteristic);
  service.addCharacteristic(magneticFieldCharacteristic);
  service.addCharacteristic(temperatureCharacteristic);
  service.addCharacteristic(pressureCharacteristic);
  service.addCharacteristic(humidityCharacteristic);
  service.addCharacteristic(proximityCharacteristic);
  service.addCharacteristic(colorCharacteristic);
  service.addCharacteristic(soundPressureCharacteristic);
  service.addCharacteristic(resistanceCharacteristic);

  versionCharacteristic.setValue(VERSION);

  BLE.addService(service);
  BLE.advertise();

  lowPower();
}

void loop() {
  BLE.poll(1000);
  while (BLE.connected()) {
    lowPowerBleWait(100);
    updateSubscribedCharacteristics();
  }
}

void updateSubscribedCharacteristics() {
  if (accelerationCharacteristic.subscribed()) {
    float acceleration[3];
    if (IMU.accelerationAvailable() && IMU.readAcceleration(acceleration[0], acceleration[1], acceleration[2])) {
      accelerationCharacteristic.writeValue((byte*)acceleration, sizeof(acceleration));
    }
  }
  if (gyroscopeCharacteristic.subscribed()) {
    float gyroscope[3];
    if (IMU.gyroscopeAvailable() && IMU.readGyroscope(gyroscope[0], gyroscope[1], gyroscope[2])) {
      gyroscopeCharacteristic.writeValue((byte*)gyroscope, sizeof(gyroscope));
    }
  }
  
  if (magneticFieldCharacteristic.subscribed()) {
    float magneticField[3];
    if (IMU.magneticFieldAvailable() && IMU.readMagneticField(magneticField[0], magneticField[1], magneticField[2])) {
      magneticFieldCharacteristic.writeValue((byte*)magneticField, sizeof(magneticField));
    }
  }
  if (soundPressureCharacteristic.subscribed()) {
    uint16_t sound = getSoundAverage();
    soundPressureCharacteristic.writeValue(sound);
  }
  if (proximityCharacteristic.subscribed() && APDS.proximityAvailable()) {
    uint32_t proximity = APDS.readProximity();
    proximityCharacteristic.writeValue(proximity);
  }
  if (colorCharacteristic.subscribed() && APDS.colorAvailable()) {
    int color[4];
    APDS.readColor(color[0], color[1], color[2], color[3]);
    colorCharacteristic.writeValue((byte*)color, sizeof(color));
  }
  bool doTemperature = temperatureCharacteristic.subscribed();
  bool doHumidity = humidityCharacteristic.subscribed();
  if (doTemperature || doHumidity) {
    float temperature = HTS.readTemperature();
    float temperatureCalibrated = temperature + TEMPERATURE_CALIBRATION;
    if (doTemperature) {
      temperatureCharacteristic.writeValue(temperatureCalibrated);
    }
    if (doHumidity) {
      float humidity = HTS.readHumidity();
      float dp = temperature - ((100.0 - humidity) / 5.0);
      float humidityCalibrated = 100.0 - (5.0 * (temperatureCalibrated - dp));
      humidityCharacteristic.writeValue(humidityCalibrated);
    }
  }
  if (pressureCharacteristic.subscribed()) {
    float pressure = BARO.readPressure();
    pressureCharacteristic.writeValue(pressure);
  }

  if(resistanceCharacteristic.subscribed()){
    readVoltage();
    uint16_t measuredValue = getVoltageAverage();
    float voltageRatio = 1024.0f / measuredValue;
    resistanceCharacteristic.writeValue(voltageRatio);
  }
}
