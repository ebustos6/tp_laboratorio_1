#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

/** \brief Constructor de variable de tipo Employee en memoria dinamica
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief Constructor por parametros de variable de tipo Employee en memoria dinamica
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);

/** \brief Ejectura la funcion free sobre un puntero ingresado por parametro
 *
 * \param Employee*
 * \return void
 *
 */
void employee_delete(Employee *this);

/** \brief setter de id empleado
 *
 * \param this Employee*
 * \param id int
 * \return int (1 ok - 0 error)
 *
 */
int employee_setId(Employee *this, int id);

/** \brief getter de id empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int (1 ok - 0 error)
 *
 */
int employee_getId(Employee *this, int *id);

/** \brief setter de nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int (1 ok - 0 error)
 *
 */
int employee_setNombre(Employee *this, char *nombre);

/** \brief getter de nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int (1 ok - 0 error)
 *
 */
int employee_getNombre(Employee *this, char *nombre);

/** \brief setter horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int (1 ok - 0 error)
 *
 */
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);

/** \brief getter horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int (1 ok - 0 error)
 *
 */
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

/** \brief setter sueldo
 *
 * \param this Employee*
 * \param sueldo int
 * \return int (1 ok - 0 error)
 *
 */
int employee_setSueldo(Employee *this, int sueldo);

/** \brief getter sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int (1 ok - 0 error)
 *
 */
int employee_getSueldo(Employee *this, int *sueldo);

/** \brief compara 2 nombres de una lista a fin de realizar un ordenamiento
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (1 mayor - 0 igual - -1 menor)
 *
 */
int employee_CompareByName(void *empleado1, void *empleado2);

/** \brief compara 2 id's de una lista a fin de realizar un ordenamiento
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (1 mayor - 0 igual - -1 menor)
 *
 */
int employee_CompareById(void *empleado1, void *empleado2);

/** \brief compara 2 valores de horas trabajadas de una lista a fin de realizar un ordenamiento
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (1 mayor - 0 igual - -1 menor)
 *
 */
int employee_CompareByHsTrabajadas(void *empleado1, void *empleado2);

/** \brief compara 2 sueldos de una lista a fin de realizar un ordenamiento
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (1 mayor - 0 igual - -1 menor)
 *
 */
int employee_CompareBySueldo(void *empleado1, void *empleado2);

#endif // employee_H_INCLUDED
