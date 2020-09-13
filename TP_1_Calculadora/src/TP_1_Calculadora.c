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

    int opcionMenu;
    float numero1;
    float numero2;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long int factorialA;
    long int factorialB;


    do{

    printf("\n1 Ingresar 1er operando (A=x) ");
    printf("\n2 Ingresar 2do operando (B=y) ");
    printf("\n3 Calcular todas las operaciones ");
    printf("\n4 Informar resultados ");
    printf("\n5 Salir");
    printf("\nElija opcion (1 a 5): ");
    scanf("%d", &opcionMenu);

    switch(opcionMenu){
    case 1: printf("\nIngrese el primer numero: ");
            scanf("%f", &numero1);
            break;

    case 2: printf("\nIngrese el segundo numero: ");
            scanf("%f", &numero2);
            break;

    case 3: suma = HacerSuma(numero1, numero2);
            resta = HacerResta(numero1, numero2);
            division = HacerDivision(numero1, numero2);
            multiplicacion = HacerMultiplicacion(numero1, numero2);
            factorialA = HacerFactorial(numero1);
            factorialB = HacerFactorial(numero2);
            break;

    case 4: printf("\nEl resultado de A+B es: %.2f", suma);
            printf("\nEl resultado de A-B es: %.2f", resta);
            if(numero2 != 0){
            printf("\nEl resultado de A/B es: %.2f", division);
            }
            else{
                printf("\nNo se puede dividir por 0");
            }
            printf("\nEl resultado de A*B es: %.2f", multiplicacion);
            printf("\nEl factorial de A es: %ld y El factorial de B es: %ld", factorialA, factorialB);
            break;

    case 5: break;

    default: printf("No es una opcion valida\n");
             break;
    }

}while(opcionMenu != 5);

    return 0;
}
