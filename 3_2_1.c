#include <stdio.h>

int mmc(int n, int m);

int main(){
    int n = 2, m = 3;
    printf("%d\n", mmc(n, m));
    return 0;
}

int mmc(int n, int m){
    int maior, menor;

    if(n > m){
        maior = n;
        menor = m;
    } else {
        maior = m;
        menor = n;
    }

    if(maior % menor == 0){
        return maior;
    }

    return (n * m);

}