/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>
#include <stdlib.h>

// Stack implementation
typedef struct {
    int *arr;
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s, int n) {
    s->arr = (int*)malloc(sizeof(int) * n);
    s->top = -1;
}

// Push
void push(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

// Pop
int pop(Stack *s) {
    return s->arr[(s->top)--];
}

// Queue implementation using array
typedef struct {
    int *arr;
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q, int n) {
    q->arr = (int*)malloc(sizeof(int) * n);
    q->front = 0;
    q->rear = -1;
}

// Enqueue
void enqueue(Queue *q, int x) {
    q->arr[++(q->rear)] = x;
}

// Dequeue
int dequeue(Queue *q) {
    return q->arr[(q->front)++];
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q, n);

    // Input queue
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    Stack s;
    initStack(&s, n);

    // Step 1: Move queue → stack
    while(q.front <= q.rear) {
        push(&s, dequeue(&q));
    }

    // Step 2: Move stack → queue
    while(s.top != -1) {
        enqueue(&q, pop(&s));
    }

    // Print reversed queue
    for(int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }

    return 0;
}