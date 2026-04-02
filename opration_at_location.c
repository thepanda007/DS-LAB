#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtLocation(int x, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for(int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void searchNode(int key) {
    struct Node* temp = head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

void displayList() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        printf("List elements: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, num, pos;
    while(1) {
        printf("1.Insert at location 2.Search node 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scanf("%d %d", &num, &pos);
                insertAtLocation(num, pos);
                break;
            case 2:
                scanf("%d", &num);
                searchNode(num);
                break;
            case 3:
                displayList();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}