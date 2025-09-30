#include <stdio.h>
#include <string.h>


int ForcaBruta(const char* t, int n, const char* p, int m){
    for(int i = 0; (n - m) > i; i++){
        int j =0;
        while(j < m && (t[i+j] == p[j])){
            j += 1;
            if(j == m){
                return i;
            }
        }
    }

    return 0;
}

int main(void){
    printf("-> %d", ForcaBruta("teste", 5, "st4", 3));


    return 0;
}