#include<stdio.h>

#define SIZE 100

void insert(int arr[],int *n,int element){
    if(*n<SIZE){
        arr[*n]=element;
        (*n)++;
    }else{
        printf("Array is full\n");
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[SIZE],n=0,choice,element;
    while(1){
        printf("1.Insert\n2.Display\n3.Exit\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter element: ");
            scanf("%d",&element);
            insert(arr,&n,element);
        }else if(choice==2){
            display(arr,n);
        }else if(choice==3){
            break;
        }else{
            printf("Invalid choice\n");
        }
    }
    return 0;
}