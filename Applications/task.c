#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int id;
    char desc[100];
    char person[50];
    char due[11];
    char stat[20];
    struct Task *next;
};

struct Task* cr_T(int id, char *desc, char *person, char *due, char *stat) {
    struct Task *newT = (struct Task *)malloc(sizeof(struct Task));
    newT->id = id;
    strcpy(newT->desc, desc);
    strcpy(newT->person, person);
    strcpy(newT->due, due);
    strcpy(newT->stat, stat);
    newT->next = NULL;
    return newT;
}

void addT(struct Task **head, int id, char *desc, char *person, char *due, char *stat) {
    struct Task *newT = cr_T(id, desc, person, due, stat);
    if (*head == NULL) {
        *head = newT;
        return;
    }
    struct Task *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newT;
}

void updateStat(struct Task *head, int id, char *newStat) {
    struct Task *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            strcpy(temp->stat, newStat);
            printf("Task ID %d status updated to '%s'.\n", id, newStat);
            return;
        }
        temp = temp->next;
    }
    printf("Task ID %d not found.\n", id);
}

void delT(struct Task **head, int id) {
    struct Task *temp = *head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task ID %d not found.\n", id);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Task ID %d deleted.\n", id);
}

void displayT(struct Task *head) {
    struct Task *temp = head;
    printf("\nTask List:\n");
    while (temp != NULL) {
        printf("\tID: %d\n\tDesc: %s\n\tPerson: %s\n\tDue: %s\n\tStatus: %s\n", 
               temp->id, temp->desc, temp->person, temp->due, temp->stat);
        temp = temp->next;
    }
}

void getNewT(struct Task **head) {
    int id;
    char desc[100], person[50], due[11], stat[20];
    
    printf("\nEnter Task ID: ");
    scanf("%d", &id);
    getchar();
    
    printf("Enter Task Description: ");
    fgets(desc, sizeof(desc), stdin);
    desc[strcspn(desc, "\n")] = 0;
    
    printf("Enter Assigned Person: ");
    fgets(person, sizeof(person), stdin);
    person[strcspn(person, "\n")] = 0;
    
    printf("Enter Deadline (DD/MM/YYYY): ");
    fgets(due, sizeof(due), stdin);
    due[strcspn(due, "\n")] = 0;
    
    printf("Enter Status (e.g., Pending, Completed): ");
    fgets(stat, sizeof(stat), stdin);
    stat[strcspn(stat, "\n")] = 0;

    addT(head, id, desc, person, due, stat);
}

int main() {
    struct Task *head = NULL;
    int choice, id;
    char newStat[20];

    while (1) {
        printf("\n\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. Update Task Status\n");
        printf("3. Delete Completed Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getNewT(&head);
                break;
            case 2:
                printf("\nEnter Task ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new status: ");
                fgets(newStat, sizeof(newStat), stdin);
                newStat[strcspn(newStat, "\n")] = 0;
                updateStat(head, id, newStat);
                break;
            case 3:
                printf("\nEnter Task ID to delete: ");
                scanf("%d", &id);
                delT(&head, id);
                break;
            case 4:
                displayT(head);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
