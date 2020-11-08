#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* archivoTexto;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        archivoTexto = fopen(path, "r");
        if(archivoTexto != NULL)
        {
            if( parser_EmployeeFromText(archivoTexto, pArrayListEmployee) == 1)
            {
                retorno = 1;
                printf("Empleados cargados correctamente. \n\n");
            }
            else
            {
                printf("Error al cargar empleados.\n");
            }

            fclose(archivoTexto);
        }
        else
        {
            printf("Error al abrir el archivo.\n");
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivoBinario;
    int error = -1;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivoBinario = fopen(path, "rb");

        if(archivoBinario != NULL)
        {
            if(parser_EmployeeFromBinary(archivoBinario, pArrayListEmployee) == 1)
            {
                printf("Empleados cargados correctamente.\n");
                error = 1;
            }
            else
            {
                printf("Error al cargar empleados.\n");
            }
        }
        else
        {
            printf("Error al abrir el archivo.\n");
        }
    }


    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    // datos del empleado nuevo
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    //se pasan al new emp con parametros
    char horasTrabajadasStr[51];
    char sueldoStr[51];
    char idStr[51];

    // valida si estan bien ingresados
    int sueldoOk;
    int horasTrabajadasOk;
    int nombreOk;

    int error = -1;
    Employee* auxEmp;

    system("cls");

    printf("  ALTA DE EMPLEADO.\n\n");

    if(pArrayListEmployee != NULL)
    {
        nombreOk = utn_getNombre(nombre, 50, "Ingrese el nombre del empleado: ", "Error, nombre demasiado largo o con caracteres erroneos.", 3);
        horasTrabajadasOk = utn_getNumero(&horasTrabajadas, "Ingrese las horas trabajadas por el empleado: ", "Error, reingrese.", 1, 5000, 3);
        sueldoOk = utn_getNumero(&sueldo, "Ingrese el sueldo del empleado: ", "Error, reingre.", 1, 999999, 3);

        if(nombreOk != -1 && horasTrabajadasOk != -1  && sueldoOk  != -1 )
        {
            obtenerId(&id);
            itoa(horasTrabajadas, horasTrabajadasStr, 10);
            itoa(sueldo, sueldoStr, 10);
            itoa(id, idStr, 10);

            auxEmp = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);

            if(auxEmp != NULL)
            {
                ll_add(pArrayListEmployee, auxEmp);
                printf("\nEl empleado se agrego con exito.\n\n");
                sumarId(id);
                error = 0;
            }
        }
        else
        {
            printf("\nError en el alta del empleado.\n\n");
        }
    }

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int len = ll_len(pArrayListEmployee);
    int flag = 0;

    system("cls");
    printf("    ID                    Nombre        Horas        Sueldo\n");
    printf("--------------------------------------------------------------------------\n");

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee,i);
            if(aux != NULL)
            {
                mostrarEmpleado(aux);
                flag = 1;
            }

        }
    }

    if(flag == 0)
    {
        printf("No hay empleados cargados en sistema.\n\n");
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int idEmp;
    int indice;
    char confirmar = 'n';

    system("cls");

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("Ingrese el ID del empleado a modificar: ");
        scanf("%d", &idEmp);

        indice = buscarPorId(pArrayListEmployee, idEmp);

        if(indice == -1)
        {
            printf("Error, no se encontro el id ingresado.\n\n");
        }
        else
        {
            printf("Empleado encontrado: ");
            mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));

            printf("Presione 's' para modificar el empleado: ");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar == 's')
            {
                modificarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
            }
        }
    }

    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indice;
    int error = -1;
    int id;
    char confirmar = 'n';

    if(pArrayListEmployee != NULL)
    {

        system("cls");

        controller_ListEmployee(pArrayListEmployee);

        printf("--------------------------------------------------------------------------\n");

        printf("\nIngrese el ID del empleado a eliminar: ");
        scanf("%d", &id);

        indice = buscarPorId(pArrayListEmployee, id);

        if(indice == -1)
        {
            printf("Error, no se encontro el ID ingresado.\n");
        }
        else
        {
            printf("El empleado seleccionado es: \n\n");
            mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));

            printf("\nPresione s para confirmar la baja: ");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar == 's')
            {
                ll_remove(pArrayListEmployee, indice);
                printf("\nEmpleado dado de baja con exito.\n\n");
                error = 1;
            }
            else
            {
                printf("\nBaja cancelada.\n\n");
            }
        }
    }

    return error;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int opcion;
    int opcionForma;

    system("cls");
    printf("Ordenar empleados.\n\n");

    printf("1 - Ordenar por ID.\n");
    printf("2 - Ordenar por Nombre.\n");
    printf("3 - Ordenar por Horas trabajadas.\n");
    printf("4 - Ordenar por Sueldo.\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        if(utn_getNumero(&opcionForma, "Ingrese 1 para ordenar Ascendente o 0 para ordenar Descendente: ", "Error, ingrese 1 o 0.", 0, 1, 3) != -1)
        {
            ll_sort(pArrayListEmployee, ordenarPorId, opcionForma);
            printf("Empleados ordenados con exito.\n\n");
        }
        else
        {
            printf("Error, problemas para ordenar los empleados.\n\n");
        }
        break;

    case 2:
        if(utn_getNumero(&opcionForma, "Ingrese 1 para ordenar Ascendente o 0 para ordenar Descendente: ", "Error, ingrese 1 o 0.", 0, 1, 3) != -1)
        {
            ll_sort(pArrayListEmployee, ordenarPorNombre, opcionForma);
            printf("Empleados ordenados con exito.\n\n");
        }
        else
        {
            printf("Error, problemas para ordenar los empleados.\n\n");
        }
        break;

    case 3:
        if(utn_getNumero(&opcionForma, "Ingrese 1 para ordenar Ascendente o 0 para ordenar Descendente: ", "Error, ingrese 1 o 0.", 0, 1, 3) != -1)
        {
            ll_sort(pArrayListEmployee, ordenarPorHorasTrabajadas, opcionForma);
            printf("Empleados ordenados con exito.\n\n");
        }
        else
        {
            printf("Error, problemas para ordenar los empleados.\n\n");
        }
        break;

    case 4:
        if(utn_getNumero(&opcionForma, "Ingrese 1 para ordenar Ascendente o 0 para ordenar Descendente: ", "Error, ingrese 1 o 0.", 0, 1, 3) != -1)
        {
            ll_sort(pArrayListEmployee, ordenarPorSueldo, opcionForma);
            printf("Empleados ordenados con exito.\n\n");
        }
        else
        {
            printf("Error, problemas para ordenar los empleados.\n\n");
        }
        break;
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int tam = ll_len(pArrayListEmployee);
    Employee* aux;
    FILE* archivoTexto;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        archivoTexto = fopen(path, "w");

        if(archivoTexto != NULL)
        {
            fprintf(archivoTexto, "id,nombre,horasTrabajadas,sueldo\n");

            for(int i = 0; i < tam; i++)
            {
                aux = (Employee*) ll_get(pArrayListEmployee, i);
                if(aux != NULL)
                {
                    fprintf(archivoTexto, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
                    retorno = 1;
                }
            }

            printf("Empleados guardados con exito.\n\n");
            fclose(archivoTexto);
        }
        else
        {
            printf("Error al abrir el archivo.\n");
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivoBinario;
    int len = ll_len(pArrayListEmployee);
    int error = -1;
    Employee* auxEmp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivoBinario = fopen(path, "wb");
        if(archivoBinario != NULL)
        {
            for(int i = 0; i < len; i++)
            {
                auxEmp = ll_get(pArrayListEmployee, i);
                if(auxEmp != NULL)
                {
                    fwrite(auxEmp, sizeof(Employee), 1, archivoBinario);
                    error = 1;
                }
            }

            printf("Empleados guardados con exito.\n\n");
        }
        else
        {
            printf("Error para abrir el archivo.\n\n");
        }
    }

    fclose(archivoBinario);

    return error;
}


