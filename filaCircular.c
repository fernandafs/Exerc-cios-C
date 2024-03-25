#include <stdio.h>
#include <stdlib.h>

typedef struct tFilaCircular {
    int *itens;       
    int inicio, fim;  
    int tamanho;      
} FilaCircular;

FilaCircular *criaFilaCircularVazia(int tamanho) {
    FilaCircular *fila = (FilaCircular *)malloc(sizeof(FilaCircular));
    fila->itens = (int *)malloc(tamanho * sizeof(int));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = tamanho;
    return fila;
}

void liberaFilaCircular(FilaCircular *fila) {
    free(fila->itens);
    free(fila);
}

int cheia(FilaCircular *fila) {
    return ((fila->fim + 1) % fila->tamanho == fila->inicio);
}

int vazia(FilaCircular *fila) {
    return (fila->inicio == fila->fim);
}

void enfileirar(FilaCircular *fila, int x) {
    if (!cheia(fila)) {
        fila->itens[fila->fim] = x;
        fila->fim = (fila->fim + 1) % fila->tamanho;
    }
}

int desenfileirar(FilaCircular *fila) {
    int valor = -1;
    if (!vazia(fila)) {
        valor = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
    }
    return valor;
}

int main() {
    int tamanho;
    char op;
    int x;
    
    scanf("%d", &tamanho);
    FilaCircular *fila = criaFilaCircularVazia(tamanho);

    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'E':
                scanf("%d", &x);
                enfileirar(fila, x);
                break;
            case 'D':
                x = desenfileirar(fila);
                if (x != -1) {
                    printf("%d\n", x);
                }
                break;
        }
    }

    liberaFilaCircular(fila);
}
