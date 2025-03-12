#include <stdio.h>
#include <math.h>

#define N 5

void mstd(double * v, double * mean, double * stdev, int n);

int main(){
    double v[N];
    double  mean;
    double stdev;
    printf("Informe os elementos do conjunto: \n");
    for(int i = 0; i < N; i++){
        printf("Elemento %d\n", i + 1);
        scanf("%lf", (v + i));
    }

    mstd(v, &mean, &stdev, N);

    printf("A média do conjunto é %.1lf\n", mean);
    printf("O desvio padrão do conjunto é %.1lf\n", stdev);

    return 0;
}

void mstd(double * v, double * mean, double * stdev, int n){
    double sum, sumStd = 0;
    for(int i = 0; i < n; i++){
        sum += *(v + i);
    }
    *mean = sum/n;

    for(int i = 0; i < n; i++){
        sumStd += pow((*(v + i) - *mean), 2);
    }
    *stdev = sqrt(sumStd/n);
}