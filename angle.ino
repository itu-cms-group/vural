int measure  = 128;
int pinNorth = A1;
int pinSouth = A3;
int pinEast  = A0;
int pinWest  = A2;
long soundN;
long soundS;
long soundE;
long soundW;
long final;
long sumN    = 0;
long sumS    = 0;
long sumE    = 0;
long sumW    = 0;
long levelN  = 0;
long levelS  = 0;
long levelE  = 0;
long levelW  = 0;

void setup(){
  pinMode (pinNorth, INPUT);
  pinMode (pinSouth, INPUT);
  pinMode (pinEast, INPUT);
  pinMode (pinWest, INPUT);

  Serial.begin (9600);
}

void loop (){
  for ( int i = 0 ; i < measure; i ++){
    soundN = analogRead (pinNorth);
    soundS = analogRead (pinSouth);
    soundE = analogRead (pinEast);
    soundW = analogRead (pinWest);

    sumN = sumN + soundN;
    sumS = sumS + soundS;
    sumE = sumE + soundE;
    sumW = sumW + soundW;
  }

  levelN = 1024 - (sumN / measure);
  levelS = 1024 - (sumS / measure);
  levelE = 1024 - (sumE / measure);
  levelW = 1024 - (sumW / measure);

  Serial.print("Angle: ");
  final = atan2 ((levelN - levelS),(levelE - levelW) ) * 180/3.14159265;
  
  if (final >= 0){
    
    Serial.println(final);  
  }
  
  if (final < 0){
    
    final = (360 + final);
    Serial.println(final);
  }
  sumN = 0;
  sumS = 0;
  sumE = 0;
  sumW = 0;

  delay(10);
}

