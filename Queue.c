#include <stdio.h>
#define MAX 100 
int queue[MAX];
int front = -1;
int rear = -1;
int maxSize;

int isFull() {
   if(rear>=maxSize)
   {
     return 1;
   }
   else
   {
     return 0;
     }
}

int isEmpty() {
  if(front==-1||front>rear)
  {
    return 1;
  }
  else
    return 0; 
}

int enqueue() {
    if (isFull()) {
        printf("Queue overflow!\n");
        return 0;
    } else {
        printf("Enter element: ");
        int number;
        scanf("%d", &number);
        rear++;
        front=0;
        queue[rear] = number;
        printf("\nOperation Succesfull!\n");
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return 0;
    } else {
        front++;
        printf("Element deleted is %d",queue[front-1]);
    }
}

int display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice;

    printf("Enter the size of the queue (up to %d): ", MAX);
    scanf("%d", &maxSize);

    if (maxSize > MAX) {
        printf("Error: Size exceeds the maximum allowed (%d)\n", MAX);
        return 1;
    }

    while (1) {
        printf("\n** QUEUE MENU **\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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