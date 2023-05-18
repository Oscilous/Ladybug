#include <LSM6DS3.h>
#include <Wire.h>

//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A


float wlow = 0.0;
float whigh = 0.0;

float gyro[3] = {0.0, 0.0, 0.0};
float gyro_prev[3] = {0.0, 0.0, 0.0};
float HPF_agnglegyro[3] = {0.0, 0.0, 0.0};//FILTERED GYRO VALUES
float gyro_calib[3];


float acc[3] = {0.0, 0.0, 0.0};
float acc_prev[3] = {0.0, 0.0, 0.0};
float LPF_agngleacc[3] = {0.0, 0.0, 0.0};//FILTERED ACC VALUES
float HPF_agngleacc[3] = {0.0, 0.0, 0.0};//FILTERED ACC VALUES
float acc_calib[3];

/*Matlab: H2 = tf([w],[1 w]) % H=(0*s+w/1*s+w), w=2*pi()*5 (cutoff), lowpass; sysd = c2d(H2,0.001, 'tustin') % discretized bilinearly*/
float coefg_HPF[3]={0.9802, 0.9901, 0.9901}; 
float coefa_HPF[3]={0.9802, 0.9901, 0.9901};
float coefa_LPF[3]={0.9802, 0.009901, 0.009901};


float acc_calib[6];

acc_calib[0] = (1.025 - 0.992) / (2)
acc_calib[1] = (1.009 - 1.001) / (2)
acc_calib[2] = (1.023 + 1.001) / (2)
acc_calib[3] = (1 - ((1.025 - 0.992) / (2) * 1.025))
acc_calib[4] = (1-((1.009 - 1.001) / (2) * 1.009))
acc_calib[5] = (1-((1.023 + 1.001) / (2) * 1.023))


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } 
}


void readgyro()
{
  for (i=0; i<3; i++)
  {
    gyro_prev[i]=gyro[i];
  }
  gyro[0] = myIMU.readFloatGyroX()+0.67;
  gyro[1] = myIMU.readFloatGyroY()+1.135;
  gyro[2] = myIMU.readFloatGyroZ()-0.8;  
}

void readacc()
{
  for (i=0; i<3; i++)
  {
    acc_prev[i]=acc[i];
  }

  acc[0] = acc_calib[0] * myIMU.readFloatAccelX() + acc_calib[3];
  acc[1] = acc_calib[1] * myIMU.readFloatAccelY() + acc_calib[4];
  acc[2] = acc_calib[2] * myIMU.readFloatAccelZ() + acc_calib[5];  
}


float phi_acc(float AccY, float AccZ)
{
  float calculated;
  calculated = atan(AccY/AccZ)*1/(3.142/180);//degrees roll / phi
  return(calculated);
}

float theta_acc(float AccX, float AccY, float AccZ)
{
  float calculated;
  calculated = atan(AccX/(sqrt(AccY*AccY+AccZ*AccZ)))*1/(3.142/180); // degress pitch / theta
  return(calculated);
}

void LPF_Acc()
{
  //y[n]=a1*y[n-1] + b0*x[n] + b1*x[n-1]
  LPF_agngleacc[0] = coefa_LPF[0] * LPF_agngleacc[0] + coefa_LPF[1] * phi_acc(acc[1], acc[2]) + coefa_LPF[2] * phi_acc(acc_prev[1],acc_prev[2]);
  LPF_agngleacc[1] = coefa_LPF[0] * LPF_agngleacc[1] + coefa_LPF[1] * theta_acc(acc[0], acc[1], acc[2]) + coefa_LPF[2] * theta_acc(acc_prev[0], acc_prev[1],acc_prev[2]);

}


/*
void HPF_Acc()
{
  //y[n]=a1*y[n-1] + b0*x[n] + b1*x[n-1]
  HPF_agngleacc[0] = coefa_HPF[0] * HPF_agngleacc[0] + coefa_HPF[1] * phi_acc(acc[1], acc[2]) + coefa_HPF[2] * phi_acc(acc_prev[1],acc_prev[2]);
  HPF_agngleacc[1] = coefa_HPF[0] * HPF_agngleacc[1] + coefa_HPF[1] * theta_acc(acc[0], acc[1], acc[2]) + coefa_HPF[2] * theta_acc(acc_prev[0], acc_prev[1],acc_prev[2]);

}

void HPF_Gyro()
{

  F_agngleacc[0] = a1*F_agngleacc[0] + b0*phi_acc(acc[1], acc[2]) + b1*phi_acc(acc_prev[1],acc_prev[2]);
  F_agngleacc[1] = a1*F_agngleacc[1] + b0*theta_acc(acc[0], acc[1], acc[2]) + b1*theta_acc(acc_prev[0], acc_prev[1],acc_prev[2]);

}
*/

void loop() 
{
  
}


/*typedef struct {

	float value_curr[3];
  float value_prev[3];

} Filter;

typedef struct {

	float value_curr[3];
  float value_prev[3];

void Filter_Init(Filter *fgyro, float wgyro)
{
  fgyro->value_curr[0] = y[n].....;
};

} ;
*/