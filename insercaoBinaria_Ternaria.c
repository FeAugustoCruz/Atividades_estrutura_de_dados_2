#include <time.h>
#include <stdlib.h>
#include <stdio.h>

double insercaoBinaria(int vet[], int size, unsigned long* troc, unsigned long* compare){
    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int auxiliar, esq, dir, meio;
    for (int i = 1; i < size; i++) {
        auxiliar = vet[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            meio = (esq + dir) / 2;
            *compare += 1;
            if (auxiliar > vet[meio]){
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }

        for (int j = i; j > esq; j--) {
            *troc += 1;
            vet[j] = vet[j - 1];
        }

        vet[esq] = auxiliar;
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double insercaoTernaria(int vet[], int size, unsigned long* troc, unsigned long* compare){

    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int auxiliar, esq, dir, m1, m2;
    for (int i = 1; i < size; i++) {
        auxiliar = vet[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            m1 = esq + (dir - esq) / 3;
            m2 = dir - (dir - esq) / 3;

            *compare += 1;
            if (auxiliar < vet[m1]) {
                dir = m1 - 1;
            } 
            else{
                *compare += 1;
                if (auxiliar > vet[m2]) {
                    esq = m2 + 1;
                } 
                else {
                    esq = m1 + 1;
                    dir = m2 - 1;
                }
            }
        }

        for (int j = i; j > esq; j--) {
            *troc += 1;
            vet[j] = vet[j - 1];
        }

        vet[esq] = auxiliar;
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

    double temp1 = insercaoBinaria(v1, TAM, &troc1, &comp1);
    double temp2 = insercaoTernaria(v2, TAM, &troc2, &comp2);
    printf("-----Insercao Binaria-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc1, comp1, temp1);
    printf("-----Insercao Ternaria-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f", troc2, comp2, temp2);

    return 0;
}