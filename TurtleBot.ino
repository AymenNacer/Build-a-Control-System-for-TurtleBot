//motor_1 pins OUTPUT & INPUT
int EncoderMotor_1 = 3;
int ClockW_motor1 = 11, AntiClockW_motor1 = 10;
int EN1 =12;
long int counter =0; //COUNTER Number of robot turns
int direction;

//motor_2 pins OUTPUT & INPUT
int EncoderMotor_2 = 2;
int EN2 =7;
int ClockW_motor2 = 9, AntiClockW_motor2 = 8;
long int c2 =0;//COUNTER Number of motor_2 turns

//control directions
int forward =A0, backward =A1, right = A2, left =A3 ; 

//UltraSonic Sensor INPUT & OUTPUT
int TrigPin=6, EchoPin = 5;
long duration; int distance;
int LED =13;

void setup()
{Serial.begin(9600);
//motor_1 pins OUTPUT & INPUT
pinMode( ClockW_motor1, OUTPUT);
pinMode( AntiClockW_motor1, OUTPUT);
pinMode( EN1, OUTPUT);
attachInterrupt(digitalPinToInterrupt(2), counter1, CHANGE);

//-motor_2 pins OUTPUT & INPUT
int EncoderMotor_2 = 2;
pinMode( ClockW_motor2, OUTPUT);
pinMode( AntiClockW_motor2, OUTPUT);
pinMode( EN2, OUTPUT);



////control directions
pinMode(forward, INPUT);
pinMode(backward, INPUT);
pinMode(right, INPUT);
pinMode(left, INPUT);

//UltraSonic Sensor INPUT & OUTPUT
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
}
void loop(){
Serial.println("******************************************************");

// no directions input is given stop
if (digitalRead(forward)==LOW && digitalRead(backward)==LOW && digitalRead(left)==LOW && digitalRead(right)==LOW)
{
digitalWrite (ClockW_motor1, LOW);
digitalWrite (AntiClockW_motor1, LOW);
digitalWrite (ClockW_motor2, LOW);
digitalWrite (AntiClockW_motor2, LOW);
analogWrite(EN1,0);
analogWrite(EN2,0);
Serial.println("robot is not moving");
delay(1000);
}

//forward direction 
else if (digitalRead(forward)==HIGH)
{
digitalWrite (ClockW_motor1, HIGH);
digitalWrite (AntiClockW_motor1, LOW);
direction = 1;
digitalWrite (ClockW_motor2, HIGH);
digitalWrite (AntiClockW_motor2, LOW);

analogWrite(EN1,255);
analogWrite(EN2,255);
Serial.println("the Robot is moving FORWARD ");
delay(1000);
}

//backward direction
else if (digitalRead(backward)==HIGH)
{
digitalWrite (ClockW_motor1, LOW);
digitalWrite (AntiClockW_motor1, HIGH);
direction = -1;
digitalWrite (ClockW_motor2, LOW);
digitalWrite (AntiClockW_motor2, HIGH);

analogWrite(EN1,255);
analogWrite(EN2,255);
Serial.println("the Robot is moving BACKWARD ");
delay(1000);
}

//left direction
else if (digitalRead(left)==HIGH)
{
digitalWrite (ClockW_motor1, HIGH);
digitalWrite (AntiClockW_motor1, LOW);
direction = 0;
digitalWrite (ClockW_motor2, LOW);
digitalWrite (AntiClockW_motor2, LOW);

analogWrite(EN1,255);
analogWrite(EN2,0);
Serial.println("the Robot is moving LEFT ");
delay(1000);
}

//right direction
else if (digitalRead(right)==HIGH)
{
digitalWrite (ClockW_motor1, LOW);
digitalWrite (AntiClockW_motor1, LOW);
direction = 0;
digitalWrite (ClockW_motor2, HIGH);
digitalWrite (AntiClockW_motor2, LOW);

analogWrite(EN1,0);
analogWrite(EN2,255);
Serial.println("the Robot is moving RIGHT ");
delay(1000);
}



// ultrasonic extracting distance
digitalWrite(TrigPin, LOW);
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
duration = pulseIn(EchoPin, HIGH);
distance = duration*0.034/2;
Serial.print("distance from obstacle in cm = ");
Serial.println(distance);
  if (distance<=30){
    digitalWrite(LED, HIGH); Serial.println("WARNING!! object is close");
  }
  else if(distance>30){
    digitalWrite(LED, LOW);
  } 


Serial.print("Number of robot turns= ");
Serial.println(counter/47);// it should be 32 due to encoder but 47 works with me
delay(200);
}

//COUNTER how many turns the robot take
void counter1 (){
if(direction ==1)
counter++;
else if (direction==-1)
counter--; 
}
