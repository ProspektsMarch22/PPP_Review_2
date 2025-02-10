#include <stdio.h>

void par(int a);

int main(){
    int a;
    printf("Digite um número se faz favoire: \n");
    scanf("%d", &a);
    par(a);
    return 0;
}

void par(int a){
    if(a % 2 == 0){
        printf("%d é par\n", a);
    } else {
        printf("%d é impar\n", a);
    }
    return;
}