#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

int main() {
    int choice=1;
    struct node *new=NULL, *head = NULL, *temp=NULL;
    while(choice==1){
        new = (struct node*)malloc(sizeof(struct node));
        printf("ENTER DATA OF NEW: ");
        scanf("%d",&new->data);
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
        printf("Enter choice 1 if you want to add a node: ");
        scanf("%d",&choice);
    }
    printf("Linked list Elements: ");
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
