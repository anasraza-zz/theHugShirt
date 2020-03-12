#include <Servo.h>          
 
Servo servo_right;        
Servo servo_left;  

const int trigPin = 13;
const int echoPin = 12;
long duration;
int distance;


int led = 10;           
int brightness = 0;   
int fadeAmount = 5;   

int angle = 0;    
 
void setup() 
{ 
servo_right.attach(4);      
servo_left.attach(7); 

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
Serial.begin(9600);

pinMode(led, OUTPUT);
} 
  
void loop() 
{
///////////////////////////////////////////////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(200);

////////////////////////////////////////// State 2 /////////////////////////////////////////////////////




if (distance>50 && distance<100)

{
                                
    servo_right.write(120);                
    delay(200);
    servo_left.write(0);  


    
  
 
 
}
////////////////////////////////////////// State 3 /////////////////////////////////////////////////////

else if (distance>10 && distance<50)

{

    digitalWrite(led, HIGH);                           
    servo_right.write(90);                 
    delay(30);
    servo_left.write(30);  
    delay(30);
    servo_right.write(120);               
    delay(30);
    servo_left.write(0);  
    delay(30);
    servo_right.write(90);                
    delay(30);
    servo_left.write(30);  
    delay(30);
    
    
  
 
 
}
////////////////////////////////////////// State 1 /////////////////////////////////////////////////////

else if (distance>=100)
{  

     servo_left.write(120); 
     delay(200);
    servo_right.write(0);             
    delay(1000);
     digitalWrite(led, LOW);
}

////////////////////////////////////////// State 4 /////////////////////////////////////////////////////

else if (distance < 10)
{  

     servo_left.write(120); 
     delay(200);
    servo_right.write(0);             
    delay(1000);
     digitalWrite(led, LOW);
}


}
