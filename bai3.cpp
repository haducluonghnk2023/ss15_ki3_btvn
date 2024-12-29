#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int n; 
    int **adj; 
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = vertices;

    graph->adj = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adj[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0; 
        }
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1; 
}

void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;

    for (int i = 0; i < graph->n; i++) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

bool isConnected(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};

    DFS(graph, 0, visited);

    for (int i = 0; i < graph->n; i++) {
        if (!visited[i]) {
            return false; 
        }
    }

    return true; 
}

int main() {
    int V, E;

    printf("Nhap so dinh (V): ");
    scanf("%d", &V);
    printf("Nhap so canh (E): ");
    scanf("%d", &E);

    Graph* graph = createGraph(V);

    printf("Nhap danh sach cac canh (u, v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isConnected(graph)) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}
