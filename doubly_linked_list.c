#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

void create(){
    head=0;
    struct node *newnode, *tail;
    int choice = 1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d", &newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do you want to continue : (0, 1) : ");
        scanf("%d", &choice);
    }
}

void display(){
    struct node *tail;
    tail=head;
    while(tail!=0){
        printf("%d->", tail->data);
        tail=tail->next;
    }
    printf("NULL\n\n");
}

int main(){
    create();
    display();
    return 0;
}