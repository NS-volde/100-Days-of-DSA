#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* adj[MAX];

// Add edge (u → v with weight w)
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap structure
struct MinHeap {
    int vertex[MAX];
    int dist[MAX];
    int size;
};

// Swap helper
void swap(struct MinHeap* heap, int i, int j) {
    int t1 = heap->vertex[i];
    int t2 = heap->dist[i];
    heap->vertex[i] = heap->vertex[j];
    heap->dist[i] = heap->dist[j];
    heap->vertex[j] = t1;
    heap->dist[j] = t2;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->dist[left] < heap->dist[smallest])
        smallest = left;

    if (right < heap->size && heap->dist[right] < heap->dist[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap, i, smallest);
        heapify(heap, smallest);
    }
}

// Extract min
int extractMin(struct MinHeap* heap) {
    int root = heap->vertex[0];
    heap->vertex[0] = heap->vertex[heap->size - 1];
    heap->dist[0] = heap->dist[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Decrease key
void decreaseKey(struct MinHeap* heap, int v, int newDist) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->vertex[i] == v) {
            heap->dist[i] = newDist;

            while (i && heap->dist[(i-1)/2] > heap->dist[i]) {
                swap(heap, i, (i-1)/2);
                i = (i-1)/2;
            }
            break;
        }
    }
}

// Dijkstra
void dijkstra(int src, int n) {
    int dist[MAX];
    int visited[MAX] = {0};

    struct MinHeap heap;
    heap.size = n;

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        heap.vertex[i] = i;
        heap.dist[i] = INT_MAX;
    }

    dist[src] = 0;
    heap.dist[src] = 0;

    while (heap.size > 0) {
        int u = extractMin(&heap);
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                decreaseKey(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n, e, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // remove for directed graph
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src, n);

    return 0;
}