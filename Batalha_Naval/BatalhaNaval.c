/*
 * Meu Desafio de Batalha Naval - Nível Novato
 * O objetivo é colocar 2 navios (tamanho 3) no tabuleiro 10x10.
 */

// 1. Incluir a biblioteca de entrada/saída
// Eu preciso disso para conseguir usar o 'printf' e mostrar coisas na tela.
#include <stdio.h> 

// 'main'  onde o programa realmente começa.
int main() {
    
    // 2. Criar o Tabuleiro
    // Vou fazer uma matriz 10x10. 'int' porque vai guardar números (0 ou 3).
    // 'tabuleiro' é o nome que eu dei pra ela.
    int tabuleiro[10][10];
    
    
    // 3. Limpar o tabuleiro (encher de ÁGUA)
    // O desafio pede para começar tudo com 0 (água).
    printf("Estou limpando o tabuleiro (colocando 0 em tudo)...\n");
    
    // Vou usar um 'for' para passar por cada LINHA (chamei de 'i')
    for (int i = 0; i < 10; i++) {
        
        // E dentro de cada linha, preciso de outro 'for'
        // para passar por cada COLUNA (chamei de 'j').
        for (int j = 0; j < 10; j++) {
            
            // Aqui eu finalmente coloco o 0 na posição [linha][coluna]
            tabuleiro[i][j] = 0;
        }
    }
    
    // 4. Posicionar meus Navios (Tamanho 3)
    // O desafio diz pra definir no código, então vou fazer "na mão".
    // O número 3 vai ser o meu NAVIO.
    
    // --- Navio 1: Horizontal ---
    // Vou colocar ele na linha 2, ocupando as colunas 3, 4 e 5.
    
    tabuleiro[2][3] = 3; // Pedaço 1 do navio 1
    tabuleiro[2][4] = 3; // Pedaço 2 do navio 1
    tabuleiro[2][5] = 3; // Pedaço 3 do navio 1
    
    
    // --- Navio 2: Vertical ---
    // Vou colocar ele na coluna 7, ocupando as linhas 4, 5 e 6.
    
    tabuleiro[4][7] = 3; // Pedaço 1 do navio 2
    tabuleiro[5][7] = 3; // Pedaço 2 do navio 2
    tabuleiro[6][7] = 3; // Pedaço 3 do navio 2

    // Só um aviso na tela pra eu saber que essa parte já rodou.
    printf("Navios posicionados!\n\n");

    // 5. Exibir o Tabuleiro Pronto
    // Um título pra ficar bonito.
    printf("--- Meu Tabuleiro Final ---\n");
    
    // Vou usar a mesma lógica de 'for' aninhado para LER e MOSTRAR.
    // Loop 'i' para as LINHAS
    for (int i = 0; i < 10; i++) {
        
        // Loop 'j' para as COLUNAS
        for (int j = 0; j < 10; j++) {
            
            // Aqui, em vez de *definir* o valor, eu vou *imprimir* o valor
            // que já está salvo lá (seja 0 ou 3).
            // %d é pra onde vai o número, e " " é pra dar um espaço.
            printf("%d ", tabuleiro[i][j]);
        }
        
        // Esse '\n' é importante!
        // Quando o loop 'j' (colunas) terminar, eu pulo uma linha
        // antes de começar a próxima linha 'i'.
        printf("\n"); 
    }

    // 'return 0' avisa o sistema que meu programa terminou
    // e deu tudo certo. Fim!
    return 0; 
}





















}

