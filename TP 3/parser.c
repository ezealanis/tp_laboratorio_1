#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant = 0;
    int error = 1;
    char id[50];
    char nombre[100];
    char horas[50];
    char sueldo[50];
    Employee* auxEmp;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");

        while(!feof(pFile))
        {
            auxEmp = employee_new();
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);

            if(cant == 4)
            {
                auxEmp = employee_newParametros(id, nombre, horas, sueldo);
                ll_add(pArrayListEmployee, auxEmp);
                error = 1;
            }
        }
    }


    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int error = -1;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            auxEmp = employee_new();

            if(fread(auxEmp, sizeof(Employee), 1, pFile) != 0)
            {
                ll_add(pArrayListEmployee, auxEmp);
                error = 1;
            }
        }
    }


    return error;
}
