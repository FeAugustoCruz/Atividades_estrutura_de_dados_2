#include <stdio.h>
#include <string.h>
#include <time.h>

int ForcaBruta(const char* texto, int n, const char* chave, int m){
    int contador = 0;
    for(int i = 0; i <= n - m; i ++){
        int j = 0;
        //printf("%c ", texto[i + j]);
        while(j < m && (texto[i + j] == chave[j])){
            contador ++;
            j++;
            if(j == m){
                printf("Total C = %d\n", contador);
                return i;
            }
        }
        contador ++;
    }
    printf("Total C = %d\n", contador);
    return -1;
}


int main(void){
    clock_t start, end;
    start = clock();
    printf("%d\n", ForcaBruta("dddddddddddddddddddddddddddddddddddddddddddddddddddddddde", strlen("dddddddddddddddddddddddddddddddddddddddddddddddddddddddde"), "dddddddddddde", strlen("dddddddddddde")));
    end = clock();

    printf("Tempo de execulcao: %f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);


    return 0;
}