/*
TRABAJO PRACTICO N1 2020
"Un escaner elemental"

INTEGRANTES: 
Alejandro Buergo / 168.569-7
Ignacio Ferrante / 171.524-0
Patricio Galli   / 172.467-8
*/

#include "scanner.h"
int cantidadIdentificadores = 0;
int cantidadConstantesEnt = 0;
int cantidadNumerales = 0;
int cantidadErrores = 0;
TOKEN c;

int main()
{
    printf("Los resultados del datosPrueba.txt son: \n\n");
    do
    {
        c = scanner();
        switch(c)
        {
            case ERROR_LEXICO:
            printf("Error Lexico\n");
            cantidadErrores++;
            break;
            case IDENTIFICADOR:
            printf("Identificador\n");
            cantidadIdentificadores++;
            break;
            case ENTERO:
            printf("Constante Entera\n");
            cantidadConstantesEnt++;
            break;
            case NUMERAL:
            printf("Numeral\n");
            cantidadNumerales++;
            break;
            case FDT:
            break;
            }
    }while(c!=FDT);

    printf("----\n");
    printf("Totales:\n");
    printf("Identificadores: %d\n",cantidadIdentificadores);
    printf("Constantes enteras: %d\n",cantidadConstantesEnt);
    printf("Numerales: %d\n", cantidadNumerales);
    printf("Errores: %d\n",cantidadErrores);
    return 0;
}
