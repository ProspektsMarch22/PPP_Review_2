#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dadosDiferenca(int size){
    int diferenca = 0, face;
    for(int i = 0; i < size; i++){
        face =  rand() % (5) + 1;
        diferenca -= face;
        diferenca = abs(diferenca);
        printf("Saiu %d\n", face);
    }
    return diferenca;
}


int main(){
    srand(time(0));

    int rolada = 2, diferenca;
    
    printf("Vamos rolar uns dados...\n");
    diferenca = dadosDiferenca(rolada);

    if(diferenca > 3){
        printf("A diferença é superior a 3\n");
    } else if(diferenca < 2){
        printf("A diferença é inferior a 2\n");
    } else if(diferenca < 4){
        printf("A diferença é inferior a 4\n");
    }
    
    return 0;
}