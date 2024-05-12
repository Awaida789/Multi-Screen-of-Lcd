#include <LiquidCrystal.h>
const int rs = 7, en = 8, d4 =9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define pb1 3
#define pb2 4
byte count=0;
int val=0;
byte buz=2;
#define pot A0
#define pot1 A3
#define led 13
#define trigPin 5
#define echoPin 13
long duration, distance;
int sensor=A4;
int reading;
byte led1=2;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(pb1,INPUT);
pinMode(pb2,INPUT);
pinMode(led,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(pot,INPUT);
pinMode(pot1,INPUT);
pinMode(buz,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(pb1)==0){
  delay(10);
  //while(digitalRead(pb1)==0);
  count++;
  if(count>3)count=4;
  }
  if(digitalRead(pb2)==0){
  delay(10);
  //while(digitalRead(pb2)==0);
  count--;
  if(count<0)count=0;
  }
  switch(count){
    case 0:
    page1();
    break;
    lcd.clear();
     case 1:
    page2();
    break;
    lcd.clear();
     case 2:
    page3();
    break;
    lcd.clear();
     case 3:
    page4();
    break;
    lcd.clear();
    }
}
void page1(){
  lcd.setCursor(13,1);
  lcd.print("1/4");
 lcd.setCursor(0,0);
  lcd.print("Tempture: ");
  lcd.setCursor(0,1);
   val=analogRead(pot);
 float myval=(val/1024.0)*5000;
 float cel=myval/10;
 lcd.setCursor(0,1);
 lcd.print("C=");
 lcd.print(cel);
  if(cel>=30){digitalWrite(led,1);}
 else{digitalWrite(led,0); } 
 }
  void page2(){
    lcd.setCursor(13,1);
  lcd.print("2/4");
  lcd.setCursor(0,0);
  lcd.print("Focus of Gas: ");
  lcd.setCursor(0,1);
  int val=analogRead(pot1);
   lcd.print("G="); 
   lcd.print(val); 
    if(val>=115){
  digitalWrite(led,1); }
  else{
  digitalWrite(led,0);  }
  } 
  void page3(){ 
    lcd.setCursor(13,1);
  lcd.print("3/4");
  lcd.setCursor(0,0);
  lcd.print("distance: ");
  lcd.setCursor(0,1);
   digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2)*0.0343 ;
lcd.print("d=");
lcd.print(distance);
if(distance<=240){
digitalWrite(led1,1);
delay(distance*30);
digitalWrite(led1,0);
delay(distance*30);
}
  } 
  void page4(){
    lcd.setCursor(13,1);
  lcd.print("4/4");
   lcd.setCursor(0,0); 
   lcd.print("Amount of Water:");
   lcd.setCursor(0,1);
   reading=analogRead(sensor);
   lcd.print("reading=");
   lcd.print(reading);
     if(reading>=215){
  digitalWrite(buz,1); }
  else{
  digitalWrite(buz,0);  }
  }
 
