#include <stdio.h>

double convertRadians(double angle){
    double coef = 3.14/180;
    double radians = angle * coef;
    return radians;
}

int main(){
    double angle, radians;

    printf("Informe o ângulo, em graus, que será convertido: \n");
    scanf("%lf", &angle);
    radians = convertRadians(angle);
    printf("O ângulo em radianos é %lf\n", radians);

    return 0;
}