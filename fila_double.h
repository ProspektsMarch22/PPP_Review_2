#ifndef FILA_FILA_H
#define FILA_FILA_H

typedef struct naFila{
    double elemento;
    struct naFila * prox;
} naFila;

typedef struct{
    naFila * inicio;
    naFila * fim;
} tipoFila;

#endif

