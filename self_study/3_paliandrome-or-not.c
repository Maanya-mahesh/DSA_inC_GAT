#include <stdio.h>
#include <string.h>
#define SIZE 100
struct stack {
    char data[SIZE];
    int top;};
typedef struct stack Stack;
void push(Stack *s, char item) {
    if (s->top == SIZE - 1) {
        printf("Stack overflow\n");
        return;}
    s->data[++s->top] = item;
}
char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';   }
    return s->data[s->top--];
}
int isPalindrome(char *str) {
    Stack s;
    s.top = -1;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);}
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;  // NOT Case
  }}
    return 1;  // Is a palindrome character array
}

int main() {
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is NOT a palindrome.\n");
    }

    return 0;
}
