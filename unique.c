#include<stdio.h>

int main(){
    char string[100], l;
    int j,n;
    printf("Enter any string: ");
    fgets(string, sizeof(string), stdin);
    
    for(int i=j=0; string[i] != '\0'; ++i)
    {
      for(int n=0; n<=i; n++)
      {
        if(string[i] != string[i-n])
          string[j++]=string[i];
      }
    }
    
    printf("%s\n", string);
    return 0;
}


// int main(){
//     char string[100], l;
//     int j=0,n;
//     printf("Enter any string: ");
//     fgets(string, sizeof(string), stdin);
//     getchar();
    
//     for(int i=1; string[i] != '\0'; ++i)
//     {
//       for(int n=1; n<=i; n++)
//       {
//         if(string[i] != string[i-n]){
//           break;
//         }
//         else{
//           continue;
//         }          
//       }
//     }    
//     return 0;
// }
