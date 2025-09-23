#include <stdio.h>

#define LEN 10

int BuscaBinariaRec(int vet[], int v, int esquerda, int direita){
    int esq = esquerda;
    int dir = direita;

    int meio = (esq + dir)/2;

    if (esq + dir){
        return -1;
    }else if(v = vet[meio]){
        return BuscaBinariaRec(vet, v, esq, dir);
    }else{
        
    }

    if (v < vet[meio] ){
        dir = meio - 1;
        BuscaBinariaRec(vet, v, esq, dir);
    }else if (v > vet[meio]){
        esq = meio + 1;
        BuscaBinariaRec(vet, v, esq, dir);
    }else{
        return vet[meio];
    }
    return -1;
}

int BuscaBinaria(int vet[], int v){
    int esq = 0;
    int dir = LEN - 1;

    for(int i = 0; esq < dir; i ++){
        int meio = (esq + dir)/2;
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
    int valores[LEN] = {1,2,3,4,5,6,7,8,9,10};

    int valor = BuscaBinaria(valores, 5);


    printf("normal: %d\n", valor);

    int valor2 = BuscaBinariaRec(valores, 3, 0, LEN-1);

    printf("recursiva: %d\n", valor2);
    return 0;
}