#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    if (root->data == key) {
        printf("Found\n");
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct node* deleteleaf(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->data == key) {
        if (root->left == NULL && root->right == NULL) {
            printf("Leaf node %d deleted\n", key);
            free(root);
            return NULL;
        } else {
            printf("Not a leaf node, cannot delete\n");
            return root;
        }
    }

    if (key < root->data)
        root->left = deleteleaf(root->left, key);
    else
        root->right = deleteleaf(root->right, key);

    return root;
}

int main() {
    struct node* root = NULL;
    int choice, value;

    while(1) {
        printf("\n-- BST --\n");
        printf("1. Search element\n");
        printf("2. Insert element\n");
        printf("3. Delete leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element inserted\n");
                break;

            case 3:
                printf("Enter leaf node to delete: ");
                scanf("%d", &value);
                root = deleteleaf(root, value);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
