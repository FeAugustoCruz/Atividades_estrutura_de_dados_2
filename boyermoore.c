#include <stdio.h>
#include <string.h>

int bmh(const char* texto, int textlen, const char* chave, int chavelen){
    char tabela[255];//inicializando uma tabela ascii
    for(int j = 0; j < 255; j ++){
        tabela[j] = chavelen;
    }
    for(int j = 1; j < chavelen; j ++){
        tabela[chave[j-1]] = chavelen - j;//bota em cada posição da chave na tabela ascii sua posição correspondente na chave
    }
    /*for(int k = 0; k < 255; k++){
        printf("%d\n", tabela[k]);
    }*/
    int i = chavelen;
    while(i <= textlen){
        int k = i;
        int j = chavelen;
        while(texto[k-1] == chave[j - 1] && j > 0){
            k --;
            j --;
        }

        if(j == 0){
            return k + 1;
        }
        i = i + tabela[texto[i - 1]];
    }
    return -1;
}

int main(void){
    printf("[%d]\n", bmh("TOMADATOMADA", strlen("TOMADATOMADA"), "TOMA", strlen("TOMA")));

    return 0;
}