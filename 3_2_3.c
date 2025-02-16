#include <stdio.h>

int somaDig(int n);

int main(){
    int n = 1234;
    printf("%d\n", somaDig(n));
    return 0;
}

int somaDig(int n){
    int soma = 0, divisao = 1;
    while(divisao > 0){
        divisao = n / 10;
        soma += n % 10;
        n = divisao;
    }
    return soma;
}