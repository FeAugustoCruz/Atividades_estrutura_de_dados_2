#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PatriciaNode {
    int bitIndex;
    char *key;
    struct PatriciaNode *left;
    struct PatriciaNode *right;
} PatriciaNode;

PatriciaNode *createNode(const char *key, int bitIndex) {
    PatriciaNode *node = (PatriciaNode *)malloc(sizeof(PatriciaNode));
    node->key = strdup(key);
    node->bitIndex = bitIndex;
    node->left = node->right = NULL;
    return node;
}

int bit(const char *key, int i) {
    int byteIndex = i / 8;
    int bitIndex = 7 - (i % 8);
    if (byteIndex >= strlen(key))
        return 0;
    return (key[byteIndex] >> bitIndex) & 1;
}

PatriciaNode *search(PatriciaNode *root, const char *key) {
    if (!root)
        return NULL;

    PatriciaNode *current = root;
    PatriciaNode *next = root->left;

    while (next->bitIndex > current->bitIndex) {
        current = next;
        next = bit(key, next->bitIndex) ? next->right : next->left;
    }

    if (strcmp(next->key, key) == 0)
        return next;
    else
        return NULL;
}

int firstDifferentBit(const char *a, const char *b) {
    int i = 0;
    while (bit(a, i) == bit(b, i) && (bit(a, i) != 0 || bit(b, i) != 0))
        i++;
    return i;
}

PatriciaNode *insert(PatriciaNode *root, const char *key) {
    if (!root) {
        root = createNode(key, -1);
        root->left = root;
        return root;
    }

    PatriciaNode *current = root;
    PatriciaNode *next = root->left;

    while (next->bitIndex > current->bitIndex) {
        current = next;
        next = bit(key, next->bitIndex) ? next->right : next->left;
    }

    if (strcmp(next->key, key) == 0) {
        printf("Chave '%s' já existe.\n", key);
        return root;
    }

    int i = firstDifferentBit(key, next->key);
    current = root;
    PatriciaNode *parent = NULL;

    do {
        parent = current;
        current = bit(key, current->bitIndex) ? current->right : current->left;
    } while (current->bitIndex > parent->bitIndex && current->bitIndex < i);

    PatriciaNode *newNode = createNode(key, i);
    newNode->left = bit(key, i) ? current : newNode;
    newNode->right = bit(key, i) ? newNode : current;

    if (bit(key, parent->bitIndex))
        parent->right = newNode;
    else
        parent->left = newNode;

    return root;
}

PatriciaNode *deleteKey(PatriciaNode *root, const char *key) {
    if (!root)
        return NULL;

    PatriciaNode *parent = root;
    PatriciaNode *current = root->left;
    PatriciaNode *grandParent = NULL;

    while (current->bitIndex > parent->bitIndex) {
        grandParent = parent;
        parent = current;
        current = bit(key, current->bitIndex) ? current->right : current->left;
    }

    if (strcmp(current->key, key) != 0) {
        printf("Chave '%s' não encontrada.\n", key);
        return root;
    }

    if (current == parent) {
        free(current->key);
        free(current);
        return NULL;
    }

    free(parent->key);
    parent->key = strdup(current->key);

    PatriciaNode *child = bit(key, current->bitIndex) ? current->left : current->right;
    if (bit(key, parent->bitIndex))
        grandParent->right = child;
    else
        grandParent->left = child;

    free(current->key);
    free(current);

    return root;
}


void printPatricia(PatriciaNode *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("   ");
    printf("-> [%d] %s\n", node->bitIndex, node->key ? node->key : "(null)");
    if (node->left != node && node->right != node) {
        printPatricia(node->left, level + 1);
        printPatricia(node->right, level + 1);
    }
}


int main() {
    PatriciaNode *root = NULL;

    root = insert(root, "casa");
    root = insert(root, "casamento");
    root = insert(root, "carro");
    root = insert(root, "cachorro");

    printf("\n--- Árvore Patricia ---\n");
    printPatricia(root, 0);

    printf("\nBusca por 'carro': %s\n", search(root, "carro") ? "Encontrado" : "Não encontrado");
    printf("Busca por 'cavalo': %s\n", search(root, "cavalo") ? "Encontrado" : "Não encontrado");

    root = deleteKey(root, "carro");
    printf("\nApós remover 'carro':\n");
    printPatricia(root, 0);

    return 0;
}