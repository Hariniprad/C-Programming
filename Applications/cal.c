#include<stdio.h>
int main()
{
    float a, b, i;
    printf("Choose an operation :\n 1. Addn\n 2. Sub\n 3. Multn\n 4. Divn\n");
    scanf("%f", &i);
    printf("Enter 2 numbers :\n");
    scanf("%f%f", &a, &b);
    
    if(i==1)
        printf("%f + %f = %f\n", a, b, a+b);
    else if(i==2)
        printf("%f - %f = %f\n", a, b, a-b);
    else if(i==3)
        printf("%f x %f = %f\n", a, b, a*b);
    else
        printf("%f / %f = %f\n", a, b, a/b);

    return 0;
}
