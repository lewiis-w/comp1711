#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
    char grade [3];
};

int main () {
    struct student new_student = {"Name Surname", "28932123", 35, "C"};
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    printf("Final grade:  %s\n", new_student.grade);

    return 0;
}