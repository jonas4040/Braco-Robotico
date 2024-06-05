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

  ![Arduino](https://github.com/jonas4040/Braco-Robotico/imagens/)

+ Placa de Expansão

![Expansao](https://github.com/jonas4040/Braco-Robotico/imagens/)

+ Braço Robótico em Acrílico

![Braco](https://github.com/jonas4040/Braco-Robotico/imagens/)


+ Micro Servo Motor

  ![Servo](https://github.com/jonas4040/Braco-Robotico/imagens/)


+ Módulo Joystick

  ![Joystick](https://github.com/jonas4040/Braco-Robotico/imagens/)
  
# 3 - Código Fonte

Segue o link código fonte do projeto: https://github.com/jonas4040/Braco-Robotico/blob/main/braco-robotico/braco-robotico.ino


```c

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

 

```


----


# 4 - Conclusão do Projeto

Ao concluir a execução de cada etapa descrita em cada tópico do documento do sistema, percebe-se que o protótipo alcançado se assemelha bastante ao ambiente de uma linha de produção industrial. A maioria dos possíveis problemas encontrados foi devidamente abordada e tratada, incluindo a montagem mecânica, a programação e a validação dos resultados, conforme planejado nos requisitos do projeto. 

O processo completo de planejamento e execução do projeto, respeitando e validando todo o fluxo do processo estabelecido, nos permite avaliar que o resultado alcançado está muito próximo do que foi proposto no início do projeto. Reconhecemos que algumas variáveis, como os elementos de fixação dos sensores, que não consideramos importantes no início, causaram alguns impactos em nosso tempo de realização e nos resultados. No entanto, com as ferramentas adequadas, o apoio dos professores e a colaboração dos membros da equipe, conseguimos entregar um trabalho de qualidade. 

No contexto específico da execução do projeto, é evidente a importância do planejamento e da execução precisa. O domínio sobre os ajustes mecânicos e a montagem, assim como a complexidade de integrar os elementos em um escopo que permita extrair o máximo de qualidade e desempenho, nos leva a considerar que o uso de uma ferramenta de CAD, com desenho assistido por computador, é fundamental para mitigar os riscos durante a execução do projeto. 

A funcionalidade do braço robótico integra de maneira satisfatória com o sistema de movimentação, e para todos nós do grupo, essa experiência foi enriquecedora em todos os aspectos, desde a programação até o processo de compras, montagem e discussões do grupo, promovendo o amadurecimento de nosso relacionamento interpessoal e nossa comunicação profissional. 

----