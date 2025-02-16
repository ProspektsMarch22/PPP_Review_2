#include <stdio.h>

//Considero apenas datas do tipo dd/mm/aaaa; Qualquer coisa além desse formato dá uma merda federal. Lidar com outros formatos, ou mesmo o texto "1 de Janeiro de 2006" envolveria a utilização de uma ferramenta chamada 'regex', e, para esse efeito, vou realizar esse mesmo exercício com o nome 2_3_3_regex em outro momento a fim de não fazer um overengineering da solução.

void le_teclado(char * f, int size);
void diaDeAmanha(char * data);

int main(){
    char data[10];
    int size = sizeof(data);
    printf("Informe a data: \n");
    le_teclado(data, size);
    printf("O dia de amanhã é: \n");
    diaDeAmanha(data);
    return 0;
}

void le_teclado(char * f, int size){
    int c, read = 0;
    while(read < size && (c = getchar()) != '\n' && c != EOF){
        f[read++] = c;
    }
    f[read] = '\0';
    return;
}

void diaDeAmanha(char * data){
    //Casting
    int dia, mes, ano;
    dia = (((int)data[0] - '0') * 10) + ((int)data[1] - '0');
    mes = (((int)data[3]  - '0') * 10) + ((int)data[4] - '0');
    ano = (((int)data[6] - '0')* 1000) + (((int)data[7] - '0')* 100) + (((int)data[8] - '0')* 10) + ((int)data[9] - '0');

    //Exceções
    if(dia == 31 && mes == 12 && ano == 2006){
        dia = 1;
        mes = 1;
        ano = 2006;
        printf("%d/%d/%d\n", dia, mes, ano);
        return;
    }
    if(dia == 30 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
        dia+= 1;
        printf("%d/%d/%d\n", dia, mes, ano);
        return;
    }
    if(dia == 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
        dia = 1;
        printf("%d/%d/%d\n", dia, mes, ano);
        return;
    }
    if(dia == 28 && mes == 2){
        dia = 1;
        mes = 3;
        printf("%d/%d/%d\n", dia, mes, ano);
        return;
    }

    //Termo geral
    if(dia == 30){
        dia = 1;
        mes += 1;
        printf("%d/%d/%d\n", dia, mes, ano);
        return;
    }
    dia += 1;
    printf("%d/%d/%d\n", dia, mes, ano);
    return;

}