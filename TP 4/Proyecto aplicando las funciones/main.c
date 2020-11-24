
//ll_newLinkedList ::: Al inicio del programa
//ll_len ::: En las funciones que recorren el linkedlist para determinar el tamaño
//getNode - test_getNode ::: Se usa internamente
//addNode - test_addNode ::: Se usa internamente
//ll_add ::: En el alta del empleado
//ll_get ::: En los casos donde se elije un empleado para realizar una accion.
//ll_set ::: Se usa internamente
//ll_remove ::: Baja de empleado
//ll_clear ::: Esta incluida en deleteLinkedList
//ll_deleteLinkedList ::: Al final del programa para liberar la memoria.
//ll_indexOf ::: Se usa en "mover empleado de lugar en la lista" para seleccionar los lugares a modificar.
//ll_isEmpty ::: En el main para ingresar en los case
//ll_push ::: Se usa en "mover empleado de lugar en la lista" para poner al empleado en el nodo elegido.
//ll_pop ::: Se usa en "mover empleado de lugar en la lista" para sacar al empleado del nodo.
//ll_contains ::: Se usa internamente en containsAll.
//ll_containsAll ::: Se usa en la ultima opcion para verificar que la lista haya sido clonada con todos los registros.
//ll_subList ::: Se usa internamente en clone.
//ll_clone ::: Se usa para clonar la lista en un nuevo archivo.
//ll_sort ::: Se usa en la opcion de ordenar lista.
//ll_filter ::: Usada en la opcion de filtrar con sus respectivas funciones de filtrado.


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

int main()
{
    int flag = 0;
    char confirmar = 'n';

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaCopia = NULL;

    do
    {
        switch(menu())
        {
        case 1:
            if(flag == 0)
            {
                controller_loadFromText("data.csv", listaEmpleados);
                flag = 1;
            }
            else
            {
                printf("El archivo ya fue cargado.\n\n");
            }
            break;

        case 2:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar el archivo.\n\n");
            }
            break;

        case 3:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            break;

        case 4:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 5:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 6:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 7:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_moverElemento(listaEmpleados);

            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_crearCopia("listaCopia.csv", listaEmpleados, listaCopia);

            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 9:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_filtrar(listaEmpleados);

            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 10:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados.\n\n");
            }
            break;

        case 11:
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
