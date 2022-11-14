#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 13
#define DHTTYPE    DHT11 
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

int led1 = 17;  // LED connected to digital pin 17
int led2 = 16;  // LED connected to digital pin 16
int led3 = 5;  // LED connected to digital pin 5

int btn1 = 18;    // pushbutton connected to digital pin 18
int btn2 = 19;    // pushbutton connected to digital pin 19

int dht11 = 13; // 온습도센서
int var = 36; // 가변저항

int val = 0;

void setup() {

  // 1. led
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // 2. btn
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  // 3. PWM
  ledcSetup(0, 5000, 8);
  ledcAttachPin(led1, 0);

  // 4. var
  pinMode(var, INPUT);

  // 5. uart
  pinMode(A0, INPUT);
  Serial.begin(9600);

  // Initialize device.
  dht.begin();
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);

  // Set delay between sensor readings based on sensor details.
  //delayMS = sensor.min_delay / 1000;

}

int pwm = 0;

void loop() {

  delay(100);

  if(digitalRead(btn1)==0){
    pwm += 50;
    if(pwm>255) pwm -=50;
  }
  if(digitalRead(btn2)==0){
    pwm -= 50;
    if(pwm>255) pwm +=50;
  }


  if (val > 4500 / 270 * 30){
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else if (val < 4500 / 270 * 15){
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
  }
  else {
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  ledcWrite(0, pwm);

  // uart input
  if(Serial.available()){
    String duty = Serial.readString();
    const char* str = &duty[0];

    pwm = atoi(str);
    if (pwm > 255) pwm = 255;
    if (pwm < 0) pwm = 0;
  }

  // regVal
  val = analogRead(var);

  // uart
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("ID: "));
    Serial.print("myID / ");
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.print(F("°C / PWM : "));
    Serial.println(pwm);
  }  
}