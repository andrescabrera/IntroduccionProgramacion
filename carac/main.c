#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int pal=0;

    printf("Ingrese un texto caracter a caracter, terminando con EOF.\n");
    c=getchar();

    //paso los primeros blancos
    while(c==' ')
    {
        putchar(c);
        c=getchar();
    }

    while(c!=EOF)
    {
        //paso caracteres de la palabra
        while(c!=' ' && c!=EOF)
        {
            putchar(c);
            c=getchar();
        }
        //cuento palabras
        pal++;
        //paso blancos hasta la otra palabra o fin de archivo
        while(c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }


    printf("Hubieron %d palabras", pal);
    return 0;
}
