#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void insert(int x) {
    if((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Queue Overflow\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

void delete() {
    if(front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void traverse() {
    if(front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear) break;
            i = (i + 1) % MAX;
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