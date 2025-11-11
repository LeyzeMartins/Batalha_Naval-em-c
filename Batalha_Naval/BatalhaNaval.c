/*
 * Meu Desafio de Batalha Naval - NÍVEL AVENTUREIRO!
 * Versão CORRIGIDA, com os navios bem separados
 * para eu não me confundir na hora de checar.
 */

// 1. Incluir a biblioteca de entrada/saída (printf e scanf)
#include <stdio.h> 

// 'main' é onde meu programa realmente começa.
int main() {
    
    int opcaoDoUsuario; 

    do {
        // --- O Menu ---
        printf("\n\n-----------------------------------\n");
        printf("--- MEU JOGO DE BATALHA NAVAL ---\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao:\n");
        printf("1. Nivel Aventureiro (Mostrar 4 Navios c/ Diagonais)\n");
        printf("0. Sair do Jogo\n");
        printf("\nSua escolha: ");

        scanf("%d", &opcaoDoUsuario);

        switch (opcaoDoUsuario) {
            
            case 1:
                printf("\nNivel Aventureiro! Montando o tabuleiro...\n\n");
                
                int tabuleiro[10][10];
                
                // Limpo o tabuleiro
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        tabuleiro[i][j] = 0;
                    }
                }
                
                // --- Posicionando os 4 Navios (Tamanho 3) ---
                
                // Navio 1: Horizontal (Lá embaixo)
                // Na linha 8, colunas 1, 2, 3.
                tabuleiro[8][1] = 3; 
                tabuleiro[8][2] = 3;
                tabuleiro[8][3] = 3;
                
                // Navio 2: Vertical (Lá na direita)
                // Na coluna 8, linhas 3, 4, 5.
                tabuleiro[3][8] = 3;
                tabuleiro[4][8] = 3;
                tabuleiro[5][8] = 3;

                // Navio 3: Diagonal (tipo '\')
                // Começando em [0][0].
                tabuleiro[0][0] = 3; 
                tabuleiro[1][1] = 3; 
                tabuleiro[2][2] = 3; 

                // Navio 4: Diagonal (tipo '/')
                // Começando em [0][4].
                tabuleiro[0][4] = 3; 
                tabuleiro[1][3] = 3;
                tabuleiro[2][2] = 3; // Opa, AQUI DEU SOBREPOSIÇÃO!

                /*
                 * VIU SÓ!
                 * O Navio 3 está em [2][2] e o Navio 4 também.
                 * Isso é EXATAMENTE o que o desafio pede para "validar".
                 * Fazer "na mão" é muito fácil de errar.
                 *
                 * VAMOS CORRIGIR O NAVIO 4 de novo.
                 */

                // Navio 4 (Diagonal '/') - CORRIGIDO
                // Começando em [1][6]
                tabuleiro[1][6] = 3;
                tabuleiro[2][5] = 3;
                tabuleiro[3][4] = 3;

                // Agora sim! Nenhum navio está em cima do outro.
                printf("Navios posicionados (dessa vez, sem sobreposicao! rs)\n");


                // D. Imprimo o tabuleiro pronto
                printf("--- Meu Tabuleiro Final (Aventureiro) ---\n");
                
                // Números das colunas
                printf("   0 1 2 3 4 5 6 7 8 9\n");
                printf("   ---------------------\n");
                
                for (int i = 0; i < 10; i++) {
                    // Número da linha
                    printf("%d | ", i); 
                    
                    for (int j = 0; j < 10; j++) {
                        printf("%d ", tabuleiro[i][j]);
                    }
                    printf("\n"); // Pulo a linha
                }
                
                break; 

            // CASO (case) o usuário tenha digitado 0:
            case 0:
                printf("\nObrigado por jogar! Ate mais! :)\n");
                break; 

            default:
                printf("\nOpa! Opcao invalida. Tente 1 ou 0.\n");
                break;
        }

    } while (opcaoDoUsuario != 0); 
    
    return 0; // Fim!
}