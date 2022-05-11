/*
 * estructura3.c
 *
 *  Created on: 10 may. 2022
 *      Author: Matias
 */

#include "color.h"


int mostrarColor(eColor* lista){
int todoOk = 0;
if (lista != NULL){
printf("%04d  %s \n", lista->id, lista->descripcion);
todoOk = 1;
}
return todoOk;
}

int listarColor(eColor* lista, int tam){
int todoOk = 0;
	if (lista != NULL && tam > 0)
	{
		printf(" \n\n         ***   Listado de Colores  ***\n\n");
		printf(" ID      Color  \n");
		printf("------------------\n");
		for (int i = 0; i < tam; i++)
		{
			mostrarColor(lista + i);
		}
		printf("\n\n");
		todoOk = 1;
	}
return todoOk;
}

int cargarDescripcionColor(eColor* lista, int tam, int id, char* descripcion){
int todoOk = 0;
int indice;

    buscarColor(lista,tam, id,&indice);

    if(descripcion != NULL && indice != -1 && lista != NULL )
    {
       strcpy(descripcion, lista[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}

int buscarColor(eColor* lista, int tam, int id, int* pIndice){
    int todoOk = 0;
    if(lista != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(lista[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
