#include <stdio.h>

int main(){
    char nome[10];
    int idade, peso;
    printf("Qual é seu nome?\n");
    scanf("%s", nome);
    printf("E qual é sua idade\n");
    scanf("%d", &idade);
    printf("E qual é seu peso\n");
    scanf("%d", &peso);

    printf("Olá, meu nome é %s, tenho %d anos e peso %d kg\n", nome, idade, peso);
    
    return 0;
}