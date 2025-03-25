#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include "fila_double.h"

//Tipos da fila

typedef struct naFila{
    double elemento;
    struct naFila * prox;
} naFila;

typedef struct{
    naFila * inicio;
    naFila * fim;
} tipoFila;

//Funções da fila

void criaFila (tipoFila * fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(tipoFila * fila){
    if(fila->inicio == NULL) return 1;
    else return 0;
}

void destroiFila (tipoFila * fila){
    naFila * temp;
    while(!filaVazia(fila)){
        temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    fila->fim = NULL;
}

int insereElemento(tipoFila * fila, double elemento){
    naFila * temp;
    temp = (naFila *)malloc(sizeof(naFila));
    if(temp != NULL){
        temp->elemento = elemento;
        temp->prox = NULL;
        if(filaVazia(fila)){
            fila->inicio = temp;
        } else {
            fila->fim->prox = temp;
        }
        fila->fim = temp;
        return 1;
    } else {
        printf("Erro na alocação de memória para a inserção do elemento\n");
        return 0;
    }
}

double retiraElemento(tipoFila * fila){
    naFila * temp;
    double d1;
    if(!filaVazia(fila)){
        temp = fila->inicio;
        d1 = temp->elemento;
        fila->inicio = fila->inicio->prox;
        if(filaVazia(fila)){
            fila->fim = NULL;
        }
        free(temp);
        return d1;
    }
    return NAN;
}

//Alternativa não-destrutiva para mostrar os elementos da fila de espera
void mostraElementos(tipoFila * fila){
    naFila * temp;
    temp = fila->inicio;
    while(temp != fila->fim){
        fila->inicio = fila->inicio->prox;
        printf("%.2lf ", temp->elemento);
        temp = fila->inicio;
    }
    printf("%.2lf \n", fila->fim->elemento);
}

int main(){
    int n;
    printf("Defina n: \n");
    scanf("%d", &n);
    tipoFila * filaDoubles = (tipoFila *)malloc(sizeof(tipoFila));
    criaFila(filaDoubles);
    for(int i = 0; i < n; i++){
        double elemento;
        printf("Insira o elemento número %d: \n", i + 1);
        scanf("%lf", &elemento);
        if(!insereElemento(filaDoubles, elemento)){
            return -1;
        }
    }
    mostraElementos(filaDoubles);
    free(filaDoubles);
    return 0;
}