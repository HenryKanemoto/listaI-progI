#include <stdio.h>

int main() {
    int resposta, lado; 

    printf("Digite o lado do quadrado: ");
    scanf("%d", &lado);

    printf("Deseja que o quadrado seja preenchido?[1 para sim | 0 para nao] ");
    scanf("%d", &resposta);


    // Cada linha, assim como cada coluna, será feito através de um for com limite igual ao tamanho do lado escolhido
    for(int linha = 0; linha < lado; linha++){
        for(int coluna = 0; coluna < lado; coluna++){

           // Esse if imprime * por toda a linha desde que seja a primeria ou a ultima linha, ou caso o quadrado deva ser totalmente preenchido 
           if(linha == 0 || linha == (lado - 1) || resposta == 1){
               printf("*");
           } 
           // Devido a condição anterior esse else só ocorrerá quando resposta == 0
           else{
                // esse código só permite a impressão quando for a primeira ou última coluna, caso contrário será um espaço vazio
                if(coluna == 0 || coluna == (lado - 1)){
                    printf("*");
                }
                else{
                    printf(" ");
                }

            }
        }

        printf("\n");
    }
    return 0;
}