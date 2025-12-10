#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_array(int *array, int size, int min, int max, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; i++)
        array[i] = (rand() % (max - min + 1)) + min;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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

    clock_t start = clock();
    heapSort(arr, size);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Heap Sort: %f seconds\n", time);
    free(arr);
    return 0;
}
