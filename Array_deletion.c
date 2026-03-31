#include<stdio.h>

#define SIZE 100

void delete(int arr[],int *n,int pos){
    if(pos<0||pos>=*n){
        printf("Invalid position\n");
        return;
    }
    for(int i=pos;i<*n-1;i++){
        arr[i]=arr[i+1];
    }
    (*n)--;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[SIZE],n=0,choice,pos,element;
    while(1){
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        if(choice==1){
            if(n<SIZE){
                printf("Enter element: ");
                scanf("%d",&element);
                arr[n++]=element;
            }else{
                printf("Array is full\n");
            }
        }else if(choice==2){
            printf("Enter position to delete: ");
            scanf("%d",&pos);
            delete(arr,&n,pos);
        }else if(choice==3){
            display(arr,n);
        }else if(choice==4){
            break;
        }else{
            printf("Invalid choice\n");
        }
    }
    return 0;
}