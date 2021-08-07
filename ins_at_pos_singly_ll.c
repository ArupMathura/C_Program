#include<stdio.h>
#include<stdlib.h>
struct node *head=NULL;

struct node{
    int data;
    struct node *next;
};

void ins(int data){
    struct node *tail = (struct node*)malloc(sizeof(struct node));
    tail->data=data;
    tail->next=head;
    head = tail;
}

void ins_at_pos_n(int data, int position){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    int i;
    struct node *tail=head;
    if(position==1){
        ptr->next=tail;
        head=ptr;
        return;
    }
    for(i=1;i<position-1;i++){
        tail=tail->next;
    }
    ptr->next=tail->next;
    tail->next=ptr;
}

void display(){
    struct node *tail=head;
    printf("\nList :");
    while(tail!=NULL){
        printf("\n%d ", tail->data);
        tail=tail->next;
    }
}

int main()
{
    int i, n, pos, data;
    printf("Enter the number of nodes: \n");
    scanf("%d",&n);
    printf("Enter the data for the nodes: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        ins(data);
    }
    printf("Enter the data you want to insert in between the nodes: \n");
    scanf("%d",&data);
    printf("Enter the position at which you want to insert the nodes: \n");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("Enter a valid position: ");
    
    }
    else 
    {
        ins_at_pos_n(data,pos);
    	
    }
    display();
    return 0;
}