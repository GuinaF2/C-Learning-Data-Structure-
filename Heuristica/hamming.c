#include <stdio.h>
#include <string.h>

// Função de distância de Hamming
int hamming_distance(const char* s1, const char* s2) {
    if (strlen(s1) != strlen(s2)) {
        fprintf(stderr, "Erro: strings de tamanhos diferentes\n");
        return -1;
    }

    int distance = 0;
    int len = strlen(s1);

    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            distance++;
        }
    }

    return distance;
}

int main() {
    const char *a = "1011101";
    const char *b = "1001001";
    int dist = hamming_distance(a, b);
    if (dist >= 0)
        printf("Distância de Hamming entre \"%s\" e \"%s\": %d\n", a, b, dist);

    // Teste com strings de tamanhos diferentes
    const char *c = "1011";
    const char *d = "10010";
    hamming_distance(c, d);

    return 0;
}