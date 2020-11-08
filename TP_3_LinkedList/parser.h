#include "LinkedList.h"

/** \brief efectua el parser de una lista ingresada desde archivo en formato texto
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 - ok / 0 - error)
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

/** \brief efectua el parser de una lista ingresada desde archivo en formato binario
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 - ok / 0 - error)
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

/** \brief Asigna un ID autoincremental tomando en cuenta los datos recibidos desde archivo
 *
 * \param LinkedList* pArrayListEmployee
 * \param int* idNumber
 * \return 1 ok / 0 error
 *
 */
int parser_AsignarID(LinkedList *pArrayListEmployee, int *idNumber);
