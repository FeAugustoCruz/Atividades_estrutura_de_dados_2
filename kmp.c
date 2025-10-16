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
    PreKMP(chave, chavelen, auxiliar);//pre-processa a chave vetor auxiliar preenchido
    
    for(int t = 0; t < chavelen; t ++){
        printf("[%d]", auxiliar[t]);
    }

    int k = -1;

    for(int i = 0; i < textlen ; i++){//responsável por percorrer o texto
        printf("======== %d loop ========\n", i);
        printf("int i = %d\nint k = %d\nchave[k + 1] = %c\ntexto[i] = %c\n", i, k, chave[k + 1], texto[i]);
        while(k > -1 && chave[k + 1] != texto[i]){
            printf("WHILE EXECULTADO....\n");
            k = auxiliar[k];//pula para a posição onde o caractere 'k' é pre-fixo   
        }            
        if(texto[i] == chave[k + 1]){//local onde se compara o texto com o padrão
            printf("IF EXECULTADO.....\n");
            k = k + 1;//código para passar para o próximo caractere da chave
        }
        if(k == chavelen - 1){//Caso k se iguale ao tamanho do padrão, retorne a posição atual no texto menos o tamanho da chave.
            printf("RETURN EXECULTADO....\n");
            return i - k;
        }
    }
    return -1;
}

int main(void){
    char texto[16] = "abacaabaccabacab";
    char chave[6] = "abacab";

    printf("\n\n\n\n==%d==", BuscaKMP(texto, 20, chave, 6));

    //int auxiliar[10];
    
    //PreKMP(texto, strlen(texto), auxiliar);

    /*for(int k = 0; k < 10; k ++){
        printf("[%d]", auxiliar[k]);
    }*/  


    return 0;
}