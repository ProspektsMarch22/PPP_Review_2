#include <stdio.h>

void menoresMultiplos(int num);

int main(){
    int n;
    printf("Informe n: \n");
    scanf("%d", &n);
    menoresMultiplos(n);
    return 0;
}

void menoresMultiplos(int num){
    int multiplo = 0;
    printf("resultado:");
    for(int i = 0; i < 4; i++){
        multiplo = num * i;
        if(multiplo <= 100){
            printf(" %d", multiplo);
        }
    }
    printf("\n");
    return;
}