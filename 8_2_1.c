#include <stdio.h>
#include <math.h>

#define N 10
#define n 2

double lineLength(double * matriz){
    double length = 0.0;
    for(int i = 0; i < N - 1; i++){
        double x1 = *(matriz + 2 * i);
        double y1 = *(matriz + 2 * i + 1);
        double x2 = *(matriz + 2 * (i + 1));
        double y2 = *(matriz + 2 * (i + 1) + 1);

        length += sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }

    return length;
}

int main(){
    double matriz[N][n];
    double comprimento;
    printf("Digite as coordenadas dos 10 pontos no formato x, y: \n");
    for(int i = 0; i < 10; i++){
        printf("ponto %d: \n", i + 1);
        scanf("%lf, %lf", *(matriz + i), (*(matriz + i) + 1));
    }

    comprimento = lineLength((double *)matriz);
    printf("O comprimento da linha formado pelos pontos dados é de: %.4lf\n", comprimento);
    return 0;
}