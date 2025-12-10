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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    printf("Vetor nao ordenado\n");
    print_array(arr,size);
    
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Vetor ordenado\n");
    print_array(arr,size);
    printf("Quick Sort: %f seconds\n", time);
    free(arr);
    return 0;
}
