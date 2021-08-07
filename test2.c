#include<stdio.h>
int count=0;
void add(){
    for(int i=0;i<5;i++){
        count++;
    }
}
void sub(){
    for(int i=0;i<5;i++){
        count++;
    }
}
void mul(){
    for(int i=0;i<5;i++){
        count++;
    }
}
void div(){
    for(int i=0;i<5;i++){
        count++;
        
    }
    printf("count = %d", count);
}

int main(){
    int option;
    do
    {
        printf("\n******MAIN MENU******\n");
        printf("1.Add \n");
        printf("2.Subtract \n");
        printf("3.Multi \n");
        printf("4.Divide \n");
        printf("\n\n Choose an option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            div();
            break;
        
        default:
            printf("\n \nChoose a corrct option : ");
            break;
        }
    } while (option != 5);
    return 0;
}