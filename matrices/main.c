/*
Andr�s Cabrera - Estructura de Datos - Trabajo Pr�ctico 1
---------------------------------------------------------
Cargar una matriz de 5 filas y 5 columnas y calcular y mostrar:
1.la matriz transpuesta
2.El promedio de los elementos de las dos diagonales (principal y secundaria)
3.Multiplicar la matriz por su transpuesta.
4.Determinar cuantos n�meros primos hay en la matriz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void cargarmatriz(int [][TAM], int n);
void mostrarmatriz(int [][TAM], int);
void transponer(int [][TAM], int [][TAM], int);
float prome(int [][TAM], int);
void multiplicar(int [][TAM], int [][TAM], int [][TAM], int);
int primos(int [][TAM], int);
int esprimo(int);

int main()
{
    int matriza[TAM][TAM];
    int matrizb[TAM][TAM];
    int matrizc[TAM][TAM]= { };
    int nprimos;
    float promedio;

    cargarmatriz(matriza, TAM);
    printf("Matriz A:\n");
    mostrarmatriz(matriza, TAM);
    transponer(matriza, matrizb, TAM);
    printf("\nMatriz A Transpuesta:\n");
    mostrarmatriz(matrizb, TAM);
    promedio=prome(matriza, TAM);
    printf("El promedio de elementos de la diagonal y la contradiagonal de A: %.2f",promedio);
    multiplicar(matriza, matrizb, matrizc, TAM);
    printf("\n\nMatriz A por su transpuesta:\n");
    mostrarmatriz(matrizc, TAM);
    nprimos=primos(matriza, TAM);
    printf("\nHubieron %d primos en A.\n", nprimos);

    return EXIT_SUCCESS;
}
//funcion cargar
void cargarmatriz(int mata[][TAM], int n)
{
    int i, j;

    srand((int)time(NULL));

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            mata[i][j]=rand()%9;
    }

    return;
}
//funcion mostrar
void mostrarmatriz(int mata[][TAM], int n)
{
    int i, j;
    printf("\n");


    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%d\t", mata[i][j]);

        printf("\n");
    }
    return;
}
//funcion trasponer
void transponer(int mata[][TAM], int matb[][TAM], int n)
{
    int i, j;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            matb[i][j]=mata[j][i];

    return;
}
//funcion promedio de las diagonales
float prome(int mata[][TAM], int n)
{
    int i, j=n-1, acu=0;

    for (i=0; i<n; i++)
        acu+=mata[i][i];

    for (i=0; i<n; i++)
    {
        acu+=mata[j][i];
        j--;
    }

    return (float)acu/n;
}
//funcion multiplicar
void multiplicar(int mata[][TAM], int matb[][TAM], int matc[][TAM], int n)
{
    int i, j, k;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            for (k=0; k<n; k++)
                matc[i][j]+=(mata[i][k]*matb[k][j]);

    return;
}
//recorrer matriz en busca de primos
int primos(int mata[][TAM], int n)
{
    int i, j, cont;
    cont = 0;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            if (esprimo(mata[i][j])) cont++;

    return cont;
}
//devuelve divisores
int esprimo(int num)
{
    int i, cantdiv=1;

    for (i=1; i<num; i++)
        if (num%i==0) cantdiv++;

    if (cantdiv==2)
        return 0;
    else
        return 1;
}



