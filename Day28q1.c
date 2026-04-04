/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create circular linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        if(head == NULL) {
            head = temp = newNode;
            newNode->next = head; // points to itself initially
        } else {
            temp->next = newNode;
            newNode->next = head; // last node points to head
            temp = newNode;
        }
    }

    // Traverse circular list
    if(head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}