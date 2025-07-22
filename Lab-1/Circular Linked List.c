

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    // Creating Circular Linked List
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
        temp->next=head;

        printf("Do you want to continue (1 for yes / 0 for no)? ");
        scanf("%d", &choice);
    }

    // Displaying the circular linked list
    printf("\nOriginal Circular Linked List: ");
    temp = head;
    while (temp->next != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d ->",temp->data);
    printf("%d\n",temp->next->data);


    //Insertion at beginning
    int c;
    printf("\nDo you want to insert at beginning (0,1)? : ");
    scanf("%d",&c);
    if(c==1){
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the data value : ");
        scanf("%d",&newnode->data);
        newnode->next=0;

        temp=head;


        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        printf("\nCircular Linked List after inserting at beginning : ");
        temp = head;
        while (temp->next != head) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d ->",temp->data);
        printf("%d\n",temp->next->data);
    }

    //Insertion at ending
    printf("\nDo you want to insert at ending (0,1)? : ");
    scanf("%d",&c);
    if(c==1){
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the data value : ");
        scanf("%d",&newnode->data);
        newnode->next=head;

        temp=head;
        while(temp->next!=head){
             temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;


        printf("\nCircular Linked List after inserting at ending : ");
        temp = head;
        while (temp->next != head) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d ->",temp->data);
        printf("%d\n",temp->next->data);
    }

    //deleting at beginning
    printf("\nDo you want to deleting at beginning (0,1)? : ");
    scanf("%d",&c);
    if(c==1){
        struct node*p,*a;
        a=head;
        temp=head;
        p=temp->next;
         while(temp->next!=head){
             temp=temp->next;
        }
        temp->next=p;
        head=p;
        temp = a;
        free(temp);
        printf("\nCircular Linked List after deleting at beginning : ");
        temp = head;
        while (temp->next != head) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d ->",temp->data);
        printf("%d\n",temp->next->data);
    }

    //deleting at ending
    printf("\nDo you want to deleting at ending (0,1)? : ");
    scanf("%d",&c);
    if(c==1){
        if (head == NULL) {
        printf("List is empty\n");
        }
        else{
            struct node*p;
            temp=head;
            while(temp->next->next!=head){
                temp=temp->next;
            }
            temp->next=head;
            p=temp->next->next;
            free(p);
            printf("\nCircular Linked List after deleting at ending : ");
            temp = head;
            while (temp->next != head) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("%d ->",temp->data);
            printf("%d\n",temp->next->data);
        }
    }
    return 0;
}
