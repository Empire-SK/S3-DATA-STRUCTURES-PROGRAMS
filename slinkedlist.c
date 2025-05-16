#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* link;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory underflow, no insertion\n");
        return;
    }
    temp->data = item;
    temp->link = *head;
    *head = temp;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = item;
    temp->link = NULL;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* ptr = *head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

// Function to insert a node after a given key
void insertAfterKey(struct Node** head, int key, int item) {
    struct Node* ptr = *head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Search failed, key not found\n");
        return;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = item;
    temp->link = ptr->link;
    ptr->link = temp;
}

// Function to delete a node from the front
void deleteFromFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->link;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    if (current->link == NULL) {
        free(current);
        *head = NULL;
        return;
    }
    while (current->link != NULL) {
        prev = current;
        current = current->link;
    }
    prev->link = NULL;
    free(current);
}

// Function to delete a node by its key
void deleteByKey(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    if (current->data == key) {
        *head = current->link;
        free(current);
        return;
    }
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->link;
    }
    if (current == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->link = current->link;
    free(current);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, item, key;

    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after key\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete by key\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &item);
                insertAtBeginning(&head, item);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &item);
                insertAtEnd(&head, item);
                break;
            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &item);
                insertAfterKey(&head, key, item);
                break;
            case 4:
                deleteFromFront(&head);
                printf("Deleted from front\n");
                break;
            case 5:
                deleteFromEnd(&head);
                printf("Deleted from end\n");
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(&head, key);
                break;
            case 7:
                printf("Current list: ");
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
