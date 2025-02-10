#include <stdio.h>

void troco(int valorItem, int valorPago) {
    int notasMoedas[] = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    
    int diferenca = valorPago - valorItem;

    printf("Troco total: %d centavos\n", diferenca);

    for (int i = 0; i < 10; i++) {
        int contador = diferenca / notasMoedas[i]; 
        diferenca %= notasMoedas[i]; // Atualiza o restante do troco

        if (contador > 0) {
            printf("%d x %.2f\n", contador, notasMoedas[i] / 100.0);
        }
    }

    if (diferenca > 0) {
        printf("Vamos ficar devendo alguns cêntimos...\n");
    }
}

int main() {
    float valorMonster = 20.00;
    float meuDinheiro = 31.00;

    printf("O Monster é R$%.2f\n", valorMonster);
    printf("O senhor me deu R$%.2f no total\n", meuDinheiro);
    printf("Aqui está o troco!\n");

    // Convertendo para centavos para evitar problemas de ponto flutuante
    troco((int)(valorMonster * 100), (int)(meuDinheiro * 100));

    return 0;
}
