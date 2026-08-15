#include<stdio.h>
#include<math.h>
int main(){
    int a, d, r, n;
    printf("First term, a = ");
    scanf("%d",&a);
    printf("Common difference, d = ");
    scanf("%d",&d);
    printf("Common ratio, r = ");
    scanf("%d",&r);
    printf("No. of term, n = ");
    scanf("%d",&n);
    printf("nth term of AP = %d\n", a + (n-1)*d);
    printf("nth term of GP = %d\n", a*(int)(pow(r,n-1)));
    return 0;
}