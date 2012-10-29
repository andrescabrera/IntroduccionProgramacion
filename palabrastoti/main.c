/*

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, ultima, anteultima, pal=0, cont=0, cont2=0;
    printf ("\n ingrese texto ");
    c=getchar();

    while (c==' ')
    {
        putchar(c);
        c=getchar();
    }

    while (c!=EOF)
    {
        anteultima=ultima;
        //paso carcteres
        while (c!=' ' && c!=EOF)
        {
            putchar(c);
            anteultima=ultima;
            ultima=c;
            c=getchar();
        }
        pal++;

        if(ultima=='n')
            cont++;
        if(ultima==anteultima)
            cont2++;
        //espacios blancos
        while (c==' ')
        {
            putchar(c);
            c=getchar();
        }

    }
    printf("Muestro pal %d y cont %d. %d pal en que la ultima y anteultima son iguales", pal, cont, cont2);
    return 0;
}
