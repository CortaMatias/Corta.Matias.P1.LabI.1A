/*
 * trabajo.c
 *
 *  Created on: 11 may. 2022
 *      Author: Matias
 */


#include "trabajo.h"
#include "servicio.h"
#include "mascota.h"

int initStructTrabajo(eTrabajo* lista, int tam){
		int todoOk = 0;

		if (lista != NULL && tam > 0)
		{
			for (int i = 0; i < tam; i++)
			{
				lista[i].isEmpty = 1;
			}
			todoOk = 1;
		}
		return todoOk;
	}

int isEmptyTrabajo(eTrabajo* lista, int tam, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0 && pIndice != NULL)
	{

		*pIndice = -1;
		for (int i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty)
			{
				*pIndice= i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


int addTrabajo(eTrabajo* lista, int tamTra, eMascota* listaM, int tamM, eServicio* listaS, int tamS, int* idTrabajo, eColor *listaC, int tamC,
		eTipo *listaT, int tamT){
int todoOk = 0;
int indice1;
int indice;
int indice2;
eTrabajo auxTrabajos;
if (lista != NULL && tamTra > 0 && listaS != NULL && tamS > 0 && listaM != NULL && tamM>0 && idTrabajo != NULL && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0){
	if(isEmptyTrabajo(lista, tamTra, &indice)){
		listarMascota(listaM, tamM, listaC, tamC, listaT, tamT);
			validarInt("\nIngresar el id de la mascota\n", "\nError al ingresar el id, ingrese un id valido\n", &auxTrabajos.idMascota, 1, 2002);
			buscarId(listaM, tamM, auxTrabajos.idMascota, &indice1);
			while (indice1 == -1) {
						validarInt(
								"\nError. no se encontro una mascota con ese ID. Reingrese un id valido: \n",
								"\nError. Reingrese un id valido\n", &auxTrabajos.idMascota, 1, 2000);
						buscarId(listaM, tamM, auxTrabajos.idMascota, &indice1);
					}
			listarServicios(listaS, tamS);
			validarInt("\nIngrese el id del servicio;  \n", "\nError. reingrese un id valido", &auxTrabajos.idServicio, 20000,20002 );
			buscarIdServicio(listaS, tamS, auxTrabajos.idServicio, &indice2);
				while (indice2 == -1) {
							validarInt(
									"\nError. no se encontro una mascota con ese ID. Reingrese un id valido: \n",
									"\nError. Reingrese un id valido\n", &auxTrabajos.idServicio, 20000, 20002);
							buscarIdServicio(listaS, tamS, auxTrabajos.idServicio, &indice2);
						}
				validarFecha(&auxTrabajos.fecha.dia, &auxTrabajos.fecha.mes, &auxTrabajos.fecha.anio);
				auxTrabajos.id = *idTrabajo;
				lista[indice] = auxTrabajos;
				lista[indice].isEmpty = 0;
				todoOk = 1;
	}else{
		printf("No hay espacio disponible en la lista\n");
	}
}

return todoOk;
}


int mostrarTrabajo(eTrabajo* lista, eMascota* listaM, int tamM, eColor* listaC, int tamC, eTipo* listaT, int tamTIPO, eServicio* listaS, int tamS){
int todoOk = 0;
char nombre[20];
char servicio[20];
	if(lista != NULL && listaC != NULL && listaM != NULL && tamM >0 && tamC>0){
	cargarDescripcionServicio(listaS, tamS, lista->idServicio, servicio);
	cargarNombreMascota(listaM, tamM, lista->idMascota, nombre);


printf(" %04d    %10s   %10s     %02d/%02d/%04d\n", lista->id, nombre, servicio, lista->fecha.dia,lista->fecha.mes, lista->fecha.anio );
		todoOk = 1;
	}
return todoOk;
}

int listarTrabajo(eTrabajo* lista,int tamTra, eMascota* listaM, int tamM, eColor* listaC, int tamC, eTipo* listaT, int tamTIPO, eServicio* listaS, int tamS){
	int todoOk = 0;
		int flag = 0;
		if (lista != NULL && tamM > 0 && listaM != NULL && tamM > 0 && listaC != NULL && tamC>0&& listaT != NULL && tamTIPO>0&& listaS != NULL && tamS>0)
		{
			system("cls");
			printf(" \n\n         ***   Listado de Autos   ***\n\n");
			printf(" ID      Nombre     Servicio    Fecha    \n");
			printf("------------------------------------------------\n");
			for (int i = 0; i < tamTra; i++)
			{
				if (!lista[i].isEmpty)
				{
					mostrarTrabajo(lista + i, listaM, tamM, listaC, tamC, listaT, tamTIPO, listaS, tamS);
					flag = 1;
				}
			}
			if (!flag)
			{
				printf("\n** No hay Trabajos en el sistema.** ");
			}
			todoOk = 1;
		}
		return todoOk;
}





