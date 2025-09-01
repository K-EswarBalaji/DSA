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


int search(int in[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (in[i] == value){
            return i;
        }
    }
    return -1;
}

struct node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd){
        return NULL;
    }
    // Pick current node from preorder
    struct node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    // If no children
    if (inStart == inEnd){
        return root;
    }

    // Find root index in inorder[]
    int inIndex = search(in, inStart, inEnd, root->data);

    // Build subtrees
    root->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    root->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct node* root) {
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int pre[] = {1,2,4,8,9,10,11,5,3,6,7};
    int in[]  = {8,4,10,9,11,2,5,1,6,3,7};
    int n = sizeof(in) / sizeof(in[0]);

    int preIndex = 0;
    struct node* root = buildTree(in, pre, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
