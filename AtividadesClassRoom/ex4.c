#include <stdio.h>
#include <string.h>

#define MAXCHAR 256

int bmh(const char* texto, const char* chave){
    int textlen = strlen(texto);
    int chavelen = strlen(chave);


    char tabela[MAXCHAR];
    for(int j = 0; j < 255; j ++){
        tabela[j] = chavelen;
    }
    for(int j = 1; j < chavelen; j ++){
        tabela[chave[j-1]] = chavelen - j;
    }
   
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

int bmhcont(const char* texto, const char* chave){
    int textlen = strlen(texto);
    int chavelen = strlen(chave);
    int contOcorrencia = 0;


    char tabela[MAXCHAR];
    for(int j = 0; j < 255; j ++){
        tabela[j] = chavelen;
    }
    for(int j = 1; j < chavelen; j ++){
        tabela[chave[j-1]] = chavelen - j;
    }
    int i = chavelen;
    while(i <= textlen){
        int k = i;
        int j = chavelen;
        while(texto[k-1] == chave[j - 1] && j > 0){
            contOcorrencia++;
            k --;
            j --;
        }

        if(j == 0){
            return contOcorrencia;
        }
        i = i + tabela[texto[i - 1]];
    }
    return contOcorrencia;
}

int main(void){
    printf("[%d]\n", bmh("TOMADATOMADA", "TOMA"));
    printf("Total de ocorrencia: %d\n", bmhcont("TOMADATOMADA", "TOMA"));

    return 0;
}