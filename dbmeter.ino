int numMeasure = 128 ;
int micPin = A0;     //  
long soundSignal;
long sum = 0 ;        //
long level = 0 ;

void setup ()  
{   
  pinMode (micPin, INPUT);
  Serial.begin (9600);  
}  
   
void loop ()  
{  
  for ( int i = 0 ; i <numMeasure; i ++)  
  {  
   soundSignal = analogRead (micPin);  
    sum = sum + soundSignal;  
  }  

  level = 1024 - (sum / numMeasure); // Fixed the reversed 
  Serial.println (level);  
  sum = 0 ; 
  delay(1);
}  
