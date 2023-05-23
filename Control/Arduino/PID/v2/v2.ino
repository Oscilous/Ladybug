//Compile for Arduino nRF52 mbed enable boards -> XIAO Sense
#include <Arduino.h>
#include <NanoBLEFlashPrefs.h>
#include <QuickPID.h>
#include <LSM6DS3.h>
#include <math.h>
#include <Adafruit_VL53L0X.h>

#define ARRAY_SIZE 20
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
    DegreeOfFreedom(float p, float i, float d) : P(p), I(i), D(d) {}
    DegreeOfFreedom(float set, float p, float i, float d) : setpoint(set), P(p), I(i), D(d) {}
};

int i=0;
float dt=0, time_last = 0;
float gyro_calib[3] = {-0.67,-1.47,0.5};
float gyro[3] = {0.001, 0.001, 0.001}; // unfiltered gyro readings
float gyro_prev[3] = {0.001, 0.001, 0.001};
float HPF_gyro_angle[3] = {0.0, 0.0, 0.0};//FILTERED GYRO ANGLE VALUES
float Unfilt_angle_gyro[3] = {0.0, 0.0, 0.0};//UNFILTERED GYRO ANGLE VALUES
float Unfilt_angle_gyro_prev[3] = {0.0, 0.0, 0.0};//UNFILTERED GYRO ANGLE VALUES (previous iteration)

float coefgyro_HPF[3] = {0.5968, 0.7984, -0.7984}; // HPF coefficients

float acc[3] = {0.001, 0.001, 0.001};  // unfiltered acc readings
float acc_prev[3] = {0.001, 0.001, 0.001};
float LPF_acc_angle[3] = {0.0, 0.0, 0.0};//FILTERED ACC ANGLE VALUES

float coefacc_LPF[3] = {0.5968, 0.2016, 0.2016}; // LPF coefficients

float Complimentary[3] = {0.0, 0.0, 0.0};//UNFILTERED GYRO ANGLE VALUES

float Z_position=0, Z_actual = 0;

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
DegreeOfFreedom Z(0, 1.02, 0.38, 0.2825);
//DegreeOfFreedom Z(0.5, 1.02, 0.38, 0.2825);
DegreeOfFreedom Phi(-2.29551125806385e-05, -1.42052143562565e-06, -5.90349375287184e-05);
DegreeOfFreedom Theta(-2.34228279252575e-05, -1.44946486469699e-06, -6.02377870487898e-05);
QuickPID Z_PID(&Z.input, &Z.output, &Z.setpoint);
QuickPID Phi_PID(&Phi.input, &Phi.output, &Phi.setpoint);
QuickPID Theta_PID(&Theta.input, &Theta.output, &Theta.setpoint);
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A
Adafruit_VL53L0X lox = Adafruit_VL53L0X();                                    // create object lox from Adafruit_VL53L0X
VL53L0X_RangingMeasurementData_t measure; 
float motor_speed[4];
int j = 0;

