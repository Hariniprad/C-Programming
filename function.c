#include<stdio.h>

int add()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = a + b;
}

int main()
{
    int add2;
    printf("%d\n", add());
    add2 =  add() + 2;
    printf("%d\n", add2);

    return 0;
}

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int fac(int n)
//     {
//         if (n <= 1)
//         return 1;

//         return n*fac(n-1);
//     }

//     printf("%d\n",fac(n));
// }
