#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  ++++
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). ++++
     3. Alta de empleado ++++
     4. Modificar datos de empleado
     5. Baja de empleado ++++
     6. Listar empleados ++++
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). ++++
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();



int main()
{
    char confirmar = 'n';
    int flagTexto = 0;
    int flagBinario = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            if(!flagTexto)
            {
                controller_loadFromText("data.csv", listaEmpleados);
                flagTexto = 1;
            }
            else
            {
                printf("El archivo ya fue cargado.\n\n");
            }
            break;

        case 2:
            if(!flagBinario)
            {
                controller_loadFromBinary("data.bin", listaEmpleados);
                flagBinario = 1;
            }
            else
            {
                printf("El archivo ya fue cargado.\n\n");
            }
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            break;

        case 4:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 5:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 6:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 7:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 9:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 10:
            printf("Presione 's' para confirmar la salida: ");
            fflush(stdin);
            scanf("%c", &confirmar);

            break;
        default:
            printf("Error. Opcion invalida.\n\n");
            break;
        }

        system("pause");
    }
    while(confirmar != 's');

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}


int menu()
{
    system("cls");

    int opcion;

    printf("\n\n****************************************************\n");
    printf("                  MENU DE OPCIONES\n");
    printf("****************************************************\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
    printf("*****************************************************\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("*****************************************************\n");
    printf("\n");

    return opcion;
}
