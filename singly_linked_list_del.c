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
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_from_pos(struct node *);


int main(){
    int option;
    do{
        printf("\n******MAIN MENU******\n");
        printf("1.create a list \n");
        printf("2.display \n");
        printf("3.Delete from beginning \n");
        printf("4.Delete from end \n");
        printf("5.Delete from a specified position \n");
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
            head = del_beg(head);
            break;
        case 4:
            head = del_end(head);
            break;
        case 5:
            head = del_from_pos(head);
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
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == 0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        printf("\nDo you want to continue(0, 1) : ");
        scanf("%d", &choice);
    }
    return head;
}

struct node *display(struct node *head){
    struct node *tail;
    count=0;
    tail=head;
    while(tail!=NULL){
        printf("%d->", tail->data);
        tail=tail->next;
        count++;
    }
    printf("NULL\n\n");
    printf("count = %d\n", count);
    return head;
}

struct node *del_beg(struct node *head){
    struct node *tail;
    tail=head;
    head=head->next;
    free(tail);
    return head;
}

struct node *del_end(struct node *head){
    struct node *prevnode, *tail;
    tail=head;
    while(tail->next!=0){
        prevnode=tail;
        tail=tail->next;
    }
    if(tail==head){
        head=0;
    }
    else{
        prevnode->next=0;
    }
    free(tail);
    return head;
}

struct node *del_from_pos(struct node *head){
    struct node *nextnode, *tail;
    int pos, i=1;
    tail=head;
    printf("\nEnter position : ");
    scanf("%d", &pos);
    while(i<pos-1){
        tail=tail->next;
        i++;
    }
    nextnode=tail->next;
    tail->next=nextnode->next;
    free(nextnode);
    return head;
}
