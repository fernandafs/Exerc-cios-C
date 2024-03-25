#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *prox;
} Item;

typedef struct tFila {
    Item *inicio, *fim;
} Fila;

Fila *criaFilaVazia() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

Item *criaItem(int x) {
    Item *novo_item = (Item *)malloc(sizeof(Item));
    novo_item->chave = x;
    novo_item->prox = NULL;
    return novo_item;
}

void liberaFila(Fila *fila) {
    Item *atual = fila->inicio;
    Item *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(fila);
}

int vazia(Fila *fila) {
    return fila->inicio == NULL;
}

void imprimir(Fila *fila) {
    Item *atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

void enfileirar(Fila *fila, int x) {
    Item *novo_item = criaItem(x);
    if (vazia(fila)) {
        fila->inicio = fila->fim = novo_item;
    } else {
        fila->fim->prox = novo_item;
        fila->fim = novo_item;
    }
}

int desenfileirar(Fila *fila) {
    if (!vazia(fila)) {
        Item *removido = fila->inicio;
        int chave = removido->chave;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
        free(removido);
        return chave;
    }
    return -1;
}

int main() {
    Fila *fila = criaFilaVazia();
    char op;
    int x;

    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'E':
                scanf("%d", &x);
                enfileirar(fila, x);
                break;
            case 'D':
                if (!vazia(fila)) {
                    printf("<%d>\n", desenfileirar(fila));
                }
                break;
            case 'M':
                imprimir(fila);
                break;
        }
    }

    liberaFila(fila);
}
