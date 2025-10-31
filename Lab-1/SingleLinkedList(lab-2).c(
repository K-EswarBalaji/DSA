



#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*create(int data){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node*head=NULL;
void insert(int data){
    struct node*node=create(data);
    if(head==NULL){
        head=node;
    }
    else{
        struct node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
    }
}

void display(){
    struct node*temp = head;
    printf("\nLinked list elements: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void insertstart(int data){
    struct node*node=create(data);
    node->next=head;
    head=node;
}


void insertend(int data){
    struct node*node=create(data);
    if (head == NULL) {
        head = node;
        return;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
}

void deletefirst(){
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }
    struct node*temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
}

int main(){

    int n=1,data;

    while(n==1){
        printf("\nEnter the value u want to insert : ");
        scanf("%d",&data);
        insert(data);
        printf("Insertion completed successfully");
        printf("\nDo you want to insert another element (0=No,1=Yes) : ");
        scanf("%d",&n);
    }
    display();

    printf("\nEnter the value u want to insert at start : ");
    scanf("%d",&data);
    insertstart(data);
    display();

    printf("\nEnter the value u want to insert at end : ");
    scanf("%d",&data);
    insertend(data);


    display();

    printf("\nAfter deletion of first node : ");
    deletefirst();


    display();

    return 0;
}
