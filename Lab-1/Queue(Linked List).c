#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node*front=NULL,*rear=NULL,*temp,*newnode;

void enqueue() {
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nMemory is not alloted\n");
    }
    else{
        printf("\nEnter the value of data : ");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(front==NULL && rear==NULL){
            front=rear=newnode;
            printf("%d is added into queue\n",newnode->data);
        }
        else{
            rear->next=newnode;
            rear=newnode;
            printf("%d is added into queue\n",newnode->data);
        }

    }

}

void dequeue() {
    if(front == NULL) {
        printf("\nQueue is empty!!\n");
    } else {
        temp = front;
        front = front->next;
        printf("%d is popped\n", temp->data);
        free(temp);

        if(front == NULL) {
            rear = NULL;
        }
    }
}


void display(){
    if(front == NULL) {
            printf("\nQueue is empty!!\n");
    }
    else {
        printf("Queue elements: ");
        temp=front;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("Null\n");

    }
}

void peek() {
    if(front == NULL) {
            printf("\nQueue is empty!!\n");
    }
    else {
        printf("\nTop node data value is %d\n",front->data);
    }

}



int main() {
    int o = 1;
    printf("\n1 -- Enqueue\n2 -- Dequeue\n3 -- Display\n4 -- Peek\n5 -- Exit\n");

    while(o) {
        int choice;

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                o = 0;
                break;
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}
