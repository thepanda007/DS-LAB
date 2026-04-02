#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int acno;
    char name[50];
    float balance;
    struct Account* prev;
    struct Account* next;
};

struct Account* head = NULL;

void insertAccount(int acno, char name[], float balance) {
    struct Account* newNode = (struct Account*)malloc(sizeof(struct Account));
    newNode->acno = acno;
    strcpy(newNode->name, name);
    newNode->balance = balance;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Account* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayAccounts() {
    if(head == NULL) {
        printf("No accounts stored\n");
    } else {
        struct Account* temp = head;
        printf("\nBank Account Holders:\n");
        while(temp != NULL) {
            printf("AC No: %d, Name: %s, Balance: %.2f\n",
                   temp->acno, temp->name, temp->balance);
            temp = temp->next;
        }
    }
}

float totalBalance() {
    float sum = 0;
    struct Account* temp = head;
    while(temp != NULL) {
        sum += temp->balance;
        temp = temp->next;
    }
    return sum;
}

int main() {
    int n, acno;
    char name[50];
    float balance;

    printf("Enter number of bank customers: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nEnter details for customer %d:\n", i + 1);
        printf("Account No: ");
        scanf("%d", &acno);
        printf("Name: ");
        scanf("%s", name);
        printf("Balance: ");
        scanf("%f", &balance);
        insertAccount(acno, name, balance);
    }

    displayAccounts();
    printf("\nTotal Balance of all customers: %.2f\n", totalBalance());

    return 0;
}