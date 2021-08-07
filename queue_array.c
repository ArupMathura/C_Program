#include<stdio.h>
#define n 5
int front = -1;
int rear = -1;
int queue[n];

void enqueue();
void dequeue();
void display();

int main()
{
    int option;
    do{
        printf("\n*********Main Menu**********\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit(to exit enter 0)\n");
        printf("\nChoose one option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;
        
        default:
            break;
        }
    }while(option != 0);
    return 0;
}

void enqueue()
{
    int item;
    printf("\n Enter the data : ");
    scanf("%d", &item);
    if(rear == n-1)
    {
        printf("\n Queue overflow");
    }
    else if(rear == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear++;
        queue[rear] = item;
    }
}

void display()
{
    if(rear == -1 && front == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        for(int i=front; i < rear+1;i++)
        {
            printf("\n%d", queue[i]);
        }
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty ");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\n The dequeue element is %d", queue[front]);
        front++;
    }
}