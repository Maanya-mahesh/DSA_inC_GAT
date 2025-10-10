#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack {
    int data[SIZE];
    int top;
};
typedef struct stack Stack ;
void push(Stack* s,int item) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow! Cannot push");
        return; }
    s->data[++s->top] = item;
    printf("%d pushed to stack\n",item);
}

void pop(Stack* s) {
    if (s->top ==-1) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    printf("Popped element: %d\n", s->data[s->top--]);
}

void display(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i<=s->top;i++) {
        printf("%d ", s->data[i]);
    }
}

int main() {
    Stack s;
    s.top = -1;
    int choice, item;
    while (1) {
        printf("\nStack Operations menu: \n");
        printf("1. Push \n 2. Pop \n 3. Display\n 4. exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
