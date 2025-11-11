#include <stdio.h>

#define LEN 6

int main(void) {
    int meio1, meio2;
    int V[LEN] = {4, 6, 8, 5, 1, 2};

    for (int i = 1; i < LEN; i++) {
        int auxiliar = V[i];
        int esq = 0;
        int dir = i - 1;

        // Busca ternária
        while (esq <= dir) {
            meio1 = esq + (dir - esq) / 3;
            meio2 = dir - (dir - esq) / 3;

            if (auxiliar < V[meio1]) {
                dir = meio1 - 1;
            } else if (auxiliar > V[meio2]) {
                esq = meio2 + 1;
            } else {
                esq = meio1 + 1;
                dir = meio2 - 1;
            }
        }

        // Desloca os elementos
        for (int j = i; j > esq; j--) {
            V[j] = V[j - 1];
        }

        // Insere o elemento
        V[esq] = auxiliar;
    }

    // Imprime vetor ordenado
    for (int i = 0; i < LEN; i++) {
        printf("[%d]", V[i]);
    }

    return 0;
}