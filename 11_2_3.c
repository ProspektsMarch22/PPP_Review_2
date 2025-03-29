#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int numero;
    double t1, t2, t3;
}Aluno;

typedef struct naFila{
    Aluno aluno;
    struct naFila * prox;
}naFila;

typedef struct{
    naFila * inicio;
    naFila * fim;
}tipoFila;

double mediaNotas(int t1, int t2, int t3){
    return (t1 + t2 + t3)/3;
}

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

void insereElemento(tipoFila * fila, Aluno aluno){
    naFila * temp = (naFila *)malloc(sizeof(naFila));
    if(temp != NULL){
        temp->aluno = aluno;
        temp->prox = NULL;
        if(filaVazia(fila)){
            fila->inicio = temp;
        } else {
            fila->fim->prox = temp;
        }
        fila->fim = temp;
    }   
}

//Aqui não teremos tipo de retorno, justamente porque eu não consigo criar um caso em que consiga retorna uma exceção/erro. Portanto, estaremos realizando alterações em uma variável passada por referência, e somente no caso em que há fila cheia.
void retiraElemento(tipoFila * fila, Aluno * alunoRef){
    if(!filaVazia(fila)){
        naFila * temp = fila->inicio;
        *alunoRef = temp->aluno;
        fila->inicio = fila->inicio->prox;
        if(filaVazia(fila)){
            fila->fim = NULL;
        }
        free(temp);
    }

}


int main(){
    /*Aqui não teremos I/O por motivos de preguiça, e estaremos trabalhando com números mágicos sim.*/
    Aluno a1, a2, a3;
    strcpy(a1.nome, "Fotocopia");
    strcpy(a2.nome, "Jupiro");
    strcpy(a3.nome, "Buteto");

    //Notas
    a1.t1 = 9; a1.t2 = 12; a1.t3 = 15;
    a2.t1 = 13; a2.t2 = 18; a2.t3 = 4.5;
    a3.t1 = 10; a3.t2 = 10; a3.t3 = 9.5;

    tipoFila * fila = (tipoFila *)malloc(sizeof(tipoFila));
    if(fila != NULL){
        criaFila(fila);

        insereElemento(fila, a1);
        insereElemento(fila, a2);
        insereElemento(fila, a3);

        double maior = 0;
        char * nome = (char *)malloc(sizeof(char) * 50);
        if(nome != NULL){
            for(int i = 0; i < 3; i++){
            Aluno * aluno = (Aluno *)malloc(sizeof(Aluno));
            if(aluno != NULL){
                retiraElemento(fila, aluno);
                double compMean = mediaNotas(aluno->t1, aluno->t2, aluno->t3);
                if(compMean > maior){
                        maior = compMean;
                        strcpy(nome, aluno->nome);
                    }
                free(aluno);
                }
            }
        }
        nome = realloc(nome, sizeof(char) * strlen(nome));
        if(nome != NULL){
            printf("O aluno com melhor média foi: %s\n", nome);
            free(nome);
        }
        destroiFila(fila);
        if(filaVazia(fila)){
            free(fila);
        }
    }
    return 0;
}