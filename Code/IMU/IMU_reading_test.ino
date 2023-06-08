#include <LSM6DS3.h>
#include <Wire.h>

//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

int i;
float g = 9.81;

float gyro[3] = {0.0, 0.0, 0.0};
float gyro_bias[3] = {0.0, 0.0, 0.0};
float gyro_prev[3] = {0.0, 0.0, 0.0};


float acc[3] = {0.0, 0.0, 0.0};
float acc_prev[3] = {0.0, 0.0, 0.0};
float acc_bias[3] = {-0.01, +0.01, -0.017};

float acc_calib[6]={1.0, 1.0, 1.0, 0.0, 0.0, 0.0};
/*
void calibrate_acc()
{
  acc_calib[0] = (1.025 - 0.992) / (2);
  acc_calib[1] = (1.009 - 1.001) / (2);
  acc_calib[2] = (1.023 + 1.001) / (2);
  acc_calib[3] = (1 - ((1.025 - 0.992) /  1.025));
  acc_calib[4] = (1 - ((1.009 - 1.001) /  1.009));
  acc_calib[5] = (1 - ((1.023 + 1.001) /  1.023));

}
*/
void calibrate_gyro()
{
  float sumX = 0, sumY = 0, sumZ = 0;
  
  for (int i = 1; i < 2000; i++) 
  {
    readgyro();
    sumX = sumX + myIMU.readFloatGyroX();
    sumY = sumY + myIMU.readFloatGyroY();
    sumZ = sumZ + myIMU.readFloatGyroZ();
  }

  gyro_bias[0] = sumX/2000.0;
  gyro_bias[1] = sumY/2000.0;
  gyro_bias[2] = sumZ/2000.0;
}


/*
void readgyro()
{
  for (i=0; i<3; ++i)
  {
    gyro_prev[i]=gyro[i];
  }
  gyro[0] = myIMU.readFloatGyroX()-0.67;
  gyro[1] = myIMU.readFloatGyroY()-1.135;
  gyro[2] = myIMU.readFloatGyroZ()+0.8;  
}

void readacc()
{
  for (i=0; i<3; ++i)
  {
    acc_prev[i]=acc[i];
  }

  acc[0] = acc_calib[0] * myIMU.readFloatAccelX() + acc_calib[3];
  acc[1] = acc_calib[1] * myIMU.readFloatAccelY() + acc_calib[4];
  acc[2] = acc_calib[2] * myIMU.readFloatAccelZ() + acc_calib[5];  
}
*/

void readgyro()
{
  for (i=0; i<3; ++i)
  {
    gyro_prev[i]=gyro[i];
  }
  gyro[0] = myIMU.readFloatGyroX() - gyro_bias[0];
  gyro[1] = myIMU.readFloatGyroY() - gyro_bias[1];
  gyro[2] = myIMU.readFloatGyroZ() - gyro_bias[2];  
}

void readacc()
{
  for (i=0; i<3; ++i)
  {
    acc_prev[i]=acc[i];
  }

  acc[0] = myIMU.readFloatAccelX() + acc_bias[0];
  acc[1] = myIMU.readFloatAccelY() + acc_bias[1];
  acc[2] = myIMU.readFloatAccelZ() + acc_bias[2];
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
    Serial.println("Device error");
  } else {
    calibrate_gyro();
    //calibrate_acc();
    Serial.println("aX,aY,aZ,gX,gY,gZ");
  }
}

void loop() {
  
    readgyro();
    readacc();

    Serial.print(gyro[0], 3);
    Serial.print(',');
    Serial.print(gyro[1], 3);
    Serial.print(',');
    Serial.print(gyro[2], 3);
    Serial.print(',');
    Serial.print(acc[0], 3);
    Serial.print(',');
    Serial.print(acc[1], 3);
    Serial.print(',');
    Serial.print(acc[2], 3);
    Serial.println();
    delay(100);

}