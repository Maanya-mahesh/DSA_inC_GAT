#include <stdio.h>
#define SIZE 100
struct stack {
    char data[SIZE];
    int top;};
typedef struct stack Stack;
void push(Stack *s, char ch) {
    if (s->top == SIZE - 1) {
        printf("Stack overflow\n");
        return;  }
    s->data[++s->top] = ch;
}
char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';}
    return s->data[s->top--];
}

void checkExpression(char *expr) {
    Stack s;
    s.top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop(&s);
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                printf("Invalid expression\n");
                return;}                                }
    }

    if (s.top == -1) {
        printf("Valid expression\n");
    } else {
        printf("Invalid expression\n");
    }
}

int main() {
    char expr[SIZE];
    printf("Enter an expression: ");
    scanf("%s", expr);
    checkExpression(expr);
    return 0;
}
