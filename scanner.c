#include "scanner.h"

char caracter;
int estadoActual;

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
int cambiarEstado(char c)
{
  if(isdigit(c))
    return tabla[estadoActual][DIGITO];

  else if(isalpha(c))
    return tabla[estadoActual][LETRA];

 //else if(isNumeral(c))
 //   return tabla[estadoActual][UN_NUMERAL];

  else if (c == EOF )
    return tabla[estadoActual][FNC];

  else if(isspace(c))
    return tabla[estadoActual][ESPACIO];

    return tabla[estadoActual][OTRO];
}
// -----------------------------------------------------------------------------------------
int aceptarToken()
{
  estadoActual = 0;

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
	do
	{
    caracter  = getchar();
    estadoActual = cambiarEstado(caracter);
    
	}while(estadoActual < 4);

	return aceptarToken();
}
