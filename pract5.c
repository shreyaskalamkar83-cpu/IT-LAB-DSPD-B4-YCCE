#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node *root, int data) {
    if (root == NULL)
        return createNode(data);

    int choice;
    printf("Insert to left(1) or right(2) of %d: ", root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(struct node *root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (search(root->left, key)) return 1;
    return search(root->right, key);
}

int main() {
    struct node *root = NULL;
    int n, data, key;

    printf("Enter data for root node: ");
    scanf("%d", &data);
    root = createNode(data);

    while (1) {
        printf("1 to insert node, 0 to stop: ");
        scanf("%d", &n);
        if (n == 0) break;

        printf("Enter data: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    // Removed: printf("Enter element to search:");
    scanf("%d", &key);

    if (search(root, key)) printf("Found\n");
    else printf("Not found\n");

    return 0;
}
