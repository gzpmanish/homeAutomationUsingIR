int ir1=3;
int ir2=4;

int relay1=8;  // for light
int relay2=9;  // for light
int relay3=10;  // for light
int relay4=11;  // for light
void setup() {
  Serial.begin(9600);
  // Input for IR sensor
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  // Output for relay
  pinMode(relay1,OUTPUT);
//  digitalWrite(D3,LOW);

}
unsigned int IRread1,IRread2;
int count=0;
void loop() {

  IRread1 = digitalRead(ir1);
  delay(600);
  IRread2 = digitalRead(ir2);

  Serial.println(IRread1);
  
///////////////////////Change from here///////////
  if(IRread1==0){
    count++;
  }
  else if(IRread2==0){
    count--;
  }
  else{
    count=count;
  }

  Serial.print("number of people: ");
  Serial.println(count);

  if(count>0){
    digitalWrite(relay1,HIGH);
    Serial.println("Relay on");
    delay(500);
  }
  if(count<=0){
    digitalWrite(relay1,LOW);
    Serial.println("Relay off");
  }
  
//  delay(1000);

}
