#include <stdio.h>
#include <string.h>

#define MAXCHAR 256

void bm(char *str, int size, int caractere[MAXCHAR]){
    int i;
    
    for(i = 0; i < MAXCHAR; i ++){
        caractere[i] = -1;
    }

    for (i = 0; i < size; i ++){
        caractere[(int) str[i]] = i;
    }

}

void pesquisa(char *txt, char *pat){
    int m = strlen(pat);
    int n = strlen(txt);

    int caractere[MAXCHAR];
    long long comparacao = 0;


    bm(pat,m,caractere);

    int s = 0;
    while(s <= (n - m)){

        int j = m - 1;
        while(j >= 0){
            comparacao++;
            if(pat[j] != txt[s + j]){
                break;
            }
            j--;
        }

        if(j < 0){
            printf("Chave encontrada na posicao: %d\n", s);
            s += (s + m < n) ? m - caractere[(int) txt[s + m]] : 1;
        }else{

            int shift = j - caractere[(int)txt[s + j]];
            if(shift < 1) shift = 1;
            s += shift;   
        }
    }

    printf("\nTotal de comparacoes realizadas: %lld\n", comparacao);
}

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

    char text[] = "TEXTO DE EXEMPLO PARA O TESTE DE BUSCA";
    char pat[] = "EXEMPLO";

    pesquisa(text, pat);

    return 0;
}