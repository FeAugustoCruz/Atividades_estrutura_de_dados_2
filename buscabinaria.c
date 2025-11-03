#include <stdio.h>

#define LEN 10

int BuscaBinariaRec(int vet[], int v, int ini, int fim){
    int meio = (ini + fim)/2;
    
    if (ini > fim){
        return -1;
    }else if(vet[meio] == v){
        return meio;
    }
    else if(vet[meio] > v){
        return BuscaBinariaRec(vet, v, ini, meio - 1);
    }else{
        return BuscaBinariaRec(vet, v, meio + 1, fim);    
    }
}

int BuscaBinaria(int vet[], int v){
    int esq = 0;
    int dir = LEN - 1;

    for(int i = 0; esq < dir; i ++){
        int meio = (esq + dir)/2;
        printf("meio = %d\n", meio);
        if (v < vet[meio] ){
            dir = meio - 1;
        }else if (v > vet[meio]){
            esq = meio + 1;
        }else{
            return vet[meio];
        }
    }
    return -1;
}

int main(void){
    int valores[LEN] = {8,14,19,23,27,32,38,42,47,51};

    int valor = BuscaBinaria(valores, 32);


    printf("normal: %d\n", valor);

    //int valor2 = BuscaBinariaRec(valores, 3, 0, LEN-1);

    //printf("recursiva: %d\n", valor2);
    return 0;
}