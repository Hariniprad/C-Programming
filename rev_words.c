#include <stdio.h>
#include <string.h>


void revWords(char* sen)
{   
   char* w = strtok(sen, " ");
   char* words[100];
   int n = 0;


   while (w != NULL){
       words[n++] = w;
       w = strtok(NULL, " ");
   }
   for (int i = n - 1; i >= 0; --i){
       printf("%s ", words[i]);
   }
   printf("\n");
}


int main()
{
   char sen[100];
   fgets(sen,sizeof(sen), stdin);
   sen[strcspn(sen, "\n")] = 0;
   revWords(sen);
   return 0;
}
