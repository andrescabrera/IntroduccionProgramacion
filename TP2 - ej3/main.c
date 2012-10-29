#include <stdio.h>
#include <stdlib.h>

int main()
{
   int c, contp=0;
   printf ("\n ingrese un texto ");
   c=getchar();
   while(c!=EOF)
   {

       while(c!=' ')
       {
           putchar(c);
           c=getchar();
       }
       while(c==' ')
       {
           putchar(c);
           c=getchar();
       }

       c=getchar();
       contp++;
   }
   printf ("\n %d palabras ", contp);
   return 0;
}
