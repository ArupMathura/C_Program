#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_at_beg(struct node *);
struct node *insert_at_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *insert_at_pos(struct node *);


int main()
{
    int option;
    do
    {
        printf("\n*******MAIN MENU*******\n");
        printf("1. Create a linked list\n");
        printf("2. Display \n");
        printf("3. Insert data at beginning\n");
        printf("4. Insert data at the end\n");
        printf("5. Insert a node before a giving node \n");
        printf("6. Insert a node after a giving node\n");
        printf("7. Insert a node at the given position\n");
        printf("8. Exit \n");
        printf("\n choose one option : \n");
        scanf("%d", &option);
        switch (option)
        {
            case 1: 
                head = create_ll(head);
                printf("\n Linked list created \n");
                break;
            
            case 2:
                head = display(head);
                break;

            case 3:
                head = insert_at_beg(head);
                break;
            
            case 4:
                head = insert_at_end(head);
                break;

            case 5:
                head = insert_before(head);
                break;
            
            case 6:
                head = insert_after(head);
                break;

            case 7:
                head = insert_at_pos(head);
                break;
        }
    }while(option != 8);
    return 0;
}

struct node *create_ll(struct node *head)
{
    struct node *newnode, *tail;
    int choice;
    head = 0;
    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if(head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do you want to continue (0, 1) : ");
        scanf("%d", &choice);
    }
    return head;
}

struct node *display(struct node *head)
{
    struct node *tail;
    int count = 0;
    tail = head;
    while(tail != 0)
    {
        printf("%d->", tail->data);
        tail = tail->next;
        count++;
    }
    printf("NULL");
    printf("\n count = %d", count);
    return head;

}

struct node *insert_at_beg(struct node * head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data you want to enter at beginning : ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

struct node *insert_at_end(struct node *head)
{
    struct node *newnode, *tail;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data you want to enter at ending : ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    tail = head;
    while(tail->next != 0)
    {
        tail = tail->next;
    }
    tail->next = newnode;
    return head;
}

struct node *insert_before(struct node *head)
{
    struct node *newnode, *tail, *pretail;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    tail = head;

    while(tail->data != val)
    {
        pretail = tail;
        tail = tail->next;
    }

    pretail->next = newnode;
    newnode->next = tail;
    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *newnode, *tail, *posttail;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    tail = head;
    posttail = tail;
    // int c = 0;
    while(posttail->data != val)
    {
        posttail = tail;
        tail = tail->next;
        // c = c + 1;
        // printf("\nposttail->data = %d", posttail->data);
    }
    // printf("\ncount = %d\n", c);
    posttail->next = newnode;
    newnode->next = tail;
    return head;
}

struct node *insert_at_pos(struct node *head)
{
    struct node *newnode, *tail, *pretail;
    int i, pos;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data u want to enter at position : ");
    // scanf("%d", &newnode->data);
    scanf("%d", &newnode->data);
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    tail = head;
    newnode->next = 0;
    for(i=1;i<pos;i++)
    {
        pretail = tail;
        tail = tail->next;
    }
    pretail->next = newnode;
    newnode->next = tail;
    return head;
}