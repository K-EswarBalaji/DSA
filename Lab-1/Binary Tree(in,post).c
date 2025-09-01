
#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node * create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

int search(int in[],int start,int end,int value){
    for(int i=start;i<=end;i++){
        if(in[i]==value){
            return i;
        }
    }
    return -1;
}

struct node* buildtree(int in[],int post[],int inStart,int inEnd,int *postIndex){

    if(inStart>inEnd){
        return NULL;
    }

    struct node * root= create(post[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd){
        return root;
    }

    int inIndex=search(in,inStart,inEnd,root->data);

    root->right=buildtree(in,post,inIndex+1,inEnd,postIndex);
    root->left=buildtree(in,post,inStart,inIndex-1,postIndex);

    return root;

}

void preorder(struct node*root){
    if (root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int post[]={8,10,11,9,4,5,2,6,7,3,1};
    int in[]={8,4,10,9,11,2,5,1,6,3,7};

    int n=sizeof(in)/sizeof(in[0]);
    int postIndex=n-1;

    struct node*root=buildtree(in,post,0,n-1,&postIndex);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}
