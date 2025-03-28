#include <stdio.h>

int main(){
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int navio1H[3];
    int navio2V[3];

    for (int j = 3; j < 6; j++){
            tabuleiro[5][j] = 3;
    }
    for (int i = 3; i < 6; i++){
        tabuleiro[i][7] = 3;
    }

    printf("    Tabuleiro: Batalha Naval\n");
    printf("   A  B  C  D  E  F  G  H  I  J\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}