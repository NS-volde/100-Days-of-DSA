#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap
struct Heap {
    int node[MAX];
    int dist[MAX];
    int size;
};

// Swap
void swap(struct Heap* h, int i, int j) {
    int t1 = h->node[i], t2 = h->dist[i];
    h->node[i] = h->node[j];
    h->dist[i] = h->dist[j];
    h->node[j] = t1;
    h->dist[j] = t2;
}

// Heapify
void heapify(struct Heap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->dist[l] < h->dist[smallest])
        smallest = l;
    if (r < h->size && h->dist[r] < h->dist[smallest])
        smallest = r;

    if (smallest != i) {
        swap(h, i, smallest);
        heapify(h, smallest);
    }
}

// Extract min
int extractMin(struct Heap* h) {
    int root = h->node[0];
    h->node[0] = h->node[h->size - 1];
    h->dist[0] = h->dist[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Decrease key
void decreaseKey(struct Heap* h, int v, int newDist) {
    for (int i = 0; i < h->size; i++) {
        if (h->node[i] == v) {
            h->dist[i] = newDist;

            while (i && h->dist[(i-1)/2] > h->dist[i]) {
                swap(h, i, (i-1)/2);
                i = (i-1)/2;
            }
            break;
        }
    }
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    struct Heap h;
    h.size = n;

    // Init
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        h.node[i-1] = i;
        h.dist[i-1] = INT_MAX;
    }

    dist[src] = 0;
    h.dist[src-1] = 0;

    while (h.size > 0) {
        int u = extractMin(&h);
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v, w = temp->w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                decreaseKey(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Init adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // remove for directed graph
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}