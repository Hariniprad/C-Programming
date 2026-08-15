/******************************************************************************

*******************************************************************************/
//Print 1, 2 and 3
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
            printf("One");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        default:
            printf("The number is not 1, 2 or 3");

    }
   return 0;
}