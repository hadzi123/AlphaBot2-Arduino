#define ECHO   2
#define TRIG   3

int robot_distance = 0;

int distance_measure()         // Measure the distance 
{
  digitalWrite(TRIG, LOW);   // set trig pin low 2μs
  delayMicroseconds(5);
  digitalWrite(TRIG, HIGH);  // set trig pin high 15μs 
  delayMicroseconds(15);
  digitalWrite(TRIG, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO, HIGH);  // Read echo pin high level time(us)
  Fdistance= Fdistance/60;          
  return (int)Fdistance;
}  

void setup()
{
  Serial.begin(115200);
  Serial.println("Robot measuring distance with Ultrasonic sensor example");  
  pinMode(ECHO, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG, OUTPUT);   // Define the ultrasonic trigger input pin   
}

void loop()
{
  robot_distance = distance_measure();                 //display distance 
  if((2 < robot_distance) && (robot_distance < 500))      //Ultrasonic range from 2cm to 500cm
  {
    Serial.print("robot_distance = ");            //print distance
    Serial.print(robot_distance);       
    Serial.println("cm");       
  }
  else
  {
    Serial.println("Out of range !!!");      
  }
  delay(250);
}