// Print preference record to Serial.
// You have to adapt this to your particular structure.
void printPreferences(flashPrefs thePrefs)
{
  for (int i = 0; i < ARRAY_SIZE; i++){
    Serial.print(thePrefs.pwm_motor_1[i]);
    Serial.print("  ");
    Serial.print(thePrefs.pwm_motor_2[i]);
    Serial.print("  ");
    Serial.print(thePrefs.pwm_motor_3[i]);
    Serial.print("  ");
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

void  time_f()
{
  dt = millis()-time_last;
  time_last=millis();
}

float calc_angle_gyro_f(float angle, float speed)
{
  float calculated = 0;  //calculated = Phi_unfiltered;
  calculated = angle - dt * speed*0.001;
  return(calculated);
}

void HPF_gyro_angle_f()
{
  HPF_gyro_angle[0] = coefgyro_HPF[0] * HPF_gyro_angle[0] + coefgyro_HPF[1] * calc_angle_gyro_f(Unfilt_angle_gyro[0], gyro[0]) + coefgyro_HPF[2]* calc_angle_gyro_f(Unfilt_angle_gyro_prev[0],gyro_prev[0]);
  HPF_gyro_angle[1] = coefgyro_HPF[0] * HPF_gyro_angle[1] + coefgyro_HPF[1] * calc_angle_gyro_f(Unfilt_angle_gyro[1], gyro[1]) + coefgyro_HPF[2]* calc_angle_gyro_f(Unfilt_angle_gyro_prev[1],gyro_prev[1]);
  //HPF_gyro_angle[2] = coefgyro_HPF[0] * HPF_gyro_angle[2] + coefgyro_HPF[1] * gyro[2] + coefgyro_HPF[2]* gyro_prev[2];
}

void Unfilt_angle_gyro_f()
{
  Unfilt_angle_gyro[0] = calc_angle_gyro_f(Unfilt_angle_gyro[0], gyro[0]);
  Unfilt_angle_gyro[1] = calc_angle_gyro_f(Unfilt_angle_gyro[1], gyro[1]);
  //Unfilt_angle_gyro[2] = calc_angle_gyro_f(Unfilt_angle_gyro[2], gyro[2]);
}

void Unfilt_angle_gyro_prev_f()
{
  Unfilt_angle_gyro_prev[0] = Unfilt_angle_gyro[0];
  Unfilt_angle_gyro_prev[1] = Unfilt_angle_gyro[1];
  //Unfilt_angle_gyro_prev[2] = Unfilt_angle_gyro[2];
}
/////////////////////////----------ACCEL PHI-----------------//////////////////////////

float calc_Theta_acc_f(float AccX, float AccY, float AccZ)
{
  float calculated;
  if  (AccZ>0)
  {
    calculated = atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);//degrees roll / phi
  }

  if  (AccZ<=0)
  {
    if (AccX>=0)
    {
      calculated = 180-atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);//degrees pitch / phi
    }
    if (AccX<0)
    {
      calculated = -180-atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);//degrees pitch / phi
    }
  }
  return(calculated);
}

float calc_Phi_acc_f(float AccY, float AccZ)
{
  float calculated;

  if  (AccZ>0)
  {
    calculated = atan(AccY/AccZ)*1/(3.142/180);//degrees roll / phi
  }
  if (AccZ<=0)
  {
    if (AccY>=0)
    {
      calculated = 180 - atan((AccY)/abs(AccZ))*1/(3.142/180);//degrees roll / phi
    }
    if (AccY<0)
    {
      calculated = -180 - atan((AccY)/abs(AccZ))*1/(3.142/180);//degrees roll / phi
    }
  }
  return(calculated);
}

void LPF_acc_angle_f()
{
  LPF_acc_angle[0] = coefacc_LPF[0] * LPF_acc_angle[0] + coefacc_LPF[1] * calc_Phi_acc_f(acc[1], acc[2]) + coefacc_LPF[2]* calc_Phi_acc_f(acc_prev[1], acc_prev[2]);
  LPF_acc_angle[1] = coefacc_LPF[0] * LPF_acc_angle[1] + coefacc_LPF[1] * calc_Theta_acc_f(acc[0], acc[1], acc[2]) + coefacc_LPF[2]* calc_Theta_acc_f(acc_prev[0], acc_prev[1], acc_prev[2]);
  //LPF_acc_angle[2] = coefacc_LPF[0] * LPF_acc_angle[2] + coefacc_LPF[1] * gyro[2] + coefacc_LPF[2]* gyro_prev[2];
}

void Complimentary_f()
{
  Complimentary[0] = LPF_acc_angle[0] + HPF_gyro_angle[0];
  Complimentary[1] = LPF_acc_angle[1] + HPF_gyro_angle[1];
}

//--------------------------------------------------------------
void readgyro_f()
{
  for (i=0; i<3; ++i)
  {
    gyro_prev[i]=gyro[i];
  }

  gyro[0] = myIMU.readFloatGyroX()-gyro_calib[0];
  gyro[1] = myIMU.readFloatGyroY()-gyro_calib[1];
  gyro[2] = myIMU.readFloatGyroZ()-gyro_calib[2];
}

