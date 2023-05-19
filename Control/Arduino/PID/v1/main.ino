#include <QuickPID.h>

#define PIN_INPUT 0

#define motor_4 7
#define motor_3 8
#define motor_2 9
#define motor_1 10

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

void setup() {
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
  for (int i = 0; i < 200;i++){
    analogWrite(10, i);
    analogWrite(9, i);
    analogWrite(8, i);
    analogWrite(7, i);
    delay(10);
  }
}

void loop() {
  z_PID.Compute(); //After this line z_output gets updated
  z_output /= cos(theta_input) * cos(phi_input);
  z_output /= -4 * thrust_const;
  phi_PID.Compute();
  phi_output /= 4 * thrust_const * sin(pi/4) * motor_distance;
  theta_PID.Compute();
  theta_output /= 4 * thrust_const * sin(pi/4) * motor_distance;

  float motor_speed[4];
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
  delay(200);

}
