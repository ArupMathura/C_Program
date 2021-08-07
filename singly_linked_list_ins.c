#include<stdio.h>
#include<stdlib.h>
int count =0;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after_loc(struct node *);

int main(){
    int option;
    do{
        printf("\n******MAIN MENU******\n");
        printf("1.create a list \n");
        printf("2.display \n");
        printf("3.Insert at beginning \n");
        printf("4.Insert at end \n");
        printf("5.Insert after a given location \n");
        printf("6.exit\n");
        printf("\n\n Choose an option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: 
            head = create_ll(head);
            printf("\nLinked list created \n");
            break;
        case 2:
            head = display(head);
            break;
        case 3:
            head = insert_beg(head);
            break;
        case 4:
            head = insert_end(head);
            break;
        case 5:
            head = insert_after_loc(head);
            break;
        default:
            printf("\njust relax\n");
            break;
        }
    }while(option != 6);
    return 0;
}

struct node *create_ll(struct node *head){
    struct node *newnode, *tail;
    int choice;
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
    return head;
}

struct node *display(struct node *head){
    struct node *tail;
    count =0;
    tail=head;
    while(tail != 0){
        printf("%d\n", tail->data);
        tail=tail->next;
        count++;
    }
    printf("\nCount = %d\n", count);
    return head;
}

struct node *insert_beg(struct node *head){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at the beginning : ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}

struct node *insert_end(struct node *head){
    struct node *newnode, *tail;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert at end : ");
    scanf("%d", &newnode->data);
    newnode->next=0;
    tail=head;
    while(tail->next != 0){
        tail = tail->next;
    }
    tail->next = newnode;
    return head;
}

struct node *insert_after_loc(struct node *head){
    struct node *newnode, *tail;
    int pos, i=1;
    printf("\ncount = %d\n", count);
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    if(pos>count){
        printf("\nInvalid position\n");
    }
    else{
        tail=head;
        while(i<pos){
            tail=tail->next;
            i++;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &newnode->data);
        newnode->next = tail->next;
        tail->next = newnode;
    }
    return head;
}