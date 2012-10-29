#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    char priletra;
    char segundaletra;
    char tercerletra;

    int cantletras;
    int palabras=0;
    int capicuas=0;

    printf("Ingrese un texto caracter a caracter, termina con EOF.\n");

    c=getchar();
    while (c==' ')
    {
        putchar(c);
        c=getchar();
    }

    //encuentro una palabra o fin de archivo
    while (c!=EOF)
    {
        //hasta que termine la palabra paso los caracteres
        while (c!=EOF && c!=' ')
        {
            cantletras=1;
            putchar(c);
            priletra=c;
            c=getchar();
            //pido segunda letra
            if(c!=EOF && c!=' ')
            {
                cantletras++;
                putchar(c);
                segundaletra=c;
                c=getchar();
            }
            //pido tercer letra
            if(c!=EOF && c!=' ')
            {
                cantletras++;
                putchar(c);
                tercerletra=c;
                c=getchar();
            }
            if(cantletras == 2)
                if(priletra==segundaletra)
                    capicuas++;

            if(cantletras==3)
                if(priletra==tercerletra)
                    capicuas++;


        }
        //termino la palabra. la sumo.
        palabras++;

        //paso los espacios en blanco
        while (c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }

    getchar();
    printf("\nHubieron %d palabras", palabras);
    printf("\nHubieron %d palabras capicuas", capicuas);
    return 0;
}
