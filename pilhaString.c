#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100

typedef struct tPilha {
    char **itens;
    int topo;
    int tamanho;
} Pilha;

Pilha *criaPilhaVazia(int tamanho) {
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    novaPilha->itens = (char **)malloc(tamanho * sizeof(char *));
    for (int i = 0; i < tamanho; i++) {
        novaPilha->itens[i] = (char *)malloc((MAX_STRING_SIZE + 1) * sizeof(char)); // +1 para o caractere nulo
    }
    novaPilha->topo = -1;
    novaPilha->tamanho = tamanho;
    return novaPilha;
}

void liberaPilha(Pilha *pilha) {
    for (int i = 0; i < pilha->tamanho; i++) {
        free(pilha->itens[i]);
    }
    free(pilha->itens);
    free(pilha);
}

bool cheia(Pilha *pilha) {
    return pilha->topo == pilha->tamanho - 1;
}

bool vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void empilha(Pilha *pilha, char *valor) {
    if (!cheia(pilha)) {
        strcpy(pilha->itens[++pilha->topo], valor);
    }
}

char *desempilha(Pilha *pilha) {
    if (!vazia(pilha)) {
        return pilha->itens[pilha->topo--];
    }
    return NULL; 
}

void imprimeTopo(Pilha *pilha) {
    if (!vazia(pilha)) {
        printf("%s\n", pilha->itens[pilha->topo]);
    }
}

void imprimeBase(Pilha *pilha, bool invertido) {
    if (invertido) {
        for (int i = pilha->topo; i >= 0; i--) {
            printf("%s", pilha->itens[i]);
            if (i > 0) {
                printf(" ");
            }
        }
    } else {
        for (int i = 0; i <= pilha->topo; i++) {
            printf("%s", pilha->itens[i]);
            if (i < pilha->topo) {
                printf(" ");
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    char op, valor[MAX_STRING_SIZE + 1];
    scanf("%d", &n);

    Pilha *pilha = criaPilhaVazia(n);

    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'E':
                scanf("%s", valor);
                empilha(pilha, valor);
                break;
            case 'D':
                desempilha(pilha);
                break;
            case 'T':
                imprimeTopo(pilha);
                break;
            case 'X':
                imprimeBase(pilha, true); 
                break;
            case 'B':
                imprimeBase(pilha, false); 
                break;
        }
    }

    liberaPilha(pilha);
}