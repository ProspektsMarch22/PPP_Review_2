#include <stdio.h>
#include <stdlib.h>

#define MAX 10

long int inteiroSeguido(char * cadeia);

int main(){
    char * cadeia = (char *)malloc(sizeof(char) * (MAX + 1));
    if(cadeia == NULL){
        printf("Falha de alocação de memória para a cadeia\n");
        return -1;
    }
    fgets(cadeia, MAX, stdin);
    int long inteiro = inteiroSeguido(cadeia);
    if(inteiro > -1){
        printf("Inteiro: %ld\n", inteiro);
    }
    free(cadeia);
    return 0;
}

long int inteiroSeguido(char * cadeia){
    long int inteiro = -1;

    int i = 0;
    while(*(cadeia + i) != '\0'){
        long int * algarismo = (long int *)malloc(sizeof(long int));
        if(algarismo == NULL){
            printf("Erro na alocação de memória\n");
            break;
        }
        *algarismo = (long int)(*(cadeia + i) - '0');
        if(*algarismo >= 0 && *algarismo <= 9){
            if(inteiro == -1){
                inteiro = 0;
            }
            inteiro = inteiro * 10 + *algarismo;
        }
        else if(inteiro != -1){
            free(algarismo);
            break;
        }
        free(algarismo);
        i++;
    }

    if(inteiro == -1){
        printf("Não foi introduzido um inteiro.\n");
        return -1;
    }

    return inteiro;
}