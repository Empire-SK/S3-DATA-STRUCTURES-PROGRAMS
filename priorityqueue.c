#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int size = 0;
int maxsize;

struct priority {
    int data;
    int priority;
};

struct priority pq[SIZE];

void insert() {
    int data, priority;
    if (size >= maxsize) {
        printf("\nQueue is overflow!\n");
    } else {
        printf("Enter the data and priority: ");
        scanf("%d, %d", &data, &priority);
        pq[size].data = data;
        pq[size].priority = priority;
        size++;
        for (int i = size - 1; i > 0; i--) {                      
            if (pq[i].priority < pq[i - 1].priority) {
                struct priority temp = pq[i];
                pq[i] = pq[i - 1];
                pq[i - 1] = temp;
            }
        }
        printf("The element inserted is (%d, %d)\n", data, priority);
    }
}

int delete() {
    if (size == 0) {
        printf("Queue is underflow!\n");
    } else {
        printf("Deleted element is : (%d, %d)\n", pq[0].data, pq[0].priority);
        for (int i = 0; i < size - 1; i++) {
            pq[i] = pq[i + 1];
        }
        size--;
    }
}

void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
    } else {
        for (int i = 0; i <size; i++) {
            printf("(%d, %d) ", pq[i].data, pq[i].priority);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the size: ");
    scanf("%d", &maxsize);
    if (maxsize > SIZE) {
        printf("The size of the queue is greater than the limit\n");
        return 0;
    }

    while (1) {
        printf("\nPriority Queue\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter an operation: ");
        
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: 
                printf("Invalid operation. Try again later!\n");
                break;
        }
    }

    return 0;
}
