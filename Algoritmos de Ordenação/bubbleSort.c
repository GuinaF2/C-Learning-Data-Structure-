#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_array(int *array, int size, int min, int max, unsigned int seed)
{
    srand(seed);
    for (int i = 0; i < size; i++)
        array[i] = (rand() % (max - min + 1)) + min;
}

// Função para imprimir o array
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int size, min_value = 1, max_value = 100;
    unsigned int seed = 5465;

    printf("Insira o tamanho desejado do array\n");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (!arr)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    fill_random_array(arr, size, min_value, max_value, seed);

    printf("Array antes da ordenação:\n");
    print_array(arr, size);

    clock_t start = clock();
    bubbleSort(arr, size);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Array após Bubble Sort:\n");
    print_array(arr, size);

    printf("Bubble Sort: %f seconds\n", time);
    free(arr);
    return 0;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int trocou = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou)
            break;
    }
}
