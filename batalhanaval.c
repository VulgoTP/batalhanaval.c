#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

   
    int linhaH = 2, colunaH = 3; 
    int linhaV = 5, colunaV = 5; 

    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

  
    if (colunaH + 3 > 10) {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: sobreposição no navio horizontal.\n");
            return 1;
        }
    }


    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }


    if (linhaV + 3 > 10) {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: sobreposição no navio vertical.\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }


    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
