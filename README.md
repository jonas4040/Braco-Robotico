----

## Braço Robótico


SISTEMAS EMBARCADOS

5° Semestre 2024 - FATEC Jundiaí

Integrantes:


- Fábio Massaretto;

- Felipe Cassalho Oliveira Da Silva;

- Jonas Felipe Módena De Morais;

- Nicollas De Oliveira Juliano;


----

# Sumário

1 - Introdução;

2 - Materiais;

3 - Código-Fonte;

4 - Conclusão do Projeto;




----


# 1 - Introdução

Com o surgimento da Indústria 4.0, também conhecida como a Quarta Revolução Industrial, surgiram tecnologias como Inteligência Artificial, Internet das Coisas, Computação em Nuvem e Big Data. A robótica e a automação são desenvolvidas a partir da integração desses sistemas (Computação, Mecânica, Eletrônica), com o objetivo de automatizar os processos industriais, substituindo o trabalho físico e mental humano por equipamentos tecnológicos. 

Essas tecnologias visam otimizar os processos industriais, aumentando a produtividade e a lucratividade. Nesse contexto, os braços robóticos têm sido amplamente utilizados em diferentes setores da indústria devido à sua versatilidade. Eles são capazes de realizar uma variedade de atividades de forma contínua, repetitiva e incansável, eliminando a necessidade de operadores humanos para tarefas repetitivas ou fisicamente exaustivas. 


----

# 2 - Materiais


Para a montagem do Braço Robótico, foram adquiridos separadamente uma placa de desenvolvimento KS0497 KEYESTUDIO V4.0 com o microcontrolador ATMEGA 328P (Arduino Uno), 4 servos motores (controlados por um conjunto de joysticks) que serão conectados a um Chassi Acrílico composto por articulações e juntas.

+ ATMEGA 328P (Arduino Uno)

  ![Arduino](https://github.com/jonas4040/Braco-Robotico/blob/main/imagens/arduino.png)

+ Placa de Expansão

![Expansao](https://github.com/jonas4040/Braco-Robotico/blob/main/imagens/expansao.png)

+ Braço Robótico em Acrílico

![Braco](https://github.com/jonas4040/Braco-Robotico/blob/main/imagens/braco-robotico-acrilico.png)


+ Micro Servo Motor

  ![Servo](https://github.com/jonas4040/Braco-Robotico/blob/main/imagens/servo.png)


+ Módulo Joystick

  ![Joystick](https://github.com/jonas4040/Braco-Robotico/blob/main/imagens/joystick.png)
  
# 3 - Código Fonte

Segue o link código fonte do projeto: https://github.com/jonas4040/Braco-Robotico/blob/main/braco-robotico/Projeto5semBracoRobotico.ino


```c

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
```


----


# 4 - Conclusão do Projeto

Ao concluir a execução de cada etapa descrita em cada tópico do documento do sistema, percebe-se que o protótipo alcançado se assemelha bastante ao ambiente de uma linha de produção industrial. A maioria dos possíveis problemas encontrados foi devidamente abordada e tratada, incluindo a montagem mecânica, a programação e a validação dos resultados, conforme planejado nos requisitos do projeto. 

O processo completo de planejamento e execução do projeto, respeitando e validando todo o fluxo do processo estabelecido, nos permite avaliar que o resultado alcançado está muito próximo do que foi proposto no início do projeto. Reconhecemos que algumas variáveis, como os elementos de fixação dos sensores, que não consideramos importantes no início, causaram alguns impactos em nosso tempo de realização e nos resultados. No entanto, com as ferramentas adequadas, o apoio dos professores e a colaboração dos membros da equipe, conseguimos entregar um trabalho de qualidade. 

No contexto específico da execução do projeto, é evidente a importância do planejamento e da execução precisa. O domínio sobre os ajustes mecânicos e a montagem, assim como a complexidade de integrar os elementos em um escopo que permita extrair o máximo de qualidade e desempenho, nos leva a considerar que o uso de uma ferramenta de CAD, com desenho assistido por computador, é fundamental para mitigar os riscos durante a execução do projeto. 

A funcionalidade do braço robótico integra de maneira satisfatória com o sistema de movimentação, e para todos nós do grupo, essa experiência foi enriquecedora em todos os aspectos, desde a programação até o processo de compras, montagem e discussões do grupo, promovendo o amadurecimento de nosso relacionamento interpessoal e nossa comunicação profissional. 

----