#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int rearrange_array(int arr[], int n, int p) {
    int pivot_value = arr[p];
    swap(&arr[p], &arr[n - 1]);
    int new_pivot_index = partition(arr, 0, n - 1);
    return new_pivot_index;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int new_pivot_index = rearrange_array(arr, n, p);

    printf("%d\n", new_pivot_index);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
