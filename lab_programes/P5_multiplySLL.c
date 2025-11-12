#include<stdio.h>
#include<stdlib.h>
struct node {
    int co, po;
    struct node *addr;
};
typedef struct node* NODE;
NODE insertend(NODE start, int co, int po) {
    NODE temp, current;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if (start == NULL)
        return temp;
    else {
        current = start;
        while (current->addr != NULL) {
            current = current->addr;
        }
        current->addr = temp;
        return start;
    }
}
void display(NODE Start) {
    NODE temp;
    if (Start == NULL)
        printf("Polynomial empty\n");
    else {
        temp = Start;
        while (temp->addr != NULL) {
            printf("%d*x^%d + ", temp->co, temp->po);
            temp = temp->addr;
        }
        printf("%d*x^%d\n", temp->co, temp->po);
    }
}
NODE addterm(NODE res, int co, int po) {
    NODE temp,current;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if (res == NULL)
        return temp;
    else {
        current = res;
        while (current != NULL) {
            if (current->po == po) {
                current->co += co;
                return res;
            }
            current = current->addr;
        }
        if (current == NULL) {
            res= insertend(res,co,po);
        return res;
    }
    }
}

NODE multiply(NODE poly1, NODE poly2) {
    NODE p1, p2, res = NULL;
    for (p1 = poly1; p1 != NULL; p1 = p1->addr)
        for (p2 = poly2; p2 != NULL; p2 = p2->addr)
            res = addterm(res, p1->co * p2->co, p1->po + p2->po);
    return res;
}

int main() {
    NODE poly1 = NULL, poly2 = NULL, poly = NULL;
    int n, i, co, po;
    printf("Read no. of terms in 1st polynomial: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Read co & po of %d term: ", i);
        scanf("%d%d", &co, &po);
        poly1 = insertend(poly1, co, po);
    }
    printf("Polynomial 1 is: ");
    display(poly1);
    printf("Read no. of terms in 2nd polynomial: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Read co & po of %d term: ", i);
        scanf("%d%d", &co, &po);
        poly2 = insertend(poly2, co, po);
    }
    printf("Polynomial 2 is: ");
    display(poly2);
    poly = multiply(poly1, poly2);
    printf("\nResultant polynomial is: \n");
    display(poly);
    return 0;
  }
