#include <stdio.h>

int main() {
    // ==============================
    // DECLARAÇÃO DO TABULEIRO
    // ==============================
    int tabuleiro[10][10];

    // Preenche o tabuleiro com 0 (representa água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==============================
    // POSICIONAMENTO DOS NAVIOS
    // ==============================

    // Cada navio ocupa 3 posições (tamanho fixo)
    // Valor 3 representa parte do navio

    // --- 1º NAVIO: HORIZONTAL (linha fixa, colunas crescentes)
    int linhaH = 1, colunaH = 2; // coordenadas iniciais
    for (int k = 0; k < 3; k++) {
        tabuleiro[linhaH][colunaH + k] = 3;
    }

    // --- 2º NAVIO: VERTICAL (coluna fixa, linhas crescentes)
    int linhaV = 4, colunaV = 5; // coordenadas iniciais
    for (int k = 0; k < 3; k++) {
        tabuleiro[linhaV + k][colunaV] = 3;
    }

    // --- 3º NAVIO: DIAGONAL ↘ (linha e coluna aumentam)
    int linhaD1 = 0, colunaD1 = 0; // canto superior esquerdo
    for (int k = 0; k < 3; k++) {
        tabuleiro[linhaD1 + k][colunaD1 + k] = 3;
    }

    // --- 4º NAVIO: DIAGONAL ↙ (linha aumenta e coluna diminui)
    int linhaD2 = 0, colunaD2 = 9; // canto superior direito
    for (int k = 0; k < 3; k++) {
        tabuleiro[linhaD2 + k][colunaD2 - k] = 3;
    }

    // ==============================
    // EXIBIÇÃO DO TABULEIRO
    // ==============================

    printf("===== TABULEIRO COMPLETO =====\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // exibe cada célula
        }
        printf("\n"); // muda de linha a cada linha do tabuleiro
    }

 
}
