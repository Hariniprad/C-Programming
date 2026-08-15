#include<stdio.h>
int main(){
    char str1[50], reversed[50];
    int a, b, c = 0;
    printf("Enter a word: ");
    scanf("%s", str1);
    while(str1[c] != '\0'){
        c++;
    }
    b = c - 1;
    for(a=0; a<c; a++){
        reversed[a] = str1[b];
        b--;
    }
    printf("Reversed word is %s!\n", reversed);
    return 0;
}