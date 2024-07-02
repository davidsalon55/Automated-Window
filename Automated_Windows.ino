  #include <Servo.h>  
  #include "DHT.h"

  #define DHTPIN 7 // what pin we're connected to temperature Sensor
  #define DHTTYPE DHT22 // DHT 22 (AM2302)
  DHT dht(DHTPIN, DHTTYPE);
  Servo servo1;  
                                                                    
  int sensor_pin = 4; //water-rain sensor
  int val;
  int angle;


  void setup()                            
  {
    Serial.begin(9600);                  
    servo1.attach(3); // servo motor
    pinMode(sensor_pin,INPUT);
    dht.begin();



  }


  void loop()                            
  {
    delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hi = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");
  / for temperatture sensor
    if (t < 38)
    {
      angle = 0;
      servo1.write(angle);
    }
    else
    {
      angle = 140;
    servo1.write(angle);
    }

  //  ///for rain water sensor

    val = digitalRead(sensor_pin);


    if (val==1)
    {   angle = 140;
      servo1.write(angle);
    }
    if (val==0)
    {  
      angle = 0;
    servo1.write(angle);
      }
  }



