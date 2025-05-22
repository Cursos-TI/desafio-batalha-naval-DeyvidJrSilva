#include <stdio.h>

// Desafio Batalha Naval - Nível Aventureiro
// Posicionamento de quatro navios dois retos horizontal e vertical e dois diagonais

int main() {
    // Definindo o tabuleiro 10x10
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com água valor 0
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Tamanho fixo dos navios 3 posições cada
    int tamanho_navio = 3;

    // Coordenadas dos navios
    // Navio horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Navio vertical
    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Navio diagonal principal linha e coluna aumentam
    int linha_diag_principal = 0;
    int coluna_diag_principal = 0;

    // Navio diagonal secundária linha aumenta e coluna diminui
    int linha_diag_secundaria = 0;
    int coluna_diag_secundaria = 9;

    // Validação de limites
    int valido = 1;

    // Verificar horizontal
    if (coluna_horizontal + tamanho_navio > 10) {
        valido = 0;
        printf("Erro: Navio horizontal fora dos limites.\n");
    }

    // Verificar vertical
    if (linha_vertical + tamanho_navio > 10) {
        valido = 0;
        printf("Erro: Navio vertical fora dos limites.\n");
    }

    // Verificar diagonal principal
    if (linha_diag_principal + tamanho_navio > 10 || coluna_diag_principal + tamanho_navio > 10) {
        valido = 0;
        printf("Erro: Navio diagonal principal fora dos limites.\n");
    }

    // Verificar diagonal secundária
    if (linha_diag_secundaria + tamanho_navio > 10 || coluna_diag_secundaria - (tamanho_navio - 1) < 0) {
        valido = 0;
        printf("Erro: Navio diagonal secundária fora dos limites.\n");
    }

    // Se todas as posições forem válidas
    if (valido) {
        // Função para verificar sobreposição
        int sobreposicao = 0;

        // Verificar navio horizontal
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 3) {
                sobreposicao = 1;
            }
        }

        // Verificar navio vertical
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                sobreposicao = 1;
            }
        }

        // Verificar diagonal principal
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] == 3) {
                sobreposicao = 1;
            }
        }

        // Verificar diagonal secundária
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] == 3) {
                sobreposicao = 1;
            }
        }

        if (sobreposicao) {
            printf("Erro: Sobreposição de navios detectada.\n");
        } else {
            // Posicionar navio horizontal
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
            }

            // Posicionar navio vertical
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = 3;
            }

            // Posicionar navio diagonal principal
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] = 3;
            }

            // Posicionar navio diagonal secundária
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] = 3;
            }

            // Exibir tabuleiro
            printf("\nTabuleiro com navios posicionados:\n\n");
            for (int linha = 0; linha < 10; linha++) {
                for (int coluna = 0; coluna < 10; coluna++) {
                    printf("%d ", tabuleiro[linha][coluna]);
                }
                printf("\n");
            }
        }

    } else {
        printf("Erro: Coordenadas inválidas.\n");
    }

    return 0;
}
