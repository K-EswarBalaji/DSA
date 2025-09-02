#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Recursive function to create tree from user input
struct node* create() {
    int x;
    printf("\nEnter the value of data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    printf("Enter left child of %d", x);
    newnode->left = create();

    printf("Enter right child of %d", x);
    newnode->right = create();

    return newnode;
}

// Function to compute the height of the tree
int height(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Recursive function to convert tree to array (1-based index)
void treeToArray(struct node* root, int arr[], int index, int size) {
    if (root == NULL || index > size) {
        return;
    }
    arr[index] = root->data;
    treeToArray(root->left, arr, 2 * index, size);
    treeToArray(root->right, arr, 2 * index + 1, size);
}

int main() {
    struct node* root = create();

    int h = height(root);
    int size = (1 << h); // 2^h nodes, index 1 to 2^h-1

    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 1; i < size; i++) arr[i] = -1; // initialize

    treeToArray(root, arr, 1, size - 1);

    printf("\nArray representation of binary tree:\n");
    for (int i = 1; i < size; i++) {
        if (arr[i] != -1)
            printf("%d ", arr[i]);
        else
            printf("_ ");
    }
    printf("\n");

    free(arr);
    return 0;
}
