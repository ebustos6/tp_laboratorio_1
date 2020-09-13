/*
 ============================================================================
 Name        : TP_1_Calculadora.c
 Author      : Emanuel Bustos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Utn.h"


int main()
{
	setbuf(stdout,NULL);

	char respuesta;
    int seguimiento = 0;
    float numero1;
    float numero2;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long int factorialA;
    long int factorialB;


    do{
    switch(menu()){
    case 1:	if(seguimiento != 0){
    				printf("\nYa se ingreso el primer numero!");
    		}
    		numero1 = utn_getFloat("\nIngrese el primer numero: ");
    		seguimiento = 1;
    		break;

    case 2:	if(seguimiento != 1){
				if(seguimiento < 1){
					printf("\nFalta ingresar un primer numero!");
					}
				else if(seguimiento > 1){
					printf("\nYa se ingreso el segundo numero!");
					}
			}
    		numero2 = utn_getFloat("\nIngrese el segundo numero: ");
    		seguimiento = 2;
            break;

    case 3: if(seguimiento != 2){
    			if(seguimiento < 2){
    				printf("\nFaltan ingresar numeros.");
    			}
    			else if(seguimiento > 2){
    				printf("\nYa se calcularon las operaciones!");
    			}
			}
    		suma = sumar(numero1, numero2);
            resta = restar(numero1, numero2);
            division = dividir(numero1, numero2);
            multiplicacion = multiplicar(numero1, numero2);
            factorialA = factorial(numero1);
            factorialB = factorial(numero2);
            seguimiento = 3;
            break;

    case 4: if(seguimiento != 3){
        		if(seguimiento <= 1){
        			printf("\nFaltan ingresar numeros.");
        			}
        		else if(seguimiento == 2){
        			printf("\nFalta calcular las operaciones!");
        			}
    		}
    		printf("\nEl resultado de A+B es: %.2f", suma);
            printf("\nEl resultado de A-B es: %.2f", resta);
            if(numero2 != 0){
            printf("\nEl resultado de A/B es: %.2f", division);
            }
            else{
                printf("\nNo se puede dividir por 0");
            }
            printf("\nEl resultado de A*B es: %.2f", multiplicacion);
            printf("\nEl factorial de A es: %ld y El factorial de B es: %ld", factorialA, factorialB);
            seguimiento = 0;
            break;

    case 5: respuesta = utn_getChar("\nEsta seguro que desea salir?(s/n): ");
    		break;

    }

}while(respuesta != 's');

    return 0;
}
