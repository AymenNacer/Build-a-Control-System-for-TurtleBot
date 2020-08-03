# Build-a-Control-System-for-TurtleBot
Control system for TurtleBot using Arduino, i used motor encoder to determine how many turns the motor(wheel) had, by counting and dividing by 47 (it should be 32)

![41rHsHX8SgL _SX342_](https://user-images.githubusercontent.com/67188835/89170916-09362280-d589-11ea-813a-9a8d88cc6b72.jpg)


I used ultrasonic distance sensor to make sure the robot does not collide with an object, here the potentiometer is used to simulate the distance to the obstacle in front of the turtlebot robot. When an object is close the led should turn on and warning message should be printed.

![Capture](https://user-images.githubusercontent.com/67188835/89171526-fe2fc200-d589-11ea-92df-a7d26c1d8ae7.PNG)

There are four directions, the user can't press two buttons at the same time, so turns are counted in case of forward and backward direction

Sample run:

![ezgif-6-b3cabaa681d2new](https://user-images.githubusercontent.com/67188835/89172175-df7dfb00-d58a-11ea-8f16-1e6f84079b2d.gif)


