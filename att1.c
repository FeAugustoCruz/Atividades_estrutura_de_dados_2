#include <stdio.h>
#include <string.h>

int BuscaStringConst(const char *texto, const char *padrao) {
    int lenTexto = strlen(texto);
    int lenPadrao = strlen(padrao);

    if (lenPadrao > lenTexto) {
        return -2; // erro de tamanho
    }

    for (int i = 0; i <= lenTexto - lenPadrao; i++) {
        int j = 0;
        for (j = 0; j < lenPadrao; j++) {
            if (texto[i + j] != padrao[j]) {
                break;
            }
        }
        if (j == lenPadrao) {
            return i; // posição da ocorrência
        }
    }

    return -1; // não encontrada
}

int main(void){
    printf("%d",BuscaStringConst("abtestcef", "teste"));


    return 0;
}