int pump=6;
int gass=A1;
int sensorpin=A0;
int sensorvalue=0;
int led=9;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(pump,OUTPUT);
pinMode(gass,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
int gassval=analogRead(gass);
sensorvalue=analogRead(sensorpin);
Serial.println(sensorvalue);
Serial.println(gassval);
if(sensorvalue<100)
{
  Serial.println("FIRE DETECTED");
  digitalWrite(led,HIGH);
  digitalWrite(pump,HIGH);
  delay(1000);
  }
  if(gassval>120)
  {
    Serial.println("GASS LEAKED");
    digitalWrite(led,HIGH);
    digitalWrite(pump,HIGH);
    delay(1000);
    }
  else
  {
    Serial.println("NO FLAME NO GASS");
    digitalWrite(led,LOW);
    digitalWrite(pump,LOW);
    delay(sensorvalue);
    }
}
