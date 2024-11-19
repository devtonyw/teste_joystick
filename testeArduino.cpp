// Definindo os pinos dos LEDs
const int ledFrente = 3;
const int ledDireita = 4;
const int ledEsquerda = 5;
const int ledTras = 6;
const int buzinaPin = 7;
const int botaoPin = 1;

// Definindo os pinos do joystick
const int eixoX = A0;  // Pino analógico para o eixo X
const int eixoY = A1;  // Pino analógico para o eixo Y

void setup() {
  // Inicializando os pinos dos LEDs como saída
  pinMode(ledFrente, OUTPUT);
  pinMode(ledDireita, OUTPUT);
  pinMode(ledEsquerda, OUTPUT);
  pinMode(ledTras, OUTPUT);
  pinMode(buzinaPin, OUTPUT);
  pinMode(botaoPin, OUTPUT);
  
  // Inicializando a comunicação serial (opcional, para depuração)
  Serial.begin(9600);
}

void loop() {
  // Lendo os valores do joystick
  int leituraX = analogRead(eixoX);  // Lê o valor do eixo X
  int leituraY = analogRead(eixoY);  // Lê o valor do eixo Y

  // Para ver os valores lidos
  Serial.print("X: ");
  Serial.print(leituraX);
  Serial.print(" | Y: ");
  Serial.println(leituraY);

  // Limpar todos os LEDs antes de ligar um novo
  digitalWrite(ledFrente, LOW);
  digitalWrite(ledDireita, LOW);
  digitalWrite(ledEsquerda, LOW);
  digitalWrite(ledTras, LOW);

  // Controle para frente/tras com eixo Y
  if (leituraY > 600) {
    // Mover para frente (eixo Y mais alto)
    digitalWrite(ledFrente, HIGH);
  } else if (leituraY < 400) {
    // Mover para trás (eixo Y mais baixo)
    digitalWrite(ledTras, HIGH);
  }

  // Controle para esquerda/direita com eixo X
  if (leituraX > 600) {
    // Mover para direita (eixo X mais alto)
    digitalWrite(ledDireita, HIGH);
  } else if (leituraX < 400) {
    // Mover para esquerda (eixo X mais baixo)
    digitalWrite(ledEsquerda, HIGH);
  }

  delay(100);  // Pequeno atraso para não sobrecarregar o Arduino


  int estadoBotao = digitalRead(botaoPin);


  // Se o botão for pressionado, ligar a buzina
  if (estadoBotao == LOW) {  // Botão pressionado (pino 7 em LOW)
    digitalWrite(buzinaPin, HIGH);  // Liga o buzzer
  } else {
    digitalWrite(buzinaPin, LOW);   // Desliga o buzzer
  }

  delay(100);  // Pequeno atraso para não sobrecarregar o Arduino
}