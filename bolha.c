#include <stdio.h>


int* Bolha(int* vetorInt){
    int size = sizeof(vetorInt)/sizeof(int);
    int* novoVetor (int*)malloc(size);
    int auxiliar;

    for(int i = size - 1; i > 1; i--){
        for(int j = 0; j < i; j --){
            if(vetorInt[j] > vetorInt[j + 1]){
                auxiliar = vetorInt[j];
                vetorInt[j] = vetorInt[j + 1];
                vetorInt[j+1] = auxiliar;
            }
        }
    }

}

int main(void){
    int vetor[4] = {4,1,4,6};

    vetor = Bolha(vetor);

    for(int i = 0; i < sizeof(vetInt)/sizeof(int); i ++){
        printf("[%d]", vetor[i]);
    }


    return 0;
}