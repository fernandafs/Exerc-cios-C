#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificaOrdenacao(int vetor[], int tamanho) {
    int crescente = 1, decrescente = 1;

    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            crescente = 0; 
        }
        if (vetor[i] < vetor[i + 1]) {
            decrescente = 0; 
        }
    }

    return crescente || decrescente; // Retorna verdadeiro se estiver ordenado (crescente ou decrescente)
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int vetor[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
        }

        if (verificaOrdenacao(vetor, n)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
        
        getchar();
    }
}
