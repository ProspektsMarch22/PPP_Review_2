/*Eu não fui à aula de Pilha e essa é a minha tentativa de criar um arquétipo de uma, junto com algumas funções básicas.

A ideia é ilustrar o conceito por trás da Estrutura de Dados. 

A pilha ilustrativa será uma pilha de inteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct naPilha{
    int elemento;
    struct naPilha * prox;
}naPilha;

typedef struct{
    naPilha * topo;
}tipoPilha;

void criaPilha(tipoPilha * pilha){
    pilha->topo = NULL;
}

int pilhaVazia(tipoPilha * pilha){
    return (pilha->topo == NULL);
}

void destroiPilha(tipoPilha * pilha){
    naPilha * temp;
    while(!pilhaVazia(pilha)){
        temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(temp);
    }
}

void push(tipoPilha * pilha, int num){
    naPilha * temp = (naPilha *)malloc(sizeof(naPilha));
    if(temp != NULL){
        temp->elemento = num;
        if(pilhaVazia(pilha)){
            temp->prox = NULL;
        } else {
            temp->prox = pilha->topo;
        }
        pilha->topo = temp;
    }
}

int pop(tipoPilha * pilha){
    if(!pilhaVazia(pilha)){
        naPilha * temp = pilha->topo;
        int num = temp->elemento;
        pilha->topo = pilha->topo->prox;
        free(temp);
        return num;
    }
    return (int)NAN;
}

int seek(tipoPilha * pilha){
    if(!pilhaVazia(pilha)){
        int num = pilha->topo->elemento;
        return num;
    }else{
        printf("Pilha vazia!\n");
        return (int)NAN;
    }
}

int main(){
    tipoPilha * pilha = (tipoPilha *)malloc(sizeof(tipoPilha));
    push(pilha, 1);
    push(pilha, 2);
    int sacou = pop(pilha);
    printf("Saquei %d da pilha\n", sacou);
    printf("E agora vi, mas não saquei: %d\n", seek(pilha));
    return 0;
}