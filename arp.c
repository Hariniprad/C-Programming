#include<stdio.h>
int main(){
    int l, b, A, P;
    scanf("%d%d", &l, &b);
    A = l*b;
    P = 2*(l+b);
    printf("Area of the given rectangle = %d\n", A);
    printf("Perimeter of the given rectangle = %d\n", P);
    return 0;
}