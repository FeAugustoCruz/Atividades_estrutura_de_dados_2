#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalarMarge(int vet[], int ini, int meio, int fim, unsigned long* troc, unsigned long* compare){
    int i = ini;
    int j = meio + 1;
    int k = 0;

    int *tmp = (int*) malloc((fim - ini + 1) * sizeof(int));

    while (i <= meio || j <= fim) {
        *compare += 1;
        if (i == meio + 1){
            tmp[k++] = vet[j++];
            *troc += 1;
        }else if(j == fim + 1){
            tmp[k++] = vet[i++];
            *troc += 1;
        }else if(vet[j] < vet[i]){
            tmp[k++] = vet[j++];
            *troc += 1;
        }else{
            tmp[k++] = vet[i++];
            *troc += 1;
        }

    }

    for (i = ini, k = 0; i <= fim; i++, k++) {
        *troc += 1;
        vet[i] = tmp[k];
    }

    free(tmp);
}

double margeSort(int vet[], int ini, int fim, unsigned long* troc, unsigned long* compare){
    clock_t inicio, end;
    double temp;
    
    inicio = clock();
    int meio;
    
    if (ini < fim){  
        meio = (ini + fim)/2;
        margeSort(vet, ini, meio,troc, compare);
        margeSort(vet, meio + 1, fim, troc, compare);
        intercalarMarge(vet, ini, meio, fim, troc, compare) ;
    }
    end = clock();
    temp = (double)(end - inicio)/CLOCKS_PER_SEC;

    return temp;
}

int getMax(int vet[], int n){
    int max = vet[0];
    for (int i = 1; i < n; i++){
        if (vet[i] > max){
            max = vet[i];
        }
    }
    return max;
}

#define TAM 10000

int main(void){

    int v1[TAM];
    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        v1[i] = rand() % 50000;
    }

    unsigned long troc1;
    unsigned long comp1;

    double temp1 = margeSort(v1, 0, TAM, &troc1, &comp1);
    printf("-----Marge Sort-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc1, comp1, temp1);

    return 0;
}