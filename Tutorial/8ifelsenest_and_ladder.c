/******************************************************************************

*******************************************************************************/
//Print 1, 2 and 3
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(num!=1)
    {
        if(num==2)
            printf("Two");
        else if(num == 3)
            printf("Three");
        else
            printf("The number is not 1, 2 or 3");
    }
    else
    {
        printf("One");
    }
   return 0;
}