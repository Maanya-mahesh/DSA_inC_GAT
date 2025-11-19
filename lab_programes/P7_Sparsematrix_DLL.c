#include <stdio.h>
#include <stdlib.h>
struct node {
    int row;
    int col;
    int data;
    struct node* next;
    struct node* prev;};
typedef struct node* NODE;
NODE insertend(NODE start ,int row, int col, int item){
    NODE temp,curr;
    temp= (NODE)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL) {
        return temp;
    } else {
        curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
        return start;
}}
void display(NODE start) {
    NODE temp;
    if (start == NULL)
        printf("List is empty\n");
    temp= start;
    printf("\n.ROW \t COLUMN \t DATA \n");
    while (temp != NULL) {
        printf("%d \t %d \t %d\n", temp->row,temp->col,temp->data);
        temp = temp->next;
    }
}
void displaymatrix(NODE start, int m , int n) {
    int i, j;
    NODE temp = start;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (temp != NULL && temp->row==i && temp->col==j){
                printf("%d\t",temp->data);
                temp=temp->next;
            }
            else {
                printf("0\t");
            }
        }printf("\n");
    }
}
int main() {
    NODE start = NULL;
    int i, j, m, n, item;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    printf("Enter elements of the %dx%d matrix:\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &item);
            if (item != 0) {
                start = insertend(start, i, j, item);
            }
        }
    }
    printf("actual matrix is :");
    displaymatrix(start, m, n);

    return 0;
}
