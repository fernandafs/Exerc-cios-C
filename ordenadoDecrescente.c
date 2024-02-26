#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificaOrdenacaoDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] < vetor[i + 1]) {
            return 0; 
        }
    }
    return 1; 

}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int vetor[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
        }

        if (verificaOrdenacaoDecrescente(vetor, n)) {
            printf("S\n");
        } else {
            printf("N\n");
        }

        getchar();
    }
}
