#include "scanner.h"

static int tabla[8][6] = {
    { 1 , 2 , 3 , 4 , 5 , 0},
    { 1 , 6 , 6 , 6 , 6 , 6},
    { 2 , 2 , 7 , 7 , 7 , 7},
    { 8 , 8 , 3 , 8 , 8 , 8},
    {99 ,99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99 ,99},
    };

const bool estado[10] = {false,false,false,false,true,true,true,true,true,false};
int estadoActual = 0;

// ------------------------------------------------------------------------------------------
int cambiarEstado(char c, int estadoActual)
{
  if(isdigit(c))
    return tabla[estadoActual][DIGITO];

  else if(isalpha(c))
    return tabla[estadoActual][LETRA];

 else if(c == 35)
    return tabla[estadoActual][UN_NUMERAL];

  else if (c == EOF )
    return tabla[estadoActual][FNC];

  else if(isspace(c))
    return tabla[estadoActual][ESPACIO];

  else
    return tabla[estadoActual][3];
}

// ------------------------------------------------------------------------------------------
bool frenar(int e)
{
	return estado[e];
}
// -----------------------------------------------------------------------------------------
int aceptarToken(char caracter, int estadoActual)
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
  int token;
  int estadoActual;
  char caracter;

	do
	{
    caracter  = getchar();
    estadoActual = cambiarEstado(caracter, estadoActual);
    
	}while(estadoActual < 4);

  token = aceptarToken(caracter, estadoActual);
  estadoActual = 0;
	return token;
}