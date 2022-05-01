int trigPin=4;
int echoPin=5;
long duration;
int cm=0;
int verd=8;
int groc=9;
int vermell=10;
int buzzer=3;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(verd,OUTPUT);
  pinMode(groc,OUTPUT);
  pinMode(vermell,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  duration=duration/2;

  cm=duration/29;
  Serial.print("Distancia");
  Serial.println(cm);
  delay(100);

  if (cm>15)
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(verd,HIGH);
    digitalWrite(vermell,LOW);
    digitalWrite(groc,LOW);
  }
  if (cm<=15&&cm>=5)
  {
   digitalWrite(groc,HIGH);
   digitalWrite(vermell,LOW);
   digitalWrite(verd,LOW);
   digitalWrite(buzzer,HIGH);
   delay(200);
   digitalWrite(buzzer,LOW);
   delay(500);
  }
  if (cm<5)
  {
    digitalWrite(vermell,HIGH);
    digitalWrite(groc,LOW);
    digitalWrite(verd,LOW);
    digitalWrite(buzzer,HIGH);
    delay(200);
}
