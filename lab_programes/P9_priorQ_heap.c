#include <stdio.h>
#include <stdlib.h>
void heapify(int a[], int n){
    int i, v, k, j, flag = 0;
    for (i = n / 2; i >= 1; i--){
        k = i;
        v = a[k]; 
        flag = 0;
        while (!flag && 2 * k <= n){
            j = 2 * k;
            if (j < n){
                if ( a[j] < a[j + 1])  
                j = j + 1;}
            if (v >= a[j])
                flag = 1;
            else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
        flag=0;
    }
}

int main(){
    int n, a[50], i, ch;
    while(1){
        printf("\n1. Create Heap");
        printf("\n2. Extract Max");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter number of elements: ");
            scanf("%d", &n);

            printf("\nEnter elements:\n");
            for (i = 1; i <= n; i++)
                scanf("%d", &a[i]);

            heapify(a, n);

            printf("\nElements after constructing heap:\n");
            for (i = 1; i <= n; i++)
                printf("%d\t", a[i]);
            break;

        case 2:
            if (n >= 1)
            {
                printf("\nKey deleted = %d\n", a[1]);
                a[1] = a[n];   
                n = n - 1;

                heapify(a, n);

                printf("\nHeap after deleting max:\n");
                for (i = 1; i <= n; i++)
                    printf("%d\t", a[i]);
            }
            else
            {
                printf("\nNo element to delete\n");
            }
            break;

        default:
            exit(0);
        }
    }

    return 0;
}
