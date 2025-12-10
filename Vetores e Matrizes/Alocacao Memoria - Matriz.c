#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void RecebeMatriz(int n, float **mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite um valor para a posicao [%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}

void ImprimeMatriz(int n, float **mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

float CalculoDeterminante(int n, float **mat) {
    float determinante = 1;
    float multiplicador;

    float **matriztemp = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        matriztemp[i] = (float *)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            matriztemp[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int max_linha = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matriztemp[k][i]) > fabs(matriztemp[max_linha][i])) {
                max_linha = k;
            }
        }

        if (max_linha != i) {
            for (int k = 0; k < n; k++) {
                float temp = matriztemp[i][k];
                matriztemp[i][k] = matriztemp[max_linha][k];
                matriztemp[max_linha][k] = temp;
            }
            determinante *= -1;
        }
        if (matriztemp[i][i] == 0) {
            for (int i = 0; i < n; i++) {
                free(matriztemp[i]);
            }
            free(matriztemp);
            return 0;
        }
        determinante *= matriztemp[i][i];
        for (int j = i + 1; j < n; j++) {
            multiplicador = matriztemp[j][i] / matriztemp[i][i];
            for (int k = i; k < n; k++) {
                matriztemp[j][k] -= multiplicador * matriztemp[i][k];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(matriztemp[i]);
    }
    free(matriztemp);

    return determinante;
}

void CalculaMatrizInversa(int n, float **mat, float **inversa) {
    float det = CalculoDeterminante(n, mat);
    if (det == 0) {
        printf("A matriz nao e invertivel (determinante igual a zero).\n");
        return;
    }
    float **cofatores = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        cofatores[i] = (float *)malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float **submatriz = (float **)malloc((n - 1) * sizeof(float *));
            for (int k = 0; k < n - 1; k++) {
                submatriz[k] = (float *)malloc((n - 1) * sizeof(float));
            }

            int subi = 0, subj = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                subj = 0;
                for (int l = 0; l < n; l++) {
                    if (l == j) continue;
                    submatriz[subi][subj] = mat[k][l];
                    subj++;
                }
                subi++;
            }
            float cofator = pow(-1, i + j) * CalculoDeterminante(n - 1, submatriz);
            cofatores[i][j] = cofator;
            for (int k = 0; k < n - 1; k++) {
                free(submatriz[k]);
            }
            free(submatriz);
        }
    }
    float **adjunta = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        adjunta[i] = (float *)malloc(n * sizeof(float));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjunta[j][i] = cofatores[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversa[i][j] = adjunta[i][j] / det;
        }
    }
    for (int i = 0; i < n; i++) {
        free(cofatores[i]);
        free(adjunta[i]);
    }
    free(cofatores);
    free(adjunta);
}

int main() {
    int n;
    printf("Digite a quantidade de linhas e colunas da matriz:\n");
    scanf("%d", &n);
    float **matriz = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (float *)malloc(n * sizeof(float));
    }

    RecebeMatriz(n, matriz);
    ImprimeMatriz(n, matriz);

    float determinante = CalculoDeterminante(n, matriz);
    printf("Determinante: %.2f\n", determinante);

    if (determinante != 0) {
        float **inversa = (float **)malloc(n * sizeof(float *));
        for (int i = 0; i < n; i++) {
            inversa[i] = (float *)malloc(n * sizeof(float));
        }
        CalculaMatrizInversa(n, matriz, inversa);
        printf("Matriz Inversa:\n");
        ImprimeMatriz(n, inversa);
        for (int i = 0; i < n; i++) {
            free(inversa[i]);
        }
        free(inversa);
    } else {
        printf("A matriz nao possui inversa.\n");
    }

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}