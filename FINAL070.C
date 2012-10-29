/*
1)	Leer números enteros hasta cargar un vector de 10 elementos impares y múltiplos de 3
y otro con los múltiplos de 5 con cantidad de elementos menor o igual que 10.
La lectura termina con la condición del primer vector. Mostrar ambos vectores.
2)	Generar otro vector con los elementos comunes a ambos vectores. Mostrarlo.
3)	Desplazar 2 posiciones hacia la derecha desde el tercer elemento hasta el décimo del primer vector
y sumarle 5 a las dos primeras posiciones (tercer y cuarto elemento). Mostrarlo.
4)	Mostrar, del segundo vector, el valor mínimo y el primer elemento mayor al mínimo.
Utilizar una sola función que regrese los dos resultados.
  */
void cargar(int x[], int tx, int y[], int *ty);
void mostrar(int x[], int n);
int generarComunes(int x[], int tx, int y[], int ty, int z[]);
void desplazar(int x[], int n, int cuantos, int desde);
void minimoYMayor(int x[], int n, int *min, int *may);
#include <stdio.h>
#include <conio.h>
#define TAM 10
void main()
{
int vec1[TAM], vec2[TAM];
int vec3[TAM];
int tam2 = 0, tam3 = 0;
int min, may;
cargar(vec1, TAM, vec2, &tam2);
printf("Vec1:\n");
mostrar(vec1, TAM);
if (tam2 > 0)
{
	printf("Vec2:\n");
	mostrar(vec2, tam2);
	tam3 = generarComunes(vec1, TAM, vec2, tam2, vec3);
	printf("Vec3:\n");
	mostrar(vec3, tam3);
	desplazar(vec1, TAM, 2, 2);
	vec1[2]+=5;
	vec1[3]+=5;
	printf("Vec1:\n");
	mostrar(vec1, TAM);
	minimoYMayor(vec2, tam2, &min, &may);
	printf("\nEl minimo es %d y el primer número mayor al minimo es %d", min , may);
}
getch();
}
void cargar(int x[], int tx, int y[], int *ty)
{
int i;
int num;
i = 0;
printf("Ingrese números:\n");
while( i < tx)
{
	printf("%d:", i);
	scanf("%d", &num);
	if (num % 2 != 0 && num % 3 == 0)
		x[i++] = num;
	if (num % 5 == 0 && *ty < 10)
    	y[(*ty)++] = num;
}
}
void mostrar(int x[], int n)
{
int  i;
for (i = 0; i <n; i++)
	printf("%d\t", x[i]); 
}
int generarComunes(int x[], int tx, int y[], int ty, int z[])
{
	int i, j;
    int k = 0;
	for (i = 0; i < tx; i++)
		for (j = 0; j < ty; j++)
			if (x[i] == y[j])
				z[k++] = x[i];
    return k;
}
void desplazar(int x[], int n, int cuantos, int desde)
{
	int i;
	for (i = n - 1;i > (desde +cuantos - 1); i--)
		x[i] = x[i - cuantos]; 
}
void minimoYMayor(int x[], int n, int *min, int *may)
{
int i;
*min = x[0];
for (i = 1; i < n; i++)
{
	if (x[i]<*min)
		*min = x[i];
}
i = 0;
while( i < n && x[i] <= *min)
	i++;
*may = x[i];

}
