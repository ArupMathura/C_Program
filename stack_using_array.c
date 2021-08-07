#include<stdio.h>
#define max 5
int top = -1;
int stack[max];

void push();
void pop();
void peek();
void display();

int main()
{
    int choose;
    do{
        printf("\n*******Main Menu********\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display \n");
        printf("Choose one option : ");
        scanf("%d", &choose);
        switch (choose)
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
            printf("\nu choose wrong option\n");
            break;
        }
    }while(choose != 0);
}

void push()
{
    int item;
    printf("\nEnter the item to be pushed : ");
    scanf("%d",&item);
    if(top == max - 1)
    {
        printf("\nStack overflow\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

void pop()
{
    int item;
    if(top == -1){
        printf("\nStack underflow\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("\npoped item is : %d", item);
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("\n Stack is empty\n");
    }
    else
    {
        for(i = top;i >= 0; i--)
        printf("\n%d", stack[i]);
        printf("\n");
    }
}

void peek()
{
    if(top == -1)
    {
        printf("\nstack is empty \n");
    }
    else
    {
        printf("after peek item is %d", stack[top]);
    }
}