#include <stdio.h>


#define N 3

typedef struct{
    int dia, mes, ano;
}Data;

Data menor(Data * datas, size_t size);

int main(){
    Data mdatas[N];
    
    printf("Informe as datas para o vetor no formato dd/mm/aaaa: \n");
    for(int i = 0; i < N; i++){
        printf("Data %d: \n", i + 1);
        scanf("%d/%d/%d", &(mdatas + i)->dia, &(mdatas + i)->mes, &(mdatas + i)->ano);
    }

    printf("A menor data entre aquelas informadas é: \n");
    printf("%d/%d/%d\n", menor(mdatas, N).dia, menor(mdatas, N).mes, menor(mdatas, N).ano);
    return 0;
}

Data menor(Data * datas, size_t size){
    Data menor;
    menor.ano = 9999;
    for(size_t i = 0; i < size; i++){
        if((datas + i)->ano < menor.ano){
            menor = *(datas + i);
        } else if((datas + i)-> ano == menor.ano){
            if((datas + i)-> mes < menor.mes){
                menor = *(datas + i);
            }
            else if((datas + i)->mes == menor.mes){
                if((datas + i)->dia < menor.dia){
                    menor = *(datas + i);
                }
            }
        }

    }
    return menor;

}