#include <stdio.h>

void intercalar(int vet[], int ini, int meio, int fim){
    int i = ini;
    int j = meio + 1;
    int k = 0;
    int Tmp[fim - ini + 1];
    while((i <= meio) || (j <= fim)){
        if ((i == meio + 1) || ( (vet[j] < vet[i]) && (j != fim + 1) ) ){
            Tmp[k] = vet[j]; //vetor temporario
            j = j + 1;
            k = k + 1;
        }else{
            Tmp[k] = vet[i];
            i++;
            k++;
        }
    }

    for(i = ini; i <= fim; i++){
        vet[i] = Tmp[i - ini];
    }
}

void margeSort(int vet[], int ini, int fim){
    if(ini < fim){
        int meio = (ini + fim)/2;
        margeSort(vet, ini, meio);
        margeSort(vet, meio + 1, fim);
        intercalar(vet, ini, meio, fim);
    }

}

int main(void){
    int vetor[5] = {3,1,6,4,7};

    margeSort(vetor, 0, 5);

    for(int i = 0; i < 5; i ++){
        printf("[%d]", vetor[i]);
    }

    return 0;
}