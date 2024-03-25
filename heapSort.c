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
    return (2 * i) + 2;
}

int ultimoPai(Heap *h) {
    return (h->quantidade / 2) - 1;
}

void peneirar(Heap *h, int pai) {
    int filhoMax;
    int temp = h->v[pai];
    while (1) {
        int filhoEsq = 2 * pai + 1;
        int filhoDir = 2 * pai + 2;

        if (filhoDir < h->quantidade && h->v[filhoDir] > h->v[filhoEsq]) {
            filhoMax = filhoDir;
        } else {
            filhoMax = filhoEsq;
        }

        if (filhoMax >= h->quantidade || temp >= h->v[filhoMax]) {
            break;
        }

        h->v[pai] = h->v[filhoMax];
        pai = filhoMax;
    }
    h->v[pai] = temp;
}

void constroiHeap(Heap *h) {
    int ultimo = ultimoPai(h);
    for (int i = ultimo; i >= 0; i--) {
        peneirar(h, i);
    }
}

void imprime(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

void imprime_one(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void heapSort(Heap *h) {
    constroiHeap(h);
    if (h->quantidade > 0) {
        imprime_one(h->v, h->quantidade);
    }

    int elementos_removidos[h->quantidade];
    int indice_elementos_removidos = 0;
    for (int i = h->quantidade - 1; i > 0; i--) {
        int temp = h->v[0];
        h->v[0] = h->v[i];
        h->v[i] = temp;
        h->quantidade--;
        peneirar(h, 0);

        imprime(h->v, h->quantidade);

       elementos_removidos[indice_elementos_removidos++] = temp;
        for (int j = indice_elementos_removidos - 1; j > 0 && elementos_removidos[j] < elementos_removidos[j - 1]; j--) {
            int temp2 = elementos_removidos[j];
            elementos_removidos[j] = elementos_removidos[j - 1];
            elementos_removidos[j - 1] = temp2;
        }

        for (int j = 0; j < indice_elementos_removidos; j++) {
            printf("%d ", elementos_removidos[j]);
        }
        printf("\n");
    }
}


int main() {
    int n;
    scanf("%d", &n);
    Heap *h = criaHeapVazio(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h->v[i]);
        h->quantidade++;
    }
    heapSort(h);
    liberaHeap(h);
}
