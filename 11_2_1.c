#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct naFila{
    int * elemento;

    //Aqui, supus que cada vetor pudesse ter um tamanho N, sendo N uma variável. Assim, todo vetor poderia ter um valor natural arbitrário.
    int size;

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
        free(temp->elemento);
        free(temp);

    }
    fila->fim = NULL;
}

/*A função de inserção exige uma lógica contraintuitiva - e por isso eu vou deixar um comentário longo, resultado de muita pesquisa e dor de cabeça pra resolver essa porra dessa questão.

Quando lidamos com vetores, o que estaremos passando efetivamente pro campo de elemento da struct é um ponteiro. E aí é que mora o perigo: o ponteiro estará apontando sempre para o último endereço de memória informado.

Ou seja, se eu apenas informar o ponteiro (tipo int *), todas as inserções na fila serão iguais à última inserção. (Você pode testar isso ao alterar essa função rapidamente pra receber somente um int * vetor). 

Dessa forma, é necessário fazer o seguinte: 

1) Após alocar o espaço em memória pro nóduo da fila, vamos alocar um espaço para o elemento dentro do nóduo, ou seja, o vetor. Para que possamos alocar corretamente esse espaço, precisamos de antemão do tamanho do vetor e, como é uma informação importante, vamos também guardá-la no nóduo da fila.

2) Com a alocação concluída com sucesso, vamos copiar a informação em memória do vetor original, byte a byte, para a memória recém-alocada dentro do nódulo. Vamos usar a função do header de strings memcpy (faço cáputadideia de porquê uma função assim estaria junto com as cenas de string), que faz justamente isso - recebe um receptor, um doador, e o tamanho em bytes que precisam ser copiados. No caso de uma string, no exercício passado eu utilizei a função strdup, mas poderia dar certo também com a strcpy, utilizando este mesmo princípio. A strdup é melhor porque ela já faz alocação + cópia de uma só vez e economiza no código.

3) É possível ver depois que na função de destruição da fila, temos agora que libertar, além da memória dinamicamente alocada pro nódulo, a memória alocada para o elemento! (se não dá uma merda fudida com memory leak, arriscado até dar ruim com o computador)

*/
void insereElemento(tipoFila * fila, int * vetor, int tamanho){
    naFila * temp = (naFila *)malloc(sizeof(naFila));
    if(temp != NULL){
        temp->elemento = (int *)malloc(tamanho * sizeof(int));
        if(temp->elemento != NULL){
            memcpy(temp->elemento, vetor, tamanho * sizeof(int));
            temp->size = tamanho;
            temp->prox = NULL;
            if(filaVazia(fila)){
                fila->inicio = temp;
            } else {
                fila->fim->prox = temp;
            }
            fila->fim = temp;
        }
    }
}

void mostraElemento(tipoFila * fila){
    naFila * temp = fila->inicio;
    while(temp != NULL){
        for(int i = 0; i < temp->size; i++){
            printf("%d ", temp->elemento[i]);
        }
        printf("\n");
        temp = temp->prox;
    }
}

//Aqui o ptrtamanho é passado por referência para que seja possível manter acessível o vetor desalojado da fila, uma vez que este seja retornado.

/*O retiraElemento aqui só está como um esforço interessante à mais e não será usado para o teste da função de inserção, nem cumpre com qualquer objetivo de resolução da questão. 

Muito embora ele tenha uso, como demonstrado na questão 11_1_3 e 11_1_2 para acessar os elementos da fila, o que me interessa é somente mostrá-los a fim de comprovar que os mesmos entraram na fila em forma FIFO.
*/
int * retiraElemento(tipoFila * fila, int * ptrtamanho){
    if(!filaVazia(fila)){
        naFila * temp = fila->inicio;
        int * vetor = temp->elemento;
        * ptrtamanho = temp->size;
        fila->inicio = fila->inicio->prox;
        if(filaVazia(fila)){
            fila->fim = NULL;
        }
        free(temp);
        return vetor;

    }
    return NULL;
}

int main(){
    int v1[3] = {1, 2, 3};
    int v2[5] = {1, 2, 3, 4, 5};
    int v3[2] = {1, 2};

    tipoFila * filaInt = (tipoFila *)malloc(sizeof(tipoFila));
    criaFila(filaInt);

    //A ideia aqui é realmente só testar a função de inserir os vetores na fila, por isso foda-se o I/O.

    insereElemento(filaInt, v1, 3);
    insereElemento(filaInt, v2, 5);
    insereElemento(filaInt, v3, 2);

    mostraElemento(filaInt);

    destroiFila(filaInt);
    if(filaVazia(filaInt)){
        free(filaInt);
    }

    return 0;
}