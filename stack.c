#include <stdio.h> 
#define MAX 100 
int stack[MAX]; 
int top = -1; 
int maxSize; 

void init(int size) { 
    maxSize = size; 
    stack[maxSize]; 
} 

int isFull() { 
    if(top==maxSize-1) 
      return 1; 
    else 
      return 0; 
} 

int isEmpty() { 
    if(top==-1) 
      return 1; 
    else 
      return 0; 
} 

void push() { 
    if (!isFull()) { 
        top++; 
        printf("Enter element : "); 
        scanf("%d",&stack[top]); 
        printf("Push operation success\n"); 
    } else { 
        printf("Stack overflow\n"); 
    } 
} 

int pop() { 
    if (!isEmpty()) { 
        top--; 
        printf("Top value deleted from stack\n"); 
    } else { 
        printf("Stack underflow\n"); 
    } 
} 

int peek() { 
    if (!isEmpty()) { 
        printf("Peek value of stack :  %d\n", stack[top]); 
    } else { 
        printf("Stack is underflow\n"); 
    }  } 

int display() { 
    if (!isEmpty()) { 
        printf("Elements of stack: \n"); 
        for (int i = 0; i<=maxSize-1; i++) { 
            printf("%d\n", stack[i]); 
        } 
    } else { 
       printf("Stack is underflow\n"); 
    } 
} 

int main() { 
    int choice, size; 
    printf("Enter the size of the stack (up to 100): "); 
    scanf("%d", &size); 
    init(size); 
    if (size > MAX) { 
        printf("Error: Size exceeds the maximum allowed (%d)\n", MAX); 
        return 0; 
    } 
    while (1) { 
        printf("\n** STACK MENU **\n"); 
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        switch (choice) { 
            case 1:  push(); 
                      break; 
            case 2:  pop(); 
                    break; 
            case 3: peek(); 
                   break; 
            case 4: display(); 
                    break; 
            default:  printf("Invalid choice! Please try again.\n"); 
                    break; 
        } 
    } 
} 