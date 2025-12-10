#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para preencher array com valores aleatórios utilizando numero maximo, minimo, array de tamanho
void fill_random_array(int *array, int size, int min, int max, unsigned int seed)
{
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % (max - min + 1)) + min;
    }
}

// Função para medir tempo de execução
double measure_execution_time(void (*func)(int *, int), int *arr, int size)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    func(arr, size);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// ======== Algoritmos de Ordenação ========

// Bubble Sort
void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        int trocou = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        if (trocou == 0)
            break;
    }
}

// Selection Sort
void selectionSort(int *arr, int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(int *arr, int n)
{
    int i, chave, j;
    for (i = 1; i < n; i++)
    {
        chave = arr[i];
        j = i - 1;

        /* Move elementos maiores que a chave
        para uma posição à frente */
        while (j >= 0 && arr[j] > chave)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

// Merge Sort (auxiliar)
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge Sort (recursivo)
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Wrapper para Merge Sort
void mergeSortWrapper(int *arr, int n)
{
    mergeSort(arr, 0, n - 1);
}

// Quick Sort (auxiliar - Lomuto partition)
void trocar(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int arr[], int baixo, int alto)
{
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j] < pivo)
        {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Quick Sort (recursivo)
void quickSort(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// Wrapper para Quick Sort
void quickSortWrapper(int *arr, int n)
{
    quickSort(arr, 0, n - 1);
}

// Heap Sort (heapify)
void heapify(int arr[], int n, int i)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior])
        maior = esq;
    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    if (maior != i)
    {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior);
    }
}

// Heap Sort (principal)
void heapSort(int arr[], int n)
{
    // Constrói max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Wrapper para Heap Sort
void heapSortWrapper(int *arr, int n)
{
    heapSort(arr, n);
}

void copy_array(int *source, int *destination, int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}


// ======== Função Principal ========
int main()
{
    int size = 0; // n elementos para testes significativos
    int min_value = 1;
    int max_value = 100;
    unsigned int seed = 12345;

    printf("Insira o tamanho desejado do array\n");
    scanf("%d", &size);

    int *random_array = malloc(size * sizeof(int));
    int *copy = malloc(size * sizeof(int));
    if (random_array == NULL || copy==NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    fill_random_array(random_array, size, min_value, max_value, seed);

    // Bubble Sort
    copy_array(random_array, copy, size);
    double bubble_time = measure_execution_time(bubbleSort, copy, size);
    printf("Bubble Sort: %f seconds\n", bubble_time);

    // Selection Sort
    copy_array(random_array, copy, size);
    double selection_time = measure_execution_time(selectionSort, copy, size);
    printf("Selection Sort: %f seconds\n", selection_time);

    // Insertion Sort
    copy_array(random_array, copy, size);
    double insertion_time = measure_execution_time(insertionSort, copy, size);
    printf("Insertion Sort: %f seconds\n", insertion_time);

    // Merge Sort
    copy_array(random_array, copy, size);
    double merge_time = measure_execution_time(mergeSortWrapper, copy, size);
    printf("Merge Sort: %f seconds\n", merge_time);

    // Quick Sort
    copy_array(random_array, copy, size);
    double quick_time = measure_execution_time(quickSortWrapper, copy, size);
    printf("Quick Sort: %f seconds\n", quick_time);

    // Heap Sort
    copy_array(random_array, copy, size);
    double heap_time = measure_execution_time(heapSortWrapper, copy, size);
    printf("Heap Sort: %f seconds\n", heap_time);
    free(random_array);
    free(copy);
    return 0;
}