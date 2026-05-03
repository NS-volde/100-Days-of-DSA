#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph (array of linked lists)
struct Node* adj[MAX];

// Queue
int queue[MAX], front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1) return -1;
    int val = queue[front++];
    if (front > rear) front = rear = -1;
    return val;
}

// Add edge
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// BFS function
void bfs(int s, int n) {
    enqueue(s);
    visited[s] = 1;

    while (front != -1) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // remove this line for directed graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    bfs(s, n);

    return 0;
}