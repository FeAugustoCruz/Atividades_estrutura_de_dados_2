#include <stdio.h>

void Bolha(int *vetorInt, int size) {
    int auxiliar;
    int i, j;

    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vetorInt[j] > vetorInt[j + 1]) {
                auxiliar = vetorInt[j];
                vetorInt[j] = vetorInt[j + 1];
                vetorInt[j + 1] = auxiliar;
            }
        }
    }
}

int main(void) {
    int vetor[4] = {4, 1, 4, 6};
    int size = sizeof(vetor) / sizeof(vetor[0]);

    Bolha(vetor, size);

    printf("Vetor ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("[%d]", vetor[i]);
    }
    printf("\n");

    return 0;
}