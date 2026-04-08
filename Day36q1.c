/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n];

    // Input elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int m;
    scanf("%d", &m);

    int front = 0;

    // Move front after m dequeues
    front = (front + m) % n;

    // Print circular queue
    for(int i = 0; i < n; i++) {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}