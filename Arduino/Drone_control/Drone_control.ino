//Compile for Arduino nRF52 mbed enable boards -> XIAO Sense
#include <Arduino.h>
#include <NanoBLEFlashPrefs.h>
#include <QuickPID.h>
#include <LSM6DS3.h>
#include <math.h>
#include <Adafruit_VL53L0X.h>

#define DURATION 2500
#define LOG_PERIOD 5
#define motor_4 10
#define motor_3 9
#define motor_2 7
#define motor_1 8


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

typedef struct flashStruct
{
  int time[DURATION / LOG_PERIOD];
  signed char phi[DURATION / LOG_PERIOD];
  signed char theta[DURATION / LOG_PERIOD];
} flashPrefs;

// Access to the library
NanoBLEFlashPrefs myFlashPrefs;

// Our preferences. All functions here can read and modify these values, but to make
// them permanent, the struct must be written to flash explicitly (see below).
flashPrefs globalPrefs;

// Structure of preferences. You determine the fields.
// Must not exeed 1019 words (4076 byte).

int i=0;
float dt=0, time_last = 0;
float gyro_calib[3] = {0.162,-2.415,0.067};
float gyro[3] = {0.001, 0.001, 0.001}; // unfiltered gyro readings
float gyro_prev[3] = {0.001, 0.001, 0.001};
float HPF_gyro_angle[3] = {0.0, 0.0, 0.0};//FILTERED GYRO ANGLE VALUES
float Unfilt_angle_gyro[3] = {0.0, 0.0, 0.0};//UNFILTERED GYRO ANGLE VALUES
float Unfilt_angle_gyro_prev[3] = {0.0, 0.0, 0.0};//UNFILTERED GYRO ANGLE VALUES (previous iteration)
float acc_calib[3] = {0.0,0.0,0.0};
float acc[3] = {0.001, 0.001, 0.001};  // unfiltered acc readings
float acc_prev[3] = {0.001, 0.001, 0.001};
float LPF_acc_angle[3] = {0.0, 0.0, 0.0};//FILTERED ACC ANGLE VALUES
float Complimentary[3] = {0.0, 0.0, 0.0};//UNFILTERED GYRO ANGLE VALUE
float Z_position=0, Z_actual = 0;

float coefgyro_HPF[3] = {0.6828, 0.8414, -0.8414}; // HPF coefficients fc=20
float coefacc_LPF[3] = {0.7767, 0.1116, 0.1116}; // LPF coefficients fc=10



//Constants
const float thrust_const = 0.00004;
const float torque_const = 0.00116;
const float motor_distance = 0.116 / 2;
const float pi = 3.14159;

//255
//DegreeOfFreedom Phi((0.01 * 0.6) + 0.004, (1.2 * 0.01 / 1), (0.075 * 0.01 * 1));
//DegreeOfFreedom Theta((0.01 * 0.6) + 0.004, (1.2 * 0.01 / 1), (0.075 * 0.01 * 1));

//225
float kp = (0.004 * 0.6)*10;
float ki = (1.2 * 0.004 / 1.2);
float kd = (0.075 * 0.004 * 1.2)*5;
float Thetacoef = 1.00;
DegreeOfFreedom Phi(kp, ki, kd);
DegreeOfFreedom Theta(kp*3, ki*3, kd*3);


QuickPID Phi_PID(&Phi.input, &Phi.output, &Phi.setpoint, Phi.P, Phi.I, Phi.D,  /* OPTIONS */
               Phi_PID.pMode::pOnError,                   /* pOnError, pOnMeas, pOnErrorMeas */
               Phi_PID.dMode::dOnError,                    /* dOnError, dOnMeas */
               Phi_PID.iAwMode::iAwCondition,             /* iAwCondition, iAwClamp, iAwOff */
               Phi_PID.Action::direct);                   /* direct, reverse */

QuickPID Theta_PID(&Theta.input, &Theta.output, &Theta.setpoint, Theta.P, Theta.I, Theta.D,  /* OPTIONS */
               Theta_PID.pMode::pOnError,                   /* pOnError, pOnMeas, pOnErrorMeas */
               Theta_PID.dMode::dOnError,                    /* dOnError, dOnMeas */
               Theta_PID.iAwMode::iAwCondition,             /* iAwCondition, iAwClamp, iAwOff */
               Theta_PID.Action::direct);                   /* direct, reverse */


LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A
float motor_speed[4];
int j = 0;


void  time_f()
{
  dt = millis()-time_last;
  time_last=millis();
}

float calc_angle_gyro_f(float angle, float speed)
{
  float calculated = 0;  //calculated = Phi_unfiltered;
  calculated = angle + dt * speed*0.001;
  return(calculated);
}

void HPF_gyro_angle_f()
{
  HPF_gyro_angle[0] = coefgyro_HPF[0] * HPF_gyro_angle[0] + coefgyro_HPF[1] * calc_angle_gyro_f(Unfilt_angle_gyro[0], gyro[0]) + coefgyro_HPF[2]* calc_angle_gyro_f(Unfilt_angle_gyro_prev[0],gyro_prev[0]);
  HPF_gyro_angle[1] = coefgyro_HPF[0] * HPF_gyro_angle[1] + coefgyro_HPF[1] * calc_angle_gyro_f(Unfilt_angle_gyro[1], gyro[1]) + coefgyro_HPF[2]* calc_angle_gyro_f(Unfilt_angle_gyro_prev[1],gyro_prev[1]);
  //HPF_gyro_angle[2] = coefgyro_HPF[0] * HPF_gyro_angle[2] + coefgyro_HPF[1] * calc_angle_gyro_f(Unfilt_angle_gyro[2], gyro[2]) + coefgyro_HPF[2]* calc_angle_gyro_f(Unfilt_angle_gyro_prev[2],gyro_prev[2]);
}
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
}

