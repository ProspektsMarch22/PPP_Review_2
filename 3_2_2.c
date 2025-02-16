#include <stdio.h>

int mdc(int n, int m);

int main(){
    int n = 10, m = 20;
    printf("%d\n", mdc(n, m));
    return 0;
}

int mdc(int n, int m){
    int maior, menor, resto;
    if(n > m){
        maior = n;
        menor = m;
    } else{
        maior = m;
        menor = n;
    }

    do {
        resto = maior % menor;
        maior = menor;
        menor = resto;
    } while(resto > 0);

    return maior;
}