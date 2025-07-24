
#include <stdio.h>
#include <stdlib.h>
#define n 5

int a[n];
int front=-1;
int rear=-1;

void enqueue() {
    int b;
    printf("Enter the data value to insert : ");
    scanf("%d",&b);
    if(rear==n-1){
        printf("\nQueue Overflow\n");
    }
    else if (front==-1 && rear==-1){
        front=rear=0;
        a[rear]=b;
        printf("%d is inserted\n",b);
    }
    else{
        rear++;
        a[rear]=b;
        printf("%d is inserted\n",b);
    }

}

void dequeue() {
    if(front == -1 && rear==-1) {
        printf("\nQueue is empty!!\n");
    }
    else if(front==rear) {
        printf("\n%d is deleted from the array\n", a[front]);
        front=rear=-1;
    }
    else{
        printf("\n%d is deleted from the array\n",a[front]);
        front++;
    }
}


void display(){
    int i;
    if(front == -1 && rear==-1) {
            printf("\nQueue is empty!!\n");
    }

    else {
        for (i=front;i<=rear;i++){
            printf("%d ",a[i]);
        }
    }
}

void peek() {
    if(front == -1 && rear==-1) {
            printf("\nQueue is empty!!\n");
    }
    else {
        printf("\nFront value in queue is...");
    }

}

int main() {
    int o = 1;
    printf("1 -- Enqueue\n2 -- Dequeue\n3 -- Display\n4 -- Peek\n5 -- Exit\n");

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
