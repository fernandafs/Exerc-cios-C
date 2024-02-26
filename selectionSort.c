#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void OrdenaPorSelecao(int A[], int n) {
    int ifs_executados = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            ifs_executados++;

            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }

        int temp = A[i];
        A[i] = A[min_index];
        A[min_index] = temp;


        for (int k = 0; k < n; k++) {
            if (k == n - 1) {
                printf("%d", A[k]);
            } else {
                printf("%d ", A[k]);
            }
        }
        printf("\n");
    }

    printf("Total de IFs executados: %d\n", ifs_executados);
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    OrdenaPorSelecao(vetor, n);
}
