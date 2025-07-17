
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    // Creating Linked List
    while (choice) {
        newnode = (struct node*) malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter the value of the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (1 for yes / 0 for no)? ");
        scanf("%d", &choice);
    }

    // Displaying the linked list
    printf("\nOriginal Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Insertion at beginning
    newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("\nEnter the data to insert at beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    // Displaying updated list
    printf("\nUpdated Linked List (After Insertion at Beginning): ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


    // Insertion at ending
    newnode=(struct node*) malloc(sizeof(struct node));
    if (newnode==NULL){
            printf("Memory is not alloted\n");
            return 1;
    }
    printf("\nEnter the data to insert at ending : ");
    scanf("%d",&newnode -> data);
    newnode->next=0;
    temp=head;
    while(temp ->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;

    printf("\nUpdated Linked List (After Insertion at ending): ");
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null\n");


    //Inserting After a position

    int pos;
    int c;
    printf("\nDo you want to insert a node after a element?(0,1) : ");
    scanf("%d",&c);
    if (c==1){
        newnode=(struct node*) malloc (sizeof(struct node));
        if(newnode==NULL){
            printf("Memory not alloted\n");
            return 1;
        }
        printf("\nEnter the position after which to insert: ");
        scanf("%d",&pos);
        printf("\nEnter the data value to insert : ");
        scanf("%d",&newnode -> data);
        newnode->next=NULL;
        temp = head;
        int i=1;
        while(i<pos && temp!=NULL){
            temp=temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid position: list is shorter than %d nodes.\n", pos);
            free(newnode);
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }

        printf("\nUpdated Linked List by inserting a node after given position : ");
        temp=head;
        while(temp!=0){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("Null\n");

    }

    //Deletion at Beginning


    printf("\nDo you want to delete node at beginning?(0,1) : ");
    scanf("%d",&c);
    if (c==1){
        temp=head;
        head=temp->next;
        free(temp);
        printf("\nUpdated Linked List after deleting at beginning is : ");
        temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("Null\n");
    }

    //Deleting at end
    struct node*prenode;
    printf("\nDo you want to delete node at ending?(0,1) : ");
    scanf("%d",&c);
    if (c==1){
        temp=head;
        while(temp->next!=0){
            prenode=temp;
            temp=temp->next;
        }
        prenode->next=0;
        free(temp);

        printf("\nUpdated Linked List after deleting at ending is : ");
        temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("Null\n");
    }

    return 0;
}




