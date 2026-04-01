#include <stdio.h>
#include <stdlib.h>

struct product {
    int product_no;
    char name[50];
    float cost;
};

void displayRange(struct product *p, int n) {
    printf("\nProducts with cost between 100 and 1000:\n");
    for (int i = 0; i < n; i++) {
        if (p[i].cost >= 100 && p[i].cost <= 1000) {
            printf("Product No: %d, Name: %s, Cost: %.2f\n", p[i].product_no, p[i].name, p[i].cost);
        }
    }
}

int main() {
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    struct product *p = (struct product*)malloc(n * sizeof(struct product));
    if (p == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    printf("Enter details of %d products:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Product %d\n", i + 1);
        printf("Product No: ");
        scanf("%d", &p[i].product_no);
        printf("Name: ");
        scanf("%s", p[i].name);
        printf("Cost: ");
        scanf("%f", &p[i].cost);
    }

    displayRange(p, n);

    free(p);
    return 0;
}