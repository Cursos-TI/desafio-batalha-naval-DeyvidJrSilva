#include <stdio.h>

// Desafio Batalha Naval - Nível Novato
// Posicionamento de dois navios no tabuleiro

int main() {
    // tabuleiro 10x10
    int tabuleiro[10][10];

    // iniciando tabuleiro com água valor 0
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Definindo tamanho dos navios 3 posições cada
    int tamanho_navio = 3;

    // Definindo coordenadas iniciais dos navios
    // Navio horizontal começando na linha 2, coluna 4
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Navio vertical começando na linha 5, coluna 1
    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Verificando os navios estão dentro da área
    if (coluna_horizontal + tamanho_navio <= 10 &&
        linha_vertical + tamanho_navio <= 10) {

        // Posicionando o navio horizontal linha fixa, coluna varia
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
        }

        // Posicionando o navio vertical linha varia, coluna fixa
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = 3;
        }

        // Mostrando o tabuleiro
        printf("Tabuleiro com navios posicionados:\n\n");

        for (int linha = 0; linha < 10; linha++) {
            for (int coluna = 0; coluna < 10; coluna++) {
                printf("%d ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }

    } else {
        // Caso as coordenadas estejam inválidas
        printf("Erro: As coordenadas dos navios estão fora dos limites do tabuleiro.\n");
    }

    return 0;
}
