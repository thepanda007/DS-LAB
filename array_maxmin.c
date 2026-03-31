#include <stdio.h>

int MAX(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int MIN(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void inputArray(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("  Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int numbers[10];

    inputArray(numbers, 10);

    printf("\nLargest number : %d\n", MAX(numbers, 10));
    printf("Smallest number: %d\n", MIN(numbers, 10));

    return 0;
}
