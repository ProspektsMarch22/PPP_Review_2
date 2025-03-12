#include <stdio.h>
#include <string.h>

#define MAX 50
#define varios 3

typedef struct{
    char nome[MAX];
    int idade;
}Aluno;

Aluno maisVelho(Aluno * alunos);

int main(){
    Aluno alunos[varios];

    printf("Informe o nome e a idade dos alunos: \n");
    for(int i = 0; i < varios; i++){
        printf("Informe o nome do aluno %d: \n", i + 1);
        fgets((alunos + i)->nome, sizeof((alunos + i)->nome), stdin);
        printf("Informe a idade do aluno %d: \n", i + 1);
        scanf("%d", &(alunos + i)->idade);
        (alunos + i)->nome[strcspn((alunos + i)->nome, "\n")] = '\0';
        getchar();
    }

    printf("Dentre esses, o aluno mais velho chama-se %s, e tem %d anos \n", maisVelho(alunos).nome, maisVelho(alunos).idade);


    return 0;
}

Aluno maisVelho(Aluno * alunos){
    Aluno velho;
    velho.idade = 0;
    for(size_t i = 0; i < varios; i++){
        if((alunos + i)->idade > velho.idade){
            velho = *(alunos + i);
        }
    }
    return velho;
}