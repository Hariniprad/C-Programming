#include<stdio.h>
int main(){
    char num[3][2] = {"12", "34", "12"};
    char *ptr = num[0];
    for(int i= 0; i<3; i++);
        printf("%s\n", num[1]);
    for(int i=0; i<3; i++)
        printf("%p\n", ptr+i);
    return 0;
}