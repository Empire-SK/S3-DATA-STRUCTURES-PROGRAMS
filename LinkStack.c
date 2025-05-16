#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = top;
    top = new_node;
}

// Function to pop an element from the stack
int pop() {
    int res;
    struct Node* temp;

    // If stack is empty, return error
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        temp = top;
        res = temp->data;
        top = top->next;
        free(temp);
        return res;
    }
}

// Function to check if the stack is empty
int isEmpty() {
    return (top == NULL);
}

// Function to peek the top element of the stack
int peek() {
    if (!isEmpty()) {
        return top->data;
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

// Function to print the stack
void printList() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Push elements onto the stack
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Stack (linked list) after pushes: ");
    printList();

    // Peek at the top element
    printf("Top element is: %d\n", peek());

    // Pop elements from the stack
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Stack (linked list) after pops: ");
    printList();

    // Check if the stack is empty
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
