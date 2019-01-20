int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9
                                       
//void Num_Write(int);

int val = 0;

const int buttonPin = 11;    
const int ledPin =  LED_BUILTIN; 

int buttonState = 0; 

void setup() 
{ 
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  analogReference(INTERNAL); //Set to 0 - 1.1V range
  
  Serial.begin(9600);   
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
   val = analogRead(A0);
   Serial.println(val);
   
  if (buttonState == LOW) {
    delay(100);
    Num_Write(val % 10);
    digitalWrite(ledPin, LOW);
    digitalWrite(9, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
    digitalWrite(9, HIGH);
  }
}

// this functions writes values to the sev seg pins  
void Num_Write(int number) 
{
  int pin= 2;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[number][j]);
   pin++;
  }
}