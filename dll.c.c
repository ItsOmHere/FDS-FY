#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *temp, *newNode, *prevNode;

void insertAtFirst() {
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtLast() {
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0 || head == NULL) {
        printf("Invalid operation\n");
        return;
    }

    temp = head;

    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int ch, ch1;

    do {
        printf("\n\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n1. Insert At First\n2. Insert At Last\n3. Insert At Position\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: insertAtFirst(); break;
                    case 2: insertAtLast(); break;
                    case 3: insertAtPosition(); break;
                    default: printf("Wrong choice\n");
                }
                break;

            case 2:
                printf("\n1. Delete At First\n2. Delete At Last\n3. Delete At Position\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: deleteAtFirst(); break;
                    case 2: deleteAtLast(); break;
                    case 3: deleteAtPosition(); break;
                    default: printf("Wrong choice\n");
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Wrong choice\n");
        }

    } while (ch != 4);
}
