#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void insert(int x) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if(front == -1) front = 0;
        queue[++rear] = x;
    }
}

void delete() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
    }
}

void traverse() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, num;
    while(1) {
        printf("1.Insert 2.Delete 3.Traverse 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                delete();
                break;
            case 3:
                traverse();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}