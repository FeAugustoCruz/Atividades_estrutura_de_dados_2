#include <stdio.h>

int main() {
    FILE *arquivo;
    int vetor[1000]; 
    int n = 0;      
    int chave, contador = 0;
    int indices[1000];

    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    while (fscanf(arquivo, "%d", &vetor[n]) == 1) {
        n++;
    }
    fclose(arquivo);

    printf("Foram lidos %d números do arquivo.\n", n);

    printf("Digite a chave de busca: ");
    scanf("%d", &chave);

    for (int i = 0; i < n; i++) {
        if (vetor[i] == chave) {
            indices[contador] = i;
            contador++;
        }
    }

    if (contador == 0) {
        printf("Chave %d não encontrada.\n", chave);
    } else {
        printf("Chave %d encontrada %d vez(es) nos índices: ", chave, contador);
        for (int i = 0; i < contador; i++) {
            printf("%d ", indices[i]);
        }
        printf("\n");
    }

    return 0;
}