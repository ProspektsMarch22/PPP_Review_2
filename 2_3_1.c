#include <stdio.h>

int somaNumeros(int * num, int size){
    int soma = 0;
    for(int i = 0; i < size; i++){
        soma += num[i];
    }
    return soma;
}

//Os números originais têm todos 4 dígitos. Os números novos terão todos 5 dígitos, mas a função lida com arrays de qualquer tamanho (sem números mágicos).
void geraNumeroCartao(int * org, int * novo, int size_org, int size_novo){
    int soma = somaNumeros(org, size_org);
    for(int i = 0; i < size_org; i++){
        int numero = org[i];
        novo[i] = numero;
    }
    if(soma % 2 == 0){
        novo[size_novo - 1] = 0;
    } else {
        novo[size_novo - 1] = 1;
    }
    return;
}

int main(){
    int org[4] = {1, 2, 3, 4};
    int novo[5];

    int size_org = sizeof(org)/sizeof(org[0]);
    int size_novo = sizeof(novo)/sizeof(novo[0]);

    geraNumeroCartao(org, novo, size_org, size_novo);

    printf("O número original é: \n");
    for(int i = 0; i < 4; i++){
        printf("%d ", org[i]);
    }
    printf("\n");

    printf("O número novo é: \n");
    for(int i = 0; i < 5; i++){
        printf("%d ", novo[i]);
    }
    printf("\n");

    
    return 0;
}