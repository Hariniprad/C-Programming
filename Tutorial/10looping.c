/*

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*/
// Program to print first n numbers
#include <stdio.h>

int main()
{
    int num;
    do
    {
        printf("\nEnter a number:");
        scanf("%d",&num);
        if(num <= 0)
        {
            printf("Invalid input. Enter a value greater 0");
        }
    }while(num<=0);
    printf("\nThe first %d numbers are:", num);
    /*
    while(i<num)
    {
        printf("%d ",i);
        i++;
    }
    */
    for(int i = 0;i<num;i++)
    {
        printf("%d ",i);
    }
    return 0;
}