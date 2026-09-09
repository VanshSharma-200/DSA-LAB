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

// Deletion at beginning
struct node* deleteBeginning(struct node *head) {
    struct node *temp;

    // If list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    temp = head;
    head = head->next;

    free(temp);

    return head;
}

// Deletion at middle
struct node* deleteMiddle(struct node *head, int position) {
    struct node *temp;
    struct node *deleteNode;
    int i;

    // If list is empty or position is invalid
    if (head == NULL || position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    // If position is 1, delete first node
    if (position == 1) {
        temp = head;
        head = head->next;

        free(temp);

        return head;
    }

    temp = head;

    // Move to the node before the required position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Check invalid position
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    return head;
}

// Deletion at last
struct node* deleteLast(struct node *head) {
    struct node *temp;
    struct node *deleteNode;

    // If list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    // If only one node exists
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    temp = head;

    // Move to second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    deleteNode = temp->next;
    temp->next = NULL;

    free(deleteNode);

    return head;
}

void main() {
    int choice = 1;
    int position;

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;

    // Creating the linked list
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

    // Delete at beginning
    head = deleteBeginning(head);

    printf("\nAfter deletion at beginning: ");
    display(head);

    // Delete at middle
    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    head = deleteMiddle(head, position);

    printf("After deletion at position %d: ", position);
    display(head);

    // Delete at last
    head = deleteLast(head);

    printf("\nAfter deletion at last: ");
    display(head);
}
