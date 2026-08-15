#include<stdio.h>
char a[4] = {"1","2","3","4"};
char *x = a;
char main(){
    printf("%s %s %s %s\n",a[0], a[1], a[2], a[3]);
    return 0;
}

#include<stdio.h>
int main(){
    char num[3][2] = {{1,2}, {3,4}}
    char *ptr = num[0];
    for(int i= 0; i<3; i++);
        printf("%s\n", num[1]);
    return 0;
}