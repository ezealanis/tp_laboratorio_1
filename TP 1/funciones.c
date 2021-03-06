#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

int menu(int flagNum1, int flagNum2, int num1, int num2)
{
    int opcion;

    system("cls");
    printf("*****   MENU DE OPCIONES   *****\n\n");

    if(flagNum1 == 0)
    {
        printf("1) - Ingresar el primer numero. A = x\n");
    }
    else
    {
        printf("1) - Ingresar el primer numero. A = %d\n", num1);
    }

    if(flagNum2 == 0)
    {
        printf("2) - Ingresar el segundo numero. B = x\n");
    }
    else
    {
        printf("2) - Ingresar el segundo numero. B = %d\n", num2);
    }
    printf("3) - Calcular resultados.\n");
    printf("4) - Mostrar resultados.\n");
    printf("5) - Salir\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int sumar(int a, int b)
{
    int resultado;

    resultado = a+b;

    return resultado;
}

int restar(int a, int b)
{
    int resultado;

    resultado = a-b;

    return resultado;
}

float dividir(int a, int b)
{
    float resultado;

    if(b == 0)
    {
        resultado = -1;
    }
    else
    {
        resultado = (float) a/b;
    }

    return resultado;
}

int multiplicar(int a, int b)
{
    int resultado;

    resultado = a*b;

    return resultado;
}

long long int factorial(int num)
{

    long long int fact;

    if(num>1)
    {
        fact = num * factorial(num-1);
    }
    else
    {
        fact = 1;
    }

    return fact;
}

void mostrarResultados(int suma, int resta, float division, int multiplicar, long long int factorialA, long long int factorialB, int flagNum1, int flagNum2, int flagCalculo)
{
    if(flagNum1 && flagNum2 && flagCalculo)
    {
        printf("\nLa suma es: %d\n", suma);
        printf("La resta es: %d\n", resta);
        if(division == -1)
        {
            printf("Error. No se puede dividir por 0.\n");
        }
        else
        {
            printf("La division es: %.2f\n", division);
        }
        printf("La multiplicacion es: %d\n", multiplicar);
        printf("Factorial de A: %lld\n", factorialA);
        printf("Factorial de B: %lld\n", factorialB);
    }
    else
    {
        printf("\nPrimero debe ingresar los dos valores y calcular los resultados.\n");
    }

}










