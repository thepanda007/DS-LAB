#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteLastNode() {
    if(head == NULL) {
        printf("List is empty\n");
    } else if(head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Deleted: %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
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
    int choice, num;
    while(1) {
        printf("1.Insert at end 2.Delete last node 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scanf("%d", &num);
                insertAtEnd(num);
                break;
            case 2:
                deleteLastNode();
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