#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10


void cargar(int x[], int z[], int tam, int *tamz);
void mostrar(int x[], int tam);
void generar(int x[], int xt, int z[], int zt, int m[], int *tamm);
void desplazar(int x[], int tam, int pos);
void minimo(int x[], int tam);

int main()
{
    int x[TAM];
    int z[TAM];
    int m[TAM];
    int tamm=0;
    int tamz=0;

    //genero numero aleatorios
    srand(time(NULL));

    cargar(x, z, TAM, &tamz);
    printf("\n\nMostrando vector A");
    mostrar(x, TAM);

    if(tamz>0)
    {
        printf("\n\nMostrando vector B");
        mostrar(z, tamz);
    }
    else
        printf("\nNo existe el vector z...");

    generar(x, TAM, z, tamz, m, &tamm);
    printf("\n\nMostrando C");
    mostrar(m, tamm);
    desplazar(x, TAM, 3);
    x[2]+=5;
    x[3]+=5;
    mostrar(x, TAM);

    minimo(z, tamz);

    return EXIT_SUCCESS;
}

void cargar(int x[], int z[], int tam, int *tamz)
{
    int i=0, num;

    while(i<tam)
    {

        //num=rand() % 11;
        printf("\nIngresar numero: ");
        scanf("%d", &num);

        if(num%2!=0 && num%3==0)
        {
            x[i]=num;
            i++;
        }

        if(num%5==0 && *tamz<tam)
        {
            z[*tamz]=num;
            (*tamz)++;
        }
    }
}

void generar(int x[], int xt, int z[], int zt, int m[], int *mt)
{
    int i, j;
    for(i=0; i<xt; i++)
    {
        for(j=0; j<zt; j++)
        {
            if(x[i]==z[j])
                m[(*mt)++]=x[i];
        }
    }
    return;
}

void mostrar(int x[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
        printf("\nPos %d vale: %d", i, x[i]);

    return;
}

void desplazar(int x[], int tam, int pos)
{
    int i;

    for(i=tam; i>pos; i--)
        x[i]=x[i-2];

    return;
}

void minimo(int x[], int tam)
{
    int min=x[0], i, may;

    for(i=1; i<tam; i++)
    {
        if(x[i]<min)
            min=x[i];
    }

    i=0;

    while(i<tam && x[i] <= min)
    {
        i++;
        may=x[i];
    }

    printf("\n\nEl minimo es: %d", min);
    printf("\nEl primer mayor al minimo es: %d", may);

    return;
}
