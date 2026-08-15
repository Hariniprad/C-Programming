#include<stdio.h>
int main(){
    int num[3]= {1,3,2};
    int *ptr = num;
    int **ptr2 = &ptr;
    printf("%p\n", ptr);
    printf("%p\n", ++ptr);
    printf("%d %d\n", *(ptr++), num[1]);
    printf("%d %d\n", *(ptr), num[1]);
    printf("%d %d\n", **(ptr2), num[1]);
    printf("%p\n", ptr);
    printf("%p\n", *(ptr2));
    printf("%p\n", ptr2);
    printf("%p\n", &ptr);
    return 0;
}
