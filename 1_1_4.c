#include <stdio.h>
#include <math.h>

double calcHipotenusa(double cateto1, double cateto2){
    double hipotenusa;
    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
    return hipotenusa;
}

int main(){
    double cateto1, cateto2, hipotenusa;

    printf("Informe o comprimento do primeiro cateto: \n");
    scanf("%lf", &cateto1);
    printf("Informe o comprimento do segundo cateto: \n");
    scanf("%lf", &cateto2);
    
    hipotenusa = calcHipotenusa(cateto1, cateto2);

    printf("O valor da hipotenusa é de: %lf\n", hipotenusa);

    return 0;
}