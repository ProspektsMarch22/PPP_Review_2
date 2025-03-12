#include <stdio.h>

void int3(int * x);

int main(){
    int numero;
    printf("Digite os caracteres. O programa irá funcionar só para os 3 primeiros, então nada de gracinhas.\n");
    int3(&numero);
    printf("%d é o número obtido\n", numero);
    return 0;
}

//vou assumir que o usuário só possa informar dígitos
void int3(int * x){
    char digito;
    int c = 0;
    *x = 0;
    while(c < 3){
        digito = getchar();
        //Ao carregar enter pra introduzir os números, pode haver bouncing. Para evitar, faço essa validação:
        if(digito != '\n'){
            *x = (*x * 10) + (digito - '0');
            c++;
        }
    }
}