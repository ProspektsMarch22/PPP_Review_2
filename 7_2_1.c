#include <stdio.h>

struct data{
    int dia, mes, ano;
};

struct data_info{
    struct data date;
    //A posição irá me ajudar no sorting depois
    int pos; 
};

struct data_array{
    struct data date[10];
    //O tamanho me ajuda a ler somente as partes importantes do array formado, sem a necessidade de iterar por lixo depois. Também atuará como variável auxiliar na lógica da função depois.
    int tamanho;
};

int comparaDatas(struct data data1, struct data data2);

void ordenaDatas(struct data mdatas[], int size);

struct data_info menorData(struct data mdatas[], int size);

struct data_array dataAno(struct data mdatas[], int size, int anoEspecifico);


int main(){
    struct data data1, data2, data3, data4;
    printf("Crie a data 1: \n");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    printf("Crie a data 2: \n");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
    printf("Crie a data 3: \n");
    scanf("%d/%d/%d", &data3.dia, &data3.mes, &data3.ano);
    printf("Crie a data 4: \n");
    scanf("%d/%d/%d", &data4.dia, &data4.mes, &data4.ano);

    struct data mdatas[] = {data1, data2, data3, data4};
    int size = (sizeof(mdatas))/(sizeof(mdatas[0]));

    struct data_info resultado;
    resultado = menorData(mdatas, size);
    printf("A menor data é %d/%d/%d\n", resultado.date.dia, resultado.date.mes, resultado.date.ano);

    printf("As datas ordenadas da menor para a maior:\n");
    ordenaDatas(mdatas, size);
    for(int i = 0; i < size; i++){
        printf("%d/%d/%d\n", mdatas[i].dia, mdatas[i].mes, mdatas[i].ano);
    }

    int anoEspecifico;
    printf("Agora, informe um ano especial para você: \n");
    scanf("%d", &anoEspecifico);
    struct data_array anosEspeciais;
    anosEspeciais = dataAno(mdatas, size, anoEspecifico);
    printf("Estes anos foram mais especiais pra você: \n");
    for(int i = 0; i < anosEspeciais.tamanho; i++){
        printf("%d/%d/%d\n", anosEspeciais.date[i].dia, anosEspeciais.date[i].mes, anosEspeciais.date[i].ano);
    }
    
    return 0;
}

int comparaDatas(struct data data1, struct data data2) {
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

struct data_info menorData(struct data mdatas[], int size){
    struct data_info menor;
    menor.date.ano = 9999;
    for(int i = 0; i < size; i++){
        int comp = comparaDatas(menor.date, mdatas[i]);
        if(comp == 1){
            menor.date = mdatas[i];
            menor.pos = i;
        }
    }
    return menor;
}

void ordenaDatas(struct data mdatas[], int size){
    struct data ordenado[size];
    int marcado[size]; //Array de flags de posições, dessa forma

    for(int i = 0; i < size; i++){
        marcado[i] = 0;
    }

    for(int j = 0; j < size; j++){
        struct data_info menor;
        menor.date.ano = 9999;
        menor.pos = -1;

        for(int i = 0; i < size; i++){
            if(!marcado[i]){
                if(menor.pos == -1 || comparaDatas(menor.date, mdatas[i]) == 1) {
                    menor.date = mdatas[i];
                    menor.pos = i;
                }
            }
        }

        marcado[menor.pos] = 1;
        ordenado[j] = menor.date;
    }

    for(int i = 0; i < size; i++){
        mdatas[i] = ordenado[i];
    }

    return;
}

struct data_array dataAno(struct data mdatas[], int size, int anoEspecifico){
    struct data_array marray;
    marray.tamanho = 0;

    for(int i = 0; i < size; i++){
        if(mdatas[i].ano == anoEspecifico){
            marray.date[marray.tamanho] = mdatas[i];
            marray.tamanho++;
        }
    }

    return marray;
};