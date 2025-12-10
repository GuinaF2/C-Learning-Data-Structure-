#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Tamanho do problema

// Avalia solução (maior é melhor) - Exemplo: soma dos elementos
int avaliar(int solucao[N]) {
    int valor = 0;
    for (int i = 0; i < N; i++)
        valor += solucao[i];
    return valor;
}

// Modifica ligeiramente a solução
void gerarVizinho(int atual[N], int vizinho[N]) {
    // Copia atual para vizinho
    for (int i = 0; i < N; i++)
        vizinho[i] = atual[i];

    // Modifica aleatoriamente um elemento
    int pos = rand() % N;
    vizinho[pos] = rand() % 100;
}

int main() {
    int atual[N], vizinho[N];
    int valorAtual, valorVizinho;

    // Inicializa semente do gerador aleatório
    srand((unsigned)time(NULL));

    // Inicializa solução aleatória
    for (int i = 0; i < N; i++)
        atual[i] = rand() % 100;

    valorAtual = avaliar(atual);

    int melhorou = 1;
    while (melhorou) {
        melhorou = 0;

        gerarVizinho(atual, vizinho);
        valorVizinho = avaliar(vizinho);

        if (valorVizinho > valorAtual) {
            // Atualiza para vizinho melhor
            for (int i = 0; i < N; i++)
                atual[i] = vizinho[i];
            valorAtual = valorVizinho;
            melhorou = 1;
        }
    }

    printf("Valor final: %d\n", valorAtual);
    return 0;
}