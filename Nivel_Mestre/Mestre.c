#include <stdio.h>
#include <stdlib.h>   // para abs()

#define SIZE 10        // dimensão do tabuleiro
#define SHIP 3         // valor para navio
#define EFFECT 5       // valor para área de habilidade
#define EMPTY 0
#define HSZ 5          // dimensão (ímpar) das matrizes de habilidade

// Protótipos
void imprimir_tabuleiro(int tab[SIZE][SIZE]);
void overlay(int mat[HSZ][HSZ], int orig_row, int orig_col, int tab[SIZE][SIZE]);

void imprimir_tabuleiro(int tab[SIZE][SIZE]) {
    printf("=== TABULEIRO (0=agua, 3=navio, 5=efeito) ===\n\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Sobrepõe a matriz de habilidade 'mat' (HSZ x HSZ) no tabuleiro
// centrando-a em (orig_row, orig_col). Apenas escreve EFFECT sobre EMPTY.
void overlay(int mat[HSZ][HSZ], int orig_row, int orig_col, int tab[SIZE][SIZE]) {
    int mid_local = HSZ / 2;
    for (int r = 0; r < HSZ; r++) {
        for (int c = 0; c < HSZ; c++) {
            if (mat[r][c] == 1) {
                int board_r = orig_row + (r - mid_local);
                int board_c = orig_col + (c - mid_local);
                if (board_r >= 0 && board_r < SIZE && board_c >= 0 && board_c < SIZE) {
                    if (tab[board_r][board_c] == EMPTY) {
                        tab[board_r][board_c] = EFFECT;
                    }
                    // se for SHIP (3), mantemos o navio visível
                }
            }
        }
    }
}

int main() {
    // 1) Inicializa o tabuleiro
    int tabuleiro[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tabuleiro[i][j] = EMPTY;

    // 2) Posiciona navios (tamanho 3)
    // Horizontal
    int linhaH = 1, colunaH = 2;
    for (int k = 0; k < 3; k++) tabuleiro[linhaH][colunaH + k] = SHIP;

    // Vertical
    int linhaV = 4, colunaV = 5;
    for (int k = 0; k < 3; k++) tabuleiro[linhaV + k][colunaV] = SHIP;

    // Diagonal ↘
    int linhaD1 = 0, colunaD1 = 0;
    for (int k = 0; k < 3; k++) tabuleiro[linhaD1 + k][colunaD1 + k] = SHIP;

    // Diagonal ↙
    int linhaD2 = 0, colunaD2 = 9;
    for (int k = 0; k < 3; k++) tabuleiro[linhaD2 + k][colunaD2 - k] = SHIP;

    // (Opcional) imprime estado com navios antes das habilidades
    // imprimir_tabuleiro(tabuleiro);

    // 3) Cria matrizes de habilidade 5x5 (inicializa com 0)
    int cone[HSZ][HSZ];
    int cruz[HSZ][HSZ];
    int octaedro[HSZ][HSZ];

    for (int i = 0; i < HSZ; i++)
        for (int j = 0; j < HSZ; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }

    int mid = HSZ / 2;

    // 3a) CONE apontando para baixo (topo no centro)
    for (int r = 0; r < HSZ; r++) {
        int alcance = (r <= mid) ? r : mid; // cresce até mid
        for (int c = mid - alcance; c <= mid + alcance; c++) {
            if (c >= 0 && c < HSZ) cone[r][c] = 1;
        }
    }

    // 3b) CRUZ (linha e coluna central)
    for (int r = 0; r < HSZ; r++) {
        for (int c = 0; c < HSZ; c++) {
            if (r == mid || c == mid) cruz[r][c] = 1;
        }
    }

    // 3c) OCTAEDRO (losango) usando distância de Manhattan
    for (int r = 0; r < HSZ; r++) {
        for (int c = 0; c < HSZ; c++) {
            int manhattan = abs(r - mid) + abs(c - mid);
            if (manhattan <= mid) octaedro[r][c] = 1;
        }
    }

    // (Opcional) imprime matrizes de habilidade para debug
    printf("MATRIZ CONE (1=afeta):\n");
    for (int i = 0; i < HSZ; i++) { for (int j = 0; j < HSZ; j++) printf("%d ", cone[i][j]); printf("\n"); }
    printf("\nMATRIZ CRUZ (1=afeta):\n");
    for (int i = 0; i < HSZ; i++) { for (int j = 0; j < HSZ; j++) printf("%d ", cruz[i][j]); printf("\n"); }
    printf("\nMATRIZ OCTAEDRO (1=afeta):\n");
    for (int i = 0; i < HSZ; i++) { for (int j = 0; j < HSZ; j++) printf("%d ", octaedro[i][j]); printf("\n"); }
    printf("\n");

    // 4) Define pontos de origem das habilidades no tabuleiro
    int origem_cone_row = 2, origem_cone_col = 2;
    int origem_cruz_row = 5, origem_cruz_col = 5;
    int origem_octa_row = 1, origem_octa_col = 7;

    // 5) Sobrepõe as habilidades
    overlay(cone, origem_cone_row, origem_cone_col, tabuleiro);
    overlay(cruz, origem_cruz_row, origem_cruz_col, tabuleiro);
    overlay(octaedro, origem_octa_row, origem_octa_col, tabuleiro);

    // 6) Imprime o tabuleiro final
    imprimir_tabuleiro(tabuleiro);

  
}
