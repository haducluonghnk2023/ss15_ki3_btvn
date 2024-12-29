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
}

bool DFS(Graph* graph, int vertex, bool visited[], bool recursionStack[]) {
    visited[vertex] = true;
    recursionStack[vertex] = true;

    for (int i = 0; i < graph->n; i++) {
        if (graph->adj[vertex][i] == 1) {
            if (!visited[i] && DFS(graph, i, visited, recursionStack)) {
                return true; 
            } else if (recursionStack[i]) {
                return true; 
            }
        }
    }

    recursionStack[vertex] = false; 
    return false; 
}

bool hasCycle(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    bool recursionStack[MAX_VERTICES] = {false};

    for (int i = 0; i < graph->n; i++) {
        if (!visited[i] && DFS(graph, i, visited, recursionStack)) {
            return true; 
        }
    }

    return false; 
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

    if (hasCycle(graph)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }
    return 0;
}
