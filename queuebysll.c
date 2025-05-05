#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *temp, *newNode;

void enqueue() {
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to enqueue: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d into the queue.\n", newNode->data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        temp = front;
        front = front->next;
        if (front == NULL) rear = NULL; 
        printf("Dequeued: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue (front to rear): ");
        temp = front;
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
        printf("\n\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid Choice\n");
        }
    } while (ch != 4);
}
