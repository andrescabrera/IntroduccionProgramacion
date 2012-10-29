/*
EJERCICIO 2

Leer un texto carácter a carácter, terminado en EOF. Mostrar el texto intercambiando la última letra con la anteúltima de las palabras de 2 o más letras.

Entrada:   el rancho de madera y paja se quemó
Salida:     le rancoh  ed madear y paaj es queóm
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    char ant;
    char ult;

    c=getchar();

    while(c==' ')
    {
        putchar(c);
        c=getchar();
    }

    //guardo la ultima letra


    //entro en una palabra
    while(c!=EOF && c!=' ')
    {
        //paso letras
        while(c!=EOF && c!=' ')
        {
            putchar(c);
            c=getchar();
            if(c!=EOF && c!=' ')
            {
                ant=ult;
                ult=c;
                putchar(c);
                c=getchar();
            }
        }
        if(c==' ')
        {
            printf("\nla ultima letra es: %c\n", ult);
            printf("\nla anteultima letra es: %c\n\n", ant);
            //paso los espacios en blanco
            while(c==' ')
            {
                putchar(c);
                c=getchar();
            }
        }



    }

    return 0;
}
