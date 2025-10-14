#include <stdio.h>
#include <string.h>

void PreKMP(const char* padrao, int m, int aux[]){
    int i = 1;
    int j = -1;
    aux[0] = j; 
    for(i = 1; i <= m - 1; i ++){
        //printf("======== %d loop ========\n", i);
        //printf("int i = %d\nint j = %d\npadrao[j+1] = %c\npadrao[i] = %c\n",i,j,padrao[j+1],padrao[i]);
        while(j > -1 && padrao[j + 1] != padrao[i]){
            //printf("WHILE EXECULTADO...\n");
            j = aux[j];
        }
        if(padrao[i] == padrao[j + 1]){
                //printf("IF EXECULTADO...\n");
                j ++;
        }
        aux[i] = j;
        //printf("aux[i] = %d\n", aux[i]);
    }
    return;
}

int BuscaKMP(){

}

int main(void){
    char texto[10] = "AMORDEROMA";
    int auxiliar[10];
    
    PreKMP(texto, strlen(texto), auxiliar);

    /*for(int k = 0; k < 10; k ++){
        printf("[%d]", auxiliar[k]);
    }*/  


    return 0;
}