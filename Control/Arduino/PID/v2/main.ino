#include <Arduino.h>
#include <NanoBLEFlashPrefs.h>
#include <QuickPID.h>

#define ARRAY_SIZE 15
#define motor_4 7
#define motor_3 8
#define motor_2 9
#define motor_1 10

typedef struct flashStruct
{
  unsigned char pwm_motor_1[ARRAY_SIZE];
  unsigned char pwm_motor_2[ARRAY_SIZE];
  unsigned char pwm_motor_3[ARRAY_SIZE];
  unsigned char pwm_motor_4[ARRAY_SIZE];
  float output_test[ARRAY_SIZE];
} flashPrefs;

class DegreeOfFreedom
{
  public:
    float setpoint = 0;
    float input = 0;
    float output = 0;
    float P = 0;
    float I = 0;
    float D = 0;
    DegreeOfFreedom(float p, float i, float d) : setpoint(0), input(0), output(0), P(p), I(i), D(d) {}
    DegreeOfFreedom(float set, float p, float i, float d) : setpoint(set), input(0), output(0), P(p), I(i), D(d) {}
};

// Access to the library
NanoBLEFlashPrefs myFlashPrefs;

// Our preferences. All functions here can read and modify these values, but to make
// them permanent, the struct must be written to flash explicitly (see below).
flashPrefs globalPrefs;

// Structure of preferences. You determine the fields.
// Must not exeed 1019 words (4076 byte).

//Constants
const float thrust_const = 0.00004;
const float torque_const = 0.00116;
const float motor_distance = 0.116 / 2;
const float pi = 3.14159;

//Declearing of degrees of freedom for collective variables
//Check constructors for proper use
DegreeOfFreedom Z(0.5, 1.02, 0.38, 0.2825);
DegreeOfFreedom Phi(-2.29551125806385e-05, -1.42052143562565e-06, -5.90349375287184e-05);
DegreeOfFreedom Theta(-2.34228279252575e-05, -1.44946486469699e-06, -6.02377870487898e-05);
QuickPID Z_PID(&Z.input, &Z.output, &Z.setpoint);
QuickPID Phi_PID(&Phi.input, &Phi.output, &Phi.setpoint);
QuickPID Theta_PID(&Theta.input, &Theta.output, &Theta.setpoint);
float motor_speed[4];

void setup()
{
  // Toggle LED for indication of on/off state
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //Initialize serial
  Serial.begin(9600);
  delay(3000);


  //Apply PID gains
  Z_PID.SetTunings(Z.P, Z.I, Z.D);
  Phi_PID.SetTunings(Phi.P, Phi.I, Phi.D);
  Theta_PID.SetTunings(Theta.P, Theta.I, Theta.D);

  //Turn the PID on
  Z_PID.SetMode(Z_PID.Control::automatic);
  Phi_PID.SetMode(Phi_PID.Control::automatic);
  Theta_PID.SetMode(Theta_PID.Control::automatic);
  
  //If the drone is connect to serial, we enter debug mode
  if (Serial)
  {
    while (1){
      Serial.print("Entered");
      String cmdStr = Serial.readString();
      cmdStr.trim();

      if (cmdStr == "i")
      {
        Serial.print("-- Info: ");
        Serial.println(myFlashPrefs.statusString());
        readPreferenceRecord(globalPrefs);
      }
      else if (cmdStr == "d")
      {
        Serial.print("-- Delete: ");
        int rc = myFlashPrefs.deletePrefs(); // Only marks records for deletion, use garbage collection to free memory
        Serial.println(myFlashPrefs.errorString(rc));
        Serial.print("-- Info: ");
        Serial.println(myFlashPrefs.statusString());
      }
      else if (cmdStr == "g")
      {
        Serial.print("-- Garbage Collection: ");
        int rc = myFlashPrefs.garbageCollection();
        Serial.println(myFlashPrefs.errorString(rc));
        Serial.print("-- Info: ");
        Serial.println(myFlashPrefs.statusString());
      }
    }
  }

  //Motors ramp up, to decrease the current spike
  motor_ramp_up();
}

