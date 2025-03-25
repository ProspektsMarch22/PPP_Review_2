#include <stdio.h>
#include <stdlib.h>

//Eu vou considerar que o sistema de classificações hipotético da questão se dá através da soma das notas.

/*Esta soma se dará por:
n_teste => Assume um valor de 0 a 10;
n_projeto => Assume um valor de 0 a 5;
n_trabalhos => Assume um valor de 0 a 5;

Eu não farei uma estrutura de verificação para essa questão, porque não quero, e eu essencialmente estou tendo que reescrevê-la/complementá-la pra que fosse clara o suficiente, o que já considero, sinceramente, trabalho demais.
*/

#define N_ALUNOS 20

typedef struct{
    int n_teste, n_projeto, n_trabalhos;
}Notas;

//A função melhorNota devolve o índice de posição do melhor aluno, dentro de um vetor que contém as notas de todos os alunos.
int melhorNota(Notas * vetorNotas);

int main(){
    Notas * notasAlunos = (Notas *)malloc(sizeof(Notas) * N_ALUNOS);
    if(notasAlunos == NULL){
        printf("Erro na alocação de memória");
        return -1;
    }

    for(int i = 0; i < N_ALUNOS; i++){
        printf("Preencha as informações do aluno %d, por favor\n", i + 1);
        for(int j = 0; j < 3; j++){
            switch(j){
                case 0:
                printf("Insira a nota do teste do aluno %d\n", i + 1);
                scanf("%d", &(notasAlunos + i)->n_teste);
                break;
                case 1:
                printf("Insira a nota do projeto do aluno %d\n", i + 1);
                scanf("%d", &(notasAlunos + i)->n_projeto);
                break;
                case 2:
                printf("Insira a nota dos trabalhos do aluno %d\n", i + 1);
                scanf("%d", &(notasAlunos + i)->n_trabalhos);
                break;
            }
        }
    }

    int melhorAluno = melhorNota(notasAlunos);
    printf("A melhor classificação foi obtida pelo aluno %d\n", melhorAluno + 1);

    free(notasAlunos);
    return 0;
}

int melhorNota(Notas * vetorNotas){
    int somaNotas = 0, tempSomaNotas, i = 0, j = 0;
    while(i < N_ALUNOS){
        tempSomaNotas = 0;
        tempSomaNotas = tempSomaNotas + (vetorNotas + i)->n_teste + (vetorNotas + i)->n_projeto + (vetorNotas)->n_trabalhos;
        if(tempSomaNotas > somaNotas){
            somaNotas = tempSomaNotas;
            j = i;
        }
        i++;
    }
    return j;
}