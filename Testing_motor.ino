#define PWMA   6           //Left Motor Speed pin 
#define AIN2   A0          //Motor-L forward
#define AIN1   A1          //Motor-L backward 
#define PWMB   5           //Right Motor Speed pin 
#define BIN1   A2          //Motor-R forward 
#define BIN2   A3          //Motor-R backward 
  
void setup() {
  // put your setup code here, to run once:
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);  
  analogWrite(PWMA,50);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMB,50);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
