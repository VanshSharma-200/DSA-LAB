#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data) {
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    if (new == NULL) {
        printf("Stack Overflow!\n");
        return;
    }

    new->data = data;
    new->next = top;
    top = new;

    printf("%d pushed into the stack.\n", data);
}

void pop() {
    struct Node *d;

    if (top == NULL) {
        printf("Stack Underflow!\n");
    }
    d = top;
    printf("%d popped from the stack.\n", d->data);

    top = top->next;
    free(d);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    }

    printf("Top element is: %d\n", top->data);
}

void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
    }

    printf("Stack elements are:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main() {
    int choice, data;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(1);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
