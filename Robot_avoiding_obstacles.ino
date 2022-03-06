#define PWMA   6           //Left Motor Speed pin (ENA)
#define AIN2   A0          //Motor-L forward (IN2).
#define AIN1   A1          //Motor-L backward (IN1)
#define PWMB   5           //Right Motor Speed pin (ENB)
#define BIN1   A2          //Motor-R forward (IN3)
#define BIN2   A3          //Motor-R backward (IN4)
#define ECHO   2
#define TRIG   3

int robot_distance = 0;
int robot_speed = 120;

int distance_measure();
void forward();
void backward();
void right();
void left();
void stop();

void setup()
{
  Serial.begin(115200);  
  Serial.println("Robot avoiding obstacles example");
  pinMode(ECHO, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG, OUTPUT);   // Define the ultrasonic trigger input pin 
  pinMode(PWMA,OUTPUT);    // Define the Left Motor Speed pin                 
  pinMode(AIN2,OUTPUT);    // Define the Left Motor forward pin  
  pinMode(AIN1,OUTPUT);    // Define the Left Motor backward pin
  pinMode(PWMB,OUTPUT);    // Define the Right Motor Speed pin   
  pinMode(BIN1,OUTPUT);    // Define the Right Motor forward pin 
  pinMode(BIN2,OUTPUT);    // Define the Rightt Motor backward pin
  analogWrite(PWMA,robot_speed);
  analogWrite(PWMB,robot_speed);
  stop();    
}

void loop()
{
  robot_distance = distance_measure();                 //display distance 
  Serial.print("robot_distance = ");            //print distance
  Serial.print(robot_distance);       
  Serial.println("cm");  
  if(robot_distance < 30)      //Ultrasonic range ranging 2cm to 500cm
  {
    right();
    //left();
    delay(500);
    stop();     
  }
  else
  {
    forward();    
  }
  delay(250);
}

int distance_measure()         // Measure the distance 
{
  digitalWrite(TRIG, LOW);   // set trig pin low 5μs
  delayMicroseconds(5);
  digitalWrite(TRIG, HIGH);  // set trig pin 15μs
  delayMicroseconds(15);
  digitalWrite(TRIG, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO, HIGH);  // Read echo pin high level time(us)
  Fdistance= Fdistance/60;      
  return (int)Fdistance;
}  

void forward()
{
  analogWrite(PWMA,robot_speed);
  analogWrite(PWMB,robot_speed);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,LOW);  
  digitalWrite(BIN2,HIGH); 
}

void backward()
{
  analogWrite(PWMA,robot_speed);
  analogWrite(PWMB,robot_speed);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);  
}

void right()
{
  analogWrite(PWMA,50);
  analogWrite(PWMB,50);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);  
}

void left()
{
  analogWrite(PWMA,50);
  analogWrite(PWMB,50);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);  
}

void stop()
{
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);  
}
