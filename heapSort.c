#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void criaHeap(int vet[], int ini, int fim, unsigned long* troc, unsigned long* compare){
    int auxiliar = vet[ini];
    int j = ini*2 + 1;

    while(j <= fim){
        //*compare += 1;
        if(j < fim){
            *compare += 1;
            if(vet[j] < vet[j + 1]){
                j += 1;
            }
        }
        if(auxiliar < vet[j]){
            *troc += 1;
            vet[ini] = vet[j];
            ini = j;
            j = 2*ini + 1;   
        }else{
            j = fim + 1;
        }
    }
    vet[ini] = auxiliar;
}

double heapSort(int vet[], int size, unsigned long* troc, unsigned long* compare){

    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int aux;
    for(int i = (size - 1)/2; i >= 0; i--){
        criaHeap(vet, i, size - 1, troc, compare);
    }

    for(int i = size - 1; i > 0; i--){
        *troc += 1;
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        criaHeap(vet, 0, i - 1, troc, compare);
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

    double temp1 = heapSort(v1, TAM, &troc1, &comp1);
    printf("-----Heap Sort-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc1, comp1, temp1);

    return 0;
}