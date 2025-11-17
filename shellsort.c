#include <stdio.h>

void shellSort(int vetor[], int len){     
    int h = 1;
    while(h < len){
        h = 3*h + 1;
    }
    while(h > 1){
        for(int i = h; i < n; i ++){
            int auxiliar = vetor[i];
            int j = i - h;
        }
    }
    printf("len: %d", len);
}


int main(void){
    int vetor[4] = {5,2,7,1};
    int n = sizeof(vetor)/sizeof(int);
    shellSort(vetor);

    return 0;
}