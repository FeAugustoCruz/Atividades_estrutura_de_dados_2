#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int calculoMediana(int vet[], int esq, int dir){
    int meio = (esq + dir)/2;
    int aux = 0;

    if(vet[esq] > vet[meio]){
        aux = vet[esq];
        vet[esq] = vet[meio];
        vet[meio] = aux;
    }

    if(vet[meio] > vet[dir]){
        aux = vet[meio];
        vet[meio] = vet[dir];
        vet[dir] = aux;
    }

    if(vet[meio] < vet[esq]){
        aux = vet[esq];
        vet[esq] = vet[meio];
        vet[meio] = aux;
    }

    return vet[meio];
}

void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo, unsigned long* troc, unsigned long* compare){
    int pivo, aux;
    *i = esq;
    *j = dir;

    switch (posiPivo)
    {
    //pivo = 1 (centro)
    case 1:
        pivo = dados[(esq + dir)/2];
        break;
    //pivo = 2 (último) -> POSSÍVEL PIOR CASO O(n^2)
    case 2:
        pivo = dados[dir];
        break;
    case 3:
    //pivo = 3 (mediana)
        pivo = calculoMediana(dados, esq, dir);
        break;
    default:
        break;
    }

    while(*i <= *j){

        while(*i < dir){
            *compare += 1;
            if (dados[*i] < pivo ){
                (*i)++;
            }
            else{
                break;
            }
        }

        while(*j > esq){
            *compare += 1;
            if(dados[*j] > pivo){
                (*j)--;
            }else{
                break;
            }
        }

        if(*i <= *j){
            *troc += 1;
            aux = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

double quickSortCentro(int vet[], int esq, int dir, unsigned long* troc, unsigned long* compare){
    clock_t inicio, fim;
    double temp;

    inicio = clock();

    while (esq < dir) {
        int i, j;
        particaoQuick(vet, esq, dir, &i, &j, 1, troc, compare);

        if (j - esq < dir - i) {
            if (j > esq) quickSortCentro(vet, esq, j, troc, compare);
            esq = i;
        } else {
            if (i < dir) quickSortCentro(vet, i, dir, troc, compare);
            dir = j;
        }
    }

    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double quickSortFim(int vet[], int esq, int dir, unsigned long* troc, unsigned long* compare){ 
    clock_t inicio, fim;
    double temp;

    inicio = clock();

    while (esq < dir) {
        int i, j;
        particaoQuick(vet, esq, dir, &i, &j, 2, troc, compare);

        if (j - esq < dir - i) {
            if (j > esq) quickSortFim(vet, esq, j, troc, compare);
            esq = i;
        } else {
            if (i < dir) quickSortFim(vet, i, dir, troc, compare);
            dir = j;
        }
    }

    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double quickSortMediana(int vet[], int esq, int dir, unsigned long* troc, unsigned long* compare){ 
    clock_t inicio, fim;
    double temp;

    inicio = clock();

    while (esq < dir) {
        int i, j;
        particaoQuick(vet, esq, dir, &i, &j, 3, troc, compare);

        if (j - esq < dir - i) {
            if (j > esq) quickSortMediana(vet, esq, j, troc, compare);
            esq = i;
        } else {
            if (i < dir) quickSortMediana(vet, i, dir, troc, compare);
            dir = j;
        }
    }

    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

#define TAM 10000

int main(void){

    int v1[TAM], v2[TAM], v3[TAM];
    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        v1[i] = rand() % 50000;
        v2[i] = v1[i]; // Mesmos dados para comparação justa
        v3[i] = v1[i];
    }

    unsigned long troc1, troc2, troc3;
    unsigned long comp1, comp2, comp3;

    double temp1 = quickSortCentro(v1, 0, TAM, &troc1, &comp1);
    double temp2 = quickSortFim(v2, 0, TAM, &troc2, &comp2);
    double temp3 = quickSortMediana(v3, 0, TAM, &troc3, &comp3);
    printf("-----Quick Sort Centro-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc1, comp1, temp1);
    printf("-----Quick Sort Fim-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc2, comp2, temp2);
    printf("-----Quick Sort Mediana-----\n");
    printf("Trocas: %lu\nComparacoes: %lu\nTempo: %.4f\n", troc3, comp3, temp3);

    return 0;
}