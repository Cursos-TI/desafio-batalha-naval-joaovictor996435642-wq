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
    int tamanho = 3; // tamanho fixo do navio

    // 1. Inicializar tudo com 0 
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) { 
            tabuleiro[i][j] = 0; 
        } 
    }


    // 2. Navios como vetores 
    int navioHorizontal[3] = {3, 3, 3}; 
    int navioVertical[3] = {3, 3, 3};

    /*Coordenadas iniciais dos navios 
    int linhaH = 2, colunaH = 1; 
    int linhaV = 5, colunaV = 7;
    */

    /*/3. Validação simples do limite do tabuleiro
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
        */

    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    /*1.1 Direções
    int dx[4] = {0,1,1,1};  // H, V, DIAG DIR, DIAG ESQ
    int dy[4] = {1,0,1,1};

    // 1.2 Posições de início escolhidas já corretas (sem precisar validar)

    int inicio_linha[4] = {2,5,0, 0};
    int inicio_coluna[4] = {1,0,1, -1};

    // Posicionar 4 navios SEM IF

    for(int n = 0; n < 4; n++){
        for (int i = 0; i < tamanho; i++)
        {
           int l = inicio_linha[n] + i *dx[n];
           int c = inicio_coluna[n] + i *dx[n];
           tabuleiro[l][c] = 3;
        }
        
    }

    // 6. Exibir o tabuleiro com letras e números
    printf(" A B C D E F G H I J\n");

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d", i);

        for (size_t j = 0; j < 10; j++)
        {
            printf("%d", tabuleiro[i][j]);
        }

        printf("\n");
        
    }
    
    */


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

    // 1. POSICIONAR NAVIOS

    int h_l = 2,h_c = 1;
    int v_l = 5, v_c = 7;
    int d1_l = 0, d1_c = 0;
    int d2_l = 0, d2_c = 9;

    for (int i = 0; i < tamanho; i++){
        tabuleiro[h_l][h_c + i]= 3;
    }

    for (int i = 0; i < tamanho; i++){
        tabuleiro[v_l + i][v_c]= 3;
    }

    for (int i = 0; i < tamanho; i++){
        tabuleiro[d1_l + i][d1_c + i]= 3;
    }

    for (int i = 0; i < tamanho; i++){
        tabuleiro[d2_l + i][d2_c - i]= 3;
    }

    // 2. MATRIZES DE HABILIDADES (FORMATO DO DESAFIO)

    int H = 3; //altura
    int L = 5; // largura

    int cone[3][5]= {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    int cruz[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    int octa[3][5] = {
      {0,0,1,0,0},
      {0,1,1,1,0},
      {0,0,1,0,0}  
    };

    ///3. CENTROS DAS HABILIDADES

    int coneL = 4, coneC = 4;
    int cruzL = 7, cruzC = 2;
    int octaL = 3, octaC = 7;

    int centroL = H / 2;  // linha 1
    int centroC = L / 2;  // coluna 2

    // 4. SOBREPOR HABILIDADES NO TABULEIRO

    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            if (cone[i][j] == 1){
                int TL = coneL + (i - centroL);
                int TC = coneC + (j - centroC);
                if(TL >= 0 && TL < 10 && TC >= 0 && TC < 10)
                tabuleiro[TL][TC] = 5;
            }
        }
        
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            if(cone[i][j] == 1){
                int TL = cruzL + (i - centroL);
                int TC = cruzC + (j - centroC);
                if(TL >= 0 && TL < 10 && TC >= 0 && TC < 10)
                tabuleiro[TL][TC] = 5;
            }
        }
        
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            if(cone[i][j] == 1){
                int TL = octaL + (i - centroL);
                int TC = octaC + (j - centroC);
                if(TL >= 0 && TL < 10 && TC >= 0 && TC < 10)
                tabuleiro[TL][TC] = 5;
            }
        }
        
    }

    // 5. EXIBIR TABULEIRO FINAL

    printf(" A B C D E F G H I J\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d", i);

        for (int j = 0; j < 10; j++)
        {
            printf("%d", tabuleiro[i][j]);
        }

        printf("\n");
        
    }
    
    return 0;
}
