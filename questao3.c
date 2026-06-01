#include <stdio.h>

int main() {
  int altura = 0, resposta = 0;
  printf("Digite a altura do triangulo: ");
  scanf("%d", &altura);

  printf(
      "Deseja que o triangulo seja preenchido?\n[ 1 - sim ]   [ 0- nao ]\n: ");
  scanf("%d", &resposta);

  // Esse primeiro for determina em qual linha está, a linha será representada
  // por i
  for (int i = 0; i < altura; i++) {
    // Esse segundo for determina em qual * está, será representado por c
    for (int c = 0; c <= i; c++) {
      // Este if verifica se resposta == 0, ou nesse caso se ela "não existe"
      if (!resposta) {
        // Este if força que a impressão seja somente nas extremidades da linha,
        // ou na última linha
        if (c == 0 || c == i || i == altura - 1) {
          printf("*");
        } else {
          printf(" ");
        }
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  return 0;
}