#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 127

void find_frequency(char [], int []);
 
int main()
{
   char string[100] = {0};
   int i,c, count[26] = {0};
 
   printf("Input a string\n");
   for(i=0;i<(MAXLENGTH-1) && (c=getchar())!=EOF && c!='\n';i++){
      string[i] = toupper(c);
   }
 
   find_frequency(string, count);
   
   printf("Character Count\n");
    
   for (c = 0 ; c < 26 ; c++)
      printf("%c \t  %d\n", c + 'A', count[c]);
 
   return 0;
}

void find_frequency(char s[], int count[]) {
   int c = 0;
   
   while (s[c] != '\0') {
      if (s[c] >= 'A' && s[c] <= 'Z' ) 
         count[s[c]-'A']++;
      c++;
   }
}