#include "scanner.h"

char caracter;
static int tabla[10][6] = {
    { 1 , 2 , 9 , 3 , 5, 0},
    { 1 , 6 , 6 , 6 , 6, 6},
    { 2 , 2 , 7 , 7 , 7, 7},
    { 8 , 8 , 8 , 3 , 8, 8},
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    {99, 99 ,99 ,99 ,99, 99},
    { 4 , 4 , 4 , 4 , 4 , 4}
    };

const bool estado[10] = {false,false,false,false,true,true,true,true,true,false};
int estadoActual = 0;

// ------------------------------------------------------------------------------------------
int cambiarEstado(char caracter)
{
  if(isdigit(caracter))
    return tabla[estadoActual][0];
  else if(isalpha(caracter))
    return tabla[estadoActual][1];
  else if(caracter==35)
    return tabla[estadoActual][2];
  else if (caracter == EOF )
    return tabla[estadoActual][4];
  else if(isspace(caracter))
    return tabla[estadoActual][5];
  else
    return tabla[estadoActual][3];
}

// ------------------------------------------------------------------------------------------
bool frenar(int e)
{
	return estado[e];
}
// -----------------------------------------------------------------------------------------
TOKEN aceptarToken(int estadoActual)
{
    switch(estadoActual)
	{
    case 4:
		ungetc(caracter,stdin);
		return NUMERAL;
    case 6:
    ungetc(caracter,stdin);
		return ENTERO;
		case 7:
    ungetc(caracter,stdin);
		return IDENTIFICADOR;
		case 8:
        ungetc(caracter,stdin);
		return ERROR_LEXICO;
	}
	return FDT;
}
// -----------------------------------------------------------------------------------------
TOKEN scanner()
{
	do
	{
 		caracter  = getchar();
        estadoActual = cambiarEstado(caracter);
	}while(!frenar(estadoActual));
	aceptarToken(estadoActual);
	estadoActual = 0;
}

