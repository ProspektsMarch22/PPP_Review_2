#include <stdio.h>

#define N 10

double * maxReais(double * v, int n);
double * minReais(double * v, int n);

int main(){
    double v[N];
    printf("Introduza os números reais: \n");
    for(int i = 0; i < N; i++){
        printf("Número %d \n", i + 1);
        scanf("%lf", (v + i));
    }
    printf("O maior número dentro do vetor é %.2lf\n", *(maxReais(v, N)));
    printf("O menor número dentro do vetor é %.2lf\n", *(minReais(v, N)));
    return 0;
}

double * maxReais(double * v, int n){
    double * max;
    max = v;
    for(int i = 1; i < n; i++){
        if(*(v + i) > *max){
            max = v + i;
        }
    }
    return max;
}

double * minReais(double * v, int n){
    double * min;
    min = v;
    for(int i = 1; i < n; i++){
        if(*(v + i) < *min){
            min = v + i;
        }
    }
    return min;
}