void loop()
{
  while (Z.input < 15){
    Phi_PID.Compute();
    Phi.output /= 4 * thrust_const * sin(pi/4) * motor_distance;
    Theta_PID.Compute();
    Theta.output /= 4 * thrust_const * sin(pi/4) * motor_distance;
    Z_PID.Compute(); //After this line Z.output gets updated
    globalPrefs.output_test[(int)Z.input] = Z.output;
    Z.output /= cos(Theta.input) * cos(Phi.input);
    Z.output /= -4 * thrust_const;
    // We calculate angular velocities
    motor_speed[0] = Z.output + Phi.output + Theta.output;
    motor_speed[1] = Z.output - Phi.output + Theta.output;
    motor_speed[2] = Z.output - Phi.output - Theta.output;
    motor_speed[3] = Z.output + Phi.output - Theta.output;
    for (int i = 0; i < 4; i++){
      if (motor_speed[i] > 3500){
        motor_speed[i] = 3500;
      }
      else if(motor_speed[i] < 0){
        motor_speed[i] = 0;
      }
    }

    //We convert to pwm
    for (int i = 0; i < 4; i++){
      motor_speed[i] = motor_speed[i] * 0.0795;
      motor_speed[i] -= 21.961;
      if (motor_speed[i] > 255){
        motor_speed[i] = 255;
      }
      else if(motor_speed[i] < 0){
        motor_speed[i] = 0;
      }
    }

    globalPrefs.pwm_motor_1[(int)Z.input] = motor_speed[0]; 
    globalPrefs.pwm_motor_2[(int)Z.input] = motor_speed[1];
    globalPrefs.pwm_motor_3[(int)Z.input] = motor_speed[2];
    globalPrefs.pwm_motor_4[(int)Z.input] = motor_speed[3];

    for (int i = 0; i < 4;i++){
      analogWrite(10 - i, motor_speed[i]);
    }
    delay(100);
    Z.input += 0.1;
  }
  //When done send the logs
  myFlashPrefs.writePrefs(&globalPrefs, sizeof(globalPrefs));
  while (1);
}

// Print preference record to Serial.
// You have to adapt this to your particular structure.
void printPreferences(flashPrefs thePrefs)
{
  Serial.println("Motor 1: ");
  for (int i = 0; i < ARRAY_SIZE; i++){
    Serial.println(thePrefs.pwm_motor_1[i]);
  }
  Serial.println("Motor 2: ");
  for (int i = 0; i < ARRAY_SIZE; i++){
    Serial.println(thePrefs.pwm_motor_2[i]);
  }
  Serial.println("Motor 3: ");
  for (int i = 0; i < ARRAY_SIZE; i++){
    Serial.println(thePrefs.pwm_motor_3[i]);
  }
  Serial.println("Motor 4: ");
  for (int i = 0; i < ARRAY_SIZE; i++){
    Serial.println(thePrefs.pwm_motor_4[i]);
  }
  Serial.println("Z: ");
  for (int i = 0; i < ARRAY_SIZE; i++){
    Serial.println(thePrefs.output_test[i]);
  }
}

// Print return code infos to Serial.
void printReturnCode(int rc)
{
  Serial.print("Return code: ");
  Serial.print(rc);
  Serial.print(", ");
  Serial.println(myFlashPrefs.errorString(rc));
}

void readPreferenceRecord(flashPrefs globalPrefs){
  int rc = myFlashPrefs.readPrefs(&globalPrefs, sizeof(globalPrefs));
  if (rc == FDS_SUCCESS)
  {
    printPreferences(globalPrefs);
  }
  else
  {
    printReturnCode(rc);
  }
}

void motor_ramp_up(){
  for (int i = 0; i < 200;i++){
    analogWrite(10, i);
    analogWrite(9, i);
    analogWrite(8, i);
    analogWrite(7, i);
  }
}