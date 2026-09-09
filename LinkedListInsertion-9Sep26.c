#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Display linked list
void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insertion at beginning
struct node* insertBeginning(struct node *head, int data) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = head;

    head = newNode;

    return head;
}

// Insertion at middle / given position
struct node* insertMiddle(struct node *head, int data, int position) {
    struct node *newNode;
    struct node *temp;
    int i;

    // If position is 1, insert at beginning
    if (position == 1) {
        newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head;

        return newNode;
    }

    if (head == NULL || position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;

    temp = head;

    // Move to the node before the required position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Insertion at last
struct node* insertLast(struct node *head, int data) {
    struct node *newNode;
    struct node *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

void main() {
    int choice = 1;
    int data;
    int position;

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;

    // Creating the original linked list
    while (choice == 1) {

        newNode = (struct node*)malloc(sizeof(struct node));

        printf("ENTER DATA OF NEW: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Enter choice 1 if you want to add a node: ");
        scanf("%d", &choice);
    }

    // Display original list
    printf("\nOriginal Linked List: ");
    display(head);

    // Insert at beginning
    printf("\nEnter data to insert at beginning: ");
    scanf("%d", &data);

    head = insertBeginning(head, data);

    printf("After insertion at beginning: ");
    display(head);

    // Insert at middle
    printf("\nEnter data to insert in middle: ");
    scanf("%d", &data);

    printf("Enter position: ");
    scanf("%d", &position);

    head = insertMiddle(head, data, position);

    printf("After insertion in middle: ");
    display(head);

    // Insert at last
    printf("\nEnter data to insert at last: ");
    scanf("%d", &data);

    head = insertLast(head, data);

    printf("After insertion at last: ");
    display(head);

}
