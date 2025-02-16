#include <stdio.h>

void indicaCor(int bits, char * vetorCores[]){
    int quo = 0;
    for(int i = 0; i < 2; i++){
        quo = bits % 10;
        bits /= 10;
        if(i == 0){
            if(quo == 1){
                vetorCores[2] = "azul";
            } else {
                vetorCores[2] = "-";
            }
        }
        if(i == 1){
            if(quo == 1){
                vetorCores[1] = "verde";
            } else {
                vetorCores[1] = "-";
            }
        }
    }
    if(bits == 1){
        vetorCores[0] = "vermelho";
    }else {
        vetorCores[0] = "-";
    }
    return;
}


int main(){
    int bits = 101;
    char * vetorCores[10];
    indicaCor(bits, vetorCores);
    printf("[%s, %s, %s]\n", vetorCores[0], vetorCores[1], vetorCores[2]);
    return 0;
}