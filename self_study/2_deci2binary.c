#include <stdio.h>
#define SIZE 32
struct stack {
    int data[SIZE];
    int top;
};
typedef struct stack Stack;
void push(Stack *s, int item) {
    if (s->top == SIZE - 1) {
        printf("Stack overflow\n");
        return;}
    s->data[++s->top] = item;
}
int pop(Stack *s) {
    if (s->top == -1) {
        return -1;}
    return s->data[s->top--];
}
void decimalToBinary(int num) {
    Stack s;
    s.top = -1;
    if (num == 0) {
        printf("Binary: 0\n");
        return;}
    while (num > 0) {
        push(&s, num % 2);
        num /= 2;}
    printf("Binary: ");
    while (s.top != -1) {
        printf("%d", pop(&s));}
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    return 0;
}
