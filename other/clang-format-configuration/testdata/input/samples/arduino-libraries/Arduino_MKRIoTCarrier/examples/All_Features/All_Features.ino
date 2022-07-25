/*  
This sketch will test the carrier board
Unless the touch pads
*/

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier; //Constructor of the carrier maybe we can include it on the library itself

float temperature;
float humidity;

int light;
int r,g,b;

float pressure;

float Gx, Gy, Gz;
float Ax, Ay, Az;

void setup() {
  // put your setup code here, to run once:
  //Start Serial comm
  Serial.begin(9600);
  while (!Serial);  //Wait to open the Serial monitor to start the program and see details on errors

  //Init everything and outputs the errors
  carrier.noCase();
  carrier.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //LED show up
  //( led index , red , green , blue )
  carrier.leds.setPixelColor(0,  0 ,  0 , 20);
  carrier.leds.setPixelColor(1,  0 , 20 , 0 );
  carrier.leds.setPixelColor(2, 20 ,  0 , 0 );
  carrier.leds.setPixelColor(3,  0 , 20 , 20);
  carrier.leds.setPixelColor(4, 20 , 20 , 20);
  carrier.leds.show();
  
  //Function to display
  displayTitle();

  //Buzzer sound sound(freq)
  /*
   * Can be used also with tone(BUZZER , freq);
   */
  carrier.Buzzer.sound(8000);
  delay(100);
  carrier.Buzzer.noSound();
  
  //Simple relay open and close loop
  /*  Relay function
     open()  - goes to Normally Open (NO) circuit, status LED will be ON
     close() - goes to Normally Close (NC) circuit, status LED will be OFF
  */
  carrier.Relay1.close();
  delay(1000);
  printStatus();
  delay(100);

  carrier.Relay1.open();
  delay(1000);
  printStatus();
  delay(100);

  printStatus();
  carrier.Relay2.close();
  delay(1000);
  printStatus();
  delay(100);

  carrier.Relay2.open();
  delay(1000);
  printStatus();
  delay(100);

  delay(1000);

  //SENSORS
  //RGB and Light sensor
  //It set the values that you point inside the brackets
  while (! carrier.Light.colorAvailable()) {
    delay(5);
  }
  carrier.Light.readColor(r,g, b, light);
  Serial.println("Ambient light sensor");
  Serial.print("\t light: ");
  Serial.println(light);
  displayLight();

  //Env sensor (Temp and Hum)
  temperature = carrier.Env.readTemperature();
  humidity = carrier.Env.readHumidity();
  Serial.println("Env sensor");
  Serial.print("\t Temperature:");
  Serial.println(temperature);
  Serial.print("\t Humidity: ");
  Serial.println(humidity);
  displayEnv();

  //Barometric sensor
  pressure = carrier.Pressure.readPressure();
  Serial.println("Barometric sensor");
  Serial.print("\t Pressure:");
  Serial.println(pressure);
  displayBaro();

  //IMU
  //Gyroscope
  Serial.println("IMU module");
  carrier.IMUmodule.readGyroscope(Gx, Gy, Gz);
  Serial.println("Gyroscope:");
  Serial.print ("\t X:");
  Serial.println(Gx);
  Serial.print ("\t Y:");
  Serial.println(Gy);
  Serial.print ("\t Z:");
  Serial.println(Gz);

  //Accelerometer
  carrier.IMUmodule.readAcceleration(Ax, Ay, Az);
  Serial.println("Accelerometer:");
  Serial.print ("\t X:");
  Serial.println(Ax);
  Serial.print ("\t Y:");
  Serial.println(Ay);
  Serial.print ("\t Z:");
  Serial.println(Az);

  Serial.println();
  Serial.println("--- \t END OF READS \t ---");
  Serial.println();



}

void displayTitle() {
  carrier.display.fillScreen(ST77XX_BLACK);

  carrier.display.setCursor(80, 120);
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.print("MKR ");
  carrier.display.setTextColor(ST77XX_GREEN);
  carrier.display.print("IoT ");
  carrier.display.setTextColor(ST77XX_MAGENTA);
  carrier.display.print("Carrier");
  carrier.display.setCursor(105, 130);
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.print("Library");
}

void printStatus() {
  carrier.display.fillScreen(ST77XX_BLACK); //oled clear()
  carrier.display.setCursor(70, 100);
  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.print("Relay 1 status: ");
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.print(carrier.Relay1.getStatus());

  carrier.display.setCursor(70, 120);
  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.print("Relay 2 status: ");
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.print(carrier.Relay2.getStatus());

}

void displayLight() {
  carrier.display.fillScreen(ST77XX_BLACK); //oled clear()
  carrier.display.setCursor(70, 100);
  carrier.display.print("Light:  ");
  carrier.display.setTextColor(ST77XX_MAGENTA);
  carrier.display.print(light);
  delay(2500);
}

void displayEnv() {
  carrier.display.fillScreen(ST77XX_BLACK); //oled clear()
  carrier.display.setCursor(70, 100);
  carrier.display.print("Humidity:  ");
  carrier.display.setTextColor(ST77XX_MAGENTA);
  carrier.display.print(humidity);
  carrier.display.setCursor(70, 115);
  carrier.display.print("Temperature:  ");
  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.print(temperature);
  delay(2500);
}

void displayBaro() {
}
