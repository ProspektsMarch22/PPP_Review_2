#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tipos da Fila*/

typedef struct naFila{
    char * elemento;
    struct naFila * prox;
}naFila;

typedef struct{
    naFila * inicio;
    naFila * fim;
}tipoFila;

void criaFila(tipoFila * fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(tipoFila * fila){
    if(fila->inicio == NULL) return 1;
    else return 0;
}

void destroiFila(tipoFila * fila){
    naFila * temp;
    while(!filaVazia(fila)){
        temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    fila->fim = NULL;
}

int insereElemento(tipoFila * fila, char * string){
    naFila * temp = (naFila *)malloc(sizeof(naFila));
    if(temp != NULL){
        temp->elemento = strdup(string);
        if(temp->elemento == NULL){
            free(temp);
            printf("Erro na alocação de memória para a string");
            return 0;
        }
        temp->prox = NULL;
        if(filaVazia(fila)){
            fila->inicio = temp;
        } else {
            fila->fim->prox = temp;
        }
        fila->fim = temp;
        return 1;
    } else {
        printf("Erro na alocação de memória para a inserção do elemento \n");
        return 0;
    }
}

char * retiraElemento(tipoFila * fila){
    naFila * temp;
    char * s1;
    if(!filaVazia(fila)){
        temp = fila->inicio;
        s1 = temp->elemento;
        fila->inicio = fila->inicio->prox;
        if(filaVazia(fila)){
            fila->fim = NULL;
        }
        free(temp);
        return s1;
    }
    return "ERROR";
}

//Alternativa não-destrutiva para mostrar os elementos da fila de espera
void mostraElementos(tipoFila * fila){
    naFila * temp;
    temp = fila->inicio;
    while(temp != fila->fim){
        fila->inicio = fila->inicio->prox;
        printf("%s ", temp->elemento);
        temp = fila->inicio;
    }
    printf("%s\n", fila->fim->elemento);
}

int main(){
    tipoFila * filaStr = (tipoFila *)malloc(sizeof(tipoFila));

    //Vou colocar um limite de tamanho para as strings a serem inseridas na fila de 50 caracteres;
    while(1){
        char s1[50];
        if(s1 != NULL){
            fgets(s1, 50, stdin);
            s1[strlen(s1) - 1] = '\0';
            if(abs(strcmp(s1, "FIM"))){
                insereElemento(filaStr, s1);
            }else break;
        } else {
            printf("Erro na alocação de memória\n");
            break;
        }
    }

    mostraElementos(filaStr);
    free(filaStr);
    return 0;
}