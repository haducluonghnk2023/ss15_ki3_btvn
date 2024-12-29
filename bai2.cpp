#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
// cau truc danh sach ke
typedef struct Node {
	int dest;
	struct Node* next;
} Node;
typedef struct AdjList{
	struct Node *head;
} AdjList;
// cau truc do thi
typedef struct Graph{
	int V;
	AdjList* array;
} Graph;
// tao node torng ds ke
Node* newAdjListNode(int dest){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}
// tao do thi
Graph* createGraph(int V){
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->array = (AdjList*) malloc(V * sizeof(AdjList));
	int i;
	for(i = 0; i < V; i++){
		graph->array[i].head = NULL;
	}
	return graph;
}
// them canh vao do thi
void addEdge(Graph* graph, int src, int dest){
	// src-> dest
	Node* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	//dest->src vh
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}
// dfs de quy
void DFSUtil(Graph* graph, int vertex, bool visited[]){
	visited[vertex] = true;
	printf("%d ", vertex);
	Node* temp = graph->array[vertex].head;
	while (temp) {
		int adjVertex = temp->dest;
		if (!visited[adjVertex]) {
	      DFSUtil(graph, adjVertex, visited);
	    }
	    temp = temp->next;
	}
}
//DFS
void DFS(struct Graph* graph, int startVertex) {
  bool visited[MAX] = {false}; 
  DFSUtil(graph, startVertex, visited);
}
int main(){
	int V, E, start;
	printf("Nhap so dinh: ");
	scanf("%d",&V);
	printf("Nhap so canh: ");
	scanf("%d",&E);
	Graph* graph = createGraph(V);
	printf("nhap u v: ");
	for( int i = 0; i < E; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		addEdge(graph, u, v);
	}
	printf("nhap dinh bd duyet: ");
	scanf("%d",&start);
	printf("thu tu duyet bfs: ");
	DFS(graph, start);
	
	return 0;
}

