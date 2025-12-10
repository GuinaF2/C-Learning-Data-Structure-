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

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
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

    printf("Vetor não ordenado\n");
    print_array(arr,size);

    clock_t start = clock();
    insertionSort(arr, size);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Vetor ordenado\n");
    print_array(arr,size);
    
    printf("Insertion Sort: %f seconds\n", time);
    free(arr);
    return 0;
}
