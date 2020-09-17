#include "scanner.h"

int estado_actual = 0;
char c;
static int tabla[8][6] = {
    { 1 , 2 , 4 , 3 , 5 , 0},
    { 1 , 6 , 6 , 6 , 6 , 6},
    { 2 , 2 , 7 , 7 , 7 , 7},
    { 8 , 8 , 8 , 3 , 8 , 8},
    {99 ,99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99 ,99},
    };

// ------------------------------------------------------------------------------------------
int cambiarEstado(char c)
{
  if(isdigit(c))
    return tabla[estado_actual][DIGITO];

  else if(isalpha(c))
    return tabla[estado_actual][LETRA];

 //else if(isNumeral(c))
 //   return tabla[estado_actual][UN_NUMERAL];

  else if (c == EOF )
    return tabla[estado_actual][FDC];

  else if(isspace(c))
    return tabla[estado_actual][ESPACIO];

    return tabla[estado_actual][OTRO];
}
// -----------------------------------------------------------------------------------------
TOKEN aceptarToken(int estado_actual)
{
    switch(estado_actual)
	{
    case 4:
        ungetc(c,stdin);
		    return NUMERAL;

    case 6:
        ungetc(c,stdin);
		    return CONSTANTE_ENTERA;

		case 7:
        ungetc(c,stdin);
		    return IDENTIFICADOR;

		case 8:
        ungetc(c,stdin);
		    return ERROR;

	}
	return FDT;
}
// -----------------------------------------------------------------------------------------
TOKEN scanner()
{
	do
	{
 		c  = getchar();
    estado_actual = cambiarEstado(c);
    
	}while(estado_actual < 4);
	aceptarToken(estado_actual);
	estado_actual = 0;
}
