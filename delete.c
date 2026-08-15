#include<stdio.h>

typedef struct Person{
    char name[10];
    int id;
}Person;

void addPerson(struct Person){
    int i = 0;
    Person person[i];    
    printf("Name: ");
    fgets(person[i].name, sizeof(person[i].name), stdin);
}