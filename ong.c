#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char palavra[101];
    int contagem;
    struct Node *ant;
    struct Node *prox;
} Node;

typedef struct Lista {
    Node *inicio;
    Node *fim;
} Lista;

Lista *criaListaVazia() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

Node *criaNode(char *palavra) {
    Node *novo_node = (Node *)malloc(sizeof(Node));
    strcpy(novo_node->palavra, palavra);
    novo_node->contagem = 1;
    novo_node->ant = NULL;
    novo_node->prox = NULL;
    return novo_node;
}

void inserirPalavra(Lista *lista, char *palavra) {
    if (lista == NULL)
        return;

    Node *atual = lista->inicio;

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            atual->contagem++;

            while (atual->ant != NULL && atual->contagem > atual->ant->contagem) {
                Node *temp_ant = atual->ant;
                Node *temp_prox = atual->prox;

                if (temp_ant->ant != NULL)
                    temp_ant->ant->prox = atual;
                else
                    lista->inicio = atual;

                if (temp_prox != NULL)
                    temp_prox->ant = temp_ant;

                atual->ant = temp_ant->ant;
                temp_ant->prox = temp_prox;
                temp_ant->ant = atual;
                atual->prox = temp_ant;
            }

            return; 
        }
        atual = atual->prox;
    }

    Node *novo_node = criaNode(palavra);
    if (lista->inicio == NULL) {
        lista->inicio = novo_node;
        lista->fim = novo_node;
    } else {
        novo_node->ant = lista->fim;
        lista->fim->prox = novo_node;
        lista->fim = novo_node;
    }
}

void liberaLista(Lista *lista) {
    Node *atual = lista->inicio;
    while (atual != NULL) {
        Node *temp = atual->prox;
        free(atual);
        atual = temp;
    }
    free(lista);
}

void imprimirLista(Lista *lista) {
    Node *atual = lista->inicio;
    while (atual != NULL) {
        printf("%s [%d]\n", atual->palavra, atual->contagem);
        atual = atual->prox;
    }
}

int main() {
    Lista *lista = criaListaVazia();
    char palavra[101];

    while (scanf("%s", palavra) != EOF) {
        inserirPalavra(lista, palavra);
    }

    imprimirLista(lista);

    liberaLista(lista);
}
