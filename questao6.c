#include <stdio.h>

// Como já expliquei todo o esquema pra posicionar os asteriscos em formato, nesse código eu decidi ir direto numa versão mais simples de tudo

int main(){
    int b = 0, a = 0, l = 0, tamanhoBaixo = 0;

    // Os while(1) vão rodar para sempre, a não ser que a variavel inserida seja válida
    while (1){
        
        printf("---> Informe o valor da base da arvore:\n\n[ O valor deve ser impar maior que 3 ] ");
        scanf("%d", &b);
        printf("\n\n");

        if((b > 3) && (b % 2 != 0)){
            break;
        } 
        else{
            printf("\n\n***Valor inválido, tente novamente***\n\n");
        }

    }
    
    while(1){

        printf("---> Informe o valor da largura do tronco:\n\n[ o valor deve ser impar maior ou igual a 1 e menor do que %d] ", ((b+1) / 2));
        scanf("%d", &l);
        printf("\n\n");

        if(l < ((b+1) / 2) && (l % 2 != 0)){
            break;
        } 
        else{
            printf("\n\n***Valor inválido, tente novamente***\n\n");
        }
    }

    while(1){

        printf("---> Informe o valor da altura do tronco:\n\n[ o valor deve ser maior ou igual a 2 e menor do que %d] ", ((b+1) / 2));
        scanf("%d", &a);
        printf("\n\n");

        if((a < ((b+1) / 2)) && (a >= 2)) {
            break;
        } 
        else{
            printf("\n\n***Valor inválido, tente novamente***\n\n");
        }
    }

    // Essa é uma versão simplificada dos códigos das questões 2 e 4, é mais legivel mas mais dificil de entender se você não souber a lógica
    for(int i = 1; i <= b; i += 2){ // qtd de asteriscos por linha
        for(int j = (b - i) / 2; j > 0; j--){ // qtd de casas vazias
            printf(" ");
        }
        for(int k = i; k > 0; k--){ // asteriscos sendo colocados
            printf("*");
        }
        printf("\n");
    }
    
    tamanhoBaixo = (b-l) / 2; // Calcula quantos espaços tem até começar os * do tronco
    
    for(int i = 0; i < a; i++){ // altura
            for(int j = tamanhoBaixo; j > 0; j--){ // qtd de casas vazias
                printf(" ");
            }
            for(int k = l; k > 0; k--){ // asteriscos sendo colocados
                printf("*");
            }
            printf("\n");
    }

    return 0;
}