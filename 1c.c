#include <stdio.h>
#include <string.h>

struct student {
    int rollno;
    char name[50];
    int age;
    float avgMarks;
};

int main() {
    struct student s[50], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks > s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted in Ascending Order of Average Marks:\n");
    printf("------------------------------------------------------\n");
    printf("RollNo\tName\t\tAge\tAverageMarks\n");
    printf("------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", s[i].rollno, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}
