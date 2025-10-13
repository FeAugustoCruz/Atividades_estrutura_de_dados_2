#include <stdio.h>
#include <string.h>

void PreKMP(const char* padrao, int m, int aux[]){
    int i = 1;
    int j = -1;
    aux[0] = j;
    for(i = 1; i < m - 1; i ++){
        while(j > -1 && padrao[j + 1] != padrao[i]){
            j = aux[j];
        }
        if(padrao[i] == padrao[j + 1]){
                j ++;
        }
        aux[i] = j;
    }
    return;
}

int main(void){
    int auxiliar[10];
    PreKMP("SUSSALVA!", strlen("SUSSALVA!"), auxiliar);
    for(int k = 0; k < 10; k ++){
        printf("[%d]", auxiliar[k]);
    }   


    return 0;
}