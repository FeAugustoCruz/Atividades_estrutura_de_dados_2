#include <stdio.h>
#include <string.h>

void PreKMP(const char* padrao, int padraolen, int aux[]){
    int i = 1;
    int j = -1;
    aux[0] = j; 
    for(i = 1; i <= padraolen - 1; i ++){
        printf("======== %d loop ========\n", i);
        printf("int i = %d\nint j = %d\npadrao[j+1] = %c\npadrao[i] = %c\n",i,j,padrao[j+1],padrao[i]);
        while(j > -1 && padrao[j + 1] != padrao[i]){
            printf("WHILE EXECULTADO...\n");
            j = aux[j];
        }
        if(padrao[i] == padrao[j + 1]){
                printf("IF EXECULTADO...\n");
                j ++;
        }
        aux[i] = j;
        printf("aux[i] = %d\n", aux[i]);
    }
    return;
}

int BuscaKMP(const char* texto, int textlen, const char* chave, int chavelen){
    int auxiliar[chavelen];
    PreKMP(chave, chavelen, auxiliar);//pre-processa a chave 
    
    for(int t = 0; t < chavelen; t ++){
        printf("[%d]", auxiliar[t]);
    }

    int k = -1;

    for(int i = 0;i <= textlen - 1; i++){
        while(k > -1 && texto[k + 1] != chave[i]){
            k = auxiliar[k];
        }            
        if(texto[i] == chave[k + 1]){
            k = k + 1;
        }
        if(k = chavelen - 1){
            return i - k;
        }
    }
    return -1;
}

int main(void){
    char texto[10] = "AMORDEROMA";
    char chave[3] = "ROM";

    BuscaKMP(texto, 10, chave, 3);

    //int auxiliar[10];
    
    //PreKMP(texto, strlen(texto), auxiliar);

    /*for(int k = 0; k < 10; k ++){
        printf("[%d]", auxiliar[k]);
    }*/  


    return 0;
}