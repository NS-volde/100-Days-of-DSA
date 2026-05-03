#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

// Add directed edge
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    int indegree[MAX] = {0};

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        indegree[v]++;  // increase indegree
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");

    int count = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->data;
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }

    // Cycle check
    if (count != n) {
        printf("\nCycle exists! Topological sort not possible.\n");
    }

    return 0;
}