
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Data.h"
#define TRUE 0
#define FALSE 1

/** \brief Inicaliza en 0 (TRUE) a todos los empleados
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return void
 */
void initEmployees(Employee list[], int len) {
	int i;

	for (i = 0; i < len; i++) {
		list[i].isEmpty = TRUE;
	}
}

/** \brief Crea automaticamente una id para la estructura Employee
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return int devuelve numero de id
 */
int createEmployeeId(Employee list[], int len) {
	int i;
	int aux = 1;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE) {
			aux++;
		}
	}
	return aux;
}

/** \brief Llena los campos de la estructura Employee
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return Employee devuelve los datos cargados
 */
Employee addEmployee(Employee list[], int len) {

	Employee aux;

	aux.id = createEmployeeId(list, len);
	printf("Ingrese nombre del empleado: ");
	fflush(stdin);
	gets(aux.name);
	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(aux.lastName);
	printf("Ingrese salario: ");
	scanf("%f", &aux.salary);
	printf("Ingrese sector: ");
	scanf("%d", &aux.sector);
	aux.isEmpty = FALSE;

	return aux;
}

/** \brief pide la id de un empleado, lo busca, imprime sus datos y devuelve su id.
 *
 *\param list[] Employee array empleados
 * \param len int largo del array
 * \return int devuelve la id si el empleado existe, sino devuelve -1
 *
 */
int findEmployeeById(Employee list[], int len) {
	int id;
	int i;

	id = getInt("\nIngrese la Id del empleado a buscar: ");

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && id == list[i].id) {
			printAnEmployee(list[i]);
			return id;
			break;
		}
	}
	return -1;
}

/** \brief Remueve un empleado por id (baja logica)
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return int -1 si no existe, 0 si existe
 */
int removeEmployee(Employee list[], int len) {

	int id;
	int i;

	id = getInt("\nIngrese la Id del empleado a eliminar: ");

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && id == list[i].id) {
			list[i].isEmpty = TRUE;
			break;
			return 0;
		}

	}
	return -1;
}

/** \brief Ordena empleados por nombre y sector
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return void
 */
void sortEmployees(Employee list[], int len) {
	int i;
	int j;
	Employee aux;

	for (i = 0; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			if (strcmp(list[i].lastName, list[j].lastName) > 0) {
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}

			else {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {
					if (list[i].sector > list[j].sector) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}
}

/** \brief Imprime listado de empleados
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return int
 */
int printEmployees(Employee list[], int len) {
	int i;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE) {
			printAnEmployee(list[i]);
		}
	}
	return 0;
}

/** \brief Imprime los datos de un empleado
 *
 * \param aux Employee
 * \return void
 */
void printAnEmployee(Employee aux) {
	printf("id%2d %10s %-10s sueldo $%4.2f sector%2d \n", aux.id, aux.name,
			aux.lastName, aux.salary, aux.sector);
}

/** \brief llama a buscar lugar, llama a cargar e informa al usuario
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return -1 si no hay espacio 1 si se cargo
 */
int addEmployeeList(Employee list[], int len) {
	int found, ret = -1;

	found = findFree(list, len);
	if (found != -1) {
		list[found] = addEmployee(list, len);
		ret = 1;
	}
	return ret;
}

/** \brief busca lugar para crear un empleado
 *
 * \param list[] Employee
 * \param len int
 * \return int devuelve la posicion donde crearlo
 */
int findFree(Employee list[], int len) {
	int i, index = -1;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == TRUE) {
			index = i;
			break;
		}
	}
	return index;
}

/** \brief Edita nombre de un empleado ya creado
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return void
 */
void editEmployeeName(Employee list[], int len) {
	int id, i;

	id = findEmployeeById(list, len);
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && id == list[i].id) {
			getString("\nIngrese el nuevo nombre: ", list[i].name);
			list[i].name[strlen(list[i].name)] = '\0';
			printf("\n|****EL NOMBRE HA SIDO EDITADO CORRECTAMENTE***|\n");
			break;

		}

	}
}

/** \brief edita apellido de un empleado
 *
 * \param list[] Employee
 * \param len int
 * \return void
 */
void editEmployeeLastName(Employee list[], int len) {
	int id, i;

	id = findEmployeeById(list, len);

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && id == list[i].id) {
			getString("\nIngrese el nuevo apellido: ", list[i].lastName);
			list[i].lastName[strlen(list[i].lastName)] = '\0';
			printf("\n|***EL APELLIDO HA SIDO EDITADO CORRECTAMENTE**|\n");
			break;
		}
	}
}

/** \brief edita salario de un empleado
 *
 * \param list[] Employee
 * \param len int
 * \return void
 */
void editEmployeeSalary(Employee list[], int len) {
	int id, i;

	id = findEmployeeById(list, len);

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && id == list[i].id) {
			list[i].salary = getFloat("\nIngrese el nuevo salario: ");
			printf("\n|***EL SALARIO HA SIDO EDITADO CORRECTAMENTE***|\n");
			break;
		}

	}
}

/** \brief edita sector de un empleado
 *
 * \param list[] Employee
 * \param len int
 * \return void
 */
void editEmployeeSector(Employee list[], int len) {
	int id, i;

	id = findEmployeeById(list, len);

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && id == list[i].id) {
			list[i].sector = getInt("\nIngrese el nuevo sector: ");
			printf("\n|***EL SECTOR HA SIDO EDITADO CORRECTAMENTE****|\n");
			break;
		}
	}
}

/** \brief suma el total de los salarios de los empleados
 *
 * \param list[] Employee
 * \param len int
 * \return float devuelve el monto total
 */
float salaryAdd(Employee list[], int len) {
	float aux;
	int i;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE){
			aux += list[i].salary;
		}
	}
	return aux;
}

/** \brief promedia los salarios de todos los empleados
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return float devuelve el promedio
 */
float salaryAverage(Employee list[], int len) {
	int i, count = 0;
	float average;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE) {
			count++;
		}
	}
	average = salaryAdd(list, len) / count;
	return average;
}

/** \brief lista los empleados con un salario mayor al promedio e informa la cantidad
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return void
 */
void salaryMoreThanAverage(Employee list[], int len) {
	int i, count = 0;
	float aux = salaryAverage(list, len);

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == FALSE && list[i].salary > aux) {
			count++;
			printAnEmployee(list[i]);
		}

	}
	printf("La cantidad de empleados que superan el salario promedio es: %d\n",
			count);
}

/** \brief informa al usuario valores de los salarios
 *
 * \param list[] Employee array empleados
 * \param len int largo del array
 * \return void
 */
void printSalary(Employee list[], int len) {
	printf("\nEl total de salarios es: $%.2f", salaryAdd(list, len));
	printf("\nEl promedio de los salarios es: $%.2f\n",
			salaryAverage(list, len));

}

