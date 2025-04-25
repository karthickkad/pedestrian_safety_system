#define IR_SENSOR_PIN 2        // TCRT5000 IR Sensor
#define E18_SENSOR_PIN 7       // E18-D80NK IR Sensor
#define VEHICLE_TRIG 8         // HC-SR04 Trigger
#define VEHICLE_ECHO 9         // HC-SR04 Echo
#define PIR_SENSOR_PIN 3       // PIR Sensor

#define GREEN_LED 10           // Green LED Strip (Safe to Cross)
#define ORANGE_LED 11          // Orange LED Strip (Warning)
#define RED_LED 5              // Red LED Strip (Stop Signal)
#define BUZZER 12              // Buzzer for Emergency Alert
#define STREET_LIGHT 4         // 5V Street Light

void setup() {
  Serial.begin(9600);
    
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(E18_SENSOR_PIN, INPUT);
  pinMode(PIR_SENSOR_PIN, INPUT);

  pinMode(VEHICLE_TRIG, OUTPUT);
  pinMode(VEHICLE_ECHO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(STREET_LIGHT, OUTPUT);
}

// **Function to Measure Distance from Ultrasonic Sensors**
int getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}

// **Functions for Each Mode**
void pedestrianDetected() {
  Serial.println("🟢 Pedestrian Detected");
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(ORANGE_LED, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(STREET_LIGHT, HIGH); // Turn ON Street Light
}

void emergencyAlert() {
    Serial.println("🔴 Emergency Alert 🚨");
    digitalWrite(RED_LED, HIGH); // Stop signal ON
    digitalWrite(BUZZER, HIGH); // Buzzer ON for alert
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(STREET_LIGHT, LOW); // Ensure Street Light turns on
    
    delay(1000); // Keep the alert for 1 second
    
    digitalWrite(BUZZER, LOW); // Turn off buzzer after alert
    digitalWrite(STREET_LIGHT, LOW); // Keep Street Light ON during Emergency Alert
}

void idleMode() {
  Serial.println("🟡 No Pedestrian Detected");
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(ORANGE_LED, HIGH); // Show Warning Light
  digitalWrite(BUZZER, LOW);
  digitalWrite(STREET_LIGHT, LOW); // Turn OFF Street Light
}

void loop() {
  int irValue = digitalRead(IR_SENSOR_PIN);
  int e18Value = digitalRead(E18_SENSOR_PIN);
  int pirValue = digitalRead(PIR_SENSOR_PIN);

  int vehicleDistance = getDistance(VEHICLE_TRIG, VEHICLE_ECHO);

  Serial.print("IR Sensor: "); Serial.println(irValue);
  Serial.print("E18-D80NK Sensor: "); Serial.println(e18Value);
  Serial.print("PIR Motion: "); Serial.println(pirValue);
  Serial.print("Vehicle Distance: "); Serial.print(vehicleDistance); Serial.println(" cm");

  if ((e18Value == HIGH) && (irValue == HIGH)) {
    pedestrianDetected(); 
  } 
  else if ((e18Value == HIGH || irValue == HIGH || pirValue == HIGH) && (vehicleDistance < 10)) {
    Serial.println("⚠️ Emergency Condition Met! Triggering Alert...");
    emergencyAlert();  
  } 
  else {
    idleMode();  
  }

  delay(100);  
}
