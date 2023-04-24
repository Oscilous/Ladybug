%Constants to be set
m = 10; % Mass of the drone
b = 1; % Thrust constant of one motor
d = 1; % Torque constant of one motor
Ixx = 1; % Drone inertia around the xx axis
Iyy = 1; % Drone inertia around the yy axis
Izz = 1; % Drone inertia around the zz axis
l = 1; % Lenght from the motor to the mid point
Jr = 1; % Rotor inertia
Ax = 1; % Air resistance from axis X
Ay = 1; % Air resistance from axis Y
Az = 1; % Air resistance from axis Z
g = 9.81; % The accelaration from gravity


%Outputs from simulink
x = out.X;
y = out.Y;
z = out.Z;

plot3(x, y, z)
