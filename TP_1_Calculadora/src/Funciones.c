#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

float sumar(float num1,float num2){
    return  num1 + num2;
}

float restar(float num1,float num2){
    return num1 - num2;
}

float multiplicar(float num1,float num2){
    return num1 * num2;
}

float dividir(float num1, float num2){
    float retorno = -1;
    if(num2 != 0){
    	return num1/num2;
    }
    else{
    	return retorno;
    }

}

int validarEntero(float num){
	int retorno = 0;
	if ((num - (int) num) == 0) {
		retorno = 1;
	}
	return retorno;
}

long int factorial(float num){
	long int factorial = num;
	int i;

	if (validarEntero(num) == 1 && num > 0) {
		for (int i = factorial; i > 1; --i) {
			factorial = ((i - 1) * factorial);
		}
	} else {
		factorial = 0;
	}
	return factorial;
}


