#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief Busca el primer espacio libre en el array
 *
 * \param empleados[] Employee
 * \param tam int
 * \return int
 *
 */
int buscarLibre(Employee empleados[], int tam);


/** \brief inicializa el array con todas las posiciones vacias
 *
 * \param empleados[] Employee
 * \param tam int
 * \return void
 *
 */
void inicializarLista(Employee empleados[], int tam);


/** \brief  muestra un solo empleado
 *
 * \param legajo int
 * \param nombre[] char
 * \param apellido[] char
 * \param salario float
 * \param sector int
 * \return void
 *
 */
void mostrarEmpleado(int legajo, char nombre[], char apellido[], float salario, int sector);


/** \brief muestra todos los empleados cargados
 *
 * \param empleados[] Employee
 * \param tam int
 * \return void
 *
 */
void mostrarEmpleados(Employee empleados[], int tam);


/** \brief busca lugar para un empleado
 *
 * \param empleados[] Employee
 * \param tam int
 * \param legajo int
 * \return int 1 si hubo algun error, 0 si se cargo el empleado
 *
 */
int addEmployee(Employee empleados[], int tam, int legajo);


/** \brief solicita los datos del empleado a agregar
 *
 * \param legajo int
 * \return Employee todos los datos validados del empleado a cargar.
 *
 */
Employee unEmpleado(int legajo);


/** \brief baja logica de un empleado en el array
 *
 * \param empleados[] Employee
 * \param tam int
 * \return int
 *
 */
int removeEmployee(Employee empleados[], int tam);


/** \brief encuentra a un empleado por su numero de legajo
 *
 * \param empleados[] Employee
 * \param tam int
 * \param legajo int
 * \return int -1 si no encuentra empleados o lugar en el array del empleado
 *
 */
int findEmployeeById(Employee empleados[], int tam, int legajo);


/** \brief modifica los datos ingresados de un empleado
 *
 * \param empleados[] Employee
 * \param tam int
 * \return int -1 si hay algun error.
 *
 */
int modificarEmployee(Employee empleados[], int tam);


/** \brief menu de modificar
 *
 * \param empleados[] Employee
 * \param indice int
 * \return int opcion elegida a modificar
 *
 */
int menuModificar(Employee empleados[], int indice);


/** \brief ordena empleados por apellido y sector
 *
 * \param empleados[] Employee
 * \param tam int
 * \return void
 *
 */
void sortEmployees(Employee empleados[], int tam);


/** \brief ordena empleados por el legajo
 *
 * \param empleados[] Employee
 * \param tam int
 * \return void
 *
 */
void sortEmployeesByLegajo(Employee empleados[], int tam);


/** \brief informa promedio de sueldos y quienes lo superan.
 *
 * \param empleados[] Employee
 * \param tam int
 * \return void
 *
 */
void informe(Employee empleados[], int tam);


/** \brief Valida que la cadena ingresada este dentro del maximo de caracteres y que sean letras
 *
 * \param cadena[] char
 * \param largoMax int
 * \return int 0 si no hay error - 1 si hay errores.
 *
 */
int validarNombre(char cadena[], int largoMax);


/** \brief  Menu de opciones
 *
 * \return int - opcion elegida del menu
 *
 */
int menu();

