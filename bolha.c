#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000

void bubbleSort(int vetor[], int n) {
    long long comparacoes = 0;
    long long trocas = 0;
    int i, j, temp;
    
    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            
            comparacoes++; 
            
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                
                trocas++; 
            }
        }
    }

    fim = clock();
    
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n--- RESULTADOS ---\n");
    printf("Tamanho do vetor: %d\n", n);
    printf("Comparacoes realizadas: %lld\n", comparacoes);
    printf("Trocas realizadas: %lld\n", trocas);
    printf("Tempo de execucao: %f segundos\n", tempo_gasto);
}

int main() {
    int vetor[TAMANHO];
    int i;

    srand(time(NULL));

    for (i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 100000;
    }

    bubbleSort(vetor, TAMANHO);

    return 0;
}