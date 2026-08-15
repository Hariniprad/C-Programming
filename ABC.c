#include<stdio.h>
#include<string.h>
void main(){
    int vc=0, cc=0, sp=0;
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    for(int i=0; i<strlen(str);i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
           vc++;
        }
        else if(str[i] == ' ')
            sp++;
        else{
            cc++;
        }
    }    
    printf("VOWELS: %d \n", vc);
    printf("CONSONANTS: %d \n", cc);
}

