#include <stdio.h>
#include <stdlib.h>

/*Vou tratar "Data mais recente" como a maior data. 

Não me apetece fazer uma comparação de qual data está mais próxima de um determinado dia em específico e tratar isso por "recente". 

Vou considerar que o usuário SÓ POSSA informar datas a partir do ano 0 E.C até a presente data de hoje - hoje sendo qualquer dia - ou seja, não será necessário uma comparação de distância de datas, e passamos a efetivamente comparar que data é maior. 

Faço isso pela minha sanidade mental e como forma de manter simples a proposta da questão.*/

typedef struct {
    int dia, mes, ano;
}Data;

typedef struct naFila{
    Data elemento;
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

int insereElemento(tipoFila * fila, Data elemento){
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
        return 1;
    } else {
        printf("Erro na alocação de memória para a inserção do elemento\n");
        return 0;
    }
    return 1;
}

Data retiraElemento(tipoFila * fila){
    naFila * temp;
    Data d1;
    if(!filaVazia(fila)){
        temp = fila->inicio;
        d1 = temp->elemento;
        fila->inicio = fila->inicio->prox;
        if(filaVazia(fila)){
            fila->fim = NULL;
        }
        free(temp);
    }
    return d1;
}

int main(){
    tipoFila * filaDatas = (tipoFila *)malloc(sizeof(tipoFila));
    
    //Datas para teste, não me apetece criar I/O pra ficar recebendo datas:
    Data d1, d2, d3;
    d1.dia = 22; d1.mes = 03; d1.ano = 1998;
    d2.dia = 15; d2.mes = 10; d2.ano = 2002;
    d3.dia = 30; d3.mes = 11; d3.ano = 2000;

    criaFila(filaDatas);
    insereElemento(filaDatas, d1);
    insereElemento(filaDatas, d2);
    insereElemento(filaDatas, d3);

    Data comp;
    comp.ano = -1;
    for(int i = 0; i < 3; i++){
        Data d = retiraElemento(filaDatas);
        if(d.ano > comp.ano){
            comp = d;
        } else if(d.ano == comp.ano){
            if(d.mes > comp.mes){
                comp = d;

            } else if(d.mes == comp.mes){
                if(d.dia > comp.dia){
                    comp = d;
                }
            }
        }
    }
    printf("A data mais recente é %d/%d/%d\n", comp.dia, comp.mes, comp.ano);

    destroiFila(filaDatas);
    if(filaVazia(filaDatas)){
        free(filaDatas);
    }
    return 0;
}