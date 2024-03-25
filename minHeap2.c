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
    int menorFilho, temp;
    int filho_esq = 2 * pai + 1;
    int filho_dir = 2 * pai + 2;

    if (filho_dir < h->quantidade && h->v[filho_dir] < h->v[filho_esq])
        menorFilho = filho_dir;
    else
        menorFilho = filho_esq;

    if (menorFilho < h->quantidade && h->v[pai] > h->v[menorFilho]) {
        temp = h->v[pai];
        h->v[pai] = h->v[menorFilho];
        h->v[menorFilho] = temp;
        desceChave(h, menorFilho);
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
        printf("%d", v[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}

int vazio(Heap *h) {
    return h->quantidade == 0;
}

void sobeChave(Heap *h, int i) {
    int temp;
    while (i > 0 && h->v[pai(i)] > h->v[i]) {
        temp = h->v[i];
        h->v[i] = h->v[pai(i)];
        h->v[pai(i)] = temp;
        i = pai(i);
    }
}

void inserir(Heap *h, int x) {
    if (h->quantidade == h->tamanho) {
        printf("Heap cheio. Não é possível inserir.\n");
        return;
    }
    h->v[h->quantidade] = x;
    h->quantidade++;
    sobeChave(h, h->quantidade - 1);
}

int extraiMinimo(Heap *h) {
    if (vazio(h)) {
        printf("Heap vazio. Não é possível extrair.\n");
        return -1;
    }
    int minimo = h->v[0];
    h->v[0] = h->v[h->quantidade - 1];
    h->quantidade--;
    desceChave(h, 0);
    return minimo;
}

void remover(Heap *h, int x) {
    int i;
    for (i = 0; i < h->quantidade; i++) {
        if (h->v[i] == x) {
            h->v[i] = h->v[h->quantidade - 1];
            h->quantidade--;
            desceChave(h, i);
            return;
        }
    }
    printf("Elemento não encontrado.\n");
}

int main() {
    int tam;
    scanf("%d", &tam);
    Heap *h = criaHeapVazio(tam);
    char op;
    int x;
    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'I': 
                scanf("%d", &x); 
                inserir(h, x);
                break;
            case 'R': 
                scanf("%d", &x); 
                remover(h, x); 
                break;
            case 'E':   
                if (!vazio(h)){
                    printf("[%d]\n", extraiMinimo(h)); 
                    break;
                }
            case 'P':   
                if (!vazio(h)){
                    imprime(h->v, h->quantidade); 
                    break;
                } 
        }
    }
    liberaHeap(h);
}
