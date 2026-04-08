/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (for insert)
void heapifyUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify Down (for delete)
void heapifyDown(int i) {
    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert operation
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Delete operation (remove min)
int deleteMin() {
    if(size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return root;
}

// Peek operation
int peek() {
    if(size == 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for(int i = 0; i < N; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        }
        else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}