#include <stdio.h>

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10];

    // Preenchendo o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {          // percorre as linhas
        for (int j = 0; j < 10; j++) {      // percorre as colunas
            tabuleiro[i][j] = 0;            // define o valor 0 (água)
        }
    }

    // Exibindo o tabuleiro no console
    printf("=== TABULEIRO ===\n\n");
    for (int i = 0; i < 10; i++) {          // percorre linhas
        for (int j = 0; j < 10; j++) {      // percorre colunas
            printf("%d ", tabuleiro[i][j]); // imprime cada valor com espaço
        }
        printf("\n");                       // pula pra próxima linha
    }

    
}
