#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


void inicializarLista(Employee empleados[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        empleados[i].isEmpty = 0;
    }
}

int buscarLibre(Employee empleados[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarEmpleado(int legajo, char nombre[], char apellido[], float salario, int sector)
{
    printf("  %4d  %20s  %20s    %5.2f    %2d\n", legajo, nombre, apellido, salario, sector);
}

void mostrarEmpleados(Employee empleados[], int tam)
{
    printf("\n Legajo                Nombre              Apellido   Salario   Sector\n");
    printf("-----------------------------------------------------------------------------\n");

    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            mostrarEmpleado(empleados[i].legajo, empleados[i].nombre, empleados[i].apellido, empleados[i].salario, empleados[i].sector);
        }
    }
}

int addEmployee(Employee empleados[], int tam, int legajo)
{
    int error = 1;
    int indice;

    system("cls");

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("Error. Sistema completo.\n");
    }
    else
    {
        empleados[indice] = unEmpleado(legajo);
        error = 0;
    }

    return error;
}

Employee unEmpleado(int legajo)
{
    Employee empleado;
    char auxNombre[100];
    char auxApellido[100];
    float auxSalario;
    int auxSector;

    printf("\n   ***   Alta de empleado   ***\n\n");

    printf("Ingrese el nombre del empleado: ");
    fflush(stdin);
    gets(auxNombre);

    while(validarNombre(auxNombre, 51))
    {
        printf("Error, nombre demasiado largo o con caracteres invalidos. Reingrese: ");
        fflush(stdin);
        gets(auxNombre);
    }

    printf("Ingrese el apellido del empleado: ");
    fflush(stdin);
    gets(auxApellido);

    while(validarNombre(auxApellido, 51))
    {
        printf("Error, apellido demasiado largo o con caracteres invalidos. Reingrese: ");
        fflush(stdin);
        gets(auxApellido);
    }

    printf("Ingrese el salario del empleado: ");
    fflush(stdin);
    scanf("%f", &auxSalario);

    while(auxSalario <= 0)
    {
        printf("Error, el salario debe ser mayor que 0. Reingrese: ");
        fflush(stdin);
        scanf("%f", &auxSalario);
    }

    printf("Ingrese el sector del empleado: ");
    fflush(stdin);
    scanf("%d", &auxSector);

    while(auxSector < 0)
    {
        printf("Error, el sector debe ser un numero mayor que cero. Reingrese: ");
        fflush(stdin);
        scanf("%d", &auxSector);
    }

    empleado.legajo = legajo;
    strcpy(empleado.nombre, auxNombre);
    strcpy(empleado.apellido, auxApellido);
    empleado.salario = auxSalario;
    empleado.sector = auxSector;
    empleado.isEmpty = 1;

    return empleado;
}

int removeEmployee(Employee empleados[], int tam)
{
    int error = -1;
    int legajo;
    int indice;
    char confirmar;

    system("cls");

    printf("\n   ***   Baja de empleado   ***\n\n");

    sortEmployeesByLegajo(empleados, tam);
    mostrarEmpleados(empleados, tam);

    printf("\n\nIngrese el legajo del empleado a eliminar: ");
    scanf("%d", &legajo);

    indice = findEmployeeById(empleados, tam, legajo);

    if(indice == -1)
    {
        printf("\nError. No se encontro el legajo ingresado.\n");
    }
    else
    {
        printf("\n");
        mostrarEmpleado(empleados[indice].legajo, empleados[indice].nombre, empleados[indice].apellido, empleados[indice].salario, empleados[indice].sector);
        printf("\nPresione 's' para eliminar al empleado: ");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            empleados[indice].isEmpty = 0;
            printf("\nBaja realizada con exito.\n");
        }
        else
        {
            printf("\nBaja cancelada por el usuario.\n");
        }
    }

    return error;
}

