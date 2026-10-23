#include <stdio.h>

struct Student
{
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};

int main()
{
    struct Student s;
    struct Student *p;

    p = &s;

    printf("Enter Roll Number: ");
    scanf("%d", &p->roll_no);

    printf("Enter Name: ");
    scanf("%s", p->name);

    printf("Enter Branch: ");
    scanf("%s", p->branch);

    printf("Enter Batch Number: ");
    scanf("%d", &p->batch_no);

    printf("\n--- Student Details ---\n");

    printf("Roll Number: %d\n", p->roll_no);
    printf("Name: %s\n", p->name);
    printf("Branch: %s\n", p->branch);
    printf("Batch Number: %d\n", p->batch_no);

    return 0;
}