void Complimentary_f()
{
  Complimentary[0] = -(LPF_acc_angle[0] + HPF_gyro_angle[0])* pi / 180;
  Complimentary[1] = (LPF_acc_angle[1] + HPF_gyro_angle[1]) * pi / 180;
}

//--------------------------------------------------------------
void readgyro_f()
{
  for (i=0; i<3; ++i)
  {
    gyro_prev[i]=gyro[i];
  }

  gyro[0] = myIMU.readFloatGyroX()-gyro_calib[0];
  gyro[1] = -(myIMU.readFloatGyroY()-gyro_calib[1]);
  gyro[2] = myIMU.readFloatGyroZ()-gyro_calib[2];
}

void readacc_f()
{
  for (i=0; i<3; ++i)
  {
    acc_prev[i]=acc[i];
  }

  acc[0] = myIMU.readFloatAccelX()+acc_calib[0];
  acc[1] = myIMU.readFloatAccelY()+acc_calib[1];
  acc[2] = myIMU.readFloatAccelZ()+acc_calib[2]; 
}


void calc_Z_f(float AccZ)
{
  Z_position = Z_position + (AccZ-1)/10*dt*dt;
}

float saturize(float value, float min, float max){
  if (value > max){
    return max;
  }
  else if (value < min){
    return min;
  }
  return value;
}

void motor_ramp_up(unsigned char value){
  for (int i = 0; i < value;i++){
    analogWrite(10, i);
    analogWrite(9, i);
    analogWrite(8, i);
    analogWrite(7, i);
  }
}

void printPreferences(flashPrefs thePrefs)
{
  Serial.println("t, phi , theta");
  for (int i = 0; i < DURATION / LOG_PERIOD; i++){
    Serial.print(thePrefs.time[i]);
    Serial.print("  ");
    Serial.print(thePrefs.phi[i], DEC);
    Serial.print("  ");
    Serial.println(thePrefs.theta[i], DEC);
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

void setup()
{
  // Toggle LED for indication of on/off state
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //Initialize serial
  Serial.begin(9600);
  delay(5000);

  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } 
  //Apply PID gains

  Phi_PID.SetTunings(Phi.P, Phi.I, Phi.D);
  Theta_PID.SetTunings(Phi.P, Phi.I, Phi.D);
  Phi_PID.SetOutputLimits(-255.0, 255.0);
  Theta_PID.SetOutputLimits(-255.0, 255.0);
  Phi_PID.SetSampleTimeUs(2500);
  Theta_PID.SetSampleTimeUs(2500);
  Phi_PID.SetMode(Phi_PID.Control::automatic);
  Theta_PID.SetMode(Phi_PID.Control::automatic);

  dt=millis();
  time_last=millis();
  if (Serial)
  {
    Serial.print("/////DEBUG MODE/////");
    while (1){
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
  motor_ramp_up(225);
}

void loop()
{
  while (j < DURATION){
    time_f();

    //IMU
    readgyro_f(); //read gyro
    readacc_f(); // read acc
    Unfilt_angle_gyro_prev_f(); // shift unfiltered values
    Unfilt_angle_gyro_f(); //calculate gyro angle from unfiltered measurements
    HPF_gyro_angle_f(); //filter calculated gyro angle
    LPF_acc_angle_f();  //filter calculated acc angle
    Complimentary_f();

    //PID
    Phi.input = Complimentary[0]; 
    Phi_PID.Compute();
    Theta.input = Complimentary[1]; 
    Theta_PID.Compute();

    float Theta_out = Thetacoef*(Theta.output / (4 * thrust_const * sin(pi/4) * motor_distance));
    Theta_out = saturize(Theta_out, -3500, 3500);
    float Phi_out = Phi.output / (4 * thrust_const * sin(pi/4) * motor_distance);
    Phi_out = saturize(Phi_out, -3500, 3500);

    // Motor calculations
    motor_speed[0] = 3500 + Phi_out - Theta_out;
    motor_speed[1] = 3500 - Phi_out - Theta_out;
    motor_speed[2] = 3500 - Phi_out + Theta_out;
    motor_speed[3] = 3500 + Phi_out + Theta_out;
    //Angular velocity to PWM
    for (int i = 0; i < 4; i++){
      motor_speed[i] = 0.07285714286 * motor_speed[i]; 
      motor_speed[i] = saturize(motor_speed[i], 0, 255);
    }
    //Toggle motors
    analogWrite(motor_1, (unsigned char)motor_speed[0]);
    analogWrite(motor_2, (unsigned char)motor_speed[1]);
    analogWrite(motor_3, (unsigned char)motor_speed[2]);
    analogWrite(motor_4, (unsigned char)motor_speed[3]);

  if (j % LOG_PERIOD == 0){
      globalPrefs.phi[j/LOG_PERIOD] = (signed char)(saturize(((Complimentary[0] * 180 ) / pi),  -127, 128));
      globalPrefs.time[j/LOG_PERIOD] = (int)(millis() - 5000);
      globalPrefs.theta[j/LOG_PERIOD] = (signed char)(saturize(((Complimentary[1] * 180 ) / pi),  -127, 128));
    }
    j++;
  }
  //When done send the logs
  myFlashPrefs.writePrefs(&globalPrefs, sizeof(globalPrefs));
  for (int i = 0; i < 4; i++){
      analogWrite(10 - i, 0);
  }
}

