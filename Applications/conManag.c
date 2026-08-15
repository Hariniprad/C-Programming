#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char *phNo;
} Contact;

Contact contacts[MAX_CONTACTS];
int n = 0;


void addContact()
{
    if (n >= MAX_CONTACTS) {
        printf("Oops! Contact list is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[n].name);

    char tempPh[20];
    printf("Enter phone number: ");
    scanf("%s", tempPh);

    contacts[n].phNo = (char *)malloc(strlen(tempPh) + 1);
    if (contacts[n].phNo == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(contacts[n].phNo, tempPh);

    n++;
    printf("Contact added successfully.\n");
}

void searchContact()
{
    char find[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", find);

    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, find) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phNo);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact()
{
    char del[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", del);

    if(n=0)
        printf("contacts database is empty.");

    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, del) == 0) {
            free(contacts[i].phNo);

            for (int j = i; j < n - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            n--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}


int main()
{
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                for (int i = 0; i < n; i++) {
                    free(contacts[i].phNo);
                }
                printf("Exiting system. Bye bye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
