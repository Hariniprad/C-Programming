#include<stdio.h>
int main(){
    int a, b, c;
    printf("Enter two numbers to switch :\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = "); 
    scanf("%d", &b);
    a = a*b;
    b = a/b;
    a = a/b;
    printf("Now, a = %d and b = %d\n", a, b);
    return 0;
}