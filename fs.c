#include<stdio.h>
int main(){
    int n, i, n1, n2, tn;
    n1=0, n2=1;
    tn = n1 + n2;
    printf("Enter no. of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: %d, %d", n1, n2);
    for(i=3; i<=n; i++){
        printf(", %d", tn);
        n1 = n2;
        n2 = tn;
        tn = n1 + n2;
    }
    printf(" \n");
    return 0;
}