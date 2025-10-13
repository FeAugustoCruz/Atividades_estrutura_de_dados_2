#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BuscaBinariRec(int vet[], int v, int ini, int fim){
    int meio = (ini + fim)/2;
    if(ini > fim){
        return -1;
    }
    else if(vet[meio] == v){
        return meio;
    }
    else if (vet[meio] > v){
        return BuscaBinariRec(vet, v, ini, meio - 1);
    }else{
        return BuscaBinariRec(vet, v, meio + 1, fim);
    }
}

int BuscaBinaria(int vet[], int v){
    int esq = 0;
    int dir = 500 - 1;

    for(int i = 0; esq < dir; i ++){
        int meio = (esq + dir)/2;
        if(v < vet[meio]){
            dir = meio - 1;
        }else if(v > vet[meio]){
            esq = meio + 1;
        }else{
            return vet[meio];
        }
    }
    return -1;
}

int main(void){
    clock_t start, end;
    getchar();

    FILE * arq;
    int vetor[500];
    int n = 0;    
    int chave, contador = 0;

    arq = fopen("entrada.txt", "r");
    if(arq == NULL){
        printf("Não foi possivel abrir o arquivo!\n");
    }

    while(fscanf(arq, "%d", &vetor[n]) == 1){
        n++;
    }
    fclose(arq);

    end = clock();

    printf("Total: %d lidos\n", n);

    printf("Digite a chave de busca: ");
    scanf("%d", &chave);

    start = clock();
    //int valor = BuscaBinariRec(vetor, chave, 0, 500);
    int valor = BuscaBinaria(vetor, chave);
    end = clock();

    printf("O valor %d\n", valor);

    printf("Velocidade de leitura do arquivo: %f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}