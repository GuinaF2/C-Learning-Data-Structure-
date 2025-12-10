#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void encontrarMinMax(int *vetor, int tamanho, int *min, int *max) {
    *min = *max = vetor[0];

    int *ptr=vetor;
    for (int i = 0; i < tamanho; i++) {
        if (*ptr < *min) {
            *min = *ptr;
        }
        if (*ptr > *max) {
            *max = *ptr;
        }
        ptr++;
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    int min, max;
    encontrarMinMax(vetor, tamanho, &min, &max);

    printf("Valor mínimo: %d\n", min);
    printf("Valor máximo: %d\n", max);

    free(vetor);
    return 0;
}

//Tipos Primitivos
//EX: INT: Numero sem Nada depois da virgula, ocupa espaço fixo, 4  bytes, binario
//FLOAT: Numero ocupa 4 bytes, divide em sinais, expoente e mantissa, IEE754

//CHAR: Ocupa 1 byte de memoria, se baseia no codigo ASCII do caractere