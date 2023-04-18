#include <LSM6DS3.h>
#include <Wire.h>


float SpeedRoll, SpeedPitch, SpeedYaw; //rotational speed around X,Y and Z axis respectively 
float AccX, AccY, AccZ; // accelaration in X Y and  Z directions
float AngleRoll, AnglePitch, AngleYaw; // rotational angle around X, Y, Z axis respectively in degrees
float GainRollAngle = 0, GainPitchAngle = 0;// Kalman gain
float FilteredAngleRoll = 0, FilteredAnglePitch = 0;
float CovarianceRoll = 4, CovariancePitch = 4;
float KalmanOutput =0, KalmanOutputCovariance = 0;


uint32_t Timer;
//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A
/*float aX, aY, aZ, gX, gY, gZ;
const float accelerationThreshold = 2.5; // threshold of significant in G's
const int numSamples = 119;
int samplesRead = numSamples;
*/

void readacc()
{
  AccX = myIMU.readFloatAccelX();
  AccY = myIMU.readFloatAccelY();
  AccZ = myIMU.readFloatAccelZ();  
}

void readgyro()
{
  SpeedRoll = myIMU.readFloatGyroX();
  SpeedPitch = myIMU.readFloatGyroY();
  SpeedYaw = myIMU.readFloatGyroZ();  
}

void angles()
{
  AngleRoll = atan(AccY/(sqrt(AccX*AccX+AccZ*AccZ)))*1/(3.142/180);
  AnglePitch = -atan(AccX/(sqrt(AccY*AccY+AccZ*AccZ)))*1/(3.142/180);
}

void Kalman(float State, float Covariance, float SpeedRoll, float accangle)
{
  float Gain;
  State = State + 0.104*SpeedRoll; //initial prediction of state (current rotational angle), 0.104- time for one itteration
  Covariance = Covariance + 0.104*0.104*4*4; //Covarianceainty of prediction, 4 - stdev on gyro, 0.104- time for one itteration
  Gain = (Covariance*1)/(1*Covariance + 3*3); // Kalman gain, 3- assumed st deviation on accel
  State = State + Gain*(accangle - State); //Update prediction
  Covariance = (1 - Gain)*Covariance;//update Covariance

  KalmanOutput=State; //output
  KalmanOutputCovariance=Covariance;//outtput
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } else {
    Serial.println("OK");
  }
}



void loop() 
{
  while(1)
  {
    readgyro();
    readacc();
    angles();
    Kalman(FilteredAngleRoll, CovarianceRoll, SpeedRoll, AngleRoll);
    FilteredAngleRoll = KalmanOutput;
    CovarianceRoll = KalmanOutputCovariance;
    Kalman(FilteredAnglePitch, CovariancePitch, SpeedPitch, AnglePitch);
    FilteredAnglePitch = KalmanOutput;
    CovariancePitch = KalmanOutputCovariance;
    GainRollAngle = GainRollAngle + 0.104 * SpeedRoll;
   // Serial.print(AccX);
   // Serial.print(",");
   // Serial.print(AccY);
   // Serial.print(",");
   // Serial.print(AccZ);
   // Serial.print(",");
   // Serial.println(SpeedRoll);
   // Serial.print(",");
   // Serial.print(SpeedPitch);
   // Serial.print(",");
   // Serial.print(SpeedYaw);
    Serial.print(AngleRoll);
    Serial.print(",");
    //Serial.print(GainRollAngle);
    //Serial.print(",");
    Serial.print(FilteredAngleRoll);
    //Serial.println(AnglePitch);
    Serial.print(",");
    Serial.println(10);
    delay(100);
  }
}


