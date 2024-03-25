#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *prox;
} Item;

typedef struct tPilha {
    Item *topo;
    int quantidade;
} Pilha;

Pilha *criaPilhaVazia() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->quantidade = 0;
    return pilha;
}

Item *criaItem(int x) {
    Item *novo_item = (Item *)malloc(sizeof(Item));
    novo_item->chave = x;
    novo_item->prox = NULL;
    return novo_item;
}

void liberaPilha(Pilha *pilha) {
    Item *atual = pilha->topo;
    Item *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(pilha);
}

int vazia(Pilha *pilha) {
    return pilha->quantidade == 0;
}

void imprimir(Pilha *pilha) {
    Item *atual = pilha->topo;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

void empilha(Pilha *pilha, int x) {
    Item *novo_item = criaItem(x);
    novo_item->prox = pilha->topo;
    pilha->topo = novo_item;
    pilha->quantidade++;
}

int desempilha(Pilha *pilha) {
    if (!vazia(pilha)) {
        Item *topo = pilha->topo;
        int chave = topo->chave;
        pilha->topo = topo->prox;
        free(topo);
        pilha->quantidade--;
        return chave;
    }
    return -1;
}

int main() {
    Pilha *pilha = criaPilhaVazia();
    char op;
    int x;

    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'E':
                scanf("%d", &x);
                empilha(pilha, x);
                break;
            case 'D':
                if (!vazia(pilha)) {
                    printf("[%d]\n", desempilha(pilha));
                }
                break;
            case 'M':
                imprimir(pilha);
                break;
        }
    }

    liberaPilha(pilha);
}
