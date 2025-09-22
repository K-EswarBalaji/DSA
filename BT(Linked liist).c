

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node*insert(struct node*root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
    
    
}

void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


int main(){
    int n,data;
    struct node*root=NULL;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d",&data);
        root=insert(root,data);
    } 
    printf("\nInorder traversal of the BST: ");
    inorder(root);
    printf("\n");
    
    
    return 0;
}