void readacc_f()
{
  for (i=0; i<3; ++i)
  {
    acc_prev[i]=acc[i];
  }

  acc[0] = myIMU.readFloatAccelX();
  acc[1] = myIMU.readFloatAccelY();
  acc[2] = myIMU.readFloatAccelZ();  
}

/////////////////--------------------------Z FROM GYRO ----------------------//////

void calc_Z_f(float AccZ)
{
  Z_position = Z_position + (AccZ-1)/10*dt*dt;
}

void setup()
{
  // Toggle LED for indication of on/off state
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //Initialize serial
  Serial.begin(9600);
  delay(3000);

  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } 

  Serial.println("Adafruit VL53L0X test");                                    // print text to Serial Monitor
  if (!lox.begin()) 
  {                                                         // check if the VL53L0X exist on the I2C adress 0x29
    Serial.println("Failed to boot VL53L0X");                              // if not exist print text to Serial Monitor
    while (1);
  }

  //Apply PID gains
  Z_PID.SetTunings(Z.P, Z.I, Z.D);
  Phi_PID.SetTunings(Phi.P, Phi.I, Phi.D);
  Theta_PID.SetTunings(Theta.P, Theta.I, Theta.D);
  Z_PID.SetOutputLimits(-0x7FFFFFFF, 0);
  //Turn the PID on
  Z_PID.SetMode(Z_PID.Control::automatic);
  Phi_PID.SetMode(Phi_PID.Control::automatic);
  Theta_PID.SetMode(Theta_PID.Control::automatic);
  
  dt=millis();
  time_last=millis();
  /*
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
  */
  //Motors ramp up, to decrease the current spike
  motor_ramp_up();
}

void loop()
{
  
  while(j < 100){
    time_f();

    readgyro_f(); //read gyro
    readacc_f(); // read acc
    Unfilt_angle_gyro_f(); //calculate gyro angle from unfiltered measurements
    Unfilt_angle_gyro_prev_f(); // shift unfiltered values

    HPF_gyro_angle_f(); //filter calculated gyro angle
    LPF_acc_angle_f();  //filter calculated acc angle
    Complimentary_f();

    lox.rangingTest(&measure, false);                                           // set lox.rangingTest to false
    Z_actual = measure.RangeMilliMeter*cos((3.142/180)*Complimentary[0])*cos((3.142/180)*Complimentary[1]); // distance to ground in mm

    //PID
    Z.input = (Z_actual / 100);
    Phi.input = Complimentary[0] * pi / 180;
    Theta.input = Complimentary[1] * pi / 180;  
    Phi_PID.Compute();
    Phi.output /= 4 * thrust_const * sin(pi/4) * motor_distance;
    Theta_PID.Compute();
    Theta.output /= 4 * thrust_const * sin(pi/4) * motor_distance;
    Z_PID.Compute(); //After this line Z.output gets updated
    //Z.output /= cos(Theta.input) * cos(Phi.input);
    //Z.output /= -4 * thrust_const;
    Z.output = 0;
    Serial.print(Z.output);
    Serial.print(",");
    Serial.print(Complimentary[0]);
    Serial.print(",");
    Serial.println(Complimentary[1]);
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

    /*
    globalPrefs.pwm_motor_1[j] = motor_speed[0]; 
    globalPrefs.pwm_motor_2[j] = motor_speed[1];
    globalPrefs.pwm_motor_3[j] = motor_speed[2];
    globalPrefs.pwm_motor_4[j] = motor_speed[3];

    analogWrite(8, motor_speed[0] * 0.1);
    analogWrite(7, motor_speed[1] * 0.1);
    analogWrite(9, motor_speed[2] * 0.1);
    analogWrite(10, motor_speed[3] * 0.1);
    */

    //When done send the logs
    if (j % 10 == 0){
      myFlashPrefs.writePrefs(&globalPrefs, sizeof(globalPrefs));
      Serial.println("LOG!");
    }
    j++;
  }
}