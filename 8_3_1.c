#include <stdio.h>
#include <string.h>

// Para esse exercício, vou assumir que "ordem crescente" refere-se à quantidade de letras em cada palavra. Por exemplo, "Universidade" seria maior que "Coimbra"

// Também irei assumir que o exemplo dado seja o de um array de strings pré-definidas, e não do output esperado.

void crescente(char * s[], int size);

int main(){
    char *s[] = {"Benvindo", "a", "Universidade", "de", "Coimbra"};
    int size = sizeof(s)/sizeof(*s);
    //Antes da função
    for(int i = 0; i < size; i++){
        printf("%s\n", *(s + i));
    }

    
    crescente(s, size);
    //Depois da função
    for(int i = 0; i < size; i++){
        printf("%s\n", *(s + i));
    }

    return 0;
}

void crescente(char *s[], int size){
    int trocou;
    do{
        trocou = 0;
        for(int i = 0; i < size - 1; i++){
            if(strlen(*(s + i)) > strlen(*(s + i + 1))){
                char * mask = *(s + i);
                *(s + i) = *(s + i + 1);
                *(s + i + 1) = mask;
                trocou = 1;
            }
        }
    } while(trocou);
}
