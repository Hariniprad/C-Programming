#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char dep[30];
    float salary;
    char desig[30];
} Employee;

typedef struct {
    int id;
    char field[30];
    char oldValue[50];
    char newValue[50];
} EditHistory;

Employee *employees = NULL;
EditHistory *histories = NULL;
int n = 0;
int histCount = 0;

void addEmployee() {
    employees = realloc(employees, (n + 1) * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    Employee *e = &employees[n];
    printf("Enter ID: ");
    scanf("%d", &e->id);

    for (int i = 0; i < n; i++) {
        if (employees[i].id == e->id) {
            printf("ID already exists. Try again.\n");
            return;
        }
    }

    printf("Enter Name: ");
    getchar();  
    fgets(e->name, sizeof(e->name), stdin);
    e->name[strcspn(e->name, "\n")] = 0;

    printf("Enter Department: ");
    fgets(e->dep, sizeof(e->dep), stdin);
    e->dep[strcspn(e->dep, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &e->salary);

    printf("Enter Designation: ");
    getchar();  
    fgets(e->desig, sizeof(e->desig), stdin);
    e->desig[strcspn(e->desig, "\n")] = 0;

    FILE *fp = fopen("emp.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "Employee ID: %d\n", e->id);
    fprintf(fp, "Employee Name: %s\n", e->name);
    fprintf(fp, "Employee Department: %s\n", e->dep);
    fprintf(fp, "Employee Salary: %.2f\n", e->salary);
    fprintf(fp, "Employee Designation: %s\n\n", e->desig);

    fclose(fp);

    n++;
    printf("Employee added successfully!\n");
}


void displayEmployees()
{
    if (n == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("%-5s%s\n", " ", " ________________________________________________________________________________");
    printf("%-5s|%-10s|%-15s|%-18s|%-18s|%-15s|\n", " ", "ID", "NAME", "DEPARTMENT", "SALARY", "DESIGNATION");
    printf("%-5s|%-10s|%-15s|%-18s|%-18s|%-15s|\n", " ", "__________", "_______________", "__________________", "__________________", "_______________");
    for (int i = 0; i < n; i++) {
        Employee *e = &employees[i];
        printf("%-5s|%-10d|%-15s|%-18s|%-18.2f|%-15s|\n", " ", e->id, e->name, e->dep, e->salary, e->desig);
    }
    printf("%-5s|%-10s|%-15s|%-18s|%-18s|%-15s|\n\n", " ", "__________", "_______________", "__________________", "__________________", "_______________");
}

void generatePaySlip(int id, char *period)
{
    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            Employee *e = &employees[i];
            printf("\n---------------------- Pay Slip for %s ----------------------\n", e->name);
            printf("Employee ID: %d\n", e->id);
            printf("Name: %s\n", e->name);
            printf("Department: %s\n", e->dep);
            printf("Designation: %s\n", e->desig);
            printf("Salary: %.2f\n", e->salary);
            printf("Period: %s\n", period);
            printf("-----------------------------------------------\n");
            printf("Total Pay: %.2f\n", e->salary);
            printf("-----------------------------------------------\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void searchEmployee()
{
    if (n == 0) {
        printf("No employees available to search.\n");
        return;
    }

    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            printf("Employee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].dep);
            printf("Salary: %.2f\n", employees[i].salary);
            printf("Designation: %s\n", employees[i].desig);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void editEmployeeDetails()
{
    int id;
    printf("Enter Employee ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            Employee *e = &employees[i];
            printf("Editing details for Employee ID %d\n", e->id);

            histories = realloc(histories, (histCount + 1) * sizeof(EditHistory));
            EditHistory *hist = &histories[histCount];
            hist->id = e->id;

            printf("Enter new Name (current: %s): ", e->name);
            getchar();
            fgets(hist->oldValue, sizeof(hist->oldValue), stdin);
            hist->oldValue[strcspn(hist->oldValue, "\n")] = 0;
            strcpy(e->name, hist->oldValue);

            printf("Enter new Department (current: %s): ", e->dep);
            fgets(hist->oldValue, sizeof(hist->oldValue), stdin);
            hist->oldValue[strcspn(hist->oldValue, "\n")] = 0;
            strcpy(e->dep, hist->oldValue);

            printf("Enter new Salary (current: %.2f): ", e->salary);
            scanf("%f", &e->salary);
            printf("Enter new Designation (current: %s): ", e->desig);
            getchar();
            fgets(hist->oldValue, sizeof(hist->oldValue), stdin);
            hist->oldValue[strcspn(hist->oldValue, "\n")] = 0;
            strcpy(e->desig, hist->oldValue);

            histCount++;
            printf("Employee details updated.\n");
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
}

void displayEditHistory()
{
    if (histCount == 0) {
        printf("No editing history available.\n");
        return;
    }

    printf("\nEditing History:\n");
    for (int i = 0; i < histCount; i++) {
        EditHistory *h = &histories[i];
        printf("Employee ID: %d, Field: %s\n", h->id, h->field);
        printf("Old Value: %s, New Value: %s\n", h->oldValue, h->newValue);
    }
}

int main()
{
    int choice;
    while(1) {
        printf("\n1. Add Employee\n2. Display Employees\n3. Search Employee\n4. Edit Employee\n5. Generate Pay Slip\n6. Display Edit History\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: editEmployeeDetails(); break;
            case 5: {
                int id;
                char period[20];
                printf("Enter Employee ID for pay slip: ");
                scanf("%d", &id);
                printf("Enter period (e.g., Monthly, Quarterly, Yearly): ");
                getchar();
                fgets(period, sizeof(period), stdin);
                period[strcspn(period, "\n")] = 0;
                generatePaySlip(id, period);
                break;
            }
            case 6: displayEditHistory(); break;
            case 7: free(employees); free(histories); printf("Exiting...\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}