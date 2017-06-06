#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} subject_t;

typedef struct {
    subject_t subject;
    int value;
} grade_t;

typedef struct {
    char name[128];
    int age;
    grade_t* grades;
    int grade_count;
} student_t;

// TODO:
// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0

student_t *CreateStudent(char *name, int age);
void LastGradeValue(student_t *student, subject_t subject, int gradevalue);
int WorstGradeSubject(student_t *student);
void DeleteStudent(student_t *student);

student_t *CreateStudent(char *name, int age)
{
    int alloc_grades = 5;
    student_t *student = (student_t*) malloc(sizeof(student_t));

    grade_t *grades = (grade_t*) malloc(alloc_grades*sizeof(grade_t));
    strcpy(student->name, name);
    student->grade_count = 0;
    student->age = age;
    student->grades = grades;
    return student;
}
// TODO:
// Create a function that takes 3 parameters:
// A pointer to a Student
// A Subject
// An int (1-5)
// It should set the last grade's values with the given arguments
void LastGradeValue(student_t *student, subject_t subject, int gradevalue)
{
    student->grades[student->grade_count].subject = subject;
    student->grades[student->grade_count].value = gradevalue;
    student->grade_count++;
}
// TODO:
// Create a function that takes a Student as a pointer and returns the subject
// that the student has worst grade in
int WorstGradeSubject(student_t *student)
{
    int worstgrade = 5;
    int i;
    for (i = 0;student->grades[i].value < worstgrade; i++, worstgrade = student->grades[i].value) {
    }
    printf("%d\n",i);
    return student->grades[i].subject;
}
// TODO:
// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should free each Grade and the Student itself
void DeleteStudent(student_t *student)
{
    free(student->grades);
    free(student);
}
int main()
{
    student_t *Bela = CreateStudent("Bela", 24);
    printf("%d\n", Bela->age);

    LastGradeValue(Bela, HISTORY, 4);
    LastGradeValue(Bela, MATH, 1);
    LastGradeValue(Bela, SCIENCE, 3);
    printf("%d\t%s\t%d is %d\n", Bela->grade_count,Bela->name, Bela->grades[2].subject, Bela->grades[2].value);

    printf("%d", WorstGradeSubject(Bela));

    DeleteStudent(Bela);

    return 0;
}
