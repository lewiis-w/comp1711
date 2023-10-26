#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

int main () {
    int stu_num_in;
    char stu_name;
    char stu_id;
    int stu_mark;

    printf("enter the number of students: ");
    scanf("%d", &stu_num_in);
    int number_of_students = stu_num_in, i;
    for (i = 0; i < number_of_students; i++) {
    printf("enter student name: ");
    scanf("%s\n", &stu_name);
    printf("enter student ID: ");
    scanf("%s\n", &stu_id);
    printf("enter student mark: ");
    scanf("%u\n", &stu_mark);
    }
    
     student students [] = {
        {stu_name, stu_id,stu_mark}
     };
    for (i = 0; i < number_of_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}