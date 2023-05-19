/*
  NanoBLEFlashPrefsTest

  Demonstrates the use of the NanoBLEFlashPrefs library for storing
  preferences and other values in flash memory

  created 2021
  by Dirk Fröhling

  https://github.com/Dirk-/NanoBLEFlashPrefs
*/
#include <Arduino.h>
#include <NanoBLEFlashPrefs.h>
#include <QuickPID.h>

#define ARRAY_SIZE 15
#define motor_4 7
#define motor_3 8
#define motor_2 9
#define motor_1 10
// Access to the library
NanoBLEFlashPrefs myFlashPrefs;

// Structure of preferences. You determine the fields.
// Must not exeed 1019 words (4076 byte).
typedef struct flashStruct
{
  unsigned char pwm_motor_1[ARRAY_SIZE];
  unsigned char pwm_motor_2[ARRAY_SIZE];
  unsigned char pwm_motor_3[ARRAY_SIZE];
  unsigned char pwm_motor_4[ARRAY_SIZE];
} flashPrefs;

// Our preferences. All functions here can read and modify these values, but to make
// them permanent, the struct must be written to flash explicitly (see below).
flashPrefs globalPrefs;

const float thrust_const = 0.00004;
const float torque_const = 0.00116;
const float motor_distance = 0.116 / 2;
const float pi = 3.14159;
//Define Variables we'll be connecting to
//Z PID
float z_setpoint, z_input, z_output;
float z_Kp = 0.6 * 1.7, z_Ki = 1.2*1.7/3-0.3, z_Kd = 0.075*1.7*3 - 0.1;
QuickPID z_PID(&z_input, &z_output, &z_setpoint);

//Phi PID
float phi_setpoint, phi_input, phi_output;
float phi_Kp = 0.6 * 1.7, phi_Ki = 1.2*1.7/3-0.3, phi_Kd = 0.075*1.7*3 - 0.1;
QuickPID phi_PID(&phi_input, &phi_output, &phi_setpoint);

//Theta PID
float theta_setpoint, theta_input, theta_output;
float theta_Kp = 0.6 * 1.7, theta_Ki = 1.2*1.7/3-0.3, theta_Kd = 0.075*1.7*3 - 0.1;
QuickPID theta_PID(&theta_input, &theta_output, &theta_setpoint);

float motor_speed[4];

void setup()
{
  // Give user a chance to open the terminal
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  delay(3000);
  z_setpoint = 10;
  phi_setpoint = 0;
  theta_setpoint = 0;
  z_input = 0;
  //apply PID gains
  z_PID.SetTunings(z_Kp, z_Ki, z_Kd);
  phi_PID.SetTunings(phi_Kp, phi_Ki, phi_Kd);
  theta_PID.SetTunings(theta_Kp, theta_Ki, theta_Kd);

  //turn the PID on
  z_PID.SetMode(z_PID.Control::automatic);
  phi_PID.SetMode(phi_PID.Control::automatic);
  theta_PID.SetMode(theta_PID.Control::automatic);
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
        printPreferences(globalPrefs);
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
  motor_ramp_up();
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (z_input < 15){
    z_PID.Compute(); //After this line z_output gets updated
    z_output /= cos(theta_input) * cos(phi_input);
    z_output /= -4 * thrust_const;
    phi_PID.Compute();
    phi_output /= 4 * thrust_const * sin(pi/4) * motor_distance;
    theta_PID.Compute();
    theta_output /= 4 * thrust_const * sin(pi/4) * motor_distance;

    // We calculate angular velocities
    motor_speed[0] = z_output + phi_output + theta_output;
    motor_speed[1] = z_output - phi_output + theta_output;
    motor_speed[2] = z_output - phi_output - theta_output;
    motor_speed[3] = z_output + phi_output - theta_output;
    
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
    for (int i = 0; i < 4;i++){
      analogWrite(10 - i, motor_speed[i]);
    }
    delay(10);
    globalPrefs.pwm_motor_1[(int)z_input] = motor_speed[0];
    globalPrefs.pwm_motor_2[(int)z_input] = motor_speed[1];
    globalPrefs.pwm_motor_3[(int)z_input] = motor_speed[2];
    globalPrefs.pwm_motor_4[(int)z_input] = motor_speed[3];
    z_input++;
  }
  //When done send the logs
  printReturnCode(myFlashPrefs.writePrefs(&globalPrefs, sizeof(globalPrefs)));
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
}

// Print return code infos to Serial.
void printReturnCode(int rc)
{
  Serial.print("Return code: ");
  Serial.print(rc);
  Serial.print(", ");
  Serial.println(myFlashPrefs.errorString(rc));
}

void readPreferenceRecord(flashPrefs localPrefs){
  int rc = myFlashPrefs.readPrefs(&localPrefs, sizeof(localPrefs));
  if (rc == FDS_SUCCESS)
  {
    printPreferences(localPrefs);
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