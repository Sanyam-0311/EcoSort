// Define moisture sensor and relay module pins 
#define MOISTURE_SENSOR_PIN A0  // Analog pin for the moisture sensor 
#define RELAY_PIN 9             // Digital pin for the relay module 
#define RELAY_PIN1  10
#define gasSensorPin A1         // Analog pin for the gas sensor 
#define MOISTURE_THRESHOLD 37  // Define a moisture threshold (adjust as needed) mm/m^3
#define GAS_THRESHOLD 200           //the value is in ppm 
const int metalproximitySensorPin = 2;   // Digital pin connected to the proximity sensor 
const int proximitySensorPin=3;
bool metalDetected = false; 
 
 
void setup() { 
  Serial.begin(9600); 
  pinMode(MOISTURE_SENSOR_PIN, INPUT); 
  pinMode(gasSensorPin,INPUT); 
  pinMode(RELAY_PIN, OUTPUT); 
  pinMode(proximitySensorPin, INPUT); 
  digitalWrite(RELAY_PIN, LOW);  //relay is initially off for the metallic waste collection 
  digitalWrite(RELAY_PIN1, LOW);  //relay is initially off for the moisture waste 
} 
 
void loop() 
{ 
  // Reads the moisture sensor value 
  int objdetection=digitalRead(proximitySensorPin);
  int moistureValue = analogRead(MOISTURE_SENSOR_PIN); 
  int gasValue = analogRead(gasSensorPin); 
  int sensorValue = digitalRead(metalproximitySensorPin); 


  if (objdetection== HIGH) 
  { 
    // Metallic waste detection
    if (sensorValue == HIGH) 
    {
    metalDetected = true; 
    digitalWrite(RELAY_PIN, HIGH); 
    delay(5000);      //in ms
    digitalWrite(RELAY_PIN, LOW); //closing the opening of the relay
      
    //another section for moisture waste and toxic
    if (moistureValue > MOISTURE_THRESHOLD  || gasValue > GAS_THRESHOLD)  
      { 
      // Moisture detected or Gas Detected, activate the conveyor belt (turn on relay) 
      digitalWrite(RELAY_PIN1, HIGH); 
      }
      else 
      { 
      // Solid waste detected, turn off the conveyor belt (turn off relay) 
        digitalWrite(RELAY_PIN1, LOW); 
      }    
    }
  }
    else 
      { 
      // If no waste edetected, turn off the conveyor belt (turn off relay) 
        digitalWrite(RELAY_PIN1, LOW); 
      }   
  // Check if the moisture level exceeds the threshold 
  delay(1000);  // Add a delay for stability and to control the sensing frequency 
}
