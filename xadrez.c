#include <stdio.h>

/* =========================================================
   Funções recursivas — simulam o movimento das peças
   Torre, Bispo e Rainha
   ========================================================= */

// ----------- Função Recursiva: Torre -----------
void moverTorre(int casas) {
    if (casas == 0) return;  // caso base: não há mais casas para mover
    printf("Direita (%d)\n", casas);
    moverTorre(casas - 1); // chamada recursiva para a próxima casa
}

// ----------- Função Recursiva com Loops Aninhados: Bispo -----------
void moverBispo(int casasVertical, int casasHorizontal) {
    if (casasVertical == 0 || casasHorizontal == 0) return; // caso base

    // Loop externo controla o movimento vertical (Cima)
    for (int i = 1; i <= casasVertical; i++) {
        // Loop interno controla o movimento horizontal (Direita)
        for (int j = 1; j <= casasHorizontal; j++) {
            printf("Cima, Direita (%d,%d)\n", i, j);
        }
    }

    // Chamada recursiva reduzindo as casas em cada direção
    moverBispo(casasVertical - 1, casasHorizontal - 1);
}

// ----------- Função Recursiva: Rainha -----------
void moverRainha(int casas) {
    if (casas == 0) return; // caso base
    printf("Esquerda (%d)\n", casas);
    moverRainha(casas - 1);
}

/* =========================================================
   Função com Loops Complexos — simula o movimento do Cavalo
   ========================================================= */
// Movimento do Cavalo: duas casas para cima e uma para a direita
void moverCavalo() {
    int movimentoVertical = 2;
    int movimentoHorizontal = 1;

    printf("Movimento do Cavalo:\n");

    // Loop externo: movimento vertical (Cima)
    for (int i = 1; i <= movimentoVertical; i++) {

        // Loop interno: movimento horizontal (Direita)
        // Usa múltiplas variáveis e controle com continue/break
        for (int j = 1, k = i; j <= movimentoHorizontal; j++, k--) {

            // Se ainda não terminou o movimento vertical, apenas sobe
            if (i < movimentoVertical) {
                printf("Cima (%d)\n", i);
                continue; // pula para a próxima iteração sem imprimir "Direita"
            }

            // Quando chegar na segunda casa para cima, move à direita
            if (i == movimentoVertical) {
                printf("Direita (%d)\n", j);
                break; // sai do loop interno após o movimento final
            }
        }
    }
}

/* =========================================================
   Função principal — chama as peças e organiza as saídas
   ========================================================= */
int main() {
    printf("=== Simulação dos Movimentos de Xadrez ===\n\n");

    // --------- TORRE ---------
    printf("Movimento da Torre (Recursividade):\n");
    moverTorre(5);
    printf("\n");

    // --------- BISPO ---------
    printf("Movimento do Bispo (Recursividade + Loops Aninhados):\n");
    moverBispo(3, 3);
    printf("\n");

    // --------- RAINHA ---------
    printf("Movimento da Rainha (Recursividade):\n");
    moverRainha(8);
    printf("\n");

    // --------- CAVALO ---------
    moverCavalo();
    printf("\n");

    printf("Simulação finalizada com sucesso!\n");

    return 0;
}
