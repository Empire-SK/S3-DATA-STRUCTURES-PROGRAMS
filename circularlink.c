#include <stdio.h> 

#include <stdlib.h> 

struct Node { 

    int data; 

    struct Node* next; 

}; 

struct Node* head = NULL; 

void insert_beg(int data) { 

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); 

    newnode->data = data; 

    if (head == NULL) { 

        head = newnode; 

        newnode->next = head; 

    } else { 

        struct Node* temp = head; 

        while (temp->next != head) 

            temp = temp->next; 

        newnode->next = head; 

        temp->next = newnode; 

        head = newnode; 

    } 

} 

void insert_end(int data) { 

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); 

    newnode->data = data; 

    if (head == NULL) { 

        head = newnode; 

        newnode->next = head; 

    } else { 

        struct Node* temp = head; 

        while (temp->next != head) 

            temp = temp->next; 

        temp->next = newnode; 

        newnode->next = head; 

    } 

} 

void insert_random(int data, int pos) { 

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); 

    newnode->data = data; 

    if (pos == 1) { 

        insert_beg(data); 

        return; 

    } 

    struct Node* temp = head; 

    for (int i = 1; i < pos - 1 && temp->next != head; i++) 

        temp = temp->next; 

    newnode->next = temp->next; 

    temp->next = newnode; 

} 

void delete_beg() { 

    if (head == NULL) { 

        printf("List is empty.\n"); 

        return; 

    } 

    struct Node* temp = head; 

    struct Node* last = head; 

    if (head->next == head) { 

        head = NULL; 

        free(temp); 

    } else { 

        while (last->next != head) 

            last = last->next; 

        head = head->next; 

        last->next = head; 

        free(temp); 

    } 

} 

void delete_end() { 

    if (head == NULL) { 

        printf("List is empty.\n"); 

        return; 

    } 

    struct Node* temp = head; 

    struct Node* prev = NULL; 

    if (head->next == head) { 

        head = NULL; 

        free(temp); 

    } else { 

        while (temp->next != head) { 

            prev = temp; 

            temp = temp->next; 

        } 

        prev->next = head; 

        free(temp); 

    } 

} 

void delete_random(int pos) { 

    if (head == NULL) { 

        printf("List is empty.\n"); 

        return; 

    } 

    if (pos == 1) { 

        delete_beg(); 

        return; 

    } 

    struct Node* temp = head; 

    struct Node* prev = NULL; 

    for (int i = 1; i < pos && temp->next != head; i++) { 

        prev = temp; 

        temp = temp->next; 

    } 

    if (temp == head) { 

        printf("Position out of range.\n"); 

    } else { 

        prev->next = temp->next; 

        free(temp); 

    } 

} 

 

void display() { 

    if (head == NULL) { 

        printf("List is empty.\n"); 

        return; 

    } 

    struct Node* temp = head; 

    do { 

        printf("%d ", temp->data); 

        temp = temp->next; 

    } while (temp != head); 

    printf("\n"); 

} 

 

int main() { 

    int choice, data, pos; 

    while (1) { 

        printf("\n1 = Insert at beginning\n2 = Insert at end\n3 = Insert at position\n4 = Delete from beginning\n5 = Delete from end\n6 = Delete from position\n7 = Display\n8 = Exit\n"); 

        printf("Enter your choice: "); 

        scanf("%d", &choice); 

        switch (choice) { 

            case 1: 

                printf("Enter data: "); 

                scanf("%d", &data); 

                insert_beg(data); 

                break; 

            case 2: 

                printf("Enter data: "); 

                scanf("%d", &data); 

                insert_end(data); 

                break; 

            case 3: 

                printf("Enter data and position: "); 

                scanf("%d %d", &data, &pos); 

                insert_random(data, pos); 

             break; 

            case 4: 

                delete_beg(); 

                break; 

            case 5: 

                delete_end(); 

                break; 

            case 6: 

                printf("Enter position to delete: "); 

                scanf("%d", &pos); 

                delete_random(pos); 

                break; 

            case 7: 

                display(); 

                break; 

            case 8: 

                exit(0); 

            default: 

                printf("Invalid option.\n"); 

        } 

    } 

    return 0; 

} 