#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int numVertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
} Grafo;

// Função para criar e inicializar um grafo com n vértices
Grafo *criarGrafo(int n) {
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertices = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grafo->matriz[i][j] = 0;
    return grafo;
}

// Adiciona uma aresta não direcionada entre os vértices i e j
void adicionarArestaNaoDirecionada(Grafo *grafo, int i, int j, int peso) {
    if (i >= 0 && i < grafo->numVertices && j >= 0 && j < grafo->numVertices) {
        grafo->matriz[i][j] = peso;
        grafo->matriz[j][i] = peso;
    }
}

// Função auxiliar para imprimir o caminho
void imprimirCaminho(int pai[], int j) {
    if (pai[j] == -1)
        return;
    imprimirCaminho(pai, pai[j]);
    printf("%d ", j);
}

// Implementação do algoritmo de Dijkstra (matriz de adjacências)
void dijkstra(Grafo* grafo, int inicio) {
    int dist[MAX_VERTICES]; // Vetor de distâncias mínimas
    int visitado[MAX_VERTICES]; // Vértices já processados
    int pai[MAX_VERTICES]; // Para reconstruir caminhos

    // Inicialização
    for (int i = 0; i < grafo->numVertices; i++) {
        dist[i] = INT_MAX; // Infinito (distância desconhecida)
        visitado[i] = 0; // Nenhum vértice visitado inicialmente
        pai[i] = -1; // Sem predecessores
    }

    // Distância da origem para si mesma é 0
    dist[inicio] = 0;

    // Encontra caminho mais curto para todos os vértices
    for (int count = 0; count < grafo->numVertices - 1; count++) {
        // Encontra vértice com distância mínima do conjunto não visitado
        int u = -1;
        int minDist = INT_MAX;
        for (int v = 0; v < grafo->numVertices; v++) {
            if (!visitado[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // Todos visitados ou não alcançável

        // Marca o vértice escolhido como processado
        visitado[u] = 1;

        // Atualiza distâncias dos vizinhos do vértice escolhido
        for (int v = 0; v < grafo->numVertices; v++) {
            if (grafo->matriz[u][v] && !visitado[v] && dist[u] != INT_MAX &&
                dist[u] + grafo->matriz[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo->matriz[u][v];
                pai[v] = u;
            }
        }
    }

    // Impressão dos resultados
    printf("\nDistancias minimas a partir do vertice %d:\n", inicio);
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("Vertice %d: Distancia = ", i);
        if (dist[i] == INT_MAX)
            printf("INF");
        else
            printf("%d", dist[i]);
        printf(" | Caminho: ");
        if (dist[i] != INT_MAX) {
            printf("%d ", inicio);
            imprimirCaminho(pai, i);
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

    printf("Dijkstra a partir do vertice 0:\n");
    dijkstra(grafo, 0);

    free(grafo);
    return 0;
}