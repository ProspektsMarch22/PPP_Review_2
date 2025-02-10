#include <stdio.h>

double volumeCilindro(double raio, double altura){
        double volume;
        volume = (raio*raio)*altura*3.14;
        return volume;
    }


int main(){
    double raio, altura, volume;    printf("Forneça o raio: \n");
    scanf("%lf", &raio);
    printf("Forneça a altura: \n");
    scanf("%lf", &altura);
    volume = volumeCilindro(raio, altura);
    printf("O volume do cilindro é: %lf\n", volume);
    
    return 0;
}