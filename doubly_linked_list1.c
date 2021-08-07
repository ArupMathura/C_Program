#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};


struct node *head=NULL, *tail=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
// struct node *insert_after_loc(struct node *);

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
        // case 5:
        //     head = insert_after_loc(head);
        //     break;
        default:
            printf("\njust relax\n");
            break;
        }
    }while(option != 0);
    return 0;
}

struct node *create_ll(struct node *head){
    struct node *newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d", &newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head == 0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("\nDo you want to continue(0, 1) : ");
        scanf("%d", &choice);
    }
    return head;
}

struct node *display(struct node *head){
    // struct node *tail;
    tail=head;
    while(tail!=0){
        printf("%d->", tail->data);
        tail=tail->next;
    }
    printf("NULL\n");
    return head;
}

struct node *insert_beg(struct node *head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}

struct node *insert_end(struct node *head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return tail;
}
