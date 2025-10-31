

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*top=NULL;

struct node*create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;

};

void insert(int data){
    struct node*newnode=create(data);

    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    if(top==NULL){
        printf("Stack is empty!\n");
        return;
    }
    int t=top->data;

    struct node*temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
    printf("%d is successfully deleted from stack\n",t);

}


void display(){
    struct node*temp = top;
    if(top==NULL){
        printf("Stack is empty!\n");
        return;
    }
    printf("\nStack elements: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main(){
    int choice,data,c=1;
    printf("1.Insert\n2.Pop\n3.Display\n4.Exit\n");
    while(c==1){
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value u want to insert : ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                c=0;
            }
    }

    return 0;
}
