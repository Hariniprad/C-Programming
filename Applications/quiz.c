#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_Q 100
#define MAX_P 50

typedef struct {
    char text[200];
    char opt[4][100];
    char ans;
    char lvl[10];
} Ques;

typedef struct {
    char name[50];
    int score;
} Part;

Ques qBank[MAX_Q];
int qCount = 0;
Part parts[MAX_P];
int pCount = 0;

void addQ();
void updQ();
void delQ();
void shuffle(Ques arr[], int n);
void takeQuiz();
void showResults();
void analyze();

int main() {
    int ch;

    do {
        printf("\n--- Quiz System ---\n");
        printf("1. Add Questions\n");
        printf("2. Update Questions\n");
        printf("3. Delete Questions\n");
        printf("4. Take Quiz\n");
        printf("5. Show Results\n");
        printf("6. Analyze\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1: addQ(); break;
            case 2: updQ(); break;
            case 3: delQ(); break;
            case 4: takeQuiz(); break;
            case 5: showResults(); break;
            case 6: analyze(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);

    return 0;
}

void addQ() {
    if (qCount >= MAX_Q) {
        printf("No space for more questions.\n");
        return;
    }
    Ques q;

    printf("Enter question: ");
    fgets(q.text, sizeof(q.text), stdin);
    strtok(q.text, "\n");

    for (int i = 0; i < 4; i++) {
        printf("Enter option %c: ", 'A' + i);
        fgets(q.opt[i], sizeof(q.opt[i]), stdin);
        strtok(q.opt[i], "\n");
    }

    printf("Enter correct answer (A/B/C/D): ");
    scanf(" %c", &q.ans);
    getchar();

    printf("Enter difficulty (easy/med/hard): ");
    fgets(q.lvl, sizeof(q.lvl), stdin);
    strtok(q.lvl, "\n");

    qBank[qCount++] = q;
    printf("Question added!\n");
}

void updQ() {
    int idx;
    printf("Enter question number to update (1-%d): ", qCount);
    scanf("%d", &idx);
    getchar();

    if (idx < 1 || idx > qCount) {
        printf("Invalid number.\n");
        return;
    }

    printf("Updating question %d\n", idx);
    idx--;
    addQ();
}

void delQ() {
    int idx;
    printf("Enter question number to delete (1-%d): ", qCount);
    scanf("%d", &idx);
    getchar();

    if (idx < 1 || idx > qCount) {
        printf("Invalid number.\n");
        return;
    }

    idx--;
    for (int i = idx; i < qCount - 1; i++) {
        qBank[i] = qBank[i + 1];
    }
    qCount--;
    printf("Question deleted!\n");
}

void shuffle(Ques arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Ques temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void takeQuiz() {
    if (qCount == 0) {
        printf("No questions available.\n");
        return;
    }

    char name[50];
    int score = 0;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");

    shuffle(qBank, qCount);

    time_t start = time(NULL);
    for (int i = 0; i < qCount; i++) {
        printf("\nQ%d: %s\n", i + 1, qBank[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", qBank[i].opt[j]);
        }
        printf("Your answer (A/B/C/D): ");
        char ans;
        scanf(" %c", &ans);
        getchar();

        if (toupper(ans) == qBank[i].ans) {
            score++;
        }

        if (difftime(time(NULL), start) > 300) {
            printf("Time up! Quiz ended.\n");
            break;
        }
    }

    parts[pCount++] = (Part){.name = "", .score = score};
    strcpy(parts[pCount - 1].name, name);
    printf("\nQuiz done! You scored %d/%d.\n", score, qCount);
}

void showResults() {
    if (pCount == 0) {
        printf("No participants.\n");
        return;
    }

    for (int i = 0; i < pCount; i++) {
        printf("%s: %d points\n", parts[i].name, parts[i].score);
    }
}

void analyze() {
    if (pCount == 0) {
        printf("No data to analyze.\n");
        return;
    }

    int best = 0, worst = 100;
    for (int i = 0; i < pCount; i++) {
        if (parts[i].score > best) best = parts[i].score;
        if (parts[i].score < worst) worst = parts[i].score;
    }

    printf("Best Score: %d\n", best);
    printf("Worst Score: %d\n", worst);
}