int findEmployeeById(Employee empleados[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].legajo == legajo && empleados[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int modificarEmployee(Employee empleados[], int tam)
{
    int error = -1;
    int legajo;
    int indice;
    char seguir = 'n';
    char auxNombre[100];
    char auxApellido[100];
    float auxSalario;
    int auxSector;

    system("cls");

    printf("\n   ***   Modificar empleado   ***\n\n");

    sortEmployeesByLegajo(empleados, tam);
    mostrarEmpleados(empleados, tam);

    printf("\n\nIngrese el legajo del empleado que quiere modificar: ");
    scanf("%d", &legajo);

    indice = findEmployeeById(empleados, tam, legajo);

    if(indice == -1)
    {
        printf("\nError. No se encontro el legajo ingresado.\n");
    }
    else
    {
        mostrarEmpleado(empleados[indice].legajo, empleados[indice].nombre, empleados[indice].apellido, empleados[indice].salario, empleados[indice].sector);
        printf("\n");

        do
        {
            switch( menuModificar(empleados, indice) )
            {
            case 1:
                printf("\nIngrese el nombre del empleado: ");
                fflush(stdin);
                gets(auxNombre);

                while(validarNombre(auxNombre, 51))
                {
                    printf("\nError, nombre demasiado largo o con caracteres invalidos. Reingrese: ");
                    fflush(stdin);
                    gets(auxNombre);
                }
                strcpy(empleados[indice].nombre, auxNombre);
                printf("\nNombre modificado con exito.\n\n");
                break;

            case 2:
                printf("\nIngrese el apellido del empleado: ");
                fflush(stdin);
                gets(auxApellido);

                while(validarNombre(auxApellido, 51))
                {
                    printf("\nError, apellido demasiado largo o con caracteres invalidos. Reingrese: ");
                    fflush(stdin);
                    gets(auxApellido);
                }
                strcpy(empleados[indice].apellido, auxApellido);
                printf("\nApellido modificado con exito.\n\n");
                break;

            case 3:
                printf("\nIngrese el salario del empleado: ");
                fflush(stdin);
                scanf("%f", &auxSalario);

                while(auxSalario <= 0)
                {
                    printf("\nError, el salario debe ser mayor que 0. Reingrese: ");
                    fflush(stdin);
                    scanf("%f", &auxSalario);
                }
                empleados[indice].salario = auxSalario;
                printf("\nSalario modificado con exito.\n\n");
                break;

            case 4:
                printf("\nIngrese el sector del empleado: ");
                fflush(stdin);
                scanf("%d", &auxSector);

                while(auxSector < 0)
                {
                    printf("Error. El sector debe ser un numero mayor que cero. Reingrese: ");
                    fflush(stdin);
                    scanf("%d", &auxSector);
                }

                empleados[indice].sector = auxSector;
                printf("\nSector modificado con exito.\n\n");
                break;

            case 5:
                printf("\nPresione 's' para salir: ");
                fflush(stdin);
                seguir = getche();
                break;

            default:
                printf("\nOpcion invalida.\n\n");
                system("pause");
                break;
            }
        }
        while(seguir != 's');
    }
    return error;
}

int menuModificar(Employee empleados[], int indice)
{
    int opcion;

    system("cls");
    printf("\n");
    mostrarEmpleado(empleados[indice].legajo, empleados[indice].nombre, empleados[indice].apellido, empleados[indice].salario, empleados[indice].sector);

    printf("\n   ***   Menu de modificacion   ***\n\n");
    printf("1 - Modificar nombre.\n");
    printf("2 - Modificar apellido.\n");
    printf("3 - Modificar salario.\n");
    printf("4 - Modificar sector.\n");
    printf("5 - Salir.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void sortEmployees(Employee empleados[], int tam)
{
    Employee aux;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(empleados[i].sector > empleados[j].sector || (empleados[i].sector == empleados[j].sector && strcmp(empleados[i].apellido, empleados[j].apellido) > 0))
            {
                aux = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = aux;
            }
        }
    }

    mostrarEmpleados(empleados, tam);
}

void sortEmployeesByLegajo(Employee empleados[], int tam)
{
    Employee aux;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(empleados[i].legajo > empleados[j].legajo)
            {
                aux = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = aux;
            }
        }
    }
}

void informe(Employee empleados[], int tam)
{
    int cont = 0;
    int flag = 0;
    float totalSalario = 0;
    float promedio = 0;

    system("cls");
    printf("\n   ***   Informes  ***\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            totalSalario += empleados[i].salario;
            cont++;
        }
    }

    promedio = totalSalario/cont;

    printf("El total de los salarios es: %.2f\n", totalSalario);
    printf("El promedio de los salarios es: %.2f\n", promedio);

    printf("\nLos empleados que superan el promedio de los salarios son: \n\n");

    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1 && empleados[i].salario > promedio)
        {
            mostrarEmpleado(empleados[i].legajo, empleados[i].nombre, empleados[i].apellido, empleados[i].salario, empleados[i].sector);
            flag = 1;
        }
    }

    if(!flag)
    {
        printf("Ningun empleado supera el promedio de los salarios.\n");
    }
}

int validarNombre(char cadena[], int largoMax)
{
    int error = 0;
    int largo;

    largo = strlen(cadena);

    if(largo < largoMax)
    {

        for(int i = 0; i < largo; i++)
        {
            if(isalpha(cadena[i]) == 0 && cadena[i] != ' ')
            {
                error = 1;
            }
        }

        if(!error)
        {
            strlwr(cadena);
            cadena[0] = toupper(cadena[0]);

            for(int i = 0; i < largo; i++)
            {
                if(cadena[i] == ' ')
                {
                    cadena[i+1] = toupper(cadena[i+1]);
                }
            }
        }

    }
    else
    {
        error = 1;
    }

    return error;
}

int menu()
{
    int opcion;

    system("cls");

    printf("***   Menu de opciones   ***\n\n");
    printf("1 - Alta de empleado.\n");
    printf("2 - Modificar empleado.\n");
    printf("3 - Baja de empleado.\n");
    printf("4 - Informar.\n");
    printf("5 - Salir.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



