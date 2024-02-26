#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int *v, int n) {
    int i, j, aux;
    int ifs_executados = 0;
    int ifs_satisfeitos = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            ifs_executados++;

            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                
                
                for (int k = 0; k < n; k++) {
                    if (k == n - 1) {
                        printf("%d", v[k]);
                    } else {
                        printf("%d ", v[k]);
                    }
                }
                printf("\n");


                ifs_satisfeitos++;
            }
        }
    }

    printf("Total de IFs executados: %d\n", ifs_executados);
    printf("Total de IFs satisfeitos: %d\n", ifs_satisfeitos);
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    bubbleSort(vetor, n);
}

