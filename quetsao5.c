#include <stdio.h>

// Nesse código eu inventei de querer primeiro fazer a forma depois a conta,
// isso foi descenessário por que depois eu descobri que o triangulo de pascal
// não precisava ter aquela forma, enfim no final ela nem ficou alinhada Por
// causa disso o código esta mais confuso do que deveria ser, no geral as ideias
// usadas foram as mesmas da 2 e 4 para fazer o triangulo, com a diferença que
// usei (n-k)/(k+1) pro triangulo ficar certo

int main() {
  int altura = 0, tamanhoLinha = 0, casasVazias = 0, casasOcupadas = 0,
      alternador = 0, numeroAtual = 0, proximoNumero = 0, coluna = 0;

  printf("Digite a altura do triângulo de Pascal: ");
  scanf("%d", &altura);

  tamanhoLinha = (altura * 2) - 1; // Sempre vai sair um número impar daqui,
                                   // assim o triangulo vai ter um meio

  // Essa parte apenas ajusta a pirâmide
  for (int i = 0; i < altura; i++) {
    casasOcupadas =
        (i + 1) + i; // Sempre as casas ocupadas dentro do triangulo, isso
                     // inclui os espaços vazios, vai ser essa fórmula
    casasVazias =
        (tamanhoLinha - casasOcupadas) /
        2; // casasVazias se refere apenas as casas vazias fora do triangulo

    // Diferente das outras, aqui eu decidi que ia já dividir casasVazias por 2
    // antes do for, de qualquer jeito, os dois modos de fazer sempre param
    // quando casasVazias estiver na metade

    for (int j = 0; j < tamanhoLinha; j++) {
      for (casasVazias; casasVazias > 0; casasVazias--) {
        printf(" ");
      }
    }

    // Aqui é onde começa o triangulo mesmo
    for (int ocupadasRestantes = casasOcupadas; ocupadasRestantes > 0;
         ocupadasRestantes--) {

      if (ocupadasRestantes == casasOcupadas) {
        // O primeiro numero da linha sempre reseta o numero pra 1, depois
        // aplicamos o nAtual * (n-k)/*(k+1)
        numeroAtual = 1;
        proximoNumero = numeroAtual * (i - coluna) / (coluna + 1);
        printf("%d", numeroAtual);
        alternador =
            1; // o alternador serve pra alternar entre numeros e espaços vazios
      } else {
        if (alternador == 1) {
          printf(" ");
          coluna -=
              1; // como esse é um espaço vazio, não contamos a coluna aqui
          alternador = 0;
        } else {
          // Aqui aplica toda a logica:
          // nAtual = proximoNumero(antigo)
          // proximoNumero(novo) = nAtual  * (linha-coluna)/(coluna+1)
          numeroAtual = proximoNumero;
          printf("%d", proximoNumero, coluna);
          proximoNumero = numeroAtual * (i - coluna) / (coluna + 1);
          alternador = 1;
        }
      }
      coluna++; // Demarcar colunas contando de trás pra frente é complicado,
                // como a forma do triangulo foi feita antes das contas, decidi
                // fazer um contador de coluna dedicado pra simplificar as
                // coisas
    }
    coluna = 0;
    printf("\n");
  }
  return 0;
}

// Todo esse código seria bem mais simples se eu tivesse usado vetores e
// começasse primeiro pela conta, mesmo assim eu vou manter ele assim como
// aprendizado