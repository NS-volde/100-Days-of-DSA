/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    if(top == MAX - 1) return; // overflow ignored
    stack[++top] = val;
}

// Pop
void pop() {
    if(top == -1) return; // underflow ignored
    top--;
}

// Display
void display() {
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Push n elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining
    display();

    return 0;
}