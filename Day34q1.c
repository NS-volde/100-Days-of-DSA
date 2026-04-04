/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if(*top == NULL) return 0;

    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    struct Node* stack = NULL;

    // Read full line
    fgets(exp, sizeof(exp), stdin);

    char* token = strtok(exp, " ");

    while(token != NULL) {

        // If number
        if(isdigit(token[0]) || 
          (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int res;

            if(token[0] == '+') res = a + b;
            else if(token[0] == '-') res = a - b;
            else if(token[0] == '*') res = a * b;
            else if(token[0] == '/') res = a / b;

            push(&stack, res);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop(&stack));

    return 0;
}