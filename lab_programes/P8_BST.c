#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;
NODE createBST(NODE root, int key) {
    NODE temp, curr, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = temp->right = NULL;
    if (root == NULL)
        return temp;
    curr = root;
    prev = NULL;
    while (curr != NULL) {
        prev = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (key < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main() {
    NODE root = NULL;
    int item, choice;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                root = createBST(root, item);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
