#include<stdio.h>
int main(){
    int yr;
    printf("Enter a leap year: ");
    scanf("%d", &yr);
    if (yr%100 != 0 && yr%4 == 0)
        printf("Yay! %d's Feb has 29 days!\n", yr);
    else if (yr%400 == 0)
        printf("Yay! %d's Feb has 29 days!\n", yr);
    else{
        printf("Nope, %d has only 365 days!\n", yr);
    }
    return 0;
}