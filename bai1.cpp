#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
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
	int V ;
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
	for(int i = 0; i < V; i++){
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
// bfs
void BFS(Graph* graph, int startVertex){
	bool visited[MAX] = {false};// mang da tham
	int queue[MAX]; // hang doi
	int front = 0, rear = -1;
	// them vao hang doi va danh dau da tham
	 visited[startVertex] = true;
	 queue[++rear] = startVertex;
	 while(front <= rear){
	 	int currentVertex = queue[front++];
	 	printf("%d",currentVertex);
	 	Node* temp = graph->array[currentVertex].head;
	 	while(temp){
	 		int adjVertex = temp->dest;
	 		if(!visited[adjVertex]){
	 			visited[adjVertex] = true;
	 			queue[++rear] = adjVertex;
			 }
			 temp = temp->next;
		 }
	 }
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
	BFS(graph, start);
	
	return 0;
}

