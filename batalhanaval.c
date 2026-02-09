#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define H 5  

int main() {
    int tabuleiro[TAMANHO][TAMANHO];


    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // navios
    int linhaH = 1, colunaH = 1; 
    int linhaV = 4, colunaV = 7; 

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    
    int cone[H][H];
    int cruz[H][H];
    int octaedro[H][H];

    // cone
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= (H/2 - i) && j <= (H/2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

   //cruz
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // losango
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - H/2) + abs(j - H/2) <= H/2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // habilidades
    int origemConeL = 2, origemConeC = 2;
    int origemCruzL = 6, origemCruzC = 3;
    int origemOctL  = 5, origemOctC  = 6;

  
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int l, c;

            // Cone
            l = origemConeL + i - H/2;
            c = origemConeC + j - H/2;
            if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                if (cone[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }

            // Cruz
            l = origemCruzL + i - H/2;
            c = origemCruzC + j - H/2;
            if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                if (cruz[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }

            // Octaedro
            l = origemOctL + i - H/2;
            c = origemOctC + j - H/2;
            if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                if (octaedro[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

  
    printf("\nTabuleiro Batalha Naval com Habilidades:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("0 ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
