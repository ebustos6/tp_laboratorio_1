#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	int auxScan;
	Employee *auxEmpleado;
	int retorno = 0;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		auxScan = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,
				horasTrabajadas, sueldo);

		do {
			auxScan = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,
					horasTrabajadas, sueldo);

			if (auxScan == 4) {
				auxEmpleado = employee_newParametros(id, nombre,
						horasTrabajadas, sueldo);
				ll_add(pArrayListEmployee, auxEmpleado);
			}

		} while (!feof(pFile));

		retorno = 1;
	}

	return retorno;
}


int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {

	Employee auxEmpleado;
	Employee *pEmpleado;
	int i;
	int len;
	int aux;
	int retorno = 0;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];

	if (pFile != NULL && pArrayListEmployee != NULL) {
		aux = fread(&len, sizeof(int), 1, pFile);
		if (aux == 1) {
			printf("Cantidad de elementos en el archivo: %d\n", len);
		}

		for (i = 0; i < len; i++) {
			aux = fread(&auxEmpleado, sizeof(Employee), 1, pFile);
			if (aux == 1) {
				sprintf(id, "%d", auxEmpleado.id);
				strcpy(nombre, auxEmpleado.nombre);
				sprintf(horasTrabajadas, "%d", auxEmpleado.horasTrabajadas);
				sprintf(sueldo, "%d", auxEmpleado.sueldo);

				pEmpleado = employee_newParametros(id, nombre, horasTrabajadas,
						sueldo);

				ll_add(pArrayListEmployee, pEmpleado);

			}
		}

		retorno = 1;
	}

	return retorno;
}

int parser_AsignarID(LinkedList *pArrayListEmployee, int *idNumber) {
	int len;
	int i;
	int auxID;
	Employee *AuxEmpleado;
	int retorno = 0;

	if (pArrayListEmployee != NULL && idNumber != NULL) {

		len = ll_len(pArrayListEmployee);

		if (len == 0) {
			*idNumber = 1;

		} else {

			for (i = 0; i < len; i++) {
				AuxEmpleado = ll_get(pArrayListEmployee, i);
				employee_getId(AuxEmpleado, &auxID);

				if (i == 0 || *idNumber < auxID) {
					*idNumber = auxID;
				}

			}

			*idNumber += 1;
			retorno = 1;

		}
	}
	return retorno;

}
