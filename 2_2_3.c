#include <stdio.h>

int classificacao(int nota);


int main(){
    int nota;

    printf("Informe a nota do aluno: \n");
    scanf("%d", &nota);
    classificacao(nota);
    
    return 0;
}

int classificacao(int nota){
    if(nota < 9){
        printf("Insuficiente\n");
        return 1;
    } else if (nota < 14){
        printf("Suficiente\n");
        return 1;
    } else if (nota < 17){
        printf("Bom\n");
        return 1;
    } else if (nota < 21){
        printf("Excelente\n");
        return 1;
    }
    return 0;
}

