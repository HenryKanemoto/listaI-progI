#include <stdio.h>

// EXPLICANDO IDEIA
  // Para fazer o programa a ideia principal foi dividir a forma em 2 partes:
    // QUADRADOS
      // o quadrado pode ser dividido em (n / 2) quadrados internos para n par ou ((n+1) / 2) quadrados internos para n impares
      // o lado de cada quadrado é (n - k) * 4 - 4, onde k é igual a 2 * camada do quadrado
      // ou seja a cada camada o lado do quadrado diminui em 2
    // TRIÂNGULOS
      // Dividiremos cada quadrado em dois lados, o triângulo superior e inferior,
      // contando somente os lados, ou seja (cima direita) e (baixo esquerda)
      // o superior deve começar em x = 1 e termniar em  (n * k -1), depois recomeçar a partir do primeiro y anterior
      // o inferior deve começar em y = (n-k) *4 - 4 e terminar em (n-k) * 2 - 2
int main() {

  int n = 0, c1 = 1, c2 = 0, fator = 0, marcadorFator = 0, fatorCamada = 0,
      numCamada = 0, linhaDeChegada = 0;

  // EXPLICANDO AS VARIÁVEIS
    // NUMERAIS
      // n é o numero do lado do quadrado da espiral, deve ser >= 3
      // c1 será os números dos lados de cima e direita do quadrado
      // c2 será os números dos lados de baixo e esquerda do quadrado
    // FATORES
      // fator, a cada camada do quadrado o fator é definido por (n - fatorCamada) *
      // 4 - 4, isto é, um lado do quadrado * 4 - 4 vertices(que se repetem)
      // fatorCamada, a cada camada o lado do quadrado mais interno diminui em 2, o
      // fatorCamada contabiliza isso marcadorFator, é a soma de todos fator, sempre
      // no final do programa marcadorFator deve ser igual a n² numCamada dita qual
      // é a camada interna do quadrado, de dentro pra fora, é usada para posicionar
      // os input de numeros corretamente
    // SEMÂNTICOS
      // linhaDeChegada indica n², seria até onde o marcadorFator deve ir 

  // Loop para garantir que n >= 3
  while (1) {
    printf("Informe o tamanho da espiral [ maior ou igual a 3 ]: ");
    scanf("%d", &n);

    if (n >= 3) {
      break;
    } else {
      printf("\n***Valor inválido***\n");
    }
  }

  int matriz[n][n];
  linhaDeChegada = n * n;

  // Esse for conta até onde o marcadorFator deve ir, o marcadorFator é definido em marcadorFator(antigo) + (n-k) * 4 - 4, onde k  é definido por 2 * numCamada(começa em zero e aumenta em cada camada)  
  while(marcadorFator < linhaDeChegada) { 
    // Este if só é usado em n impar, ele impede que o while estoure a memória, pois marcadorFator estaria sempre somando 0
    if ((n - fatorCamada) == 1) {
    matriz[numCamada][numCamada] = linhaDeChegada; 
    break;
  }

  fator = (n - fatorCamada) * 4 - 4; // Essa é a conta principal, (n - k) * 4 - 4, ela conta quantas casas o quadrado atual vai ter
  
  c1 = marcadorFator + 1; // ponto de partida do quadrado atual
  c2 = marcadorFator + fator; // ponto de saída do quadrado atual
  
  // Esse for conta as linhas de cada quadrado, por isso é variavel de acordo com fatorCamada
  for (int i = 0; i < (n - fatorCamada); i++) {   
    
    // Esse for conta as colunas de cada quadrado, por isso é variável de acordo com fatorCamada
    for (int j = 0; j < (n - fatorCamada); j++) {
      
      // Esse if só se ativa caso seja a primeira linha ou a ultima coluna (triãngulo superior)
      if (i == 0 || j == (n - fatorCamada) - 1) {
        matriz[i + numCamada][j + numCamada] = c1; //Observe que nesse input de matriz devemos usar i + numCamada, para que seja a posição do quadrado atual, não do maior quadrado que estamos percorrendo
        c1 += 1;
      } else { // Else garante que não haja repetições nos vértices
        
        // Esse if só se ativa caso seja a primeira coluna ou a ultima linha (triãngulo inferior)
        if (j == 0 || i == (n - fatorCamada) - 1) {
          matriz[i + numCamada][j + numCamada] = c2;
          c2 -= 1;
        }
      }
    }
  }
  
    marcadorFator += fator; // Isso acumula o marcadorFator, conta quantas casas todos os quadrados ocupam até agora
    numCamada += 1;
    fatorCamada += 2; // fatorCamada diminui em 2 pois cada quadrado perde 2 de tamanho de lado
  }

  // Esse for só printa a matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("[%4d] ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}