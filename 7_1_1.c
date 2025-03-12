#include <stdio.h>

struct data {
    int dia, mes, ano;
};

int comparaDatas(struct data data1, struct data data2);

//Todos os meses são considerados como tendo 30 dias. Não há anos bissextos.
struct data diferencaDatas(struct data data1, struct data data2);

//A função a seguir assume que apenas datas antes do ano 10000 e após a Era Comum serão utilizadas.
int seculo(struct data data);

int main(){
    struct data data1, data2;
    int resultado;
    printf("Crie a data 1: \n");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    printf("Crie a data 2: \n");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    resultado = comparaDatas(data1, data2);
    switch (resultado)
    {
    case 1:
        printf("A data 1 é posterior à data 2\n");
        break;
    case -1:
        printf("A data 1 é anterior à data 2 \n");
        break;
    case 0:
        printf("A data 1 é igual à data 2\n");
        break;
    default:
        printf("Deu ruim \n");
        break;
    }

    int sec1 = seculo(data1);
    int sec2 = seculo(data2);

    printf("O século ao qual pertence a data 1 é o %d\n", sec1);
    printf("O século ao qual pertence a data 2 é o %d\n", sec2);

    struct data diferenca = diferencaDatas(data1, data2);
    printf("A diferença entre as datas 1 e 2 é de %d dia(s), %d mes(es), %d ano(s)\n", diferenca.dia, diferenca.mes, diferenca.ano);

    return 0;
}

int comparaDatas(struct data data1, struct data data2){
    if(data1.ano > data2.ano){
        return 1;
    } else if(data1.ano < data2.ano){
        return -1;
    } else if(data1.ano == data2.ano){
        if(data1.mes > data2.mes){
            return 1;
        } else if(data1.mes < data2.mes){
            return -1;
        } else if(data1.mes == data2.mes){
            if(data1.dia > data2.dia){
                return 1;
            } else if(data1.dia < data2.dia){
                return -1;
            } else if(data1.dia == data2.dia){
                return 0;
            }
        }
    }
    return 2;
}

int seculo(struct data data){
    int sec = (data.ano / 100) + 1;
    return sec;   
}

struct data diferencaDatas(struct data data1, struct data data2){
    struct data diferenca, menor, maior;
    int comp = comparaDatas(data1, data2);
    switch (comp)
    {
    case 1:
        maior = data1;
        menor = data2;
        break;
    case -1:
        maior = data2;
        menor = data1;
        break;
    case 0:
        printf("Não há diferença entre as datas");
        diferenca.ano = 0;
        diferenca.mes = 0;
        diferenca.dia = 0;
        return diferenca;
        break;
    default:
        printf("Resultado inesperado");
        break;
    }

    int diferencaMes;

    if(maior.ano != menor.ano){
        diferenca.ano = maior.ano - menor.ano;
        if(maior.mes < menor.mes){
            diferenca.ano -= 1;
            diferencaMes = (menor.mes + maior.mes) - 12;
        }
    }

    if(maior.ano == menor.ano){
        diferenca.ano = 0;
        if(maior.mes == menor.mes){
            diferencaMes = 0;
        } else {
            diferencaMes = maior.mes - menor.mes;
        }
    }

    if(menor.dia > maior.dia){
        diferencaMes -= 1;
        diferenca.dia = (30 - menor.dia) + maior.dia + (30 * diferencaMes);
    } else if (maior.dia >= menor.dia){
        diferenca.dia = maior.dia - menor.dia + (30 * diferencaMes);
    }

    diferenca.mes = diferenca.dia / 30;
    diferenca.dia = diferenca.dia % 30;
    
    return diferenca;
}   