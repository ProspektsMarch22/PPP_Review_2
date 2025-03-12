#include <stdio.h>

double avgVetor(int * vetor, int size);

int main(){
    int marray[] = {1, 2, 3, 4, 5}, size = sizeof(marray)/sizeof(marray[0]);
    double avg = avgVetor(marray, size);
    printf("%.2lf\n", avg);
    return 0;
}

double avgVetor(int * vetor, int size){
    int * end = &vetor[size];
    int * ptr = &vetor[0];
    double sum = 0.0;

    while(ptr < end){
        sum += *ptr;
        ptr++;
    }
    return sum/size;
}