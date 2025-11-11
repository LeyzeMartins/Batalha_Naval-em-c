/*
 * Meu Desafio de Batalha Naval - NÍVEL AVENTUREIRO
 * Agora o bicho pega. Tenho que adicionar 4 navios,
 * e dois deles na DIAGONAL.
 * Vou manter a base do menu que fiz antes.
 */

// 1. Minha biblioteca de sempre (printf/scanf)
#include <stdio.h> 

// 'main' - onde tudo começa
int main() {
    
    // Variável pra guardar a escolha do menu
    int opcaoDoUsuario; 

    // Meu loop 'do-while' pro menu ficar repetindo
    do {
        // --- O Menu ---
        printf("\n\n-----------------------------------\n");
        printf("--- MEU JOGO DE BATALHA NAVAL ---\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao:\n");
        printf("1. Nivel Aventureiro (4 Navios c/ Diagonais)\n"); // Mudei o texto
        printf("0. Sair do Jogo\n");
        printf("\nSua escolha: ");

        // 2. Lendo o que eu digitei
        scanf("%d", &opcaoDoUsuario);

        // 3. Decidindo o que fazer
        switch (opcaoDoUsuario) {
            
            // CASO (case) eu tenha digitado 1:
            case 1:
                printf("\nNivel Aventureiro! Bora montar esse tabuleiro...\n\n");
                
                // A. Crio a matriz 10x10
                int tabuleiro[10][10];
                
                // B. Limpo o tabuleiro (encho de 0 - ÁGUA)
                // (Loop 'i' pras linhas)
                for (int i = 0; i < 10; i++) {
                    // (Loop 'j' pras colunas)
                    for (int j = 0; < 10; j++) {
                        tabuleiro[i][j] = 0;
                    }
                }
                
                // C. Posicionar meus 4 Navios (Tamanho 3)
                // O 3 continua sendo o meu NAVIO.
                
                // --- Navio 1: Horizontal ---
                // Vou botar ele lá embaixo pra não atrapalhar.
                // Linha 8, colunas 1, 2, 3.
                tabuleiro[8][1] = 3; 
                tabuleiro[8][2] = 3;
                tabuleiro[8][3] = 3;
                
                // --- Navio 2: Vertical ---
                // Vou botar ele lá na direita.
                // Coluna 8, linhas 3, 4, 5.
                tabuleiro[3][8] = 3;
                tabuleiro[4][8] = 3;
                tabuleiro[5][8] = 3;

                // --- Navio 3: Diagonal (tipo '\') ---
                // Onde linha e coluna aumentam juntas.
                // Começando em [0][0].
                tabuleiro[0][0] = 3; 
                tabuleiro[1][1] = 3; 
                tabuleiro[2][2] = 3; 

                /* * --- Navio 4: Diagonal (tipo '/') ---
                 * Onde a linha aumenta e a coluna diminui.
                 * Tinha colocado em [0][4] antes...
                 * tabuleiro[0][4] = 3; 
                 * tabuleiro[1][3] = 3;
                 * tabuleiro[2][2] = 3; // ...e deu sobreposição com o Navio 3!
                 *
                 * Droga, fazer "na mão" é fácil de errar.
                 * O desafio pedia pra validar isso.
                 *
                 * OK, VOU CORRIGIR O NAVIO 4.
                 */
                 
                // --- Navio 4: Diagonal (tipo '/') - VERSÃO CORRIGIDA ---
                // Vou começar em [1][6] pra ficar longe dos outros.
                tabuleiro[1][6] = 3; // Posição [1][6]
                tabuleiro[2][5] = 3; // Posição [2][5]
                tabuleiro[3][4] = 3; // Posição [3][4]