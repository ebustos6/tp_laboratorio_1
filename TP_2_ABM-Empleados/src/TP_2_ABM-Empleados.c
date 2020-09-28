/*
 ============================================================================
 Name        : TP_2_ABM-Empleados.c
 Author      : Emanuel Bustos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Data.h"

int main()
{

Employee employeeList[1000];
int option;
int option2;
int option3;

initEmployees(employeeList,1000);


do{
    option = menu1(option);
    switch(option){
    case 1:
        addEmployeeList(employeeList, 1000);
        break;

    case 2:
        do{
            option2 = menu2(option2);

            switch(option2){
            case 1:
                editEmployeeName(employeeList,1000);
                break;

            case 2:
                editEmployeeLastName(employeeList,1000);
                break;

            case 3:
                editEmployeeSalary(employeeList,1000);
                break;

            case 4:
                editEmployeeSector(employeeList,1000);
                break;

            case 5:
                printMessages2(option2);
                break;

            default:
                printMessages2(option2);
            }
        }while(option2 != 5);
        break;

    case 3:
        if(removeEmployee(employeeList, 1000) == 0){
            printf("\n|***EL EMPLEADO HA SIDO BORRADO EXITOSAMENTE***|\n");
        }
        else{
            printf("\n|***EL EMPLEADO QUE DESEA ELIMINAR NO EXISTE***|\n");
        }
        break;

    case 4:
        do{
            option3 =  menu3(option3);

            switch(option3){
            case 1:
                sortEmployees(employeeList, 1000);
                printEmployees(employeeList, 1000);
                break;

            case 2:
                printSalary(employeeList, 1000);
                salaryMoreThanAverage(employeeList, 1000);
                break;

            case 3:
                printMessages3(option3);
                break;

            default:
                printMessages3(option3);
            }
        }while(option3 != 3);
        break;

    case 5:
        printMessages1(option);
        break;

    default:
        printMessages1(option);
}
}while(option != 5);

    return 0;
}
