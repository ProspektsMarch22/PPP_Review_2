#include <stdio.h>

int somaLimite(int limite);

int main(){
    int limite, numero;
    printf("Indique o limite da soma: \n");
    scanf("%d", &limite);
    numero = somaLimite(limite);
    printf("O número em que parou foi %d\n", numero);
    return 0;
}

int somaLimite(int limite){
    int soma = 0, c = 1;
    while(soma <= limite){
        soma += c++;
    }
    return (c - 1);
}