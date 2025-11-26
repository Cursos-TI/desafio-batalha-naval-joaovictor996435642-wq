#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    

    int tabuleiro[10][10];// tabuleiro fixo 10x10 
    int tamanhoNavio = 3; // tamanho fixo do navio

    // 1. Inicializar tudo com 0 
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) { 
            tabuleiro[i][j] = 0; 
        } 
    }

    // 2. Navios como vetores 
    int navioHorizontal[3] = {3, 3, 3}; 
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios 
    int linhaH = 2, colunaH = 1; 
    int linhaV = 5, colunaV = 7;

    //3. Validação simples do limite do tabuleiro
    if (colunaH + tamanhoNavio > 10 || linhaV + tamanhoNavio > 10){
        printf("Erro: um dos navios está fora do tabuleiro.\n"); 
        return 1;
    }

    // 4. Posicionar o navio horizontal
    for (int i = 0; i < tamanhoNavio; i++){
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // 5. Posicionar o navio vertical
    for (size_t i = 0; i < tamanhoNavio; i++){
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // 6. Exibir o tabuleiro com letras e números
    printf(" A B C D E F G H I J\n");

    for (size_t i = 0; i < 10; i++)
    {
        printf("%2d", i);

        for (size_t j = 0; j < 10; j++)
        {
            printf("%d", tabuleiro[i][j]);
        }

        printf("\n");
        
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
