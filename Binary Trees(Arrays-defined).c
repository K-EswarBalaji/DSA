#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to store binary tree in array (0-based index)
void treeToArray(struct node* root, int arr[], int index, int size) {
    if (root == NULL || index >= size) {
        return;
    }
    arr[index] = root->data;
    treeToArray(root->left, arr, 2 * index + 1, size);
    treeToArray(root->right, arr, 2 * index + 2, size);
}

// Example usage
int main() {
    // Construct binary tree
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);



    int size = 15; // Enough to store all nodes (for small example)
    int arr[size];
    for (int i = 0; i < size; i++) arr[i] = -1; // Initialize empty slots

    treeToArray(root, arr, 0, size);

    printf("Array representation of binary tree:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1)
            printf("%d ", arr[i]);
        else
            printf("_ "); // Empty slot
    }
    printf("\n");

    return 0;
}
