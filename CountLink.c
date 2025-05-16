#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node and add it to the list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to add a node at the end of the list
void appendNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Adding nodes to the linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);

    // Counting the number of nodes
    int nodeCount = countNodes(head);
    printf("The number of nodes in the linked list is: %d\n", nodeCount);

    // Free allocated memory (optional but recommended)
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
