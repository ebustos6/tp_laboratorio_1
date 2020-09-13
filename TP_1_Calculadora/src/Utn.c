/*
 * Utn.c
 *
 *  Created on: Sep 12, 2020
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"

int getInt(char msj[]){
	int aux;
	printf("%s", msj);
	scanf("%d", &aux);
	return aux;
}

float getFloat(char msj[]){
	float aux;
	printf("%s", msj);
	scanf("%f", &aux);
	return aux;
}

char getChar(char msj[]){
	char aux;
	printf("%s", msj);
	fflush(stdin);
	scanf("%c", &aux);
	return aux;
}
