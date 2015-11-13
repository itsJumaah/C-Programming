#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* convert word to lower case */

void word_tolower(char s[], char t[])
{ 
   int i = 0;
    
   while(s[i] != '\0')
   {
      t[i] = tolower(s[i]);
      i++;
   }

   t[i] = '\0';
}
     
int main() {
   char line[80];
   char filename[40];
   char word[20], word1[20], word2[20], lword1[20], lword2[20];
   int i, j, wordcount1, wordcount2, linecount;
   FILE *fp;

   printf("Enter the first word: ");
   gets(word1);
   word_tolower(word1, lword1);
   
   printf("Enter the second word: ");
   gets(word2);
   word_tolower(word2, lword2);

   printf("Enter the name of the text file: ");
   gets(filename);
   printf("\n");

   fp = fopen(filename, "r");

   wordcount1 = wordcount2 = linecount = 0;
  
   while(!feof(fp))
   {
      linecount++;
      fgets(line, 79, fp); /* note that there will be a '\n' before the final '\0' */     
      i = j = 0;
      
      while(line[i] != '\0')
      {
        if (line[i] != ' ' && line[i] != '.' && line[i] != '\n')
        {
           word[j] = tolower(line[i]);
           j++;
        }
        else
        {
           word[j] = '\0';
           j = 0;
           if(!strcmp(word, lword1))
           { 
              wordcount1++;
              if (wordcount1 == 1)
              {
                 printf("The word \'%s\' first appears in line %d which is\n%s\n", word1, linecount, line); 
              }
           }
           else if (!strcmp(word, lword2))
           {
              wordcount2++;
              if (wordcount2 == 1)
              {
                 printf("The word \'%s\' first appears in line %d which is\n%s\n", word2, linecount, line); 
              }
           }
        }

        i++;
      }      
   }

   fclose(fp);

   if(wordcount1 > 0)
   {
      printf("The word \'%s\' appears %d time(s) in the file.", word1, wordcount1);
   }
   else
   {
      printf("The word \'%s\' does not appear in the file.", word1);
   }


   if(wordcount2 > 0)
   {
      printf("\nThe word \'%s\' appears %d time(s) in the file.", word2, wordcount2);
   }
   else
   {
      printf("\nThe word \'%s\' does not appear in the file.", word2);
   }

   return 0;
}