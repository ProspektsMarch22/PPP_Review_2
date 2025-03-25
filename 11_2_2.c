#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct naFila{
    double elemento;
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
    return (fila->inicio == NULL);
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

void insereElemento(tipoFila * fila, double elemento){
    naFila * temp = (naFila *)malloc(sizeof(naFila));
    if(temp != NULL){
        temp->elemento = elemento;
        temp->prox = NULL;
        if(filaVazia(fila)){
            fila->inicio = temp;
        } else {
            fila->fim->prox = temp;
        }
        fila->fim = temp;
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

void enviaVetor(tipoFila * fila, double * vetor, int tamanhoVetor){
    for(int i = 0; i < tamanhoVetor; i++){
        *(vetor + i) = retiraElemento(fila);
    }
}

int main(){
    tipoFila * filaDouble = (tipoFila *)malloc(sizeof(tipoFila));

    criaFila(filaDouble);

    /*Neste caso eu vou criar um I/O, pra variar*/

    char string[50];
    double number;
    int contador = 0;
    printf("Preencha um número para ser introduzido na fila e aperte enter. Ou, caso queira sair, digite qualquer outra coisa: \n");
    while(1){
        fgets(string, sizeof(string), stdin);
        char * endptr;
        number = strtod(string, &endptr);
        if(endptr == string || *endptr != '\n'){
            printf("Saindo...\n");
            break;
        }
        insereElemento(filaDouble, number);
        contador++;
    }
    
    double * vetor = (double *)malloc(sizeof(double) * contador);
    enviaVetor(filaDouble, vetor, contador);

    printf("Aqui estão os elementos do vetor que foi preenchido a partir da fila FIFO: \n");
    printf("{");
    for(int i = 0; i < (contador - 1); i++){
        printf("%.4lf, ", *(vetor + i));
    }
    printf(" %.4lf}\n", *(vetor + (contador - 1)));
    destroiFila(filaDouble);
    if(filaVazia(filaDouble)){
        free(filaDouble);
    }
    free(vetor);
    return 0;
}
