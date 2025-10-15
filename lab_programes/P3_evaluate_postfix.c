#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <math.h>
#define SIZE 20

struct stack {
    int data[SIZE];
    int top;
};
typedef struct stack Stack;

void push(Stack *s ,float item) {
    if (s->top== SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top]=item;
}
int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}
float compute(float opr1,char symbol,float opr2){
    switch (symbol) {
                case '+': return opr1+opr2; break;
                case '-': return opr1-opr2; break;
                case '*': return opr1*opr2; break;
                case '/': return opr1/opr2; break;
                case '^' : return pow(opr1,opr2);break;
                default : printf("invalid operator");break;
            }
    
}
float evaluatePostfix(Stack *s,char postfix[20]) {
    s->top = -1;
    int i = 0;
    float opr1,opr2,result;
    char symbol;
    for (i=0;postfix[i] != '\0';i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            push(s,symbol-'0');
        } else {
            opr2=pop(s);
            opr1=pop(s);
            result =compute(opr1,symbol,opr2);
            push(s,result);
        }}
        return pop(s);
}

int main() {
    char postfix[20];
    Stack s;
    s.top=-1;
    float result;
    printf("read postfix expression:");
    scanf("%s",postfix);
    result = evaluatePostfix(&s,postfix);
    printf("Result: %.2f\n", result);
    return 0;
}
