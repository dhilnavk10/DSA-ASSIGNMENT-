#include <stdio.h>
#include <stdlib.h>
#define MAX 6
char vertices[MAX] = {'A', 'B', 'C', 'D', 'E', 'F'};
/* Adjacency Matrix */
int matrix[MAX][MAX] = {
 {0, 1, 1, 0, 0, 0},
 {1, 0, 0, 1, 1, 0},
 {1, 0, 0, 0, 0, 1},
 {0, 1, 0, 0, 0, 0},
 {0, 1, 0, 0, 0, 1},
 {0, 0, 1, 0, 1, 0}
};
/* Node for adjacency list */
struct Node {
 int vertex;
 struct Node *next;
};
struct Node *adj[MAX] = {NULL};
/* Function to add an edge */
void addEdge(int u, int v) {
 struct Node *newNode;
 newNode = (struct Node *)malloc(sizeof(struct Node));
 newNode->vertex = v;
 newNode->next = adj[u];
 adj[u] = newNode;
 newNode = (struct Node *)malloc(sizeof(struct Node));
 newNode->vertex = u;
 newNode->next = adj[v];
 adj[v] = newNode;
}
/* Display adjacency matrix */
void displayMatrix()
{
 int i, j;
 printf("\nAdjacency Matrix:\n");
 printf(" ");
 for (i = 0; i < MAX; i++)
 printf("%c ", vertices[i]);
 printf("\n"); for (i = 0; i < MAX; i++)
 {
 printf("%c ", vertices[i]);
 for (j = 0; j < MAX; j++)
 printf("%d ", matrix[i][j]);
 printf("\n");
 }
}
/* Display adjacency list */
void displayList()
{
 int i;
 struct Node *temp;
 printf("\nAdjacency List:\n");
 for (i = 0; i < MAX; i++)
 {
 printf("%c -> ", vertices[i]);
 temp = adj[i];
 while (temp != NULL) {
 printf("%c ", vertices[temp->vertex]);
 temp = temp->next;
 }
 printf("\n");
 }
}
/* BFS */
void BFS(int start)
{
 int visited[MAX] = {0};
 int queue[MAX];
 int front = 0;
 int rear = 0;
 int current;
 int i;
 visited[start] = 1;
 queue[rear++] = start;
 printf("\nBFS from A: ");
 while (front < rear) {
 current = queue[front++];
 printf("%c ", vertices[current]);
 for (i = 0; i < MAX; i++)
 {
 if (matrix[current][i] == 1 &&
 visited[i] == 0)
 {
 visited[i] = 1;
 queue[rear++] = i;
 }
 }
 }
 printf("\n");
}
/* DFS */
void DFS(int current, int visited[])
{
 int i;
 visited[current] = 1;
 printf("%c ", vertices[current]); for (i = 0; i < MAX; i++)
 {
 if (matrix[current][i] == 1 &&
 visited[i] == 0)
 {
 DFS(i, visited);
 }
 }
}
/* Search */
void searchVertex(char key)
{
 int i;
 for (i = 0; i < MAX; i++)
 {
 if (vertices[i] == key)
 {
 printf("\nVertex %c found at position %d.\n",
 key, i + 1);
 return;
 }
 }
 printf("\nVertex %c not found.\n", key); }
int main()
{
 int visited[MAX] = {0};
 /* Given connections */
 addEdge(0, 1); // A-B
 addEdge(0, 2); // A-C
 addEdge(1, 3); // B-D
 addEdge(1, 4); // B-E
 addEdge(2, 5); // C-F
 addEdge(4, 5); // E-F
 /* Display representations */
 displayMatrix();
 displayList();
 /* BFS */
 BFS(0); /* DFS */
 printf("\nDFS from A: ");
 DFS(0, visited);
 printf("\n");
 /* Search */
 searchVertex('F');
 return 0;
}
