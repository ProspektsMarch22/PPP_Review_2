#include <stdio.h>
#include <stdlib.h>

#define N 2

/*Vou assumir que a matriz NxN seja uma matriz de inteiros.
É possível resolver a situação para um caso em que não sei o tipo da matriz,
no entanto, por simplicidade, vou considerar que já sei o tipo.*/

/*Outra coisa importante é que me valho do princípio da horizontalização em memória de 
uma matriz. Isto é, toda matriz, em termos de memória, continua horizontal, como se fosse um vetor.
Isso quer dizer que, por exemplo, o elemento [1][0] está imediatamente após o elemento [0][n].
Isso me permite simplesmente acessar esse elementos em termos agora de um múltiplo de n*/

void preencheMatriz(int * matrix, int n);
void mostrarMatriz(int * matrix, int n);
int * matrixMult(int * matrix, int c, int n);

int main(){
    int * matriz = (int *)malloc(N * N * sizeof(int));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz original.\n");
        return 1;
    }

    preencheMatriz(matriz, N);
    mostrarMatriz(matriz, N);
    
    int * novaMatriz;
    int c;
    printf("Defina uma constante c: \n");
    scanf("%d", &c);

    novaMatriz = matrixMult(matriz, c, N);

    if (novaMatriz == NULL) {
        printf("Erro: Falha na alocação da nova matriz. Encerrando programa.\n");
        free(matriz);
        return 1;
    }

    mostrarMatriz(novaMatriz, N);

    free(matriz);
    free(novaMatriz);
    return 0;
}

void preencheMatriz(int * matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Informe o elemento da linha %d coluna %d\n", i + 1, j + 1);
            scanf("%d", (matrix + i * n + j));
        }
    }
}

void mostrarMatriz(int * matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(matrix + i * n + j));
        }
        printf("\n");
    }
}

int * matrixMult(int * matrix, int c, int n){
    int * matrizNova = (int *) malloc(n * n * sizeof(int));
    if(matrizNova == NULL){
        printf("Erro: Memória insuficiente na função matrixMult.\n");
        return NULL; 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(matrizNova + i * n + j) = *(matrix + i * n + j) * c; // Multiplicação direta
        }
    }
    return matrizNova;
}
