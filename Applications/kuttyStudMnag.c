#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 10
#define SUB 4

void calc_avg(float **score, int n, float *avg)
{
    for (int i = 0; i < n; i++) {
        float sum = 0.0f;
        for (int j = 0; j < SUB; j++) {
            sum += score[i][j];
        }
        avg[i] = sum / SUB;
    }
}

void display(char **name, int *id, float **score, float *avg, int n)
{
    printf("\nStudent Records:\n");
    printf("|%-6s|%-10s|%-25s|%-5s\n", "ID", "Name", "Scores", "Average");
    printf("----------------------------------------------------\n");
            
    for (int i = 0; i < n; i++) {
        printf("|%-6d|%-10s|", id[i], name[i]);
        for (int j = 0; j < SUB; j++) {
            printf("%-5.2f ", score[i][j]);
        }
        printf("|%-5.2f\n", avg[i]);
    }
    printf("\n");
}


int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    char **name = (char **)malloc(n * sizeof(char *));
    int *id = (int *)malloc(n * sizeof(int));
    float **score = (float **)malloc(n * sizeof(float *));
    float *avg = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        name[i] = (char *)malloc(NAME_LEN * sizeof(char));
        score[i] = (float *)malloc(SUB * sizeof(float));

        printf("\nEnter details for student %d:\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &id[i]);

        printf("Enter name: ");
        scanf("%s", name[i]);

        printf("Enter Scores for %d subjects: ", SUB);
        for (int j = 0; j < SUB; j++) {
            scanf("%f", &score[i][j]);
        }
    }

    calc_avg(score, n, avg);
    display(name, id, score, avg, n);

    for (int i = 0; i < n; i++) {
        free(name[i]);
        free(score[i]);
    }
    free(name);
    free(id);
    free(score);
    free(avg);

    return 0;
}
