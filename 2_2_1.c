#include <stdio.h>

void tipoBilhete(int idade);

int main(){
    int idades[] = {13, 7, 65, 32, 27, 25, 16, 18};
    int c = 0, size = sizeof(idades)/sizeof(idades[0]);
    while(c < size){
        printf("A idade do cliente é %d\n", idades[c]);
        tipoBilhete(idades[c++]);
    }
    return 0;
}

void tipoBilhete(int idade){
    if((idade < 12) || (idade > 60)){
        printf("Isento de pagamento\n");
    } else if (idade > 12 && idade < 25){
        printf("Bilhete radical\n");
    } else if ((idade > 24 && idade < 37) || (idade > 48 && idade < 61)){
        printf("Bilhete light\n");
    } else if (idade > 36 && idade < 49){
        printf("Bilhete normal\n");
    }

    return;
}