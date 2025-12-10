#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_array(int *array, int size, int min, int max, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; i++)
        array[i] = (rand() % (max - min + 1)) + min;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size, min_value = 1, max_value = 100;
    unsigned int seed = 5465;

    printf("Insira o tamanho desejado do array\n");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("Erro ao alocar mem\u00f3ria.\n");
        return 1;
    }
    

    fill_random_array(arr, size, min_value, max_value, seed);
    
    printf("Vetor nao ordenado\n");
    print_array(arr,size);
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Vetor ordenado\n");
    print_array(arr,size);

    printf("Merge Sort: %f seconds\n", time);
    free(arr);
    return 0;
}
