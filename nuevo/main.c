#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 30000
#define TAM2 5

void generar(int vec[], int tam);
void mostrar(int vec[], int tam);
void intercalar(int vec1[], int vec2[], int vec3[], int tam1, int tam2);
void ordenar(int vec1[], int tam);

int main()
{
    //genero aleatorios
    srand(time(NULL));

    int vec1[TAM];
    int vec2[TAM2];
  //  int vec3[(TAM+TAM2)];

    generar(vec1, TAM);
    mostrar(vec1, TAM);
    generar(vec2, TAM2);
    mostrar(vec2, TAM2);

    ordenar(vec1, TAM);
    mostrar(vec1, TAM);
    /*
    intercalar(vec1, vec2, vec3, TAM, TAM2);
    mostrar(vec3, (TAM+TAM2));
    */

    return 0;
}

void generar(int vec[], int tam)
{
    int i;
    printf("\nGenerando Vector...\n");
    for(i=0; i<tam; i++)
        vec[i]=rand() % 10;

    return;
}

void mostrar(int vec[], int tam)
{
    int i;

    printf("\nMostrando Vector...\n");

    for(i=0; i<tam; i++)
        printf(" %d | ", vec[i]);

    printf("\n");
    return;
}

void intercalar(int vec1[], int vec2[], int vec3[], int tam1, int tam2)
{
    int i=0, j=0, mayor=tam2;

    while(j<tam1 && j<tam2)
    {
        vec3[i]=vec1[j];
        vec3[i+1]=vec2[j];
        j++;
        i+=2;
    }
    //encuentro el mayor
    if(tam1>tam2)
        mayor=tam1;

    if(j<tam1 || j<tam2)
    {
        for(i=j; i<mayor; i++)
        {
            if(tam1>tam2)
                vec3[i]=vec1[i];
            else
                vec3[i]=vec2[i];
        }
    }

    return;
}


void ordenar(int vec1[], int tam)
{
    int i, j, aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(vec1[i]<vec1[j])
            {
                aux=vec1[i];
                vec1[i]=vec1[j];
                vec1[j]=aux;
            }
        }
    }

    return;
}
