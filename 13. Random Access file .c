#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    FILE *fp;
    struct employee emp;
    int n, i, empno, choice;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    fp = fopen("employee.dat", "wb+");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp.name);
        printf("Age: ");
        scanf("%d", &emp.age);
        printf("Salary: ");
        scanf("%f", &emp.salary);
        fwrite(&emp, sizeof(struct employee), 1, fp);
    }

    while (1) {
        printf("\n1. Display employee details\n");
        printf("2. Modify employee details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the employee number to display: ");
                scanf("%d", &empno);
                fseek(fp, (empno - 1) * sizeof(struct employee), SEEK_SET);
                fread(&emp, sizeof(struct employee), 1, fp);
                printf("\nEmployee %d details:\n", empno);
                printf("Name: %s\n", emp.name);
                printf("Age: %d\n", emp.age);
                printf("Salary: %.2f\n", emp.salary);
                break;
            case 2:
                printf("\nEnter the employee number to modify: ");
                scanf("%d", &empno);
                fseek(fp, (empno - 1) * sizeof(struct employee), SEEK_SET);
                fread(&emp, sizeof(struct employee), 1, fp);
                printf("\nEnter new details of employee %d:\n", empno);
                printf("Name: ");
                scanf("%s", emp.name);
                printf("Age: ");
                scanf("%d", &emp.age);
                printf("Salary: ");
                scanf("%f", &emp.salary);
                fseek(fp, (empno - 1) * sizeof(struct employee), SEEK_SET);
                fwrite(&emp, sizeof(struct employee), 1, fp);
                break;
            case 3:
                fclose(fp);
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
}

