#include <stdio.h>
#include <stdlib.h>

#define TAM_HASH 11

typedef struct {
    int chave;
    int ocupado;
} Elemento;

void inicializarAberto(Elemento tabela[]) {
    for (int i = 0; i < TAM_HASH; i++) tabela[i].ocupado = 0;
}

int hash(int chave) { return chave % TAM_HASH; }

void inserirAberto(Elemento tabela[], int chave) {
    int pos = hash(chave);
    while (tabela[pos].ocupado && tabela[pos].chave != chave) {
        pos = (pos + 1) % TAM_HASH;
    }
    tabela[pos].chave = chave;
    tabela[pos].ocupado = 1;
}

void imprimirAberto(Elemento tabela[]) {
    printf("--- HASH: ENDEREÇAMENTO ABERTO ---\n");
    for (int i = 0; i < TAM_HASH; i++) {
        if (tabela[i].ocupado) printf("[%d]: %d\n", i, tabela[i].chave);
        else printf("[%d]: Vazio\n", i);
    }
}

typedef struct No {
    int chave;
    struct No *prox;
} No;

void inicializarEncadeado(No *tabela[]) {
    for (int i = 0; i < TAM_HASH; i++) tabela[i] = NULL;
}

void inserirEncadeado(No *tabela[], int chave) {
    int pos = hash(chave);
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->prox = tabela[pos]; 
    tabela[pos] = novo;
}

void imprimirEncadeado(No *tabela[]) {
    printf("\n--- HASH: ENCADEAMENTO SEPARADO ---\n");
    for (int i = 0; i < TAM_HASH; i++) {
        printf("[%d]: ", i);
        No *atual = tabela[i];
        while (atual) {
            printf("%d -> ", atual->chave);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}

int main(void) {
    Elemento tabAberto[TAM_HASH];
    inicializarAberto(tabAberto);
    
    No *tabEncadeado[TAM_HASH];
    inicializarEncadeado(tabEncadeado);

    int valores[] = {12, 23, 34, 45, 1, 12};
    for (int i = 0; i < 6; i++) {
        inserirAberto(tabAberto, valores[i]);
        inserirEncadeado(tabEncadeado, valores[i]);
    }

    imprimirAberto(tabAberto);
    imprimirEncadeado(tabEncadeado);

    return 0;
}