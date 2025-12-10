#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_array(int *array, int size, int min, int max, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; i++)
        array[i] = (rand() % (max - min + 1)) + min;
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int size, min_value = 1, max_value = 100;
    unsigned int seed = 1234;

    printf("Insira o tamanho desejado do array\n");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    fill_random_array(arr, size, min_value, max_value, seed);

    printf("Vetor original:\n");
    print_array(arr, size);

    clock_t start = clock();
    selectionSort(arr, size);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Vetor ordenado:\n");
    print_array(arr, size);

    printf("Tempo de execucao: %.6f segundos\n", time);

    free(arr);
    return 0;
}