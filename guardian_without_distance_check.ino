#include <SoftwareSerial.h>

SoftwareSerial mySerial(A0, A1); // RX, TX for Bluetooth communication
String BT_value;
String BT_value_temp;
volatile int Front_Distance;
volatile boolean Flag = true;

const int Trig = A3;
const int Echo = A2;
const int PWM2A = 11;      // Motor M1
const int PWM2B = 3;       // Motor M2  
const int PWM0A = 6;       // Motor M3
const int PWM0B = 5;       // Motor M4
const int DIR_CLK = 4;     // Data input clock line
const int DIR_EN = 7;      // L293D enable pins
const int DATA = 8;        // USB cable (shift register data line)
const int DIR_LATCH = 12;  // L293D direction latch pin

// Define motion states
const int Move_Forward = 39;
const int Move_Backward = 216;
const int Left_Move = 116;
const int Right_Move = 139;
const int Right_Rotate = 149;
const int Left_Rotate = 106;
const int Stop = 0;

// Speed configuration
int Speed1 = 255;
int Speed2 = 255;
int Speed3 = 255;
int Speed4 = 255;

// Motor control function
void Motor(int Dir, int Speed1, int Speed2, int Speed3, int Speed4) {
  analogWrite(PWM2A, Speed1); // Motor speed
  analogWrite(PWM2B, Speed2); // Motor speed
  analogWrite(PWM0A, Speed3); // Motor speed
  analogWrite(PWM0B, Speed4); // Motor speed

  digitalWrite(DIR_LATCH, LOW);  // Prepare to write direction
  shiftOut(DATA, DIR_CLK, MSBFIRST, Dir); // Shift out the direction command
  digitalWrite(DIR_LATCH, HIGH);  // Latch the command
}

// Function to check distance with ultrasonic sensor
float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}

// Setup the pin modes and initialize communication
void setup() {
  BT_value = "";
  BT_value_temp = "";
  Front_Distance = 0;

  mySerial.begin(9600);  // Bluetooth communication
  Serial.begin(9600);    // Serial monitor for debugging

  pinMode(DIR_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(DIR_EN, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(PWM0B, OUTPUT);
  pinMode(PWM0A, OUTPUT);
  pinMode(PWM2A, OUTPUT);
  pinMode(PWM2B, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

// Main loop for receiving Bluetooth commands and executing motor actions
void loop() {
  if (mySerial.available() > 0) {
    BT_value_temp += (char)mySerial.read();
    delay(2);

    if (!mySerial.available()) {
      BT_value = BT_value_temp;
      BT_value_temp = "";
    }
  }

  if (BT_value.length() > 0) {
    Serial.println(BT_value);  // Print received command for debugging

    // Ensure the received command is in the correct format: %Command#
    if (BT_value.charAt(0) == '%' && BT_value.charAt(BT_value.length() - 1) == '#') {
      char command = BT_value.charAt(1);  // Extract the command character

      switch (command) {
        case 'A': // Move forward
          Motor(Move_Forward, Speed1, Speed2, Speed3, Speed4);
          delay(200);
          break;
        case 'B': // Move backward
          Motor(Move_Backward, Speed1, Speed2, Speed3, Speed4);
          delay(200);
          break;
        case 'C': // Move left
          Motor(Left_Move, Speed1, Speed2, Speed3, Speed4);
          delay(200);
          break;
        case 'D': // Move right
          Motor(Right_Move, Speed1, Speed2, Speed3, Speed4);
          delay(200);
          break;
        case 'E': // Left rotate
          Motor(Left_Rotate, Speed1, Speed2, Speed3, Speed4);
          delay(100);
          break;
        case 'F': // Right rotate
          Motor(Right_Rotate, Speed1, Speed2, Speed3, Speed4);
          delay(100);
          break;
        case 'S': // Stop
          Motor(Stop, 0, 0, 0, 0);
          break;
        default:
          Motor(Stop, 0, 0, 0, 0);  // Stop if the command is unrecognized
          break;
      }
      BT_value = "";  // Clear the value after processing
    }
  } else {
    Motor(Stop, 0, 0, 0, 0);  // Stop motors if no command is received
  }
}
