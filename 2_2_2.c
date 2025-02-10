#include <stdio.h>

void formatoHora(char * horas, char * formato), le_teclado(char * frase, int size);


int main(){
    char texto[5], meridian[2];
    printf("Informe as horas no formato 24:00, por favor\n");
    le_teclado(texto, sizeof(texto)); 
    printf("%s", texto);
    formatoHora(texto, meridian);
    return 0;
}

//Precisa estar no formato XX:xx
void formatoHora(char * texto, char * formato){
    int horas;
    formato = "am";
    printf("%c\n", texto[0]);
    horas = (int)texto[0] - '0';
    horas *= 10;
    printf("%d\n", horas);
    horas += (int)texto[1] - '0';

    if(horas >= 13 && horas < 24){
        horas -= 12;
        formato = "pm";
    }

    printf("A hora é %d:%c%c %s\n", horas, texto[3], texto[4], formato);

    return;
}

void le_teclado(char * frase, int size){
    int c, read = 0;
    while(read < size && (c = getchar()) != '\n' && c != EOF){
        frase[read++] = c;
    }
    frase[read] = '\0';
    return;
}

