#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap {
    int *v;
    int tamanho;
    int quantidade;
} Heap;

Heap *criaHeapVazio(int tam) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->v = (int *)malloc(tam * sizeof(int));
    h->tamanho = tam;
    h->quantidade = 0;
    return h;
}

void liberaHeap(Heap *h) {
    free(h->v);
    free(h);
}

int pai(int i) {
    return (i - 1) / 2;
}

int filhoDir(int i) {
    return 2 * i + 2;
}

int ultimoPai(Heap *h) {
    return (h->quantidade / 2) - 1;
}

void desceChave(Heap *h, int pai) {
    int maiorFilho, temp;
    int filho_esq = 2 * pai + 1;
    int filho_dir = 2 * pai + 2;

    if (filho_dir < h->quantidade && h->v[filho_dir] > h->v[filho_esq])
        maiorFilho = filho_dir;
    else
        maiorFilho = filho_esq;

    if (maiorFilho < h->quantidade && h->v[pai] < h->v[maiorFilho]) {
        temp = h->v[pai];
        h->v[pai] = h->v[maiorFilho];
        h->v[maiorFilho] = temp;
        desceChave(h, maiorFilho);
    }
}

void constroiHeap(Heap *h) {
    int i;
    for (i = ultimoPai(h); i >= 0; i--)
        desceChave(h, i);
}

void imprime(int *v, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    while (n != 0) {
        Heap *h = criaHeapVazio(n);
        
        for (i = 0; i < n; i++) {
            scanf("%d", &h->v[i]);
        }
        
        h->quantidade = n;
        
        constroiHeap(h);
        
        imprime(h->v, h->quantidade);
        
        liberaHeap(h);
        
        scanf("%d", &n);
    }
}
