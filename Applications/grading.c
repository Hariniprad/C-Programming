#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 4
#define MAX_GRADES 10

typedef struct {
    char name[50];
    float grades[MAX_SUBJECTS][MAX_GRADES];
    int grade_counts[MAX_SUBJECTS];
} Student;

typedef struct {
    char subject_name[50];
    float class_average;
    float top_performance;
    char top_student[50];
} SubjectReport;

void inputStudentData(Student *student, int num_subjects) {
    printf("Enter student name: ");
    scanf(" %[^\n]", student->name);
    for (int i = 0; i < num_subjects; i++) {
        printf("Enter number of grades for subject %d: ", i + 1);
        scanf("%d", &student->grade_counts[i]);
        printf("Enter grades for subject %d:\n", i + 1);
        for (int j = 0; j < student->grade_counts[i]; j++) {
            scanf("%f", &student->grades[i][j]);
        }
    }
}

float calculateAverage(float grades[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}

void generateReports(Student students[], int student_count, SubjectReport reports[], int num_subjects) {
    for (int i = 0; i < num_subjects; i++) {
        reports[i].class_average = 0;
        reports[i].top_performance = 0;
        reports[i].top_student[0] = '\0';
    }

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < num_subjects; j++) {
            float average = calculateAverage(students[i].grades[j], students[i].grade_counts[j]);
            reports[j].class_average += average;

            if (average > reports[j].top_performance) {
                reports[j].top_performance = average;
                snprintf(reports[j].top_student, sizeof(reports[j].top_student), "%s", students[i].name);
            }
        }
    }

    for (int i = 0; i < num_subjects; i++) {
        reports[i].class_average /= student_count;
    }
}

void suggestFocusStudents(Student students[], int student_count, SubjectReport reports[], int num_subjects) {
    printf("\nFocus Suggestions for Faculty:\n");
    for (int i = 0; i < num_subjects; i++) {
        printf("For %s:\n", reports[i].subject_name);
        for (int j = 0; j < student_count; j++) {
            float average = calculateAverage(students[j].grades[i], students[j].grade_counts[i]);
            if (average < reports[i].class_average) {
                printf("  - %s needs attention (Average: %.2f)\n", students[j].name, average);
            }
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    SubjectReport reports[MAX_SUBJECTS] = {{"Mathematics"}, {"English"}, {"Science"}, {"History"}};
    int student_count = 0;
    int num_subjects = MAX_SUBJECTS;

    char continue_input;
    do {
        inputStudentData(&students[student_count], num_subjects);
        student_count++;
        printf("Do you want to enter another student? (y/n): ");
        scanf(" %c", &continue_input);
    } while (continue_input == 'y' && student_count < MAX_STUDENTS);

    generateReports(students, student_count, reports, num_subjects);

    printf("\nClass Averages and Top Performers:\n");
    for (int i = 0; i < num_subjects; i++) {
        printf("%s - Class Average: %.2f, Top Performer: %s (Score: %.2f)\n",
               reports[i].subject_name, reports[i].class_average,
               reports[i].top_student, reports[i].top_performance);
    }

    suggestFocusStudents(students, student_count, reports, num_subjects);

    return 0;
}
