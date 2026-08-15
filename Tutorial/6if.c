/******************************************************************************

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(num%2==0)
    {
        printf("\n The entered number %d is even",num);
    }
    if(num%2!=0)
        printf("\n The entered number %d is odd",num);
   return 0;
}