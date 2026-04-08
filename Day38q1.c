/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
void init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check empty
int empty(Deque *dq) {
    return dq->size == 0;
}

// Check full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// push_front
void push_front(Deque *dq, int val) {
    if(isFull(dq)) {
        printf("Overflow\n");
        return;
    }

    if(empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = val;
    dq->size++;
}

// push_back
void push_back(Deque *dq, int val) {
    if(isFull(dq)) {
        printf("Overflow\n");
        return;
    }

    if(empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = val;
    dq->size++;
}

// pop_front
void pop_front(Deque *dq) {
    if(empty(dq)) {
        printf("-1\n");
        return;
    }

    dq->front = (dq->front + 1) % MAX;
    dq->size--;

    if(dq->size == 0)
        dq->front = dq->rear = -1;
}

// pop_back
void pop_back(Deque *dq) {
    if(empty(dq)) {
        printf("-1\n");
        return;
    }

    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;

    if(dq->size == 0)
        dq->front = dq->rear = -1;
}

// front element
int getFront(Deque *dq) {
    if(empty(dq)) return -1;
    return dq->arr[dq->front];
}

// back element
int getBack(Deque *dq) {
    if(empty(dq)) return -1;
    return dq->arr[dq->rear];
}

// size
int getSize(Deque *dq) {
    return dq->size;
}

// clear
void clear(Deque *dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

// display deque
void display(Deque *dq) {
    if(empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;
    for(int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// reverse
void reverse(Deque *dq) {
    int start = dq->front;
    int end = dq->rear;

    for(int i = 0; i < dq->size / 2; i++) {
        int temp = dq->arr[start];
        dq->arr[start] = dq->arr[end];
        dq->arr[end] = temp;

        start = (start + 1) % MAX;
        end = (end - 1 + MAX) % MAX;
    }
}