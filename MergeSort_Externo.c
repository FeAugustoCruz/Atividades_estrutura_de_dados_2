#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int criarBlocosOrdenados(char *arquivoInput, int tamBloco) {
    FILE *in = fopen(arquivoInput, "r");
    if (!in) return 0;

    int *buffer = (int*)malloc(tamBloco * sizeof(int));
    int numArquivos = 0;
    int lidos, continuar = 1;

    while (continuar) {
        lidos = 0;
        for (int i = 0; i < tamBloco; i++) {
            if (fscanf(in, "%d", &buffer[i]) != 1) {
                continuar = 0;
                break;
            }
            lidos++;
        }

        if (lidos > 0) {
            qsort(buffer, lidos, sizeof(int), comparar);
            char nomeBloco[20];
            sprintf(nomeBloco, "bloco%d.txt", numArquivos++);
            FILE *out = fopen(nomeBloco, "w");
            for (int i = 0; i < lidos; i++) fprintf(out, "%d ", buffer[i]);
            fclose(out);
        }
    }

    free(buffer);
    fclose(in);
    return numArquivos;
}

void intercalarArquivos(int numArquivos, char *arquivoOutput) {
    FILE *out = fopen(arquivoOutput, "w");
    FILE *blocos[numArquivos];
    int valores[numArquivos];
    int ativos[numArquivos];

    for (int i = 0; i < numArquivos; i++) {
        char nome[20];
        sprintf(nome, "bloco%d.txt", i);
        blocos[i] = fopen(nome, "r");
        if (fscanf(blocos[i], "%d", &valores[i]) == 1) ativos[i] = 1;
        else ativos[i] = 0;
    }

    while (1) {
        int min = -1;
        for (int i = 0; i < numArquivos; i++) {
            if (ativos[i]) {
                if (min == -1 || valores[i] < valores[min]) min = i;
            }
        }

        if (min == -1) break;

        fprintf(out, "%d ", valores[min]);
        if (fscanf(blocos[min], "%d", &valores[min]) != 1) ativos[min] = 0;
    }

    for (int i = 0; i < numArquivos; i++) fclose(blocos[i]);
    fclose(out);
}

int main() {
    int tamMemoria;
    char *entrada = "dados.txt";
    char *saida = "ordenado.txt";

    FILE *f = fopen(entrada, "w");
    srand(time(NULL));
    for (int i = 0; i < 100; i++) fprintf(f, "%d ", rand() % 1000);
    fclose(f);

    printf("Arquivo 'dados.txt' gerado.\n");
    printf("Digite o tamanho do bloco de memoria principal (ex: 10): ");
    scanf("%d", &tamMemoria);

    int numBlocos = criarBlocosOrdenados(entrada, tamMemoria);
    printf("Criados %d blocos ordenados temporarios.\n", numBlocos);

    intercalarArquivos(numBlocos, saida);
    printf("Ordenacao concluida! Verifique 'ordenado.txt'.\n");

    return 0;
}
