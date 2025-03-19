#include <stdio.h>

int len(char * s);

int main(){
    char * nome = "Paola";
    printf("Meu nome tem %d caracteres\n", len(nome));
    return 0;
}

int len(char * s){
    char ch = *s;
    int i = 0;
    while(ch != '\0'){
        ch = *(s + i);
        i++;
    }
    return i - 1;
}