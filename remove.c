#include<stdio.h>

int main(){
    char line[100], l;
    int j,n;
    printf("Enter any string: ");
    fgets(line, sizeof(line), stdin);
    printf("Enter a letter to remove: ");
    scanf("%s", &l);
    
    for(int i=j=0; line[i] != '\0'; ++i)
        if(line[i] != l)
          line[j++]=line[i];
        line[j]='\0';

    printf("%s\n", line);
    return 0;
}