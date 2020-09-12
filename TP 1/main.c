#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    int num1;
    int num2;
    int flagNum1 = 0;
    int flagNum2 = 0;
    int flagCalculo = 0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMult;
    long long int factorialA;
    long long int factorialB;
    float resultadoDivision;
    char seguir = 'n';


    do
    {
        switch(menu(flagNum1, flagNum2, num1, num2))
        {

        case 1:

            printf("\nIngrese el valor del primer numero: ");
            scanf("%d", &num1);
            flagNum1 = 1;
            break;

        case 2:

            if(!flagNum1)
            {
                printf("\nPrimero debe ingresar el primer valor.\n");
            }
            else
            {
                printf("\nIngrese el valor del segundo numero: ");
                scanf("%d", &num2);
                flagNum2 = 1;
            }
            break;

        case 3:
            if(flagNum1 && flagNum2)
            {
                resultadoSuma = sumar(num1, num2);
                resultadoResta = restar(num1, num2);
                resultadoMult = multiplicar(num1, num2);
                resultadoDivision = dividir(num1, num2);
                factorialA = factorial(num1);
                factorialB = factorial(num2);
                flagCalculo = 1;
                printf("\nCalculos realizados.\n");
            }
            else
            {
                printf("\nPrimero debe ingresar los dos valores.\n");
            }
            break;

        case 4:

            mostrarResultados(resultadoSuma, resultadoResta, resultadoDivision, resultadoMult, factorialA, factorialB, flagNum1, flagNum2, flagCalculo);

            break;

        case 5:

            printf("\nPresione 's' para salir: ");
            fflush(stdin);
            seguir = getche();
            seguir = tolower(seguir);
            if(seguir != 's')
            {
                seguir = 'n';
            }
            break;


        default:

            printf("\nOpcion invalida. Por favor vuelva a ingresar.\n");
            break;
        }

        printf("\nPresione una tecla para continuar...");
        getch();

    }
    while(seguir == 'n');

    return 0;
}
