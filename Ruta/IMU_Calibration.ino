//***********Calibration*******************

#include <LSM6DS3.h>
#include <Wire.h>

LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A
uint32_t Timer;


float gyro[3] = {0.0, 0.0, 0.0};
float gyro_bias[3] = {0.0, 0.0, 0.0};
float gyro_prev[3] = {0.0, 0.0, 0.0};


float acc[3] = {0.0, 0.0, 0.0};
float acc_prev[3] = {0.0, 0.0, 0.0};
float acc_bias[3] = {-0.01, +0.01, -0.017};

float acc_calib[6]={1.0, 1.0, 1.0, 0.0, 0.0, 0.0};

void acc_calculate()
{
  acc_calib[0]=(1.008+1.012)/2;
  acc_calib[3]=(acc_calib[0]*1.008-1)/2;

  acc_calib[1]=(0.994+1.006)/2;
  acc_calib[4]=(acc_calib[0]*0.994-1)/2;

  acc_calib[2]=(1.017+0.984)/2;
  acc_calib[5]=(acc_calib[0]*1.017-1)/2;
}

float g = 9.81;

void readgyro()
{
  gyro[0] = myIMU.readFloatGyroX();//+0.67;
  gyro[1] = myIMU.readFloatGyroY();//+1.135;
  gyro[2] = myIMU.readFloatGyroZ();//-0.8;  
}

void readacc()
{
  acc[0] = myIMU.readFloatAccelX();//-0.0165;
  acc[1] = myIMU.readFloatAccelY();//-0.005;
  acc[2] = myIMU.readFloatAccelZ();//-0.012;  
}



void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } else {
    Serial.println("OK");
    delay(1000);
    acc_calculate();
    delay(1000);
    calibrate_gyro();
    //gyro_bias[0] = -2.39;
    //gyro_bias[1] = -0.2;
    //gyro_bias[2] = -2.39;
  }

    delay(1000);
}

void calibrate_gyro()
{
  float sumX = 0, sumY = 0, sumZ = 0;
  
  for (int i = 0; i < 10000; i++) 
  {
    readgyro();
    sumX = sumX + gyro[0];
    sumY = sumY + gyro[1];
    sumZ = sumZ + gyro[2];
  }

  gyro_bias[0] = sumX/10000.0;
  gyro_bias[1] = sumY/10000.0;
  gyro_bias[2] = sumZ/10000.0;
}

void calibrate_acc()
{
  float sumX = 0, sumY = 0, sumZ = 0;

  for (int i = 0; i < 10000; i++) 
  {
    readacc();
    sumX = sumX + acc[0];
    sumY = sumY + acc[1];
    sumZ = sumZ + acc[2];
  }

  acc_bias[0] = sumX/10000.0-1;
  acc_bias[1] = sumY/10000.0-1;
  acc_bias[2] = sumZ/10000.0-1;
}



void loop() 
{
  calibrate_gyro();
  calibrate_acc();

  readgyro();
  readacc();


  Serial.println("Gyro");
  Serial.print(gyro[0], 3);
  Serial.print(',');
  Serial.print(gyro[1], 3);
  Serial.print(',');
  Serial.print(gyro[2], 3);
  Serial.print("    ");
  Serial.print(gyro[0]-gyro_bias[0], 3);
  Serial.print(',');
  Serial.print(gyro[1]-gyro_bias[1], 3);
  Serial.print(',');
  Serial.print(gyro[2]-gyro_bias[2], 3);
  Serial.print("    Gyro bias:");
  Serial.print(gyro_bias[0], 3);
  Serial.print(',');
  Serial.print(gyro_bias[1], 3);
  Serial.print(',');
  Serial.print(gyro_bias[2], 3);
  Serial.println();
  Serial.println("Acc:");
  Serial.print(acc[0], 3);
  Serial.print(',');
  Serial.print(acc[1], 3);
  Serial.print(',');
  Serial.print(acc[2], 3);
  Serial.print("    ");
  Serial.print(acc[0]-acc_bias[0], 3);
  Serial.print(',');
  Serial.print(acc[1]-acc_bias[1], 3);
  Serial.print(',');
  Serial.print(acc[2]-acc_bias[2], 3);
  Serial.print("    Acc bias:");
  Serial.print(acc_bias[0], 3);
  Serial.print(',');
  Serial.print(acc_bias[1], 3);
  Serial.print(',');
  Serial.print(acc_bias[2], 3);
  //Serial.println();

/*
  Serial.println("Accel:");
  Serial.print(acc[0], 3);
  Serial.print(',');
  Serial.print(acc[1], 3);
  Serial.print(',');
  Serial.print(acc[2], 3);
  Serial.print(',');
  Serial.print((acc[0]*acc_calib[0]-acc_calib[3]), 3);
  Serial.print(',');
  Serial.print((acc[1]*acc_calib[1]-acc_calib[4]), 3);
  Serial.print(',');
  Serial.print((acc[2]*acc_calib[2]-acc_calib[5]), 3);
  
  Serial.println("coef:");
  Serial.print(acc_calib[0], 3);
  Serial.print(',');
  Serial.print(acc_calib[1], 3);
  Serial.print(',');
  Serial.print(acc_calib[2], 3);
  Serial.print(',');
  Serial.print(acc_calib[3], 3);
  Serial.print(',');
  Serial.print(acc_calib[4], 3);
  Serial.print(',');
  Serial.print(acc_calib[5], 3);
  /*
  Serial.print(gyro_bias[0], 3);
  Serial.print(',');
  Serial.print(gyro_bias[1], 3);
  Serial.print(',');
  Serial.print(gyro_bias[2], 3);
  Serial.print(',');
  Serial.print(acc_bias[0], 3);
  Serial.print(',');
  Serial.print(acc_bias[1], 3);
  Serial.print(',');
  Serial.print(acc_bias[2], 3);*/
  Serial.println();
  delay(500);

 
}

