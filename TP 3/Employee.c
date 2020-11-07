#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "Validaciones.h"

Employee* employee_new()
{
    Employee* aux;
    aux = (Employee*) malloc(sizeof (Employee) * 1);

    if(aux != NULL)
    {
        aux->id = 0;
        strcpy(aux->nombre, " ");
        aux->horasTrabajadas = 0;
        aux->sueldo = 0;
    }

    return aux;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmp = (Employee*) malloc(sizeof(Employee));

    if(newEmp != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        newEmp->id = atoi(idStr);
        strcpy(newEmp->nombre, nombreStr);
        newEmp->horasTrabajadas = atoi(horasTrabajadasStr);
        newEmp->sueldo = atoi(sueldoStr);
    }


    return newEmp;
}

void mostrarEmpleado(Employee* this)
{
    if(this != NULL)
    {
        printf(" %4d      %20s         %3d          %6d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}

int buscarPorId(LinkedList* pArrayListEmployee, int id)
{
    int auxId;
    int indice = -1;
    Employee* auxEmp;

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            if(employee_getId(auxEmp, &auxId) && auxId == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


int employee_setId(Employee* this,int id)
{
    int succes = -1;

    if ( this != NULL && id >0 && id <= 100000)
    {
        this-> id = id;
        succes = 1;
    }
    return succes;
}


int employee_getId(Employee* this,int* id)
{
    int succes = -1;
    if(this != NULL && id!=NULL)
    {
        *id = this-> id;
        succes = 1;
    }
    return succes;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int succes = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this -> nombre, nombre);
        succes = 1;
    }
    return succes;
}


int employee_getNombre(Employee* this, char* nombre)
{
    int succes = -1;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre, this -> nombre);
        succes = 1;
    }
    return succes;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int succes = -1;

    if ( this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this-> horasTrabajadas = horasTrabajadas;
        succes = 1;
    }
    return succes;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int succes = -1;
    if ( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this -> horasTrabajadas;
        succes = 1;
    }
    return succes;
}


int employee_setSueldo(Employee* this, int sueldo)
{
    int succes = -1;

    if ( this != NULL && sueldo >0 && sueldo <= 500000 )
    {
        this-> sueldo = sueldo;
        succes = 1;
    }
    return succes;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int succes = -1;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        succes = 1;
    }
    return succes;
}

int proximoId(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int idMax = 1;
    int len = ll_len(pArrayListEmployee);

    for(int i = 0; i < len; i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee, i);

        if(aux->id > idMax)
        {
            idMax = aux->id + 1;
        }
    }


return idMax;
}


int menuModificar()
{
    int opcion;

    system("cls");
    printf("Menu de Modificacion.\n\n");
    printf("1- Modificar nombre.\n");
    printf("2- Modificar horas trabajadas.\n");
    printf("3- Modificar sueldo.\n");
    printf("4- Salir.\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarEmpleado(Employee* this)
{
    int error = -1;
    int nombreOk;
    char nombreNuevo[51];
    int horasTrabajadasOk;
    int horasTrabajadas;
    int sueldoOk;
    int sueldo;
    char confirmar = 'n';

    do
    {

        switch(menuModificar())
        {
        case 1:
            nombreOk = utn_getNombre(nombreNuevo, 50, "Ingrese el nombre del empleado: ", "Error, reingrese nombre.", 3);
            if(nombreOk == 1)
            {
                employee_setNombre(this, nombreNuevo);
                printf("Nombre modificado con exito.\n\n");
                error = 1;
            }
            break;

        case 2:
            horasTrabajadasOk = utn_getNumero(&horasTrabajadas, "Ingrese las horas trabajadas: ", "Error, reingrese.", 1, 5000, 3);
            if(horasTrabajadasOk == 1)
            {
                employee_setHorasTrabajadas(this, horasTrabajadas);
                printf("Horas trabajadas modificadas con exito.\n\n");
                error = 1;
            }
            break;

        case 3:
            sueldoOk = utn_getNumero(&sueldo, "Ingrese las horas trabajadas: ", "Error, reingrese.", 1, 999999, 3);
            if(sueldoOk == 1)
            {
                employee_setSueldo(this, sueldo);
                printf("Sueldo modificado con exito.\n\n");
                error = 1;
            }
            break;

        case 4:
            printf("Presione 's' para confirmar la salida: ");
            fflush(stdin);
            scanf("%c", &confirmar);
            break;

        default:
            printf("Opcion invalida\n\n");
            break;

        }

        system("pause");

    }
    while(confirmar != 's');

    return error;
}

int ordenarPorId(void* employeeA, void* employeeB)
{
    Employee* auxA;
    Employee* auxB;
    int retorno;

    if(employeeA != NULL && employeeB != NULL)
    {
        auxA = (Employee*) employeeA;
        auxB = (Employee*) employeeB;

        if(auxA->id > auxB->id)
        {
            retorno = 1;
        }
        else if(auxA->id < auxB->id)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ordenarPorSueldo(void* employeeA, void* employeeB)
{
    Employee* auxA;
    Employee* auxB;
    int retorno;

    if(employeeA != NULL && employeeB != NULL)
    {
        auxA = (Employee*) employeeA;
        auxB = (Employee*) employeeB;

        if(auxA->sueldo > auxB->sueldo)
        {
            retorno = 1;
        }
        else if(auxA->sueldo < auxB->sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ordenarPorHorasTrabajadas(void* employeeA, void* employeeB)
{
    Employee* auxA;
    Employee* auxB;
    int retorno;

    if(employeeA != NULL && employeeB != NULL)
    {
        auxA = (Employee*) employeeA;
        auxB = (Employee*) employeeB;

        if(auxA->horasTrabajadas > auxB->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(auxA->horasTrabajadas < auxB->horasTrabajadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ordenarPorNombre(void* employeeA, void* employeeB)
{
    Employee* auxA;
    Employee* auxB;
    int retorno;

    if(employeeA != NULL && employeeB != NULL)
    {
        auxA = (Employee*) employeeA;
        auxB = (Employee*) employeeB;

        if(strcmp(auxA->nombre, auxB->nombre) == 1)
        {
            retorno = 1;
        }
        else if(strcmp(auxA->nombre, auxB->nombre) == -1)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int obtenerId(LinkedList* lista)
{
    int idMax = 1;
    int len = ll_len(lista);
    Employee* aux;

    if(lista != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            aux = ll_get(lista, i);

            if(aux->id > idMax)
            {
                idMax = aux->id + 1;
            }
        }
    }

    return idMax;
}
