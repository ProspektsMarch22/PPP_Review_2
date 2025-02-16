#include <stdio.h>

int somaSerie(int limite);

int main(){
    int soma, limite;
    scanf("%d", &limite);
    printf("%d\n", limite);
    soma = somaSerie(limite);
    printf("O resultado é: %d\n", soma);
    return 0;
}

//Esse é o algoritmo de Gauss!
int somaSerie(int limite){
    int soma = 0;
    for(int i = 1; i <= limite; i++){
        soma += i;
    }
    return soma;
}