
#include <stdio.h>
#include <stdlib.h>
#define n 5

int a[n];
int front =-1;
int rear=-1;

void enqueue(){
    int v;
    printf("\nEnter the value : ");
    scanf("%d",&v);
    if(front==-1 && rear==-1){
        front=rear=0;
        a[rear]=v;
        printf("%d has been added\n",v);
    }
    else if((rear+1)%n==front){
        printf("\nQueue is full\n");
    }
    else{
        rear=(rear+1)%n;
        a[rear]=v;
        printf("%d has been added\n",v);
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("\nQueue is Empty\n");
    }
    else if(front==rear){
        printf("%d is deleted fom the Queue\n",a[front]);
        printf("Now queue is empty\n");
        front=rear=-1;
    }
    else{
         printf("%d is deleted fom the Queue\n",a[front]);
         front=(front+1)%n;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("\nQueue is Empty");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d\n",a[i]);
            i=(i+1)%n;
        }
        printf("%d\n",a[rear]);
    }

}

int main() {
    int o = 1;
    printf("1 -- Enqueue\n2 -- Dequeue\n3 -- Display\n4 -- Exit\n");

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
                o = 0;
                break;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}


