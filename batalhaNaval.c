#include <stdio.h>

// Desafio Batalha Naval - MateCheck lllll
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10];
    int i, j;

    // inicializa o tabuleiro 10x10 com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // dois navios de tamanho 3 (um horizontal e um vertical), dentro dos limites e sem sobreposição
    // navio horizontal começando em (linha=1, coluna=1): ocupa (1,1), (1,2), (1,3)
    if (1 >= 0 && 1 + 2 < 10) {
        if (tabuleiro[1][1] == 0 && tabuleiro[1][2] == 0 && tabuleiro[1][3] == 0) {
            tabuleiro[1][1] = 3;
            tabuleiro[1][2] = 3;
            tabuleiro[1][3] = 3;
        }
    }
    // navio vertical começando em (linha=5, coluna=6): ocupa (5,6), (6,6), (7,6)
    if (5 + 2 < 10 && 6 >= 0) {
        if (tabuleiro[5][6] == 0 && tabuleiro[6][6] == 0 && tabuleiro[7][6] == 0) {
            tabuleiro[5][6] = 3;
            tabuleiro[6][6] = 3;
            tabuleiro[7][6] = 3;
        }
    }

    // exibe coordenadas ocupadas por cada navio (apenas com printf simples)
    printf("Coordenadas navio horizontal (tamanho 3): (1,1) (1,2) (1,3)\n");
    printf("Coordenadas navio vertical   (tamanho 3): (5,6) (6,6) (7,6)\n\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    // mais dois navios diagonais (tamanho 3), garantindo limites e sem sobreposição

    // diagonal principal: começa em (7,1) -> (7,1), (8,2), (9,3)
    if (7 + 2 < 10 && 1 + 2 < 10) {
        if (tabuleiro[7][1] == 0 && tabuleiro[8][2] == 0 && tabuleiro[9][3] == 0) {
            tabuleiro[7][1] = 3;
            tabuleiro[8][2] = 3;
            tabuleiro[9][3] = 3;
        }
    }

    // diagonal secundária: começa em (0,9) -> (0,9), (1,8), (2,7)
    if (0 + 2 < 10 && 9 - 2 >= 0) {
        if (tabuleiro[0][9] == 0 && tabuleiro[1][8] == 0 && tabuleiro[2][7] == 0) {
            tabuleiro[0][9] = 3;
            tabuleiro[1][8] = 3;
            tabuleiro[2][7] = 3;
        }
    }

    // exibição do tabuleiro completo (0 = água, 3 = navio)
    printf("Tabuleiro 10x10 (0=agua, 3=navio):\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    // Matrizes 5x5 para cada habilidade (0 = não afetada, 1 = afetada)
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // preenche CONE (topo no meio da primeira linha, abrindo para baixo)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // faixa do cone por linha i: colunas entre (2 - i) e (2 + i)
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // preenche CRUZ (linha central e coluna central)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // preenche OCTAEDRO (losango por distância de Manhattan <= 2 em torno do centro (2,2))
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int di = (i > 2) ? (i - 2) : (2 - i);
            int dj = (j > 2) ? (j - 2) : (2 - j);
            if (di + dj <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    printf("Habilidade CONE (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    printf("Habilidade OCTAEDRO (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    printf("Habilidade CRUZ (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}