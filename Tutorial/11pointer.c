#include <stdio.h>

int main()
{
    int num, *ptr,**ptr1;
    printf("%p\n",&num);
    printf("%p\n",&ptr);
    printf("%p\n",&ptr1);
    ptr = &num;
    ptr1 = &ptr;
    *ptr = 5;
    printf("%d\n",num);
    printf("Enter a number:");
    scanf("%d",ptr);
    printf("%d\n",num);
    printf("%d\n",*ptr);
    printf("%d",num);
    return 0;
}