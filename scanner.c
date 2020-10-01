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

// ------------------------------------------------------------------------------------------
int cambiarEstado(char c, int estadoActual)
{
  if(isdigit(c))
    return tabla[estadoActual][DIGITO];

  else if(isalpha(c))
    return tabla[estadoActual][LETRA];

 else if(c == '#')
    return tabla[estadoActual][UN_NUMERAL];

  else if (c == EOF )
    return tabla[estadoActual][FNC];

  else if(isspace(c))
    return tabla[estadoActual][ESPACIO];

  else
    return tabla[estadoActual][OTRO];
}
// -----------------------------------------------------------------------------------------
int aceptarToken(char caracter, int estadoActual)
{
  switch(estadoActual)
	{
    case 4:
        ungetc(caracter,stdin);
		    return NUMERAL;
    
    case 5:
        return FDT;

    case 6:
        ungetc(caracter,stdin);
		    return CONSTANTE_ENTERA;

		case 7:
        ungetc(caracter,stdin);
		    return IDENTIFICADOR;

		case 8:
        ungetc(caracter,stdin);
		    return ERROR;
	}
}
// -----------------------------------------------------------------------------------------
int scanner()
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

/*
En el código está emparchado porque hacen ungetc cuando es numeral, pero resulta que numeral no lleva centinela por lo tanto no debe tener ungetc
*/