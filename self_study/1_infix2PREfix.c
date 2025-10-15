#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
struct stack {
    char data[SIZE];
    int top;};
typedef struct stack Stack;

void push(Stack *s, char item) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;}
    s->data[++s->top] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';}
    return s->data[s->top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0; }
}

void infixToPrefix(char *infix) {
    Stack s;
    s.top = -1;
    char prefix[SIZE];
    int i, j = SIZE - 1;
    int len = strlen(infix);

    for (i = len - 1; i >= 0; i--) {
        char ch = infix[i];
        if (isalnum(ch)) {
            prefix[j--] = ch;
        } else if (ch == ')') {
            push(&s, ch);
        } else if (ch == '(') {
            while (s.top != -1) {
                char temp = pop(&s);
                if (temp == ')') break;
                prefix[j--] = temp;
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
            while (s.top != -1) {
                char temp = s.data[s.top];  // direct access
                if (temp == ')' || precedence(temp) > precedence(ch)) {
                    prefix[j--] = pop(&s);
                } else {
                    break;
                }
            }
            push(&s, ch);
        }
    }

    while (s.top != -1) {
        prefix[j--] = pop(&s);
    }

    printf("Prefix expression: ");
    for (i = j + 1; i < SIZE; i++) {
        printf("%c", prefix[i]);
    }
    printf("\n");
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix);
    return 0;
}
