#include<stdio.h>
int main(){
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,b1,b2,b3,b4,b5,b6,b7,b8,b9,a,b,c,d,e,f,g,h,i;
    printf("Enter matrix A :\n");
    scanf("%d%d%d%d%d%d%d%d%d", &a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9);
    printf("Enter matrix B :\n");
    scanf("%d%d%d%d%d%d%d%d%d", &b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8,&b9);
    a = a1*b1 + a2*b4 + a3*b7;
    b = a1*b2 + a2*b5 + a3*b8;
    c = a1*b3 + a2*b6 + a3*b9;
    d = a4*b1 + a5*b4 + a6*b7;
    e = a4*b2 + a5*b5 + a6*b8;
    f = a4*b3 + a5*b6 + a6*b9;
    g = a7*b1 + a8*b4 + a9*b7;
    h = a7*b2 + a8*b5 + a9*b8;
    i = a7*b3 + a8*b6 + a9*b9;
    printf("AxB =\n %d %d %d\n %d %d %d\n %d %d %d \n", a,b,c,d,e,f,g,h,i);    
    return 0;
}