#include <stdio.h>
#include <stdlib.h>

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

void gamePlay() { // Lógica do jogo
  int secretNumber = rand() % 101; // Gera um numero aleatorio entre 0 e 100
  int kick;
  printf("Numero secreto: %d\n", secretNumber);

  printf("\n-> Chute um número: ");
  scanf("%d", &kick);

  printf("<- O numero chutado foi: %d\n", kick);
}

int main() {
  gameHeader();
  gameRules();
  gamePlay();
  return 0;
}
