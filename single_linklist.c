#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void deleteFirstNode() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
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
        printf("1.Insert at beginning 2.Delete first node 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scanf("%d", &num);
                insertAtBeginning(num);
                break;
            case 2:
                deleteFirstNode();
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