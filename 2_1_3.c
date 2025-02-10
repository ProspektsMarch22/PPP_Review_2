#include <stdio.h>

void le_inteiros(int * arr, int size);

int main(){
    int size = 2;
    int arr[size];
    le_inteiros(arr, size);
    return 0;
}

void le_inteiros(int * arr, int size){
    for(int i = 0; i < size; i++){
        int leitura;
        printf("Informe o primeiro número: \n");
        scanf("%d", &leitura);
        arr[i] = leitura;
    }

    if(arr[0] % 2 == 0 && arr[1] % 2 == 0){
        int soma = arr[0] + arr[1];
        printf("Sendo os dois pares, a soma é %d\n", soma);
    } else if(arr[0] % 2 != 0 && arr[1] % 2 != 0){
        int produto = arr[0] * arr[1];
        printf("Sendo os dois ímpares, o produto é %d\n", produto);
    } else {
        if(arr[0] % 2 != 0){
            printf("Só o primeiro número é ímpar\n");
        } else {
            printf("Só o segundo número é ímpar\n");
        }
    }
}