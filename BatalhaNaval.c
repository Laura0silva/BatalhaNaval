#include <stdio.h>

int main(){
    int tabuleiro[10][10] = {           //inicia o tabuleiro
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
    int navio1H[2];     //vetor para as coordenadas do navio 1
    int navio2V[2];     //vetor para as coordenadas do navio 2

    printf("    Tabuleiro: Batalha Naval\n");
    printf("   1  2  3  4  5  6  7  8  8  10\n");
    for (int i = 0; i < 10; i++)            //loop para percorrer as linhas da matriz
    {
        printf("%d  ", i + 1);      //imprime a coordenada na linha
        for (int j = 0; j < 10; j++)    //loop para percorrer as colunas da matriz
        {
            printf("%d  ", tabuleiro[i][j]);    //imprime o números
        }
        printf("\n");   //quebra de linha
    }

    printf("\nVamos posicionar o primeiro navio na horizontal.\n");
    printf("Digite a coordenada da linha (de 1 a 10): ");
    scanf("%d", &navio1H[0]);   //armazena a coordenada no índice 0 do vetor
    printf("Agora da coluna onde o navio vai começar (de 1 a 8), exemplo: digite 2 e vai ocupar os espaços 2, 3 e 4: ");
    scanf(" %d", &navio1H[1]);  //armazena a coordenada no índice 1 do vetor

    if (navio1H[0] < 11 && navio1H[1] < 9)  //verifica se as coordenadas são válidas
    {
        for (int j = 0; j < 3; j++){    //loop para repetir 3 vezes
            tabuleiro[navio1H[0] - 1][navio1H[1] - 1] = 3; //pega as coordenadas do vetor e subtrai 1, pois a matriz começa 0 e termina 9
            navio1H[1]++;       //adiciona 1 ao valor da coordenada para ocupar 3 espaços
        }
    }
    else{   //caso a coordenada dada for inválida
        printf("Você escolheu um valor inválido!!!\n");     
    }

    printf("\nVamos posicionar o segundo navio na vertical.\n");
    printf("Digite a coordenada da linha onde o navio vai começar (de 1 a 8): ");
    scanf("%d", &navio2V[0]);       //armazena a coordenada no índice 0 do vetor
    printf("Agora da coluna (de 1 a 10): ");
    scanf(" %d", &navio2V[1]);      //armazena a coordenada no índice 1 do vetor

    if (navio2V[1] < 11 && navio2V[0] < 9)  //verifica se as coordenadas são válidas
    {
        for (int i = 0; i < 3; i++){        //loop para repetir 3 vezes

            tabuleiro[navio2V[0] - 1][navio2V[1] - 1] = 3;  //pega as coordenadas do vetor e subtrai 1, pois a matriz começa 0 e termina 9
            navio2V[1]++;                   //adiciona 1 ao valor da coordenada para ocupar 3 espaços
        }
    }
    else{   //caso a coordenada dada for inválida
        printf("Você escolheu um valor inválido!!!\n");
    }

    //Imprime o tabuleiro novamente
    printf("    Tabuleiro: Batalha Naval\n");
    printf("   1  2  3  4  5  6  7  8  8  10\n");
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