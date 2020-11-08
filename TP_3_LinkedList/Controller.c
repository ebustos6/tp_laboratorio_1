#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int retorno;

	pArchivo = fopen(path, "r");

	if (pArchivo != NULL && pArrayListEmployee != NULL) {
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		retorno = 1;
		fclose(pArchivo);

	} else {

		retorno = 0;
	}

	return retorno;
}

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int retorno = 0;

	pArchivo = fopen(path, "rb");

	if (pArchivo != NULL && pArrayListEmployee != NULL) {
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		retorno = 1;
		fclose(pArchivo);

	}

	return retorno;
}

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 0;
	Employee *auxEmpleado;
	char nombre[50];
	int id;
	int sueldo;
	int horasTrabajadas;

	auxEmpleado = employee_new();

	if (auxEmpleado != NULL && pArrayListEmployee != NULL) {
		CargarTexto("Ingrese nombre: ", nombre, 50);
		sueldo = GetInt("Ingrese sueldo: ",
				"El sueldo debe ser mayor a 0, reingrese: ", 0);
		horasTrabajadas = GetInt("ingrese horas trabajadas: ",
				"Las hs trabajadas deben ser mayores a 0, reingrese: ", 0);
		parser_AsignarID(pArrayListEmployee, &id);

		employee_setId(auxEmpleado, id);
		employee_setNombre(auxEmpleado, nombre);
		employee_setSueldo(auxEmpleado, sueldo);
		employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);

		ll_add(pArrayListEmployee, auxEmpleado);

		printf("ID number: %d\n", id);

		retorno = 1;
	}

	return retorno;
}

int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int auxID;
	int id;
	char auxNombre[50];
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	int len;
	char modifica = 'n';
	Employee *auxEmpleado;
	int i;
	int opcion;
	int retorno = 0;

	if (pArrayListEmployee != NULL) {
		auxID = GetInt("Ingrese el ID a modificar: ",
				"El ID debe ser mayor a 0, reingrese: ", 0);
		len = ll_len(pArrayListEmployee);

		for (i = 0; i < len; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);

			if (auxID == id) {
				employee_getNombre(auxEmpleado, auxNombre);
				printf("Esta por modificar el id %d del empleado %s\n", id,
						auxNombre);

				do {
					opcion =
							MostrarMenu(
									"1. Nombre: \n2. Hs trabajadas: \n3.Sueldo: \n4. Salir: \nSeleccione una opcion: ");

					switch (opcion) {
					case 1:
						CargarTexto("Ingrese nombre: ", nombre, 50);
						employee_setNombre(auxEmpleado, nombre);
						modifica = 's';
						break;
					case 2:
						horasTrabajadas =
								GetInt("Ingrese hs trabajadas: ",
										"La cantidad de horas debe ser mayor a 0, reingrese: ",
										0);
						employee_setHorasTrabajadas(auxEmpleado,
								horasTrabajadas);
						modifica = 's';
						break;
					case 3:
						sueldo = GetInt("Ingrese sueldo: ",
								"El sueldo debe ser mayor a 0, reingrese: ", 0);
						employee_setSueldo(auxEmpleado, sueldo);
						modifica = 's';
						break;
					}

				} while (opcion != 4);

				if (modifica == 's') {
					ll_set(pArrayListEmployee, i, auxEmpleado);
					retorno = 1;
					break;

				} else {

					break;
				}

			}
		}

	}

	return retorno;
}

int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int auxID;
	char auxNombre[50];
	int id;
	int i;
	int len;
	Employee *auxEmpleado;
	char respuesta;
	int retorno = 0;

	if (pArrayListEmployee != NULL) {
		auxID = GetInt("Ingrese el ID que desea eliminar: ",
				"El ID debe ser mayor a 0, reingrese: ", 0);

		len = ll_len(pArrayListEmployee);

		for (i = 0; i < len; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);

			if (auxID == id) {
				employee_getNombre(auxEmpleado, auxNombre);
				printf("Esta por eliminar el id %d del empleado %s", id,
						auxNombre);

				respuesta = ConfirmarOperacion();

				if (respuesta == 's') {
					ll_remove(pArrayListEmployee, i);
					retorno = 1;
				}
			}

			if (retorno == 1 || respuesta == 'n') {
				break;
			}
		}
	}

	return retorno;
}

