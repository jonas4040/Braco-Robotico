// inclui bibilioteca do servomotor
#include <Servo.h>

// define pinos dos servos
#define pinServoBase 2
#define pinServoEsquerdo 3
#define pinServoDireito 4
#define pinServoGarra 5

// define as portas dos potenciometros
#define potGarra A0
#define potBase A1
#define potEsquerdo A2
#define potDireito A3

// nomeia os servos
Servo servGarra, servBase, servEsquerdo, servDireito;

// cria as variavies dos angulos de cada motor
int motorGarra, motorBase, motorEsquerdo, motorDireito;

void initialPosition() {
  servBase.write(96);
  delay(1000);
  servGarra.write(1);
  delay(1000);
  servDireito.write(56);
  delay(1000);
  servEsquerdo.write(117);
  delay(1000);
}

void catchObject(){
  servBase.write(80);
  delay(1000);
  servBase.write(69);
  delay(1000);

  servEsquerdo.write(85);
  delay(1000);
  servDireito.write(96);
  delay(1000);
  servEsquerdo.write(67);
  delay(1000);
  servDireito.write(90);
  delay(1000);

  servGarra.write(40);
  delay(1000);

  servEsquerdo.write(60);
  delay(1000);
  servDireito.write(71);
  delay(1000);
  servEsquerdo.write(67);
  delay(1000);
  servDireito.write(65);
  delay(1000);

  servGarra.write(10);
  delay(1000);
}

void dropObject() {
  Serial.print("inicio dropObject...");
  servEsquerdo.write(80);
  delay(1000);
  servDireito.write(50);
  delay(1000);

  servBase.write(90);
  delay(1000);
  servBase.write(110);
  delay(1000);
  servBase.write(130);
  delay(1000);

  servEsquerdo.write(80);
  delay(1000);
  servDireito.write(64);
  delay(1000);
  servEsquerdo.write(80);
  delay(1000);
  servDireito.write(65);
  delay(1000);

  servGarra.write(40);

  servEsquerdo.write(80);
  delay(1000);
  servDireito.write(80);
  delay(1000);
  servEsquerdo.write(81);
  delay(1000);
  servDireito.write(98);
  delay(1000);
  servEsquerdo.write(75);
  delay(1000);
  servDireito.write(80);
  delay(1000);
}

void setup() {

  //inicia o monitor serial
  Serial.begin(9600);

  // atribui pinos dos servos
  servGarra.attach(pinServoGarra);
  servBase.attach(pinServoBase);
  servEsquerdo.attach(pinServoEsquerdo);
  servDireito.attach(pinServoDireito);


  // zerar os servos
  // servBase.write(80); //Angle
  // servGarra.write(0); //Angle
  // servDireito.write(0); //Angle
  // servEsquerdo.write(180); //Angle
}

void loop() {
  initialPosition();
  catchObject();
  dropObject();
  delay(4000);

  // //Lê os valores dos potenciômetros (0 a 1023)
  // int potGarraValue = analogRead(potGarra);
  // int potBaseValue = analogRead(potBase);
  // int potEsquerdoValue = analogRead(potEsquerdo);
  // int potDireitoValue = analogRead(potDireito);

  // // Mapeia os valores dos potenciômetros para o intervalo de 0 a 180 graus
  // int motorGarra = map(potGarraValue, 0, 1023, 0, 180);
  // int motorBase = map(potBaseValue, 0, 1023, 0, 180);
  // int motorEsquerdo = map(potEsquerdoValue, 0, 1023, 0, 180);
  // int motorDireito = map(potDireitoValue, 0, 1023, 0, 180);

  // // Define a posição dos servos motores com base nos valores dos potenciômetros
  // servGarra.write(motorGarra);
  // servBase.write(motorBase);
  // servEsquerdo.write(motorEsquerdo);
  // servDireito.write(motorDireito);

  // // Imprime os valores dos potenciômetros e os ângulos para depuração (opcional)
  // Serial.print("Garra Angle: ");
  // Serial.print(motorGarra);
  // Serial.print(" | Base Angle: ");
  // Serial.print(motorBase);
  // Serial.print(" | Esquerdo Angle: ");
  // Serial.print(motorEsquerdo);
  // Serial.print(" | Direito Angle: ");
  // Serial.println(motorDireito);

  // Aguarda um pouco antes de ler os valores novamente
  delay(100);
}
