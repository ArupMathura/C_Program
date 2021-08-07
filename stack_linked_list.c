#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = 0;

void push();
void pop();
void peek();
void display();

int main()
{
    int choice;
    do{
        printf("\n*******Main Menu********\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display \n");
        printf("5. Exit\n");
        printf("choose one option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            peek();
            break;
        
        case 4:
            display();
            break;

        default:
            break;
        }
    }while(choice != 0);
}

void push()
{
    int x;
    struct stack *newnode;
    printf("\nEnter the number you want to push in the stack : ");
    scanf("%d", &x);
    newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void peek()
{
    if(top == 0)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nThe top element is : %d", top->data);
    }
}

void pop()
{
    struct stack *tail;
    tail = top;
    if(top == 0)
    {
        printf("\n Stack is empty\n");
    }
    else
    {
        printf("\nThe value being deleted is : %d", top->data);
        top = top->next;
        free(tail);
    }
}

void display()
{
    struct stack *tail;
    tail = top;
    if(top == 0)
    {
        printf("\nstack is empty\n");
    }
    else
    {
        while(tail != 0)
        {
            printf("%d\n", tail->data);
            tail = tail->next;
        }
    }
}