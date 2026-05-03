#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Array of pointers (adjacency list)
    struct Node* adj[n];

    // Initialize all lists as NULL
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Convert to 0-based index
        u--; 
        v--;

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add u to v's list (for undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency list
    for(int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        struct Node* temp = adj[i];
        while(temp != NULL) {
            printf("%d -> ", temp->data + 1);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}