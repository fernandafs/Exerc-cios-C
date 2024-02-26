#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void OrdenaPorInsercao(int A[], int n) {
    int deslocamentos = 0;

    for (int j = 1; j < n; j++) {
        int chave = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > chave) {
            
            A[i + 1] = A[i];
            i--;
            deslocamentos++;
            
            for (int k = 0; k < n; k++) {
                if (k == n - 1) {
                    printf("%d", A[k]); // retirada de espaço no último elemento do vetor
                } else {
                    printf("%d ", A[k]);
                }
            }
            printf("\n");
        }

        A[i + 1] = chave;
        
        for (int k = 0; k < n; k++) {
            if (k == n - 1) {
                printf("%d", A[k]); // retirada de espaço no último elemento do vetor
            } else {
                printf("%d ", A[k]);
            }
        }
        printf("\n");
    }

    printf("Deslocamentos: %d\n", deslocamentos);
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    OrdenaPorInsercao(vetor, n);
}
