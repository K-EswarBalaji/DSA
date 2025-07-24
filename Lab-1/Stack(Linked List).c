#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node*top=NULL,*temp,*newnode;

void push() {
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nMemory is not alloted\n");
    }
    else{
        printf("\nEnter the value you want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next=top;
        top=newnode;
        printf("Inserted value is %d\n",top->data);
    }

}


void pop() {
        if(top == NULL) {
            printf("\nStack is empty!!\n");
        }
        else {
            temp=top;
            top=temp->next;
            printf("%d is popped\n",temp->data);
            free(temp);
        }
}

void display(){
    if(top == NULL) {
            printf("\nStack is empty!!\n");
    }
    else {
        printf("Stack elements: ");
        temp=top;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;

        }
        printf("Null\n");

    }
}

void peek() {
    if(top == NULL) {
            printf("\nStack is empty!!\n");
    }
    else {
        printf("\nTop node data value is %d\n",top->data);
    }

}



int main() {
    int o = 1;
    printf("\n1 -- Push\n2 -- Pop\n3 -- Display\n4 -- Peek\n5 -- Exit\n");

    while(o) {
        int choice;

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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
