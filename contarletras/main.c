#include <stdio.h>
#include <stdlib.h>

int main()
{

    int c, contp3=0, contc=0;

    printf("Ingresar texto ");
    c=getchar();

    while (c==' ')
    {
        putchar(c);
        c=getchar();
    }

    while (c!=EOF)
    {
        contc=0;
        while (c!=' ' && c!=EOF)
        {
            putchar(c);
            c=getchar();
           contc++;
        }

        if (contc>3)
        {
            contp3++;
        }

        while (c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }

    printf ("\n la cantidad de palabra que tienen mas de 3 caracteres es %d ", contp3);
    return 0;
}
