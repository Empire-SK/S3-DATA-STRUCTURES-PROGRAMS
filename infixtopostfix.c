#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
