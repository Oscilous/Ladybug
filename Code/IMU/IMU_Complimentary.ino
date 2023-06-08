//--------------------------------------------------------//V3//----------------------------------------

#include <LSM6DS3.h>
#include <Wire.h>
#include <math.h>
#include <Adafruit_VL53L0X.h>     

//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A
Adafruit_VL53L0X lox = Adafruit_VL53L0X();                                    // create object lox from Adafruit_VL53L0X
VL53L0X_RangingMeasurementData_t measure; 
//VL53L0X_RangingMeasurementData_t measure;      


//////////////////////////////////------------------------------------------------------------------------

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

////////////////////////-------------------

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  while (!Serial);
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } 

  Serial.println("Adafruit VL53L0X test");                                    // print text to Serial Monitor
  if (!lox.begin()) 
  {                                                         // check if the VL53L0X exist on the I2C adress 0x29
    Serial.println("Failed to boot VL53L0X");                              // if not exist print text to Serial Monitor
    while (1);
  }
  delay(1000);
  Serial.println("OK");  
  dt=millis();
  time_last=millis();
}

void loop() 
{
   
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

  Serial.print(Complimentary[0], 3);
  Serial.print(',');
  Serial.print(Complimentary[1], 3);
  Serial.print(',');
  Serial.print((HPF_gyro_angle[1]+LPF_acc_angle[1]), 3);
  Serial.print(',');
  Serial.print((HPF_gyro_angle[0]+LPF_acc_angle[0]), 3);
  Serial.print(',');
  //Serial.print(Z_position, 3);
  //Serial.print(',');
  Serial.print(Z_actual, 3);
  Serial.print(',');
  Serial.print(50);
  Serial.print(',');
  Serial.print(-50);
  Serial.println();
  //delay(T*1000);
}


/*
//float HPF_gyro[3] = {0.0, 0.0, 0.0};//FILTERED GYRO VALUES
//float HPF_gyro_angle_prev[3] = {0.0, 0.0, 0.0};//FILTERED GYRO ANGLE VALUES
//float Filt_angle_gyro[3] = {0.0, 0.0, 0.0};//GYRO ANGLE VALUES CALCULATED FROM FILTERED  SIGNAL
//float LPF_acc[3] = {0.0, 0.0, 0.0};//FILTERED ACC VALUES
//float LPF_acc_angle_prev[3] = {0.0, 0.0, 0.0};//FILTERED ACC ANGLE VALUES
//float Unfilt_angle_acc[3] = {0.0, 0.0, 0.0};//UNFILTERED ACC ANGLE VALUES
//float Filt_angle_acc[3] = {0.0, 0.0, 0.0};//ACC ANGLE VALUES CALCULATED FROM FILTERED  SIGNAL


void HPF_gyro_f()
{
  HPF_gyro[0] = coefgyro_HPF[0] * HPF_gyro[0] + coefgyro_HPF[1] * gyro[0] + coefgyro_HPF[2]* gyro_prev[0];
  HPF_gyro[1] = coefgyro_HPF[0] * HPF_gyro[1] + coefgyro_HPF[1] * gyro[1] + coefgyro_HPF[2]* gyro_prev[1];
  HPF_gyro[2] = coefgyro_HPF[0] * HPF_gyro[2] + coefgyro_HPF[1] * gyro[2] + coefgyro_HPF[2]* gyro_prev[2];
}


void shift_f()
{
  LPF_acc_angle_prev[0] = LPF_acc_angle[0];
  LPF_acc_angle_prev[1] = LPF_acc_angle[1];
  LPF_acc_angle_prev[2] = LPF_acc_angle[2];
}

void LPF_acc_f()
{
  LPF_acc[0] = coefacc_LPF[0] * LPF_acc[0] + coefacc_LPF[1] * acc[0] + coefacc_LPF[2]* acc_prev[0];
  LPF_acc[1] = coefacc_LPF[0] * LPF_acc[1] + coefacc_LPF[1] * acc[1] + coefacc_LPF[2]* acc_prev[1];
  LPF_acc[2] = coefacc_LPF[0] * LPF_acc[2] + coefacc_LPF[1] * acc[2] + coefacc_LPF[2]* acc_prev[2];
}
*/
