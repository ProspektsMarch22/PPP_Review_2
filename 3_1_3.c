#include <stdio.h>

int minConjunto(int * conj, int size);

int main(){
    int size, min;
    printf("Número de números: \n");
    scanf("%d", &size);
    int conj[size];
    for(int i = 0; i < size; i++){
        printf("Número: \n");
        scanf("%d", &conj[i]);
    }
    min = minConjunto(conj, size);
    printf("Valor mínimo = %d\n", min);
    return 0;
}

int minConjunto(int * conj, int size){
    int min = conj[0];
    for(int i = 1; i < size; i++){
        if(conj[i] < min){
            min = conj[i];
        }
    }
    return min;
}