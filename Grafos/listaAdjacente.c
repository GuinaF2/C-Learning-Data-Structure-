#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100

typedef struct {
    int numVertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int numArestas;
} Grafo;

// Função para criar e inicializar um grafo com n vértices
Grafo *criarGrafo(int n) {
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertices = n;
    grafo->numArestas = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grafo->matriz[i][j] = 0;
    return grafo;
}

// Adiciona uma aresta não direcionada entre os vértices i e j (grafo simétrico)
void adicionarArestaNaoDirecionada(Grafo *grafo, int i, int j, int peso) {
    if (i >= 0 && i < grafo->numVertices && j >= 0 && j < grafo->numVertices) {
        grafo->matriz[i][j] = peso;
        grafo->matriz[j][i] = peso;
        grafo->numArestas += 2;
    }
}

// Função recursiva para busca em profundidade (DFS) a partir de um vértice
void dfs(Grafo *grafo, int vertice, int *visitado) {
    visitado[vertice] = 1;
    printf("Visitando vertice %d\n", vertice);
    for (int i = 0; i < grafo->numVertices; i++) {
        if (grafo->matriz[vertice][i] && !visitado[i]) {
            dfs(grafo, i, visitado);
        }
    }
}

// Função auxiliar para iniciar a DFS a partir de um vértice inicial
void dfsGrafo(Grafo *grafo, int verticeInicial) {
    int *visitado = (int *)calloc(grafo->numVertices, sizeof(int));
    dfs(grafo, verticeInicial, visitado);
    free(visitado);
}

// Função auxiliar para imprimir o caminho (usada em algoritmos de caminhos mínimos)
void imprimirCaminho(int pai[], int j) {
    if (pai[j] == -1)
        return;
    imprimirCaminho(pai, pai[j]);
    printf("%d ", j);
}

// Função para imprimir a matriz de adjacências do grafo
void imprimirGrafo(Grafo *grafo) {
    printf("Matriz de Adjacencias:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        for (int j = 0; j < grafo->numVertices; j++) {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Cria um grafo com 6 vértices
    Grafo *grafo = criarGrafo(6);

    // Adiciona arestas (grafo não direcionado)
    adicionarArestaNaoDirecionada(grafo, 0, 1, 1);
    adicionarArestaNaoDirecionada(grafo, 0, 2, 1);
    adicionarArestaNaoDirecionada(grafo, 1, 3, 1);
    adicionarArestaNaoDirecionada(grafo, 2, 4, 1);
    adicionarArestaNaoDirecionada(grafo, 3, 4, 1);
    adicionarArestaNaoDirecionada(grafo, 3, 5, 1);

    imprimirGrafo(grafo);

    printf("\nDFS a partir do vertice 0:\n");
    dfsGrafo(grafo, 0);

    // Libera memória alocada para o grafo
    free(grafo);
    return 0;
}