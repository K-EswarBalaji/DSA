


#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node * right;
};

struct node*create(){
    int d;
    struct node*newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory is not alloted");
    }
    else{
        printf("\nEnter the value of data : ");
        scanf("%d",&d);
        if(d==-1){
            return 0;
        }
        newnode->data=d;
        printf("\nEnter the left value of %d",d);
        newnode->left=create();
        printf("\nEnter the right value of %d",d);
        newnode->right=create();
        return newnode;
    }
}

void preorder(struct node*root){
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node*root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}

void postorder(struct node*root){
    if(root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}

int main(){
    struct node*root;
    root=create();

    printf("\nPreorder is : ");
    preorder(root);
    printf("\n");
    printf("\nInorder is : ");
    inorder(root);
    printf("\n");
    printf("\nPostorder is : ");
    postorder(root);
    return 0;

}

