/*
 * Meu Desafio de Batalha Naval - NÍVEL MESTRE!
 * Hora de adicionar HABILIDADES ESPECIAIS (Cone, Cruz, Octaedro)
 * O desafio é criar matrizes de habilidade (5x5) e
 * DEPOIS sobrepor elas no meu tabuleiro principal (10x10).
 *
 * Bora codar!
 */

// 1. Minhas bibliotecas
#include <stdio.h>  // Para 'printf' e 'scanf'
#include <stdlib.h> // Vou precisar disso para 'abs()' (valor absoluto)
                    // que vou usar na habilidade do Octaedro.

// Vou definir um tamanho fixo para as minhas matrizes de habilidade
// Usar 5x5 é bom porque tem um centro claro (2,2)
#define TAM_HABILIDADE 5

// 'main' - onde a mágica acontece
int main() {
    
    // Variável pra guardar a escolha do menu
    int opcaoDoUsuario; 

    // Meu loop 'do-while' pro menu ficar repetindo
    do {
        // --- O Menu (Versão "bonita" com emojis) ---
        printf("\n\n=======================================\n");
        printf(" 🚢 MEU JOGO DE BATALHA NAVAL (MESTRE) 🚢\n");
        printf("=======================================\n");
        printf("Escolha uma Habilidade para testar:\n\n");
        printf("  1. 🎯 Habilidade em CONE\n");
        printf("  2. ✝️  Habilidade em CRUZ\n");
        printf("  3. 💎 Habilidade em OCTAEDRO (Losango)\n");
        printf("  4. 🗺️  Mostrar Apenas Navios (Sem Habilidade)\n");
        printf("\n  0. ❌ Sair do Jogo\n");
        printf("\nSua escolha: ");

        // 2. Lendo o que eu digitei
        scanf("%d", &opcaoDoUsuario);

        // 3. Decidindo o que fazer
        switch (opcaoDoUsuario) {
            
            // --- OPÇÃO 1, 2 ou 3 (A LÓGICA É PARECIDA) ---
            case 1: // Cone
            case 2: // Cruz
            case 3: // Octaedro
            { // <-- Abro chaves aqui pra poder declarar variáveis dentro do case

                printf("\n💥 Disparando Habilidade! 💥\n\n");

                // --- A. Preparar Tabuleiro e Matriz de Habilidade ---
                int tabuleiro[10][10];
                int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];
                
                // O centro da matriz 5x5 é o [2] (resultado de 5 / 2)
                int centroHab = TAM_HABILIDADE / 2;

                // --- B. Limpar o Tabuleiro (Encher de 0 - Água) ---
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        tabuleiro[i][j] = 0; // 0 = ÁGUA
                    }
                }

                // --- C. Posicionar meus 4 Navios (do Nível Aventureiro) ---
                // (Vou usar as posições corrigidas que eu já tinha)
                // 3 = NAVIO
                
                // Navio 1: Horizontal (Linha 8)
                tabuleiro[8][1] = 3; tabuleiro[8][2] = 3; tabuleiro[8][3] = 3;
                
                // Navio 2: Vertical (Coluna 8)
                tabuleiro[3][8] = 3; tabuleiro[4][8] = 3; tabuleiro[5][8] = 3;

                // Navio 3: Diagonal '\' (Começa em 0,0)
                tabuleiro[0][0] = 3; tabuleiro[1][1] = 3; tabuleiro[2][2] = 3; 

                // Navio 4: Diagonal '/' (Começa em 1,6)
                tabuleiro[1][6] = 3; tabuleiro[2][5] = 3; tabuleiro[3][4] = 3;

                
                // --- D. CONSTRUIR a Matriz de Habilidade (5x5) ---
                // O desafio manda construir usando 'if', não "na mão".
                // Primeiro, limpo ela toda com 0s.
                for (int i = 0; i < TAM_HABILIDADE; i++) {
                    for (int j = 0; j < TAM_HABILIDADE; j++) {
                        habilidade[i][j] = 0; // 0 = Não afeta
                    }
                }

                // Agora, a lógica de CADA habilidade
                if (opcaoDoUsuario == 1) {
                    // LÓGICA DO CONE (tipo '\/')
                    // A "boca" do cone aumenta com a linha 'i'.
                    printf("...Construindo matriz de CONE...\n");
                    for (int i = 0; i < TAM_HABILIDADE; i++) {
                        for (int j = 0; j < TAM_HABILIDADE; j++) {
                            // O 'j' (coluna) tem que estar entre (centro - i) e (centro + i)
                            if (j >= centroHab - i && j <= centroHab + i) {
                                habilidade[i][j] = 1; // 1 = Afeta
                            }
                        }
                    }
                } 
                else if (opcaoDoUsuario == 2) {
                    // LÓGICA DA CRUZ (+)
                    printf("...Construindo matriz de CRUZ...\n");
                    for (int i = 0; i < TAM_HABILIDADE; i++) {
                        for (int j = 0; j < TAM_HABILIDADE; j++) {
                            // Se a linha 'i' for o centro OU a coluna 'j' for o centro...
                            if (i == centroHab || j == centroHab) {
                                habilidade[i][j] = 1; // 1 = Afeta
                            }
                        }
                    }
                } 
                else if (opcaoDoUsuario == 3) {
                    // LÓGICA DO OCTAEDRO (Losango/Diamante)
                    printf("...Construindo matriz de LOSANGO...\n");
                    for (int i = 0; i < TAM_HABILIDADE; i++) {
                        for (int j = 0; j < TAM_HABILIDADE; j++) {
                            // A "distância de Manhattan" (abs(i-c) + abs(j-c))
                            // tem que ser menor ou igual ao centro.
                            int distancia = abs(i - centroHab) + abs(j - centroHab);
                            if (distancia <= centroHab) {
                                habilidade[i][j] = 1; // 1 = Afeta
                            }
                        }
                    }
                }

                // --- E. Sobrepor a Habilidade no Tabuleiro Principal ---
                
                // Vou definir um "ponto de origem" (alvo) no tabuleiro
                // Onde o *centro* da habilidade vai "cair"
                int origemLinha = 4;
                int origemColuna = 5;
                printf("...Mirando a habilidade em [%d][%d] do tabuleiro...\n", origemLinha, origemColuna);

                // Agora, passo pela matriz de habilidade (5x5)
                for (int i_hab = 0; i_hab < TAM_HABILIDADE; i_hab++) {
                    for (int j_hab = 0; j_hab < TAM_HABILIDADE; j_hab++) {
                        
                        // Eu só me importo se a habilidade for 1 (afeta)
                        if (habilidade[i_hab][j_hab] == 1) {
                            
                            // Calculo qual célula do TABULEIRO 10x10 ela vai acertar
                            // (i_hab - centroHab) me dá a posição relativa (ex: -2, -1, 0, 1, 2)
                            int alvoLinha = origemLinha + (i_hab - centroHab);
                            int alvoColuna = origemColuna + (j_hab - centroHab);

                            // REQUISITO: Validar se o alvo está DENTRO do 10x10
                            if (alvoLinha >= 0 && alvoLinha < 10 && alvoColuna >= 0 && alvoColuna < 10) {
                                
                                // Se sim, marco no tabuleiro!
                                // 5 = ÁREA AFETADA
                                tabuleiro[alvoLinha][alvoColuna] = 5;
                            }
                        }
                    }
                }

                // --- F. Exibir o Tabuleiro Final (com caracteres) ---
                printf("\n--- Tabuleiro Final com Habilidade ---\n");
                
                // Bônus: Números das colunas
                printf("   0 1 2 3 4 5 6 7 8 9\n");
                printf("   ---------------------\n");
                
                for (int i = 0; i < 10; i++) {
                    printf("%d | ", i); // Bônus: Número da linha
                    
                    for (int j = 0; j < 10; j++) {
                        // Agora vou trocar os números por "desenhos"
                        int celula = tabuleiro[i][j];
                        
                        if (celula == 0) {
                            printf("~ "); // Água
                        } else if (celula == 3) {
                            printf("N "); // Navio
                        } else if (celula == 5) {
                            printf("X "); // Efeito da Habilidade
                        } else {
                            printf("? "); // (Só pra caso dê algum erro)
                        }
                    }
                    printf("\n"); // Pulo a linha
                }
                
                break; // Fim do case 1/2/3
            } // <-- Fecho as chaves do case

            // --- OPÇÃO 4: MOSTRAR SÓ OS NAVIOS ---
            case 4:
            {
                printf("\n🗺️  Mostrando o tabuleiro base (apenas navios)...\n\n");
                
                int tabuleiro[10][10];

                // A. Limpo o tabuleiro
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        tabuleiro[i][j] = 0;
                    }
                }
                
                // B. Posiciono os 4 navios
                tabuleiro[8][1] = 3; tabuleiro[8][2] = 3; tabuleiro[8][3] = 3;
                tabuleiro[3][8] = 3; tabuleiro[4][8] = 3; tabuleiro[5][8] = 3;
                tabuleiro[0][0] = 3; tabuleiro[1][1] = 3; tabuleiro[2][2] = 3; 
                tabuleiro[1][6] = 3; tabuleiro[2][5] = 3; tabuleiro[3][4] = 3;
                
                // C. Exibo o tabuleiro (bonito)
                printf("--- Tabuleiro Base (Aventureiro) ---\n");
                printf("   0 1 2 3 4 5 6 7 8 9\n");
                printf("   ---------------------\n");
                for (int i = 0; i < 10; i++) {
                    printf("%d | ", i); 
                    for (int j = 0; j < 10; j++) {
                        int celula = tabuleiro[i][j];
                        if (celula == 0) printf("~ ");
                        else if (celula == 3) printf("N ");
                        else printf("? ");
                    }
                    printf("\n"); 
                }
                break;
            }

            // --- OPÇÃO 0: SAIR ---
            case 0:
                printf("\nObrigado por jogar! Saindo... 👋\n");
                break; // Sai do 'switch'

            // 'default' é pra qualquer outra coisa que eu digitar
            default:
                printf("\nOpa! 🤷‍♀️ Opcao invalida. Tente de novo.\n");
                break; // Sai do 'switch'
        }

    // ENQUANTO (while) a minha escolha for DIFERENTE (!=) de 0.
    } while (opcaoDoUsuario != 0); 
    
    return 0; // Fim!
}