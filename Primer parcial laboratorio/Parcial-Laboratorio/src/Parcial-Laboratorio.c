/*
 ============================================================================
 Name        : Parcial-Laboratorio.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "mascota.h"
#include "trabajo.h"
#include "servicio.h"


#define TAMM 2000
#define TAMTIPO 5
#define TAMC 5
#define TAMS 3
#define TAMTRABAJO 2000


int main(void) {
	setbuf(stdout, NULL);
	int salida = 'n';
	int flagAdd = 0;
	int idMascota = 1;
	int idTrabajo = 1;
	int flagAddTrabajo = 0;
	eColor listaC[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Rojo"},{5003,"Gris"},{5004,"Azul"}};
	eTipo listaT[TAMTIPO]= {{1000,"Ave"},{1001,"Perro"},{1002,"Roedor"},{1003,"Gato"},{1004,"Pez"}};
	eServicio listaS[TAMS] ={
					{20000, "Corte", 450},
					{20001, "Desparasitado", 800},
					{20002, "Castrado", 600}};
	eMascota listaM[TAMM];
	eTrabajo listaTra[TAMTRABAJO];

	if(initStruct(listaM, TAMM) && initStructTrabajo(listaTra, TAMTRABAJO)){
	do{

		switch(menu()){

	case 1:
		if(addMascota(listaM, TAMM, listaC, TAMC, listaT, TAMTIPO, &idMascota)){
			flagAdd++;
			idMascota++;
		}
	break;

	case 2:
		if(flagAdd){
			modificarMascota(listaM, TAMM, listaC, TAMC, listaT, TAMTIPO);
		}else{
			printf("\nError. No se han ingresado mascotas a la lista\n");
		}
	break;

	case 3:
		if(flagAdd){
			removeMascota(listaM, TAMM, listaC, TAMC, listaT, TAMTIPO, &flagAdd);
			printf("\nMascota removida con exito\n");
		}else{
			printf("\nError. No se han ingresado mascotas a la lista\n");
		}
	break;

	case 4:
		listarMascota(listaM, TAMM,listaC, TAMC ,listaT, TAMTIPO);
	break;

	case 5:
		listarTipo(listaT, TAMTIPO);
	break;

	case 6:
		listarColor(listaC, TAMC);
	break;

	case 7:
		listarServicios(listaS, TAMS);
		break;
	case 8:
		if(flagAdd){
		if(addTrabajo(listaTra, TAMTRABAJO, listaM, TAMM, listaS, TAMS, &idTrabajo, listaC, TAMC, listaT, TAMTIPO)){
			printf("\n\nTrabajo agregado con exito\n\n");
			idTrabajo++;
			flagAddTrabajo++;
		}
		}else{
			printf("\nError. No se han ingresado mascotas a la lista\n");
		}
		break;

	case 9:
		if(flagAddTrabajo){
			listarTrabajo(listaTra, TAMTRABAJO, listaM, TAMM, listaC, TAMC, listaT, TAMTIPO, listaS, TAMS);
		}
		break;
	case 10:
		salida = 's';
	break;
		}
	}while(salida == 'n');
	}
	return EXIT_SUCCESS;
}