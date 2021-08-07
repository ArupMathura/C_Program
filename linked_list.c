#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

int main(){
    struct node *head, *newnode, *tail;
    int choice, count=0;
    head = 0;
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next=0;
        if(head == 0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do you want to continue (0, 1)");
        scanf("%d", &choice);
    }
    tail=head;
    while(tail != 0){
        printf("%d\n", tail->data);
        tail=tail->next;
        count++;
    }
    printf("\nCount = %d\n", count);
    return 0;
}
