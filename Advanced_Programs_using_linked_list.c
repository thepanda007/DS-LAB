#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char name[50];
    char team[50];
    float battingAverage;
    struct Player* next;
};

struct Player* head = NULL;

void insertPlayer(char name[], char team[], float avg) {
    struct Player* newNode = (struct Player*)malloc(sizeof(struct Player));
    strcpy(newNode->name, name);
    strcpy(newNode->team, team);
    newNode->battingAverage = avg;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Player* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayQualifiedPlayers() {
    struct Player* temp = head;
    int found = 0;
    printf("\nPlayers with batting average >= 50:\n");
    while(temp != NULL) {
        if(temp->battingAverage >= 50) {
            printf("Name: %s, Team: %s, Batting Average: %.2f\n",
                   temp->name, temp->team, temp->battingAverage);
            found = 1;
        }
        temp = temp->next;
    }
    if(!found) {
        printf("No players found with batting average >= 50\n");
    }
}

int main() {
    int n;
    char name[50], team[50];
    float avg;

    printf("Enter number of players: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nEnter details for player %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Team: ");
        scanf("%s", team);
        printf("Batting Average: ");
        scanf("%f", &avg);
        insertPlayer(name, team, avg);
    }

    displayQualifiedPlayers();
    return 0;
}