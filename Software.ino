
int motorPWM;
//Sets up variables for most of the pins
int m1PinP = 5;
int m1PinD =  4;
int m2PinP = 6;
int m2PinD = 7;
int DIP1 = 13;
int DIP2 = 12;
int DIP3 = 11;
int DIP4 = 10;

//Sets up a variable for the potentiometer
double pot;

//Creates variables to store the DIP readings in
int DIP1R, DIP2R, DIP3R, DIP4R;

void setup()
{
  //Initializes all output pins
  pinMode(m1PinP, OUTPUT);
  pinMode(m1PinD, OUTPUT);
  pinMode(m2PinP, OUTPUT);
  pinMode(m2PinD, OUTPUT);
  
  //Initializes DIP switch pins
  pinMode(DIP1, INPUT_PULLUP);
  pinMode(DIP2, INPUT_PULLUP);
  pinMode(DIP3, INPUT_PULLUP);
  pinMode(DIP4, INPUT_PULLUP);
  
  //Initializes potentiometer switch
  pinMode(A5, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  //Reads the values of each potentiometer and stores them in variables
  DIP1R = digitalRead(DIP1);
  DIP2R = digitalRead(DIP2);
  DIP3R = digitalRead(DIP3);
  DIP4R = digitalRead(DIP4);
  
  //Calls on each method to show they work, as i couldn't figure out the DIP switch stuff
  fDrive();
  delay(5000);
  bDrive();
  delay(5000);
  rTurn();
  delay(5000);
  lTurn();
  delay(5000);
  stop();
  delay(5000);
  
  //Is supposed to check which DIP switch is on and switch modes based on that, but I couldn't get it working
  if(DIP1R == HIGH){
	fDrive();
  }
  else if(DIP2R == HIGH){
	bDrive();
  }
  else if(DIP3R == HIGH){
	rTurn();
  }
  else if(DIP4R == HIGH){
	lTurn();
  }
  else{
    stop();
  }
}

//Drive Forwards
void fDrive(){
  //Reads the potentiometer and does some math to get the PWM equivilent
  pot = analogRead(A5);
  motorPWM = (pot / 1023) * 255;
  
  //Uses analogWrite to set the motor speeds and digitalWrite to set the speed direction
  analogWrite(m1PinP, motorPWM);
  analogWrite(m2PinP, motorPWM);
  digitalWrite(m1PinD, HIGH);
  digitalWrite(m2PinD, HIGH);
}

//Drive backwards
void bDrive(){
  //Reads the potentiometer and does some math to get the PWM equivilent
  pot = analogRead(A5);
  motorPWM = (pot / 1023) * 255;
  
  analogWrite(m1PinP, -motorPWM);
  analogWrite(m2PinP, -motorPWM);
  digitalWrite(m1PinD, LOW);
  digitalWrite(m2PinD, LOW);
}

void rTurn(){
  //Reads the potentiometer and does some math to get the PWM equivilen
  pot = analogRead(A5);
  motorPWM = (pot / 1023) * 255;
  
  //Uses analogWrite to set the motor speeds and digitalWrite to set the speed direction
  analogWrite(m1PinP, motorPWM);
  analogWrite(m2PinP, -motorPWM);
  digitalWrite(m1PinD, HIGH);
  digitalWrite(m2PinD, LOW);
}

void lTurn(){
  //Reads the potentiometer and does some math to get the PWM equivilent
  pot = analogRead(A5);
  motorPWM = (pot / 1023) * 255;
  
  //Uses analogWrite to set the motor speeds and digitalWrite to set the speed direction
  analogWrite(m1PinP, -motorPWM);
  analogWrite(m2PinP, motorPWM);
  digitalWrite(m1PinD, LOW);
  digitalWrite(m2PinD, HIGH);
}

void stop(){
  //Sets the motor speeds to 0 using PWM to stop the motors, and sets the direction controller to a digital low to avoid power consumption
  analogWrite(m1PinP, 0);
  analogWrite(m2PinP, 0);
  digitalWrite(m1PinD, LOW);
  digitalWrite(m2PinD, LOW);
}