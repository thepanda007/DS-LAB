#include<stdio.h>

#define SIZE 10

void multiply(int a[][SIZE],int b[][SIZE],int c[][SIZE],int r1,int c1,int r2,int c2){
    if(c1!=r2){
        printf("Matrix multiplication not possible\n");
        return;
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            c[i][j]=0;
            for(int k=0;k<c1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

void display(int m[][SIZE],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a[SIZE][SIZE],b[SIZE][SIZE],c[SIZE][SIZE];
    int r1,c1,r2,c2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter elements of first matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d",&r2,&c2);
    printf("Enter elements of second matrix:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    multiply(a,b,c,r1,c1,r2,c2);
    if(c1==r2){
        printf("Resultant matrix:\n");
        display(c,r1,c2);
    }
    return 0;
}