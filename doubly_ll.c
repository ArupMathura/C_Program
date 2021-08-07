#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = 0;
struct node *tail = 0;

void create();
void display();
void insert_at_beg();
void insert_at_end();

int main()
{
    int option;
    do{
        printf("\n*********Main Menu**********");
        printf("\n 1. Create");
        printf("\n 2. Display");
        printf("\n 3. Insert at beginning ");
        printf("\n 4. Insert at ending ");
        printf("\n Choose one option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;
        
        case 3:
            insert_at_beg();
            break;

        case 4:
            insert_at_end();
            break;
        
        default:
            break;
        }
    }while(option != 0);
}

void create()
{
    struct node *newnode;
    int choice = 1;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if(head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("\nDo you want to continue (0 to exit, 1 to continue): ");
        scanf("%d", &choice);
    }
}

void display()
{
    tail = head;
    printf("\n\n");
    while(tail != 0)
    {
        printf("%d->", tail->data);
        tail = tail->next;
    }
    printf("NULL\n");
}

void insert_at_beg()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data u want to insert at beginning : ");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_at_end()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data which you want to enter at ending : ");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}