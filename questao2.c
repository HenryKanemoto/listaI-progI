#include <stdio.h>

int main(){
    int n = 0,casasVazias = 0;

    printf("Digite o numero N para a piramide: (maior que dois para magica) ");
    scanf("%d", &n);
    
    // Usaremos o mesmo principio da primeria questão, um for para linha e outro para coluna
    for(int linha = 0; linha < n; linha++){
        // CasasVazias representa os espaços da pirâmide, ou seja, na prática ainda é um quadrilatero só que com números invisíveis
        // a cada linha, casasVazias receberá a quantidade N menos o número da linha, isso faz com que o núemro de espaços dos números visíveis sejam reservados
        // o valor é dobrado pois  estamos contando os espaços da esquerda e da direita
        casasVazias =  (n - (linha + 1)) * 2;

        // casasVaziasContador é usada pois precisaremos ainda do valor de casasVazias original
        // este for serve para posicionar os espaços em branco, a não ser que o if seja ativado
        for(int casasVaziasContador = casasVazias; casasVaziasContador >= 0; casasVaziasContador--){
            // este if verifica se o valor de espaços vazios chegou na metade, neste caso começaremos a imprimir os números
            if(casasVazias/2 == casasVaziasContador){
                int coluna = 0;
                // imprimimos os números em ordem crescente até o número da linha
                for(coluna; coluna < linha + 1; coluna++){
                    printf("%d ", coluna + 1);
                }
                // depois imprimimos os números em ordem decrescente até 1
                for(coluna; coluna > 0; coluna--){
                    // o print precisa remover -1 da coluno, isso faria com que zeros fossem impressos, este if evita isso
                    if(coluna - 1 != 0){
                        printf("%d ", coluna - 1);
                    }
                }
            } 
            else{
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}