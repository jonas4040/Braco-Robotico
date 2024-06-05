#include <Servo.h> 

Servo myservo1; 

Servo myservo2; 

Servo myservo3; 

Servo myservo4; 

int pos1 = 80, pos2 = 60, pos3 = 130, pos4 = 0; 

const int right_X = A2; 

const int right_Y = A5; 

const int right_key = 7; 

const int left_X = A3; 

const int left_Y = A4; 

const int left_key = 8; 

int x1, y1, z1; 

int x2, y2, z2; 

 

void setup() 

{ 

  myservo1.write(pos1); 

  delay(1000); 

  myservo2.write(pos2); 

  myservo3.write(pos3); 

  myservo4.write(pos4); 

  delay(1500); 

  pinMode(right_key, INPUT); 

  pinMode(left_key, INPUT); 

  Serial.begin(9600); 

} 

 

void loop() 

{ 

  myservo1.attach(A1); 

  myservo2.attach(A0); 

  myservo3.attach(6); 

  myservo4.attach(9); 

  x1 = analogRead(right_X); 

  y1 = analogRead(right_Y); 

  z1 = digitalRead(right_key); 

  x2 = analogRead(left_X); 

  y2 = analogRead(left_Y); 

  z2 = digitalRead(left_key); 

 

  zhuazi(); 

  zhuandong(); 

  xiaobi(); 

  dabi(); 

} 

 

void zhuazi() 

{ 

  if (x2 < 50) 

  { 

    pos4 = pos4 - 2; 

    myservo4.write(pos4); 

    delay(5); 

    if (pos4 < 2) 

    { 

      pos4 = 2; 

    } 

  } 

  if (x2 > 1000) 

  { 

    pos4 = pos4 + 8; 

    myservo4.write(pos4); 

    delay(5); 

    if (pos4 > 108) 

    { 

      pos4 = 108; 

    } 

  } 

} 

 

void zhuandong() 

{ 

  if (x1 < 50) 

  { 

    pos1 = pos1 - 1; 

    myservo1.write(pos1); 

    delay(5); 

    if (pos1 < 1) 

    { 

      pos1 = 1; 

    } 

  } 

  if (x1 > 1000) 

  { 

    pos1 = pos1 + 1; 

    myservo1.write(pos1); 

    delay(5); 

    if (pos1 > 180) 

    { 

      pos1 = 180; 

    } 

  } 

} 

 

void xiaobi() 

{ 

  if (y1 > 1000) 

  { 

    pos2 = pos2 - 1; 

    myservo2.write(pos2); 

    delay(5); 

    if (pos2 < 0) 

    { 

      pos2 = 0; 

    } 

  } 

  if (y1 < 50) 

  { 

    pos2 = pos2 + 1; 

    myservo2.write(pos2); 

    delay(5); 

    if (pos2 > 180) 

    { 

      pos2 = 180; 

    } 

  } 

} 

 

void dabi() 

{ 

  if (y2 < 50) 

  { 

    pos3 = pos3 + 1; 

    myservo3.write(pos3); 

    delay(5); 

    if (pos3 > 180) 

    { 

      pos3 = 180; 

    } 

  } 

  if (y2 > 1000) 

  { 

    pos3 = pos3 - 1; 

    myservo3.write(pos3); 

    delay(5); 

    if (pos3 < 35) 

    { 

      pos3 = 35; 

    } 

  } 

} 

 
