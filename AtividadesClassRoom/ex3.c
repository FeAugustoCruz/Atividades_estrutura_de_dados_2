#include <stdio.h>
#include <string.h>

int buscaForcaBruta(char texto[], char padrao[], int *comparacoes) {
    int n = strlen(texto);
    int m = strlen(padrao);
    *comparacoes = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && ++(*comparacoes) && texto[i + j] == padrao[j]) {
            j++;
        }
        if (j == m) {
            return i; 
        }
    }
    return -1; 
}

void calculaLPS(char padrao[], int m, int lps[]) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < m) {
        if (padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int buscaKMP(char texto[], char padrao[], int *comparacoes) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int lps[m];
    *comparacoes = 0;

    calculaLPS(padrao, m, lps);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        (*comparacoes)++;
        if (texto[i] == padrao[j]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; 
        } else if (i < n && texto[i] != padrao[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1;
}

int main() {
    char texto[1000], padrao[100];
    int compFB = 0, compKMP = 0;
    int posFB, posKMP;

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // remove o \n

    printf("Digite o padrao (chave) a buscar: ");
    fgets(padrao, sizeof(padrao), stdin);
    padrao[strcspn(padrao, "\n")] = '\0'; // remove o \n

    posFB = buscaForcaBruta(texto, padrao, &compFB);
    posKMP = buscaKMP(texto, padrao, &compKMP);

    printf("\n===== RESULTADOS =====\n");
    if (posFB != -1)
        printf("Força Bruta: encontrou na posição %d (%d comparações)\n", posFB, compFB);
    else
        printf("Força Bruta: padrão não encontrado (%d comparações)\n", compFB);

    if (posKMP != -1)
        printf("KMP: encontrou na posição %d (%d comparações)\n", posKMP, compKMP);
    else
        printf("KMP: padrão não encontrado (%d comparações)\n", compKMP);

    return 0;
}