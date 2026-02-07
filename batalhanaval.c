#include <stdio.h>

#define TAMANHO 10 
#define NAVIO 3
#define AGUA 0

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Coordenadas iniciais
    int linhaH = 1, colunaH = 1; // Horizontal →
    int linhaV = 4, colunaV = 7; // Vertical ↓

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ===== Navio Horizontal =====
    if (colunaH + 2 >= TAMANHO) {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA) {
            printf("Erro: sobreposição no navio horizontal.\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // ===== Navio Vertical =====
    if (linhaV + 2 >= TAMANHO) {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaV + i][colunaV] != AGUA) {
            printf("Erro: sobreposição no navio vertical.\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // ===== Exibir Tabuleiro =====
    printf("\nTabuleiro Batalha Naval (10x10):\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
