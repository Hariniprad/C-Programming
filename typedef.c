#include<stdio.h>
#include<stdlib.h>

typedef unsigned long ulong;
typedef int* IntPtr;
typedef struct {int id; char name[50];} Student;
typedef int (*Operation)(int, int);

int add(int a, int b){
    return a+b;
}

int main()
{
    
}