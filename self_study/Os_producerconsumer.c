#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 10

int mutex = 1;
int Full = 0;
int Empty, n, item, item1;
int buffer[BUFFERSIZE];
int in = 0, out = 0;

void wait(int *s) {
    while (*s <= 0);
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void Producer() {
    if ((in - out) >= n) {
        printf("Cannot add item, buffer full\n");
        return;
    }
    wait(&Empty);
    wait(&mutex);
    printf("Enter an Item ");
    scanf("%d", &item);
    buffer[in % BUFFERSIZE] = item;
    in++;
    signal(&mutex);
    signal(&Full);
}

void consumer() {
    if (out == in) {
        printf("No items to Consume\n");
        return;
    }
    wait(&Full);
    wait(&mutex);
    item1 = buffer[out % BUFFERSIZE];
    printf("consumed item = %d\n", item1);
    out++;
    signal(&mutex);
    signal(&Empty);
}

int main() {
    int choice;
    printf("Enter the number of items (n)\n"items (n)\n");
    scanf("%d", &n);
    if (n > BUFFERSIZE) {
        printf("Buffer size exceeded max allowed is %d\n", BUFFERSIZE);
        return 1;
    }
    Empty = n;
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. exit\nEnter your choice");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
