#include <stdio.h>

// Esse código se parece muito com o da segunda questão por isso usei as mesmas ideias, para adiantar as coisas, no geral oque mudou foi:
// - Agora eu conto as casas ocupadas também, pois neste eu fiz os dois lados de uma vez
// - ELe é quase duas vezes maior que o da segunda questão, já que é uma repetição invertida da mesma lógica, entretanto acredito que tenha como usar apenas a primeira parte, só não sei como


int main(){
    int largura = 0, casasOcupadas = 0, casasVazias = 0, casasOcupadasNaLinha;

    printf("Informe a largura central do losangulo: ");
    scanf("%d", &largura);

    // Programa vai sempre adicionando de 2 em 2, se a largura for impar começa com 1 se for par começa com dois
    if(largura % 2 == 0){
        casasOcupadas = 2;
    } 
    else{
        casasOcupadas = 1;
    }
    // Esse método só funciona por que sempre estamos ou tirando par com par ou impar com impar, assim sempre teremos um numero par de casasVazias

    for(casasOcupadas; casasOcupadas <= largura; casasOcupadas += 2){

        casasVazias = largura - casasOcupadas; 

        // Enquanto percorre casas vazias até chegar na metade
        for(casasVazias; casasVazias >= 0; casasVazias--){

            // Verifica se chegou na metade ou se ta na linha do meio
            if((casasVazias == (largura - casasOcupadas) / 2) || (casasVazias == 0  && casasOcupadas == largura)){

                for(int casasOcupadasNaLinha = casasOcupadas; casasOcupadasNaLinha > 0; casasOcupadasNaLinha --){
                    printf("X");
                }
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }


    // Esse código é a inversão da primeira parte, a diferença é que ele conta de trás pra frente casasVazias e desconsidera a linha onde não tem casasVazias

    for(casasOcupadas; casasOcupadas >= 1; casasOcupadas -= 2){
        casasVazias = largura - casasOcupadas;
        if(casasVazias > 0){
            for(casasVazias; casasVazias >= 0; casasVazias--){

                if((casasVazias == (largura - casasOcupadas) / 2)){

                    for(int casasOcupadasNaLinha = casasOcupadas; casasOcupadasNaLinha > 0; casasOcupadasNaLinha --){
                        printf("X");
                    }
                }
                else{
                    printf(" ");
                }
            }

            printf("\n");
        }

    }

    

    return 0;
}