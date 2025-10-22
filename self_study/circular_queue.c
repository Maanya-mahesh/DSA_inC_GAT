#include <stdio.h>
#include<stdlib.h>
#define SIZE 4
struct queue {
    int r,f;
    int data[SIZE];
};
typedef struct queue Queue;
void enqueue(Queue *q,int item){
    if (q->f==(q->r+1)%SIZE){
        printf("queue is full");
    } else {
        q->r=(q->r+1)%SIZE;
        q->data[q->r]=item;
        if (q->f==-1){q->f=0;}
    }
}
void dequeue(Queue *q){
    if (q->f==-1){
        printf("queue is empty");
    } else {printf("element deleted is = %d",q->data[q->f]);
        if (q->f==q->r){q->f=-1;
        q->r=-1;}
        else {q->f=(q->f+1)%SIZE;}
    }
}
void display(Queue q){//no need of pointers here
    if (q.f==-1){
        printf("queue is empty");}
    else{
        printf("queue content:");
        for (int i=q.f;i!=q.r;i=(i+1)%SIZE){
            printf("%d\t",q.data[i]);
        }
        printf("%d",q.data[q.r]);
    }
}
int main() {
    int item ,choice;
    Queue q;
    q.f=-1;
    q.r=-1;
    while(1){
        printf("\n 1.insert \n2.delete \n 3.display \n4.exit");
        printf("read choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1 :
            printf("read item to insert:");
            scanf("%d",&item);
            enqueue(&q,item);
            break;
            case 2:
            dequeue(&q);
            break;
            case 3:
            display(q);
            break;
            case 4:
            exit(0);
            default:exit(0);}}
    return 0;
}
