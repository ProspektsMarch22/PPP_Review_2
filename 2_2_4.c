#include <stdio.h>

//Aceita datas apenas no formato dd/mm

//Todos os meses do ano têm 31 dias, por motivos de praticidade.
/*
Datas a serem consideradas:

Primavera = 20/03;
Verão = 21/06;
Outono = 22/09;
Inverno = 21/12;

*/
void determinaEstacao(char* data){
    int mes, dia;
    //Para o mês:
    mes = (int)data[3] - '0';
    mes *= 10;
    mes += (int)data[4] - '0';

    //para o dia:
    dia = (int)data[0] - '0';
    dia *= 10;
    dia += (int)data[1] - '0';

    if(dia > 31 || dia <= 0 || mes <= 0 || mes > 12){
        printf("Erro: data inválida");
    }

    if(mes < 4 || mes > 11){
        if(mes == 3 && dia < 21){
            printf("Está no Inverno\n");
            return;
        } else if (mes == 12 && dia > 20){
            printf("Está no Inverno\n");
            return;
        }
    }

    if(mes >= 3 && mes <= 6){
        if(mes == 6 && dia < 21){
            printf("Está na Primavera\n");
            return;
        }
        printf("Está na Primavera\n");
        return;
    }

    if(mes >= 6 && mes <= 9){
        if(mes == 9 && dia < 22){
            printf("Está no Verão\n");
            return;
        }
        printf("Está no Verão\n");
        return;
    }

    if(mes >= 9 && mes <= 12){
        if(mes == 12 && dia < 21){
            printf("Está no Outono\n");
            return;
        }
        printf("Está no Outono\n");
        return;
    }
}

void le_teclado(char * frase, int size){
    int c, read = 0;
    while(read < size && (c = getchar()) != '\n' && c != EOF){
        frase[read++] = c;
    }
    frase[read] = '\0';
    return;
}



int main(){
    //para este programa, não implementei uma função de leitura de datas por motivo de preguiça mesmo.
    char data[5];
    printf("Informe a data: \n");
    le_teclado(data, sizeof(data));
    determinaEstacao(data);
    return 0;
}