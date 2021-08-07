#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, i, *ptr, sum = 0;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    ptr = (int *)malloc(n*sizeof(int));
    // printf("%d", *ptr);
    if(ptr == NULL){
        printf("sorry! unable to allocate memory ");
        exit(0);
    }
    printf("Enter ther elements of the array : ");
    for(int i=0;i<n;i++){
        scanf("%d", ptr + i);
        sum += *(ptr+i);
    }
    printf("sum = %d\n", sum);
    free(ptr);
    return 0;
}