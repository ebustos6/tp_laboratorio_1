#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados;
    int len;
    int opcion;
    int retorno;
    char cargaArchivo='n';

    listaEmpleados = ll_newLinkedList();
    len = ll_len(listaEmpleados);
    printf("Cantidad de empleados: %d\n", len);


    do{
        opcion=MenuPrincipal();

        switch(opcion)
        {

        case 1:
        if(cargaArchivo=='n')
        {
         retorno = controller_loadFromText("data.csv", listaEmpleados);
         if(retorno==1)
         {
             printf("Carga realizada con exito!");
             len = ll_len(listaEmpleados);
             printf("\nCantidad de empleados: %d\n", len);
             cargaArchivo='s';

         } else {

            printf("Error en la carga!\n");
         }
         } else {

            printf("Error! Ya se cargaron los datos previamente!\n");
         }
        break;

        case 2:
        if(cargaArchivo=='n')
        {
        retorno = controller_loadFromBinary("data.dat", listaEmpleados);
         if(retorno==1)
         {
            printf("Carga realizada con exito!");
            len = ll_len(listaEmpleados);
            printf("\nCantidad de empleados: %d\n", len);
            cargaArchivo='s';

         } else {

            printf("Error en la carga!\n");
         }
         } else {

            printf("Error! Ya se cargaron los datos previamente!\n");
         }

        break;

        case 3:
        retorno = controller_addEmployee(listaEmpleados);
        if(retorno==1)
        {
            printf("Carga correcta!\n");
        }
        if(retorno==0)
        {
            printf("Error en la carga!\n");
        }
        len = ll_len(listaEmpleados);
        printf("\nCantidad de empleados: %d\n", len);
        break;

        case 4:
        retorno = controller_editEmployee(listaEmpleados);
        if(retorno==1)
        {
            printf("Operacion realizada con exito!\n");

        } else {

            printf("Error en la operacion!\n");
        }
        break;

        case 5:
        retorno = controller_removeEmployee(listaEmpleados);
        if(retorno==1)
        {
            printf("Operacion realizada con exito!\n");

        } else {

            printf("Error en la operacion!\n");
        }
        len = ll_len(listaEmpleados);
        printf("\nCantidad de empleados: %d\n", len);
        break;

        case 6:
        retorno = controller_ListEmployee(listaEmpleados);
        if(retorno==1)
        {
            if(len!=0)
            {
               printf("Impresion realizada con exito!\n");

            } else {

               printf("Aun no hay datos cargados!\n");
            }


        } else {

            printf("Error en la operacion!\n");
        }
        break;

        case 7:
        retorno = controller_sortEmployee(listaEmpleados);
        if(retorno==1)
        {
            printf("\nOperacion realizada con exito!\n");

        } else {

            printf("\nError en la operacion!\n");
        }
        break;

        case 8:
        retorno = controller_saveAsText("data.csv", listaEmpleados);
        if(retorno==1)
        {
            printf("\nOperacion realizada con exito!\n");

        } else {

            printf("\nError en la operacion!\n");
        }
        break;

        case 9:
        retorno = controller_saveAsBinary("data.dat", listaEmpleados);
        if(retorno==1)
        {
            printf("\nOperacion realizada con exito!\n");

        } else {

            printf("\nError en la operacion!\n");
        }
        break;
        }

        system("pause");
        system("cls");

    }while(opcion!=10);

    retorno = ll_deleteLinkedList(listaEmpleados);
    if(retorno==0)
    {
        printf("Se ha eliminados la lista de empleados");

    } else {

        printf("Error al procesar");
    }


    return 0;
}
