#include <stdio.h>
#include <string.h>

typedef struct Employee{
    int id;
    char name[50];
    char dep[30];
    float salary;
    char desig[30];
}Employee;

typedef struct EditHist{
    
}EditHist;

int n = 0;

void addEmp(struct Employee employee[n], FILE *fp)
{
    fp = fopen("emp.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee %d id : ", n+1);
    scanf("%d", &employee[n].id);
    getchar();
    for(int i = 0; i<n; i++){
        if(employee[n].id == employee[i].id){
            printf("Oops! ID already exists. Enter another.\n");
            printf("Enter Employee ID : ");
            scanf("%d", &employee[n].id);
            getchar();
            i = -1;
        }            
    }
  
    printf("Enter Employee %d name : ", n+1);
    fgets(employee[n].name, sizeof(employee[n].name), stdin);
    employee[n].name[strcspn(employee[n].name, "\n")] = 0;
  
    printf("Enter Employee %d Dep : ", n+1);
    fgets(employee[n].dep, sizeof(employee[n].dep), stdin);
    employee[n].dep[strcspn(employee[n].dep, "\n")] = 0;
  
    printf("Enter Employee %d Salary : ", n+1);
    scanf("%f", &employee[n].salary);
    getchar();
   
    printf("Enter Employee %d Designation : ", n+1);
    fgets(employee[n].desig, sizeof(employee[n].desig), stdin);
    employee[n].desig[strcspn(employee[n].desig, "\n")] = 0;

    
    n++;

    for(int i = 0; i<n; i++){
        fprintf(fp, "DETAILS of EMPLOYEE %d\n:",i+1);
        fprintf(fp, "Employee %d ID : %d\n",i+1, employee[i].id);
        fprintf(fp, "Employee %d Name : %s\n",i+1,employee[i].name);
        fprintf(fp, "Employee %d Dep : %s\n",i+1,employee[i].dep);
        fprintf(fp, "Employee %d Salary : %f\n",i+1,employee[i].salary);
        fprintf(fp, "Employee %d Desig : %s\n\n",i+1,employee[i].desig);
    }
    // char c[1000];
    // fgets(c, sizeof(c), fp);
    // printf("%s", c);
}


//     FILE *fp;

//     fp = fopen("emp.txt", "r+");
//     if (fp == NULL) {
//         printf("Error opening file!\n");
//         return 1; // Exit with an error code
//     }

//     // Get data to append
//     printf("Enter text to append to the file: ");
//     fgets(data, sizeof(data), stdin);

//     // Append data to the file
//     fprintf(fp, "%s", data);

//     // Close the file
//     fclose(fp);
//     printf("Data appended successfully.\n");


void dispEmps(struct Employee employee[n]){
    printf("%-5s%s\n", " ", " ________________________________________________________________________________");
    printf("%-5s|%-10s|%-15s|%-18s|%-18s|%-15s|\n", " ", "ID", "NAME", "DEPARTMENT", "SALARY", "DESIGNATION");
    printf("%-5s|%-10s|%-15s|%-18s|%-18s|%-15s|\n", " ", "__________", "_______________", "__________________", "__________________", "_______________");
    for(int i = 0; i<n; i++){
       printf("%-5s|%-10d", " ", employee[i].id);
       printf("|%-15s", employee[i].name);
       printf("|%-18s", employee[i].dep);
       printf("|%-18.2f", employee[i].salary);
       printf("|%-15s|\n", employee[i].desig);
    }
    printf("%-5s|%-10s|%-15s|%-18s|%-18s|%-15s|\n\n", " ", "__________", "_______________", "__________________", "__________________", "_______________");
}

void searchEmp(struct Employee employee[n]){
   int ID;
   printf("Enter ID of Employee that is returned : ");
   scanf("%d", &ID);


   for(int i = 0; i<n; i++){
       if(ID == employee[i].id){
       printf("Employee ID: %d",employee[i].id);
       printf("Employee Name: %s",employee[i].name);
       printf("Employee Dep: %s",employee[i].dep);
       printf("Employee Salary: %f",employee[i].salary);
       printf("Employee Desig: %s",employee[i].desig);
       }
   }   
}

int main()
{
    Employee employee[100];
    FILE *fp;
    addEmp(employee, fp);
    addEmp(employee, fp);
    dispEmps(employee);
    return 0;

}
