#include <stdio.h>

struct student {
    int rollno;
    char name[50];
    int age;
};

void displayEligible(struct student s[], int n) {
    printf("\nStudents with age >= 20:\n");
    for (int i = 0; i < n; i++) {
        if (s[i].age >= 20) {
            printf("Roll No: %d, Name: %s, Age: %d\n", s[i].rollno, s[i].name, s[i].age);
        }
    }
}

int main() {
    struct student s[5];
    printf("Enter details of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
    }
    displayEligible(s, 5);
    return 0;
}