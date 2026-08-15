#include<stdio.h>
int main()
{
    int n, rev;
    printf("Enter no. to reverse: ");
    scanf("%d", &n);
    printf("Reversed no. = ");
    while(n > 0)
    {
        rev = n%10;
        printf("%d", rev);
        n = n/10;
    }
    printf("\n");
}