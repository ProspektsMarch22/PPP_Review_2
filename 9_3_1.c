#include <stdio.h>

#define MAX 10

int isbn(int * original, int * s1, int * s2);

int main(){
    int original[MAX] = {0, 8, 9, 2, 3, 7, 0, 1, 0, 6};
    int s1[MAX];
    int s2[MAX];
    int valido;

    valido = isbn(original, s1, s2);

    printf("As somas parciais do ISBN informado são:\n");
    for(int i = 0; i < MAX; i++){
        printf("%d ", *(s1 + i));
    }
    printf("\nAs somas totais do ISBN informado são: \n");
    for(int i = 0; i < MAX; i++){
        printf("%d ", *(s2 + i));
    }
    if(valido){
        printf("\nO ISBN informado é válido.\n");
    } else {
        printf("\nO ISBN informado não é válido \n.");
    }
    return 0;
}

int isbn(int * original, int * s1, int * s2){
    //Cálculo da soma parcial
    int somaP = 0;
    for(int i = 0; i < MAX; i ++){
        somaP += *(original + i);
        *(s1 + i) = somaP;
    }

    //Cálculo da soma total
    int somaT = 0;
    for(int i = 0; i < MAX; i ++){
        somaT += *(s1 + i);
        *(s2 + i) = somaT;
    }

    if(*(s2 + MAX - 1)%11 == 0){
        return 1;
    }
    return 0;
}

