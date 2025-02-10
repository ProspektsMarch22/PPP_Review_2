#include <stdio.h>

void max(int * narr, int size);
void le_numeros(int * narr, int size);

int main(){
    int size;
    int narr[] = {17, 53, 4};
    size = sizeof(narr)/sizeof(narr[0]);
    le_numeros(narr, size);
    max(narr, size);
    return 0;
}

void max(int * narr, int size){
    int max;
    for(int i = 0; i < size; i++){
        if(i == 0 || narr[i] > max){
            max = narr[i];
        }
    }
    printf("O máximo é %d\n", max);
    return;
}

void le_numeros(int * narr, int size){
    int i = 0, leitura;
    while(i < size){
        printf("Informe o número %d : \n", i + 1);
        scanf("%d", &leitura);
        narr[i] = leitura;
        i++;
    }
    return;
}