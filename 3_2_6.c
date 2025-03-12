#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void advinhaSo(int min, int max){
    int rnd = rand() % (max - min + 1) + min;
    int i = 0;
    while(1){
        int try;
        if(i == 0){
            printf("Advinhe o número gerado! \n");
        }
        scanf("%d", &try);
        if(try == rnd){
            printf("Parebéns, você venceu!\n");
            break;
        }
        if(try > rnd){
            printf("Você chutou um pouco acima. Tente de novo!\n");
            i++;
            continue;
        }
        if(try < rnd){
            printf("Você chutou um pouco abaixo. Tente de novo!\n");
            i++;
            continue;
        }
    }
    printf("Você conseguiu após %d tentativas!\n", (i + 1));
    return; 
}

int main(){
    srand(time(0));
    printf("Vamos jogar um jogo!\n");
    int max, min;
    printf("Defina os intervalos máximo e mínimo, nessa ordem\n");
    scanf("%d", &max);
    scanf("%d", &min);
    advinhaSo(min, max);
    return 0;
}