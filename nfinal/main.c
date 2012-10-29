#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15

void cargar(float vec1[], float vec2[], int tam);
void mostrar(float vec[], float vec2[], int tam);
int cargarsup(float vec[], float vec2[], float vec3[], int tam);
void mostrarsup(float vec[], int tam);
void precios(float super[], int tam);
void intercambiar(float super[], int tam);

int main()
{
    float vec1[TAM];
    float vec2[TAM];
    float super[TAM];
    int tamsuper;

    srand(time(NULL));
    cargar(vec1, vec2, TAM);
    mostrar(vec1, vec2, TAM);
    tamsuper=cargarsup(vec1, vec2, super, TAM);
    if(tamsuper==0)
        printf("No hay superficies\n...");
    else
    {
        mostrarsup(super, tamsuper);
        precios(super, tamsuper);
        intercambiar(super, tamsuper);
        mostrarsup(super, tamsuper);
    }

    return 0;
}

void cargar(float vec1[], float vec2[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        //genero medida del frente
        vec1[i]=rand()%11;
        //genero superficie
        vec2[i]=rand()%20;
    }
    return;
}

void mostrar(float vec[], float vec2[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        printf(" %.2f, %.2f\n", vec[i], vec2[i]);

    return;
}

int cargarsup(float vec[], float vec2[], float vec3[], int tam)
{
    int i, j=0, sup;

    for(i=0; i<tam; i++)
    {
        sup=(vec[i]*vec2[i]);

        if(sup>100)
        {
            vec3[j]=sup;
            j++;
        }
    }

    return j;
}

void mostrarsup(float vec[], int tam)
{
    int i;
    printf("\n\nEl vector de superficies es:\n");
    for(i=0; i<tam; i++)
        printf(" %.2f |", vec[i]);
    printf("\n");
    return;
}

void precios(float super[], int tam)
{
    int i, j, aux;
    float precios[tam];

    for (i=0; i<tam; i++)
        precios[i]=(super[i]*500);

    //ordeno los precios
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(precios[i]>precios[j])
            {
                aux=precios[i];
                precios[i]=precios[j];
                precios[j]=aux;
            }
        }
    }

    i=0;
    printf("Los 4 más baratos son: \n");

    while(i<tam && i < 4)
    {
        printf(" %.2f |", precios[i]);
        i++;
    }
}

void intercambiar(float super[], int tam)
{
    int i, aux;
    int mitad=tam/2;
    int j=tam-1;

    for(i=0; i<mitad; i++)
    {
        aux=super[i];
        super[i]=super[j];
        super[j]=aux;
        j--;
    }

    return;
}


