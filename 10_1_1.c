#include <stdio.h>
#include <stdlib.h>

void armazenaNumeroInt(int * arr, int size);

int maiorNumero(int * arr, int size);

//int maiorValor(int * arr);

int main(){
    int n = 5;
    int * ptr = (int *) malloc(n * sizeof(int));
    if(ptr != NULL){
        armazenaNumeroInt(ptr, n);
        
        int k;
        printf("Defina k: \n");
        scanf("%d", &k);
        
        int maior;
        maior = maiorNumero(ptr + (n - k), k);
        printf("O maior número entre os últimos k elementos é %d\n", maior);

    }
    free(ptr);
    return 0;
}

void armazenaNumeroInt(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("Informe o elemento %d: \n", i + 1);
        scanf("%d", arr + i);
    }
}

int maiorNumero(int * arr, int size){
    int maior = *arr;
    for(int i = 1; i < size; i++){
        if(*(arr + i) > maior){
            maior = *(arr + i);
        }
    }
    return maior;
}