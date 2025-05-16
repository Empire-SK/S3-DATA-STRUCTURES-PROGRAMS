#include <stdio.h>

#define SIZE 100  
int queue[SIZE];
int front = -1, rear = -1;
int maxSize;

int isFull(){
    if(front==((rear+1)%maxSize))
        return 1;
    return 0;
}
int isEmpty(){
    if((front==-1)&&(rear==-1))return 1;
    return 0;
}
void insert() {
  int element;
    if (isFull()) {
        printf("Queue overflow\n");
    }
   else{
    if(front==-1)front=0;
    printf("Enter the element: ");
    scanf("%d",&element);
    rear=(rear+1)%maxSize;
    queue[rear]=element;
    printf("Inserted -> %d",element);
   }
}

int delete() {
    int element;
    if (isEmpty()) {
        printf("Queue underflow\n");
        return (-1);
    } else {
        element=queue[front];
        if (front==rear){
            front=-1;
            rear=-1;
        } else {
            front=(front+1)%maxSize;
        }
    printf("\nDeleted element ->%d\n",element);
    return (element); 
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("\nFront->%d",front);
        printf("\nQueue->");
        for(i = front; i != rear; i = (i + 1) % maxSize) {
            printf("%d ", queue[i]);
        }
       printf("%d",queue[i]);
       printf("\nRear-> %d\n",rear);
    }
}

int main() {
    int option;
    printf("Enter the size of the queue (up to 100): ");
    scanf("%d", &maxSize);
    if (maxSize > SIZE) {
        printf("Error: Size exceeds the maximum allowed 100\n");
        return 0;
    }
    while (1) {
        printf("\n** QUEUE MENU **\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}