

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

    // Displaying the cricular linked list
    printf("\nOriginal Circular Linked List: ");
    temp = head;
    while (temp->next != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d ->",temp->data);
    printf("%d ->",temp->next->data);
    printf("NULL\n");

    return 0;
}

