#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 100


int main()
{
    int legajo = 1000;
    int flag = 0;
    char seguir = 'n';
    Employee empleados[TAM];

    inicializarLista(empleados, TAM);

    do
    {
        switch( menu() )
        {
        case 1:

            if(addEmployee(empleados, TAM, legajo) == 0)
            {
                legajo++;
                printf("\nAlta realizada con exito.\n");
                flag = 1;
            }
            else
            {
                printf("\nNo se pudo realizar el alta.\n");
            }

            break;

        case 2:

            if(flag)
            {
                modificarEmployee(empleados, TAM);
            }
            else
            {
                printf("\nPrimero debe cargar un empleado.\n");
            }

            break;

        case 3:

            if(flag)
            {
                removeEmployee(empleados, TAM);
            }
            else
            {
                printf("\nPrimero debe cargar un empleado.\n");
            }

            break;

        case 4:
            if(flag)
            {
                sortEmployees(empleados, TAM);
                informe(empleados, TAM);
            }
            else
            {
                printf("\nPrimero debe cargar un empleado.\n");
            }
            break;

        case 5:

            printf("\nPresione 's' para salir: ");
            fflush(stdin);
            seguir = getche();
            break;

        default:
            printf("\nOpcion invalida.");
            break;
        }

        printf("\n");
        system("pause");
    }
    while(seguir != 's');

    return 0;
}



