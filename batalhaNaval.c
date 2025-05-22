#include <stdio.h>
#include <stdlib.h> //para abs
 
// Definindo o tamanho do tabuleiro e das habilidades
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios 3 posições
    int tamanho_navio = 3;

    // Posicionamento dos navios (igual ao seu código)
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 1;
    int linha_diag_principal = 0, coluna_diag_principal = 0;
    int linha_diag_secundaria = 0, coluna_diag_secundaria = 9;

    // Posiciona os navios no tabuleiro (sem validação aqui para simplificar)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;            // horizontal
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;                // vertical
        tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] = 3; // diagonal principal
        tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] = 3; // diagonal secundária
    }

    // Criando matrizes para habilidades 5x5 com valores 0 ou 1

    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Construindo a matriz cone (ponta para baixo)
    // Ponto de origem no topo central (linha=0, coluna=2)
    // Exemplo visual (1 = área afetada):
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Para formar um cone:
            // Linha 0: só coluna central
            // Linha 1: colunas 1,2,3
            // Linha 2: colunas 0,1,2,3,4
            // Para as linhas 3 e 4 não preenche (0)
            if (i == 0 && j == 2)
                cone[i][j] = 1;
            else if (i == 1 && (j >= 1 && j <= 3))
                cone[i][j] = 1;
            else if (i == 2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Construindo a matriz cruz
    // Centro (linha=2, coluna=2) como origem
    // Cruz: linha central inteira + coluna central inteira
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) // toda linha central e toda coluna central
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Construindo a matriz octaedro (losango)
    // Centro no meio (2,2)
    // Forma losango simétrica, valores 1 nas posições diagonais do centro
    // Exemplo:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    // 0 1 1 1 0
    // 0 0 1 0 0
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int dist = abs(i - 2) + abs(j - 2);
            // Distância manhattan até o centro <= 2 forma um losango
            if (dist <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Definir pontos de origem das habilidades no tabuleiro (linha, coluna)
    int origem_cone_linha = 1, origem_cone_coluna = 2;
    int origem_cruz_linha = 6, origem_cruz_coluna = 7;
    int origem_octaedro_linha = 4, origem_octaedro_coluna = 4;

    // Função para aplicar habilidade no tabuleiro
    // Marca o valor 5 nas posições afetadas (onde matriz_hab == 1)
    // Faz o alinhamento da matriz 5x5 centrada no ponto de origem (origem_linha, origem_coluna)
    void aplicar_habilidade(int tab[TAM_TABULEIRO][TAM_TABULEIRO], int hab[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
        int offset = TAM_HABILIDADE / 2;
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                if (hab[i][j] == 1) {
                    int lin_tab = origem_linha - offset + i;
                    int col_tab = origem_coluna - offset + j;
                    // Verifica se está dentro dos limites do tabuleiro
                    if (lin_tab >= 0 && lin_tab < TAM_TABULEIRO && col_tab >= 0 && col_tab < TAM_TABULEIRO) {
                        // Não sobrescreve navios (3), apenas marca áreas de efeito (5)
                        if (tab[lin_tab][col_tab] == 0) {
                            tab[lin_tab][col_tab] = 5;
                        }
                    }
                }
            }
        }
    }

    // Aplicando as habilidades
    aplicar_habilidade(tabuleiro, cone, origem_cone_linha, origem_cone_coluna);
    aplicar_habilidade(tabuleiro, cruz, origem_cruz_linha, origem_cruz_coluna);
    aplicar_habilidade(tabuleiro, octaedro, origem_octaedro_linha, origem_octaedro_coluna);

    // Exibir o tabuleiro com navios e áreas de efeito das habilidades
    // 0 = água, 3 = navio, 5 = área de efeito
    printf("Tabuleiro final com navios (3) e habilidades (5):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