int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int i;
	Employee *auxEmpleado;
	int len;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	int contador = 0;

	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		printf("SE IMPRIME LISTA DE EMPLEADOS: \n");
		printf("ID EMPLEADO / NOMBRE / HS TRABAJADAS / SUELDO \n");

		for (i = 0; i < len; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);
			employee_getNombre(auxEmpleado, nombre);
			employee_getSueldo(auxEmpleado, &sueldo);
			employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
			contador++;

			printf("%10d %20s %10d %10d\n", id, nombre, horasTrabajadas,
					sueldo);

			if (contador % 250 == 0) {
				system("pause");
			}

		}
	}

	return 1;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int opcion;
	int orden;
	int retorno = 0;
	char modifica = 'n';

	if (pArrayListEmployee != NULL) {
		orden =
				CargarEntero(
						"\n1. Orden ascendente\n0. Orden descendente\nSeleccione la opcion deseada: ",
						"\nError, seleccione 1 ascendente o 0 descendente: ", 0,
						1);
		do {

			opcion =
					MostrarMenu(
							"1. ID\n2. Nombre\n3. Horas trabajadas\n4. Sueldo\n5. Salir\nSeleccione la opcion deseada: ");

			switch (opcion) {
			case 1:
				printf("Aguarde mientras se realiza el ordenamiento...");
				ll_sort(pArrayListEmployee, employee_CompareById, orden);
				modifica = 's';
				break;
			case 2:
				printf("Aguarde mientras se realiza el ordenamiento...");
				ll_sort(pArrayListEmployee, employee_CompareByName, orden);
				modifica = 's';
				break;
			case 3:
				printf("Aguarde mientras se realiza el ordenamiento...");
				ll_sort(pArrayListEmployee, employee_CompareByHsTrabajadas,
						orden);
				modifica = 's';
				break;
			case 4:
				printf("Aguarde mientras se realiza el ordenamiento...");
				ll_sort(pArrayListEmployee, employee_CompareBySueldo, orden);
				modifica = 's';
				break;
			case 5:
				break;
			}

		} while (opcion < 1 || opcion > 5);

		if (modifica == 's') {
			retorno = 1;
		}

	}

	return retorno;
}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int i;
	int len;
	Employee *auxEmpleado;
	int id;
	int sueldo;
	int horasTrabajadas;
	char nombre[50];
	int retorno = 0;

	pArchivo = fopen(path, "w");
	len = ll_len(pArrayListEmployee);

	if (pArchivo != NULL && pArrayListEmployee != NULL
			&& len != 0&& path!=NULL) {
		fprintf(pArchivo, "id, nombre, horasTrabajadas, sueldo\n");

		for (i = 0; i < len; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);

			employee_getId(auxEmpleado, &id);
			employee_getNombre(auxEmpleado, nombre);
			employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
			employee_getSueldo(auxEmpleado, &sueldo);

			fprintf(pArchivo, "%d, %s, %d, %d\n", id, nombre, horasTrabajadas,
					sueldo);
		}

		fclose(pArchivo);
		retorno = 1;
	}

	return retorno;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int i;
	int len;
	Employee *auxEmpleado;
	int aux;
	int contador = 0;
	int retorno = 0;

	pArchivo = fopen(path, "wb");
	len = ll_len(pArrayListEmployee);

	if (pArchivo != NULL && pArrayListEmployee != NULL
			&& len != 0&& path!=NULL) {
		fwrite(&len, sizeof(int), 1, pArchivo);
		printf("Cantidad de archivos a guardar: %d\n", len);

		for (i = 0; i < len; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);

			aux = fwrite(auxEmpleado, sizeof(Employee), 1, pArchivo);
			if (aux == 1) {
				contador++;
			}

		}
		printf("Elementos guardados: %d\n", contador);
		fclose(pArchivo);
		retorno = 1;
	}

	return retorno;
}

