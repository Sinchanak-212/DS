#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int i, n;
    struct employee *ptr;

    printf("size of structure employee %d\n",sizeof(struct employee));
    printf("Enter number of employees: ");
    scanf("%d", &n);

    ptr = (struct employee*)malloc(n * sizeof(struct employee));
    printf("size of structure employee %d\n",sizeof(struct employee));
    if (ptr == NULL) {
        printf("Memory is not allocated\n");
        return 1;
    } else {
        printf("Memory is created\n");
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter employee %d details:\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &ptr[i].id);

        printf("Enter Name: ");
        scanf("%s", ptr[i].name);

        printf("Enter Salary: ");
        scanf("%f", &ptr[i].salary);
    }

    printf("\nAnnual Salary Expenditure of Each Employee:\n");
    for (i = 0; i < n; i++) {
        float annual_exp = 12 * ptr[i].salary;
        printf("Employee %d Annual Salary: %.2f\n", ptr[i].id, annual_exp);
    }

    free(ptr);
    return 0;
}

