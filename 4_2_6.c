#include <stdio.h>

int inverte(int i){
    int soma = 0;
    int condicao = 1;
    while(condicao){
        int divisao = i / 10;
        if(divisao != 0){
            soma = (soma * 10) + (i % 10);
            i = divisao;
        } else {
            soma = (soma * 10) + i;
            condicao = 0;
        };
    }
    return soma;
}


int main(){
    int i = 1221;
    int resultado;
    resultado = inverte(i);
    printf("%d\n", resultado);
    if(i == resultado){
        printf("E ainda por cima é capicua\n");
    } else {
        printf("E não é capicua\n");
    }
    return 0;
}