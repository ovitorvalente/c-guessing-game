#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gameHeader() { // Imprime o cabeçalho do jogo
  printf("*********************************************\n");
  printf("* ==> Bem vindo ao jogo de adivinhacao  <== *\n");
  printf("*********************************************\n");
}

void gameRules() { // Imprime as regras do jogo
  printf("\nRegras do jogo:\n");
  printf("=> 1. O jogador deve adivinhar um numero entre 1 e 100.\n");
  printf("=> 2. O jogador tem 10 tentativas para adivinhar o numero.\n");
  printf("=> 3. O jogo ira informar se o numero e maior ou menor que a resposta correta.\n");
  printf("=> 4. O jogador vence se adivinhar o numero dentro do numero de tentativas.\n");
}

int generateRandomNumber() { // Gera um numero aleatorio entre 0 e 100
  return rand() % 101;
}

void gamePlay() { // Lógica do jogo
  int secretNumber = generateRandomNumber();
  const int MAX_ATTEMPTS = 10;
  int attempts = 0;
  int kick;
  printf("Numero secreto: %d\n", secretNumber);


  for (int i = 0; i < MAX_ATTEMPTS; i++) {
    printf("\n<- Chute um número: ");
    scanf("%d", &kick);

    attempts++;
    
    if (kick == secretNumber) {
      printf("\n***************************************************************************\n");
      printf("* -> Parabéns! Você acertou o número secreto após %d tentativas!           *\n", attempts);
      printf("***************************************************************************\n");
      return;
    }

    if (kick > secretNumber) {
      printf("-> O número chutado (%d) é maior que o número secreto. Você tem %d tentativas restantes.\n", kick, MAX_ATTEMPTS - attempts);
    }
    
    if (kick < secretNumber) {
      printf("-> O número chutado (%d) é menor que o número secreto. Você tem %d tentativas restantes.\n", kick, MAX_ATTEMPTS - attempts);
    }

    sleep(3);
    system("clear"); // Limpa a tela para cada tentativa
  }

  printf("\n****************************************************************************************\n");
  printf("*                                                                                      *\n");
  printf("* -> Infelizmente, você não conseguiu adivinhar o número secreto em %d tentativas.     *\n", MAX_ATTEMPTS);
  printf("*    ->  Suas chances acabaram. O número secreto era: %d                               *\n", secretNumber);
  printf("*    ->  Fim de jogo! Obrigado por jogar.                                              *\n");
  printf("*                                                                                      *\n");
  printf("****************************************************************************************\n");
}

int main() {
  gameHeader();
  gameRules();
  gamePlay();
  return 0;
}
