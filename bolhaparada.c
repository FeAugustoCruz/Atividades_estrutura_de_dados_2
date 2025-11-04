#include <stdio.h>
#include <stdbool.h>

void bolhaParada(int* vectorInt){
    int size = (sizeof(vectorInt)*sizeof(int))/sizeof(int);
    int indice = size - 1;
    bool mudou = true;


    while(mudou){
        int j = 1;
        mudou = false;
        //printf("TESTE-1 j = %d| size = %d \n", j, size);
        while(j < size){
            //printf("TESTE-2\n");
            if(vectorInt[j-1] > vectorInt[j]){
                //printf("TESTE-3\n");
                int auxiliar = vectorInt[j - 1];
                vectorInt[j - 1] = vectorInt[j];
                vectorInt[j] = auxiliar;
                mudou = true;
            }
            indice = j;
            j = j + 1;
        }
        size = indice;
    }
}

int main(void){
    int vetor[4] = {5, 1, 6, 8};

    bolhaParada(vetor);

    for(int i = 0; i < 4; i++){
        printf("[%d]", vetor[i]);
    }


    return 0;
}