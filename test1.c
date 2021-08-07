#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head, *newnode, *tail;
    head=NULL;
    int choice;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        printf("\nDo you want to continue(0, any integer)");
        scanf("%d", &choice);
    }
    tail=head;
    while(tail!=NULL){
        printf("%d->", tail->data);
        tail=tail->next;
    }
    printf("\n");
    return 0;
}

