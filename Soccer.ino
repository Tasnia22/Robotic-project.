
int relay1 = 2;     //motor1
int relay2 = 3;    //motor1
int relay3 = 4;   //motor2
int relay4 = 5;   //motor2
int Speed1 = 9; //speed
int Speed2 = 10; //speed

char bt = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)
  {
    bt = Serial.read();
    /*________________________________________________________________________*/
    if (bt == 'R')       //move forwards
    {
      Serial.print("F\n");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, HIGH);
    }
    else if (bt == 'L')       //move backwards
    {
      Serial.print("B\n");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);
    }
    else if (bt == 'S')     //stop!!
    {
      Serial.print("S\n");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH);
    }
    else if (bt == 'B')    //right
    {
      Serial.print("R\n");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);
    }
    else if (bt == 'J')       //move FORWARD RIGHT
    {
      Serial.print("FR\n");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    }
    else if (bt == 'G')       //move BACKWARD RIGHT
    {
      Serial.print("BR\n");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW );
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    }
    else if (bt == 'F')     //left
    {
      Serial.print("L\n");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, HIGH);
    }
    else if (bt == 'I')       //move FORWARD LEFT
    {
      Serial.print("FL\n");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, HIGH);
    }
    else if (bt == 'H')       //move BACKWARD LEFT
    {
      Serial.print("BL\n");

      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);
    }
  }
}
const int echoPin = 3;
const int trigPin = 2;
 
void setup() {
  Serial.begin(9600);                    // Start serial communication with a baud rate of 9600
  pinMode(echoPin, INPUT);               // Set echo pin as input
  pinMode(trigPin, OUTPUT);              // Set trig pin as output
  Serial.println("Ultrasonic sensor:");  // Print a message indicating the ultrasonic sensor is ready
}
 
void loop() {
  float distance = readDistance();       // Call the function to read the sensor data and get the distance
  
  if (distance > 400) {                  // Check if the distance is greater than 400 cm
    Serial.println("Out of Range");      // Print "Out of Range"
  } else {
    Serial.print(distance);              // Print the distance value
    Serial.println(" cm");               // Print " cm" to indicate the unit of measurement
  }
  
  delay(400);                            // Delay for 400 milliseconds before repeating the loop
}
 
// Function to read the sensor data and calculate the distance
float readDistance() {
  digitalWrite(trigPin, LOW);            // Set trig pin to low to ensure a clean pulse
  delayMicroseconds(2);                  // Delay for 2 microseconds
  digitalWrite(trigPin, HIGH);           // Send a 10 microsecond pulse by setting trig pin to high
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);            // Set trig pin back to low
 
  // Measure the pulse width of the echo pin and calculate the distance value
  float pulse_duration = pulseIn(echoPin, HIGH); // Read pulse duration
  float distance = pulse_duration / 58.00;       // Calculate the distance
  
  return distance;                               // Return the calculated distance
}