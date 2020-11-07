#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarEmpleado(Employee* this);
int buscarPorId(LinkedList* pArrayListEmployee, int id);
int proximoId(LinkedList* pArrayListEmployee);
int menuModificar();
int modificarEmpleado(Employee* this);

int ordenarPorId(void* employeeA, void* employeeB);
int ordenarPorNombre(void* employeeA, void* employeeB);
int ordenarPorSueldo(void* employeeA, void* employeeB);
int ordenarPorHorasTrabajadas(void* employeeA, void* employeeB);

int obtenerId(LinkedList* lista);

#endif // employee_H_INCLUDED
