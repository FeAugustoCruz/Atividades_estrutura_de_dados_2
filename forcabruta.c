#include <stdio.h>
#include <string.h>

int ForcaBruta(const char* texto, int n, const char* chave, int m){
    for(int i = 0; i < n - m; i ++){
        int j = 0;
        printf("%c ", texto[i + j]);
        while(j < m && (texto[i + j] == chave[j])){
            //printf("texto[i + j] = %c\nchave[j] = %c\n", texto[i + j], chave[j]);
            j++;
            if(j == m){
                return i;
            }
        }
    }
    return -1;
}


int main(void){
    printf("%d", ForcaBruta("abacaxi", 7, "axi", 3));



    return 0;
}