#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *ant, *prox;
} Item;

typedef struct tLista {
    Item *primeiro, *ultimo;
    int quantidade;
} Lista;

Lista *criaListaVazia() {
    
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->primeiro = lista->ultimo = NULL;
    lista->quantidade = 0;
    
    return lista;
}

Item *criaItem(int x) {
    
    Item *novo_item = (Item *)malloc(sizeof(Item));
    novo_item->chave = x;
    novo_item->ant = novo_item->prox = NULL;
    
    return novo_item;
}

void liberaLista(Lista *lista) {
    Item *atual = lista->primeiro;
    Item *proximo;
    
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    
    free(lista);
}

int vazia(Lista *lista) {
    
    return lista->primeiro == NULL;
}

void imprimir(Lista *lista) {
    Item *atual = lista->primeiro;
    
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    
    printf("\n");
}

void imprimirReverso(Lista *lista) {
    Item *atual = lista->ultimo;
    
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->ant;
    }
    
    printf("\n");
}

void inserir(Lista *lista, int x) {
    Item *novo_item = criaItem(x);
    
    if (vazia(lista)) {
        lista->primeiro = lista->ultimo = novo_item;
    } 
    else if (lista->primeiro->chave >= x) {
        novo_item->prox = lista->primeiro;
        lista->primeiro->ant = novo_item;
        lista->primeiro = novo_item;
    } 
    else if (lista->ultimo->chave <= x) {
        novo_item->ant = lista->ultimo;
        lista->ultimo->prox = novo_item;
        lista->ultimo = novo_item;
    } 
    else {
        Item *atual = lista->primeiro;
        
        while (atual->prox != NULL && atual->prox->chave < x) {
            atual = atual->prox;
        }
        
        novo_item->prox = atual->prox;
        novo_item->ant = atual;
        if (atual->prox != NULL) {
            atual->prox->ant = novo_item;
        }
        
        atual->prox = novo_item;
    }
    
    lista->quantidade++;
}

void remover(Lista *lista, int x) {
    if (!vazia(lista)) {
        Item *atual = lista->primeiro;
        while (atual != NULL && atual->chave != x) {
            atual = atual->prox;
        }
        if (atual != NULL) {
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox;
            } 
            else {
                lista->primeiro = atual->prox;
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            } 
            else {
                lista->ultimo = atual->ant;
            }
            free(atual);
            lista->quantidade--;
        }
    }
}

int main() {
    Lista *lista = criaListaVazia();
    char op;
    int x;

    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'I':
                scanf("%d", &x);
                inserir(lista, x);
                break;
            case 'E':
                scanf("%d", &x);
                remover(lista, x);
                break;
            case 'M':
                imprimir(lista);
                printf("\n");
                break;
            case 'R':
                imprimirReverso(lista);
                printf("\n");
                break;
        }
    }

    liberaLista(lista);
}
