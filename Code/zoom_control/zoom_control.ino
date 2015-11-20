
#include <Servo.h> 
 
Servo myservo;

int pos = 90;
float velocity = 1;

#define out   9
#define in  10

#define outLimit 150
#define inLimit  5


void setup() 
{ 
  
  Serial.begin(115200);
  
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object 

  pinMode(in, INPUT);
  digitalWrite(in, 1);
  
  pinMode(out, INPUT);
  digitalWrite(out, 1);

} 
 
void loop() 
{ 
                               
  myservo.write(pos);              // tell servo to go to position in variable 'pos' 

  if (digitalRead(in) == 0 and pos > inLimit) {
    
    pos -= velocity;
    
    velocity += .1;

  }

  if (digitalRead(out) == 0 and pos < outLimit) {
    
    pos += velocity;

    velocity += .1;

  }
  
  if (digitalRead(in) and digitalRead(out)) {
  
    velocity = 1;
    
  }
  
  delay(25);
  
  Serial.print(pos);
  Serial.println(" ");

} 

