#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int roll_no;
    char name[50];
    float marks_subject1;
    float marks_subject2;
    float marks_subject3;
    float total_marks;
    float percentage;
    char grade;
};
void calculate_grade(struct Student *s) {
    s->total_marks = s->marks_subject1 + s->marks_subject2 + s->marks_subject3;
    s->percentage = (s->total_marks / 300.0) * 100.0;
    if (s->percentage >= 90) {
        s->grade = 'A';
    } else if (s->percentage >= 80) {
        s->grade = 'B';
    } else if (s->percentage >= 70) {
        s->grade = 'C';
    } else if (s->percentage >= 60) {
        s->grade = 'D';
    } else {
        s->grade = 'F';
    }
}
void input_student_info(struct Student *s) {
    printf("Enter roll number: ");
    scanf("%d", &s->roll_no);
    while (getchar() != '\n');
    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;
    printf("Enter marks for Subject 1 (out of 100): ");
    scanf("%f", &s->marks_subject1);
    printf("Enter marks for Subject 2 (out of 100): ");
    scanf("%f", &s->marks_subject2);
    printf("Enter marks for Subject 3 (out of 100): ");
    scanf("%f", &s->marks_subject3);
    calculate_grade(s);
}
void display_grade_sheet(struct Student s) {
    printf("\n--- Student Grade Sheet ---\n");
    printf("Roll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks Subject 1: %.2f\n", s.marks_subject1);
    printf("Marks Subject 2: %.2f\n", s.marks_subject2);
    printf("Marks Subject 3: %.2f\n", s.marks_subject3);
    printf("Total Marks: %.2f\n", s.total_marks);
    printf("Percentage: %.2f%%\n", s.percentage);
    printf("Grade: %c\n", s.grade);
    printf("---------------------------\n");
}
int main() {
    struct Student student1;
    printf("Enter information for the student:\n");
    input_student_info(&student1);
    display_grade_sheet(student1);
    return 0;
}
