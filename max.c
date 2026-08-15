#include<stdio.h>
int main(){
    int l, m, n;
    printf("Enter three numbers: ");
    scanf("%d%d%d", &l, &m, &n);
    if (l>=m && l>=n)
        printf("%d is the biggest number!\n", l);
    else if (m>=l && m>=n)
        printf("%d is the biggest number!\n", m);
    else{
        printf("%d is the biggest number!\n", n);
    }
    return 0;
}