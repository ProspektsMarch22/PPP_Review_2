#include <stdio.h>
#include <string.h>

//Para essa questão, vou assumir que a string tenha separadores bem delimitados. Nesse caso, vou escolher o "-" como separador

#define MAX 51

char * maiorPalavra(char * mwords);

int main(){
    char mwords[51];
    printf("Introduza a frase, com as palavras separadas por '-': \n");
    fgets(mwords, MAX, stdin);
    mwords[strcspn(mwords, "\n")] = 0;
    
    printf("A maior palavra encontrada foi: %s\n", maiorPalavra(mwords));
    return 0;
}

char * maiorPalavra(char * mwords){
    char * tok = strtok(mwords, "-");
    if(tok == NULL){
        return " ";
    }
    char * maior = tok;
    while((tok = strtok(NULL, "-")) != NULL){
        if(strlen(tok) > strlen(maior)){
            maior = tok;
        }
    }
    return maior;

}