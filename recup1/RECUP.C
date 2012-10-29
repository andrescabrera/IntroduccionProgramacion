#include <stdio.h>
#include <stdlib.h>

tLista cargarListaExistencias(FILE *fE);
tLista cargarListaPedidos(FILE *fP);

int
main()
{
    FILE *fExistencias;
    FILE *fPedidos;
    tLista listaExistencias;
    tLista listaPedidos;
    fExistencias = fopen("existencias.txt", "r");
    if (fExistencias == NULL)
        fprintf(stderr, "No pudo abrirse archivo existencias.");
    else
    {
        fPedidos = fopen("pedidos.txt", "r");
        if (fPedidos == NULL)
        {
            fprintf(stderr, "No pudo abrirse archivo de pedidos");
            fclose(fExistencias);
        }else
        {
            listaExistencias = cargarListaExistencias(fExistencias);
            listaPedidos = cargarListaPedidos(fPedidos);
            fclose(fExistencias);
            fclose(fPedidos);
            mostrarLista(listaExistencias);
            mostrarLista(listaPedidos);
	    liberarLista(&listaExistencias);
	    liberarLista(&listaPedidos);
        }
    }
    return EXIT_SUCCESS;
}
tLista cargarListaExistencias(FILE *fE)
{
    tLista  lista;
    tArt    art;
    lista = nuevaLista();
    while(!feof(fE))
    {
        fscanf(fE, "%s %f %d", art.cod, &art.precio, &art.cant);
        lista = insertarElemento(lista, art);
    }
   return lista;
}
tLista cargarListaPedidos(FILE *fP)
{
    tLista lista;
    tArt art;
    lista = nuevaLista();
    while(!feof(fP))
    {
        fscanf(fP, "%s %d", art.cod,&(art.cant));
        art.precio = 0;
        lista = insertarElemento(lista, art);
    }
    return lista;
}

