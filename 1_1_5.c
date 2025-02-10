#include <stdio.h>

double converte(double euro){
    double dollar;
    dollar = euro * 0.99;
    return dollar;
}

int main(){
    double dollar, euro;

    printf("Qual é o valor para converter?\n");
    scanf("%lf", &euro);

    dollar = converte(euro);
    printf("O valor que possui em dólares é $%lf \n", dollar);
    return 0;
}