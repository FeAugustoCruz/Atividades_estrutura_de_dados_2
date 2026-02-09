#include <time.h>
#include <stdlib.h>
#include <stdio.h>

double shellSort(int vet[], int size, unsigned long* troc, unsigned long* compare) {

    clock_t inicio, fim;
    double tempo;

    int h = 1, auxiliar, j;

    while (h < size) {
        h = 3 * h + 1;
    }

    inicio = clock();

    while (h > 1) {
        h = h / 3;

        for (int i = h; i < size; i++) {
            auxiliar = vet[i];
            j = i - h;

            while (j >= 0) {
                (*compare)++;               
                if (auxiliar < vet[j]) {
                    vet[j + h] = vet[j];
                    (*troc)++;                 
                    j -= h;
                } else {
                    break;
                }
            }
            vet[j + h] = auxiliar;             
        }
    }

    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double selectionSort(int vet[], int size, unsigned long* troc, unsigned long* compare){

    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int min, aux;
    for (int i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            *compare += 1;              
            if (vet[j] < vet[min]) {
                min = j;
            }
        }

        if (min != i) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            *troc += 1;                   
        }
    }
    fim = clock();

    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return temp;
}

#define TAM 10000

int main(void){

    int v1[TAM], v2[TAM];
    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        v1[i] = rand() % 50000;
        v2[i] = v1[i]; // Mesmos dados para comparação justa
    }

    unsigned long troc1, troc2;
    unsigned long comp1, comp2;

    double temp1 = shellSort(v1, TAM, &troc1, &comp1);
    double temp2 = selectionSort(v2, TAM, &troc2, &comp2);
    printf("-----Shell Sort-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc1, comp1, temp1);
    printf("-----Selection Sort-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f", troc2, comp2, temp2);

    return 0;
}