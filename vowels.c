#include<stdio.h>
int main(){
    char line[100], string;
    int v=0, c=0, s=0;
    printf("Enter any string: ");
    fgets(line, sizeof(line), stdin);
    
    for(int i=0; line[i] != '\0'; i++)
        if(line[i] == 'a' || line[i] == 'A'
        || line[i] == 'e' || line[i] == 'E'
        || line[i] == 'i' || line[i] == 'I'
        || line[i] == 'o' || line[i] == 'O'
        || line[i] == 'u' || line[i] == 'U')
            v++;
        else if(line[i]>='a' && line[i]<= 'z' || line[i]>='A' && line[i]<='Z')
            c++;
        else if(line[i] == ' ')
            s++;
    
    printf("Number of vowels: %d\n", v);
    printf("Number of consonants: %d\n", c);
    return 0;
}