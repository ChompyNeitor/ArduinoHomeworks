const int Trigger = 11;  //Pin digital 11 for the Trigger sensor
const int Echo = 10;   //Pin digital 10 for the Echo sensor
int led = 5;

void setup() {
  Serial.begin(9600);  //Start comunication 
  pinMode(Trigger, OUTPUT); //Pin out
  pinMode(Echo, INPUT);  //Pin it
  digitalWrite(Trigger, LOW); //The pin stars in 0
  pinMode (6,OUTPUT);
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (led,OUTPUT);
   
}

void loop()
{
  long t; //Time it takes for the echo in arrive
  long d; //Distance in centimeters

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(5);          //Send a pulse for 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH);  //Get the pulse width
  d = t/59;           //Scale the time to adistance in centimeters
  
  Serial.print("Distance: ");  //Print the distance in the screen 
  Serial.print(d);      
  Serial.print("cm");
  Serial.println();
  delay(100);    

     if(d <= 15){                 //If the distance is less or equal than 15cm the car stop
      digitalWrite(led,HIGH);
      digitalWrite (6,0);
      digitalWrite (7,0);
      digitalWrite (8,0);
      digitalWrite (9,0);
     }
     else{                        //Else the car moves ahead
      digitalWrite(led,LOW); 
      digitalWrite (6,0);
      digitalWrite (7,1);
      digitalWrite (8,1);
      digitalWrite (9,0);
 }
}
   
