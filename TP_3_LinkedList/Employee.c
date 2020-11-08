#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

static int isValidNombre(char *cadena, int longitud);

Employee* employee_new(void) {
	Employee *aux;

	aux = (Employee*) malloc(sizeof(Employee));

	return aux;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *aux = NULL;
	int flagOk = 0;
	aux = employee_new();

	if (aux != NULL) {

		if (employee_setNombre(aux, nombreStr) == 0) {

			if (employee_setHorasTrabajadas(aux, atoi(horasTrabajadasStr))
					== 0) {

				if (employee_setSueldo(aux, atoi(sueldoStr)) == 0) {

					if (employee_setId(aux, atoi(idStr)) == 0) {

						flagOk = 1;
					}
				}
			}
		}
		if (flagOk == 0) {
			employee_delete(aux);
			aux = NULL;
		}
	}

	return aux;
}

void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}

int employee_setId(Employee *this, int id) {
	int retorno = -1;
	if (this != NULL && id >= 0) {
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int employee_getId(Employee *this, int *id) {

	int retorno = -1;
	if (this != NULL && id != NULL) {
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		if (isValidNombre(nombre, 128)) {
			retorno = 0;
			strlwr(nombre);
			strncpy(this->nombre, nombre, 128);
		}
	}
	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		retorno = 0;
		strncpy(nombre, this->nombre, 128);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = -1;
	if (this != NULL && horasTrabajadas >= 0) {
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno = -1;
	if (this != NULL && horasTrabajadas != NULL) {
		retorno = 0;
		*horasTrabajadas = this->id;
	}
	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = -1;
	if (this != NULL && sueldo >= 0) {
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno = -1;
	if (this != NULL && sueldo != NULL) {
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

int employee_CompareByName(void *empleado1, void *empleado2) {
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;
	int retorno;

	if (empleado1 != NULL && empleado2 != NULL) {
		auxEmpleado1 = (Employee*) empleado1;
		auxEmpleado2 = (Employee*) empleado2;

		retorno = strcmp(auxEmpleado1->nombre, auxEmpleado2->nombre);

	}

	return retorno;
}

int employee_CompareById(void *empleado1, void *empleado2) {
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;
	int retorno;

	if (empleado1 != NULL && empleado2 != NULL) {
		auxEmpleado1 = (Employee*) empleado1;
		auxEmpleado2 = (Employee*) empleado2;

		if (auxEmpleado1->id > auxEmpleado2->id) {
			retorno = 1;
		}

		if (auxEmpleado1->id < auxEmpleado2->id) {
			retorno = -1;
		}

		if (auxEmpleado1->id == auxEmpleado2->id) {
			retorno = 0;
		}

	}
	return retorno;
}

int employee_CompareByHsTrabajadas(void *empleado1, void *empleado2) {
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;
	int retorno;

	if (empleado1 != NULL && empleado2 != NULL) {
		auxEmpleado1 = (Employee*) empleado1;
		auxEmpleado2 = (Employee*) empleado2;

		if (auxEmpleado1->horasTrabajadas > auxEmpleado2->horasTrabajadas) {
			retorno = 1;

		}

		if (auxEmpleado1->horasTrabajadas < auxEmpleado2->horasTrabajadas) {
			retorno = -1;
		}

		if (auxEmpleado1->horasTrabajadas == auxEmpleado2->horasTrabajadas) {
			retorno = 0;
		}
	}

	return retorno;
}

int employee_CompareBySueldo(void *empleado1, void *empleado2) {
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;
	int retorno;

	if (empleado1 != NULL && empleado2 != NULL) {
		auxEmpleado1 = (Employee*) empleado1;
		auxEmpleado2 = (Employee*) empleado2;

		if (auxEmpleado1->sueldo > auxEmpleado2->sueldo) {
			retorno = 1;

		}

		if (auxEmpleado1->sueldo < auxEmpleado2->sueldo) {
			retorno = -1;
		}

		if (auxEmpleado1->sueldo == auxEmpleado2->sueldo) {
			retorno = 0;
		}
	}

	return retorno;
}

/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char *cadena, int longitud) {
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**********************************************************************/
