#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include "library.h"


void Type(const char * p)
{
   if (NULL == p) return;
   while(*p)
   {
      printf("%c",*p++);
      Sleep(50);
   }
   Sleep(300);
}

void TypeSlower(const char * p){
   if (NULL == p) return;
   while(*p)
   {
      printf("%c",*p++);
      Sleep(300);
   }
   Sleep(1000);
}

int getNewline(void)
{
   char ch;
   printf("\n-> ");
   scanf("%c", &ch);
   if (ch == '\n'){
      return 0;
   }else{
      printf("Plese press 'Enter'.");
      while ((getchar()) != '\n');
   }
   return 1;
}

char getYorN(void)
{
    printf("\n--> ");
    char ch = toupper(getchar());
    if (ch == 'Y'||ch == 'N')
    {
        while ((getchar()) != '\n');
        return ch;
    } else 
    {
        puts("Invalid input.\nPlease enter again.\n");
        getYorN();
    }
}

char getABC(void)
{
    printf("\n--> ");
    char ch = toupper(getchar());
    if (ch == 'A'||ch == 'B'||ch == 'C')
    {
        while ((getchar()) != '\n');
        return ch;
    } else 
    {
        puts("Invalid input.\nPlease enter again.\n");
        while ((getchar()) != '\n');
        getABC();
    }
}

char input[100];
int getInput(void)
{
   printf("\n--> ");
   return fgets(input, sizeof(input), stdin) != NULL;
}

int executePhrase(void)
{
   char *verb = strtok(input, " \n");
   char *noun = strtok(NULL, " \n");
   char *noun1 = strtok(NULL, " \n");
   if (verb != NULL)
   {
      if (strcmp(verb, "quit") == 0)
      {
         exit(EXIT_GAME);
      }
      else if (strcmp(verb, "look") == 0)
      {
         Look(noun);
      }
      else if (strcmp(verb, "go") == 0)
      {
         Go(noun);
      }
      else if (strcmp(verb, "item") == 0){
         Item();
      }
      else if (strcmp(verb, "examine") == 0){
         Examine(noun);
      }
      else if (strcmp(verb, "direction") == 0){
         Direction();
      }
      else if (strcmp(verb, "start") == 0){
         return 0;
      }
      else
      {
         printf("Action '%s' is invalid.\n", verb);
         puts("Valid actions:\n-look  -go  -examine  -direction  -item");
      }
   }
   return 1;
}

int getPassword(void)
{
    printf("\nEnter password: ");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
      char *password = strtok(input, " \n");
      if (password != NULL)
      {
         if (strcmp(password, "7879") == 0)
         {
            puts("Valid");
            SecretFileFound = true;
            return 0;
         } else
         {
            printf("Invalid.\n");
            puts("Try again? (Y/N)");
            if ( getYorN() == 'Y')
            {
               getPassword();
            } else 
            {
               puts("Ok.");
               return 0;
            }
         }
      }
   }
   return 0;
}

int readFile(void) 
{ 
    FILE *fptr; 
    char filename[100], c; 
  
    fptr = fopen("Charlie.txt", "r"); 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
    fclose(fptr); 
    return 0; 
}

int readLetter(void) 
{ 
    FILE *fptr; 
    char filename[100], c; 
  
    fptr = fopen("letter.txt", "r"); 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
    fclose(fptr); 
    return 0; 
}