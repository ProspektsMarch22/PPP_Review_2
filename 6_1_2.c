#include <stdio.h>

void copy(char * dest, char * org);

int main(){
    char nome[6] = "Isaac";
    char nomeCopia[6];
    copy(nomeCopia, nome);
    printf("Este é meu nome: %s\n", nomeCopia);
    return 0;
}

void copy(char * dest, char * org){
    int i = 0;
    while(*(org + i) != '\0'){
        *(dest + i) = *(org + i);
        i++;
    };
}