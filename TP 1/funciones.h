#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED


/** \brief Menu de opciones.
 *
 * \param bandera para saber si se ingreso el primer valor.
 * \param bandera para saber si se ingreso el segundo valor.
 * \param primer valor ingresado.
 * \param segundo valor ingresado.
 * \return Devuelve la opcion elegida por el usuario como entero.
 *
 */
int menu(int flag1, int flag2, int a, int b);


/** \brief Calcula la suma de dos numeros.
 *
 * \param primer valor ingresado.
 * \param segundo valor ingresado.
 * \return Devuelve el resultado de la suma.
 *
 */
int sumar(int a, int b);


/** \brief Calcula la resta de dos numeros.
 *
 * \param primer valor ingresado.
 * \param segundo valor ingresado.
 * \return Devuelve el resultado de la resta.
 *
 */
int restar(int a, int b);


/** \brief Calcula la multiplicacion de dos numeros.
 *
 * \param primer valor ingresado.
 * \param segundo valor ingresado.
 * \return Devuelve el resultado de la multiplicacion.
 *
 */
int multiplicar(int a, int b);


/** \brief Calcula la division de dos numeros.
 *
 * \param primer valor ingresado.
 * \param segundo valor ingresado.
 * \return Devuelve el resultado de la division. En caso de error devuelve -1.
 *
 */
float dividir(int a, int b);


/** \brief Calcula el factorial de un numero.
 *
 * \param numero a calcular su factorial
 * \return Devuelve el factorial del numero recibido.
 *
 */
long long int factorial(int num);

