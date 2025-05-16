#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Include ctype.h for tolower function

struct node {
    char data;
    struct node *rlink;
    struct node *llink;
};

struct node *head = NULL;

void create(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->rlink = NULL;
    new_node->llink = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->rlink = new_node;
        new_node->llink = temp;
    }
}

int is_palindrome() {
    if (head == NULL) {
        return 1;
    } else {
        struct node *left = head;
        struct node *right = head;
        while (right->rlink != NULL) {
            right = right->rlink;
        }

        while (left != right && left->llink != right) {
            if (tolower(left->data) != tolower(right->data)) {
                return 0;
            }
            left = left->rlink;
            right = right->llink;
        }
        return 1;
    }
}

int main() {
    char ch[20];
    printf("Enter the string: ");
    scanf("%19s", ch);  // Limit input to prevent buffer overflow

    for (int i = 0; ch[i] != '\0'; i++) {
        create(ch[i]);
    }

    if (is_palindrome()) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
