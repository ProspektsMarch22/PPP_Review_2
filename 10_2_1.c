#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void leStr(char * s);

int subStr(char * s, char * w, int size_s, int size_w);

int main(){
    char * wally = "Wally";
    int size_wally = (int)strlen(wally);
    char * string = (char *)malloc(sizeof(char) * MAX);
    if(string == NULL){
        printf("Alocação de memória falhou\n");
        return -1;
    }

    leStr(string);
    
    int size_s = strlen(string);

    if(size_s > 0 && *(string + (size_s - 1)) == '\n'){
        *(string + (size_s - 1)) = '\0';
        size_s--;
    }

    string = (char *)realloc(string, sizeof(char) * size_s);
    if(string == NULL){
        printf("Realocação de memória falhou\n");
        free(string);
        return -1;
    }

    int wally_index = subStr(string, wally, size_s, size_wally);
    if(wally_index == -1){
        printf("Palavra não encontrada.\n");
    } else {
        printf("Posicao: %d\n", wally_index);
    }

    free(string);
    return 0;
}

void leStr(char * s){
    fgets(s, MAX, stdin);
}

int subStr(char * s, char * w, int size_s, int size_w){
    int j = 0, c = 0;
    for(int i = 0; i < size_s; i++){
        if(j == size_w){
            break;
        }
        if(*(s + i) == *(w + j)){
            if(j == 0){
                c = i;
            }
            j++;
        } else if (*(s + i) != *(w + j)){
            j = 0;
        }
    }
    if(j == (size_w)){
        return c;
    } else {
        return -1;
    }
}