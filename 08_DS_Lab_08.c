
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int x) {
    if (root == NULL) {
        root = malloc(sizeof(struct node));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void search(struct node *root, int x) {
    if (root == NULL)
        printf("Not Found\n");
    else if (x == root->data)
        printf("Found\n");
    else if (x < root->data)
        search(root->left, x);
    else
        search(root->right, x);
}3


void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = NULL;
    int ch, x;

    do {
        printf("\n1.Insert  2.Search  3.Preorder  4.Postorder  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            printf("Enter value: ");
            scanf("%d", &x);
            search(root, x);
        }
        else if (ch == 3) {
            preorder(root);
            printf("\n");
        }
        else if (ch == 4) {
            postorder(root);
            printf("\n");
        }

    } while (ch != 5);

    return 0;
}

