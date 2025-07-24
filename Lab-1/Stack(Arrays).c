
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;


void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}


int peek() {
    if(top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}


void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


int main() {
    int choice, value;

    while(1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Top element is %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

