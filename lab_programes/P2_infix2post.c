#include <stdio.h>
#include <ctype.h>
#define SIZE 20
struct stack {
    char data[SIZE];
    int top;
};
typedef struct stack Stack;

void push(Stack* s, char item) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow! Cannot push");
        return;
    }
    s->data[++s->top] = item;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return '\0';
    }
    return s->data[s->top--];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix) {
    Stack s;
    s.top = -1;
    int i = 0;
    char symbol;
    while (infix[i] != '\0') {
        symbol=infix[i];
        if (isalnum(symbol)) {
            printf("%c",symbol);}
        else if (symbol == '(') {
            push(&s, symbol);} 
        else if (symbol == ')') {
            while (s.top != -1 && s.data[s.top] != '(') {
                printf("%c", pop(&s)); }
            if (s.top != -1) {
                pop(&s); 
            }
        } else {
            while (s.top != -1 && precedence(s.data[s.top]) >= precedence(symbol)) {
                printf("%c", pop(&s));
            }
            push(&s,symbol);
        }
        i++;
    }
    while (s.top != -1) {
        printf("%c", pop(&s));
    }
}

int main() {
    char infix[SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    printf("Postfix expression: ");
    infixToPostfix(infix);
    printf("\n");
    return 0;
}
