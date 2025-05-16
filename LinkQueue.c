#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Global queue
struct Queue* queue;

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
void createQueue() {
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
}

// Function to enqueue an element to the queue
void enqueue(int data) {
    struct Node* temp = newNode(data);

    // If the queue is empty, then the new node is both front and rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    // Add the new node at the end of the queue and change rear
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to dequeue an element from the queue
int dequeue() {
    // If the queue is empty, return an error value
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        exit(1);
    }

    // Store the previous front and move the front one node ahead
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    // If the queue is now empty, change the rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmpty() {
    return queue->front == NULL;
}

// Function to print the queue
void printQueue() {
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    createQueue();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Queue after enqueues: ");
    printQueue();

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    printf("Queue after dequeues: ");
    printQueue();

    return 0;
}
