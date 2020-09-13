#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"

int utn_getInt(char msj[]){
	int aux;
	printf("%s", msj);
	scanf("%d", &aux);
	return aux;
}

float utn_getFloat(char msj[]){
	float aux;
	printf("%s", msj);
	scanf("%f", &aux);
	return aux;
}

char utn_getChar(char msj[]){
	char aux;
	printf("%s", msj);
	fflush(stdin);
	scanf("%c", &aux);
	return aux;
}

int validarIntMenu(){
	int aux;
	aux = utn_getInt("\nElija opcion (1 a 5): ");
	while(aux < 1 || aux > 5){
			printf("La opcion elegida no es valida, por favor intentelo nuevamente.");
			aux = utn_getInt("\nElija opcion (1 a 5): ");
		}
	return aux;
}

int menu(){
	int aux;
	printf("************MENU PRINCIPAL************");
	printf("\n1 Ingresar 1er operando (A=x) ");
	printf("\n2 Ingresar 2do operando (B=y) ");
    printf("\n3 Calcular todas las operaciones ");
    printf("\n4 Informar resultados ");
	printf("\n5 Salir");
	aux = validarIntMenu();

	return aux;
}
