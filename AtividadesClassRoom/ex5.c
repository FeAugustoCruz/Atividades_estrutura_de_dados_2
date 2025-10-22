#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALFABETO 26  // considerando apenas letras minúsculas de 'a' a 'z'

// ===============================
// Estrutura do nó da Trie
// ===============================
typedef struct TrieNode {
    struct TrieNode *filhos[ALFABETO];
    bool fimDePalavra; // indica se é o fim de uma palavra
} TrieNode;

// ===============================
// Função para criar um novo nó
// ===============================
TrieNode* criaNo() {
    TrieNode *no = (TrieNode*) malloc(sizeof(TrieNode));
    no->fimDePalavra = false;
    for (int i = 0; i < ALFABETO; i++)
        no->filhos[i] = NULL;
    return no;
}

// ===============================
// Inserção de palavra na Trie
// ===============================
void insere(TrieNode *raiz, const char *palavra) {
    TrieNode *atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filhos[indice] == NULL)
            atual->filhos[indice] = criaNo();
        atual = atual->filhos[indice];
    }
    atual->fimDePalavra = true;
}

// ===============================
// Busca de palavra na Trie
// ===============================
bool busca(TrieNode *raiz, const char *palavra) {
    TrieNode *atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filhos[indice] == NULL)
            return false; // caminho não encontrado
        atual = atual->filhos[indice];
    }
    return atual != NULL && atual->fimDePalavra;
}

// ===============================
// Função auxiliar: verifica se um nó tem filhos
// ===============================
bool temFilhos(TrieNode *no) {
    for (int i = 0; i < ALFABETO; i++)
        if (no->filhos[i] != NULL)
            return true;
    return false;
}

// ===============================
// Exclusão de palavra da Trie
// ===============================
// Retorna true se o nó deve ser apagado
bool removePalavra(TrieNode *no, const char *palavra, int profundidade) {
    if (no == NULL)
        return false;

    // Caso base: fim da palavra
    if (palavra[profundidade] == '\0') {
        // se a palavra existe, marca como não final
        if (no->fimDePalavra)
            no->fimDePalavra = false;

        // se o nó não tem filhos, pode ser removido
        return !temFilhos(no);
    }

    int indice = palavra[profundidade] - 'a';
    if (removePalavra(no->filhos[indice], palavra, profundidade + 1)) {
        // libera memória do filho
        free(no->filhos[indice]);
        no->filhos[indice] = NULL;

        return (!no->fimDePalavra && !temFilhos(no));
    }
    return false;
}

// ===============================
// Programa principal
// ===============================
int main() {
    TrieNode *raiz = criaNo();

    insere(raiz, "casa");
    insere(raiz, "carro");
    insere(raiz, "cachorro");

    printf("Busca por 'casa': %s\n", busca(raiz, "casa") ? "Encontrada" : "Nao encontrada");
    printf("Busca por 'carro': %s\n", busca(raiz, "carro") ? "Encontrada" : "Nao encontrada");
    printf("Busca por 'gato': %s\n", busca(raiz, "gato") ? "Encontrada" : "Nao encontrada");

    printf("\nRemovendo 'carro'...\n");
    removePalavra(raiz, "carro", 0);

    printf("Busca por 'carro' apos remocao: %s\n", busca(raiz, "carro") ? "Encontrada" : "Nao encontrada");
    printf("Busca por 'cachorro' apos remocao de 'carro': %s\n", busca(raiz, "cachorro") ? "Encontrada" : "Nao encontrada");

    return 0;
}