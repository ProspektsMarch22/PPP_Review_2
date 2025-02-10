#include <stdio.h>

int main(){
    int lados;
    printf("Informe a quantidade de lados: \n");
    scanf("%d", &lados);
    if(lados <= 0){
        printf("Inválido\n");
        return 0;
    }
    switch(lados){
        case 1:
            printf("Segmento de reta\n");
            break;
        case 2:
            printf("Segmento de reta\n");
            break;
        case 3:
            printf("Triângulo\n");
            break;
        case 4:
            printf("Quadrilátero\n");
            break;
        case 5:
            printf("Pentágono\n");
            break;
        case 6:
            printf("Hexágono\n");
            break;
        default:
            printf("Polígono regular");
            break;
    }   

    return 0;
}