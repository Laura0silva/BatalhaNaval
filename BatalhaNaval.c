#include <stdio.h>

void ImprimirTabuleiro(int tabuleiro[10][10])
{
    printf("    Tabuleiro: Batalha Naval\n");
    printf("   1  2  3  4  5  6  7  8  9  10\n");

    for (int i = 0; i < 10; i++) {            // loop para percorrer as linhas da matriz
        printf("%d  ", i + 1);                // imprime a coordenada na linha
        for (int j = 0; j < 10; j++) {        // loop para percorrer as colunas da matriz
            printf("%d  ", tabuleiro[i][j]);  // imprime os números
        }
        printf("\n");                         // quebra de linha
    }
}

int main() {
    int tabuleiro[10][10] = {           // inicia o tabuleiro
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
    
    // vetores para as coordenadas dos navios
    int navio1H[2], navio2V[2], navio3D[2], navio4D[2];
    //Matrizes de Habilidade
    int octaedro[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    int cruz[3][5] ={
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    ImprimirTabuleiro(tabuleiro);

    printf("\nVamos posicionar o primeiro navio na horizontal.\n");
    printf("Digite a coordenada da linha (de 1 a 10): ");
    scanf("%d", &navio1H[0]);   // armazena a coordenada no índice 0 do vetor

    printf("Agora da coluna onde o navio vai começar (de 1 a 8), exemplo: digite 2 e vai ocupar os espaços 2, 3 e 4: ");
    scanf("%d", &navio1H[1]);   // armazena a coordenada no índice 1 do vetor

    if (navio1H[0] < 11 && navio1H[1] < 9) {    // verifica se as coordenadas são válidas
        for (int j = 0; j < 3; j++) {           // loop para repetir 3 vezes
            tabuleiro[navio1H[0] - 1][navio1H[1] - 1] = 3;  // define navio
            navio1H[1]++;                       // avança para o próximo espaço
        }
    } else {                                    // caso a coordenada dada for inválida
        printf("Você escolheu um valor inválido!!!\n");
    }

    ImprimirTabuleiro(tabuleiro);

    printf("\nVamos posicionar o segundo navio na vertical.\n");
    printf("Digite a coordenada da linha onde o navio vai começar (de 1 a 8): ");
    scanf("%d", &navio2V[0]);   // armazena a coordenada no índice 0 do vetor

    printf("Agora da coluna (de 1 a 10): ");
    scanf("%d", &navio2V[1]);   // armazena a coordenada no índice 1 do vetor

    if (navio2V[1] < 11 && navio2V[0] < 9) {    // verifica se as coordenadas são válidas
        int sobreposicao = 0;

        // Verifica se algum dos 3 espaços está ocupado
        for (int i = 0; i < 3; i++) {           // loop para repetir 3 vezes
            if (tabuleiro[navio2V[0] - 1 + i][navio2V[1] - 1] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao) {         // Se for verdadeiro, não executa o comando.
            printf("\nOs navios não podem se sobrepor!\n");
        } 
        else {                      // Posiciona o navio
            for (int i = 0; i < 3; i++) {
                tabuleiro[navio2V[0] - 1][navio2V[1] - 1] = 3;
                navio2V[0]++;       // avança para o próximo espaço
            }
        }
    } else {
        printf("Você escolheu um valor inválido!!!\n");
    }

    ImprimirTabuleiro(tabuleiro);

    printf("\nVamos posicionar o terceiro navio na diagonal esquerda-baixo.\n");
    printf("Digite a coordenada da linha onde o navio vai começar (de 1 a 8): ");
    scanf("%d", &navio3D[0]);       // armazena a coordenada no índice 0 do vetor

    printf("Agora da coluna (de 1 a 8): ");
    scanf("%d", &navio3D[1]);       // armazena a coordenada no índice 1 do vetor

    if (navio3D[0] < 9 && navio3D[1] < 9) {       // verifica se as coordenadas são válidas
        int sobreposicao = 0;

        // Verifica se algum dos 3 espaços está ocupado
        for (int i = 0; i < 3; i++) {           // loop para repetir 3 vezes
            if (tabuleiro[navio3D[0] - 1 + i][navio3D[1] - 1 + i] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao) {         // Se for verdadeiro, não executa o comando.
            printf("\nOs navios não podem se sobrepor!\n");
        } 
        else {                      // Posiciona o navio
            for (int i = 0; i < 3; i++) {
                tabuleiro[navio3D[0] - 1 + i][navio3D[1] - 1 + i] = 3;
            }
        }
    } else {
        printf("Você escolheu um valor inválido!!!\n");
    }

    ImprimirTabuleiro(tabuleiro);

    printf("\nVamos posicionar o quarto navio na diagonal direita-baixo.\n");
    printf("Digite a coordenada da linha onde o navio vai começar (de 1 a 8): ");
    scanf("%d", &navio4D[0]);       // armazena a coordenada no índice 0 do vetor

    printf("Agora da coluna (de 3 a 10): ");
    scanf("%d", &navio4D[1]);       // armazena a coordenada no índice 1 do vetor

    if (navio4D[0] < 9 && navio4D[1] < 11 && navio4D[1] > 2) {       // verifica se as coordenadas são válidas
        int sobreposicao = 0;

        // Verifica se algum dos 3 espaços está ocupado
        for (int i = 0; i < 3; i++) {           // loop para repetir 3 vezes
            if (tabuleiro[navio4D[0] - 1 + i][navio4D[1] - 1 - i] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao) {         // Se for verdadeiro, não executa o comando.
            printf("\nOs navios não podem se sobrepor!\n");
        } 
        else {                      // Posiciona o navio
            for (int i = 0; i < 3; i++) {
                tabuleiro[navio4D[0] - 1 + i][navio4D[1] - 1 - i] = 3;
            }
        }
    } else {
        printf("Você escolheu um valor inválido!!!\n");
    }

    ImprimirTabuleiro(tabuleiro);
    printf("\nVamos ver se o seu navio sobreviveu! Algumas áreas foram atacadas.\n");

    int linha = 0, linha2 = 0;
    for (int i = 0; i < 10; i++){           //Percorre as linhas
        for (int j = 0; j < 10; j++)        //Percorre as colunas
        {
            if(i > 0 && i < 4){             //Posiciona a matriz do cone no tabuleiro
                tabuleiro[i][j] = cone[linha][j];
                if(j == 4) {
                    linha++;
                    break;
                }
            }  
            if(i > 3 && i < 7){             //Posiciona a matriz da cruz no tabuleiro
                if(j > 4){
                    tabuleiro[i][j] = cruz[(linha - 3)][(j - 5)];
                    if(j == 9) linha++;
                }
            }  
            if(i > 5 && i < 9){             //Posiciona a matriz do octaedro no tabuleiro
                if(j > 1 && j < 5){
                    tabuleiro[i][j] = octaedro[linha2][j - 2];
                    if(j == 4) linha2++;
                }
            }
        }
    }

    ImprimirTabuleiro(tabuleiro);
    return 0;
}
