/*
 * Data.c
 *
 *  Created on: Sep 28, 2020
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

/** \brief pide string de datos y lo lee
 *
 * \param msg[] char
 * \param input[] char
 * \return void
 */
void getString(char msg[], char input[]) {
	printf(msg);
	fflush(stdin);
	scanf("%s", input);
}

/** \brief pide un int y lo lee
 *
 * \param msg[] char
 * \return int
 */
int getInt(char msg[]) {
	int aux;
	printf("%s", msg);
	scanf("%d", &aux);
	return aux;
}

/** \brief pide un float y lo lee
 *
 * \param msg[] char
 * \return float
 */
float getFloat(char msg[]) {
	float aux;
	printf("%s", msg);
	scanf("%f", &aux);

	return aux;
}

/** \brief Menu principal
 *
 * \param aux int
 * \return int
 */
int menu1(int aux) {

	printf("\n|----------------MENU PRINCIPAL----------------|");
	printf("\n|1.-ALTAS--------------------------------------|");
	printf("\n|2.-MODIFICACIONES-----------------------------|");
	printf("\n|3.-BAJAS--------------------------------------|");
	printf("\n|4.-INFORMES-----------------------------------|");
	printf("\n|5.------------------SALIR---------------------|");
	printf("\nIndique la opcion: ");
	scanf("%d", &aux);

	return aux;
}

/** \brief Menu de modificaciones
 *
 * \param aux int
 * \return int
 */
int menu2(int aux) {

	printf("\n|-------------MENU MODIFICACIONES--------------|");
	printf("\n|1.-MODIFICAR NOMBRE---------------------------|");
	printf("\n|2.-MODIFICAR APELLIDO-------------------------|");
	printf("\n|3.-MODIFICAR SUELDO---------------------------|");
	printf("\n|4.-MODIFICAR SECTOR---------------------------|");
	printf("\n|5.-----------------SALIR----------------------|");
	printf("\nIndique la opcion: ");
	scanf("%d", &aux);

	return aux;
}

/** \brief Menu de informes
 *
 * \param aux int
 * \return int
 */
int menu3(int aux) {

	printf("\n|--------------MENU INFORMES-------------------|");
	printf("\n|1.-EMPLEADOS POR APELLIDO Y SECTOR------------|");
	printf("\n|2.-TOTAL Y PROMEDIO DE LOS SALARIOS-----------|");
	printf("\n|3.---------------SALIR------------------------|");
	printf("\nIndique la opcion: ");
	scanf("%d", &aux);

	return aux;
}

/** \brief imprime mensajes de menu principal
 *
 * \param aux int
 * \return void
 */
void printMessages1(int aux) {

	if (aux > 5 || aux == 0) {
		printf("\n|******LA OPCION SELECCIONADA NO ES VALIDA*****|\n");
	}
	if (aux == 5) {
		printf("\n|*******TRABAJO PRACTICO NUMERO 2 E.B.*********|\n");
	}

}

/** \brief imprime mensajes de menu de modificaciones
 *
 * \param aux int
 * \return void
 */
void printMessages2(int aux) {

	if (aux == 5) {
		printf("\n|**********VOLVIENDO A MENU PRINCIPAL**********|\n");
	}
	if (aux > 5 || aux == 0) {
		printf("\n|******LA OPCION SELECCIONADA NO ES VALIDA*****|\n");
	}
}

/** \brief imprime mensajes de menu de informes
 *
 * \param aux int
 * \return void
 */
void printMessages3(int aux) {

	if (aux == 3) {
		printf("\n|**********VOLVIENDO A MENU PRINCIPAL**********|\n");
	}
	if (aux > 3 || aux == 0) {
		printf("\n|******LA OPCION SELECCIONADA NO ES VALIDA*****|\n");
	}
}

