#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *newNode;

void push() {
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to push: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Pushed %d onto the stack.\n", newNode->data);
}

void pop() {
    if (head == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = head;
        head = head->next;
        printf("Popped: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack (top to bottom): ");
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    int ch;
    do {
        printf("\n\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid Choice\n");
        }
    } while (ch != 4);
}
