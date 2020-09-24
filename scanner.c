#include "scanner.h"

char c;
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
int estado_actual = 0;

// ------------------------------------------------------------------------------------------
int cambiarEstado(char c)
{
  if(isdigit(c))
    return tabla[estado_actual][0];
  else if(isalpha(c))
    return tabla[estado_actual][1];
  else if(c==35)
    return tabla[estado_actual][2];
  else if (c == EOF )
    return tabla[estado_actual][4];
  else if(isspace(c))
    return tabla[estado_actual][5];
  else
    return tabla[estado_actual][3];
}

// ------------------------------------------------------------------------------------------
bool frenar(int e)
{
	return estado[e];
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
		return ENTERO;
		case 7:
    ungetc(c,stdin);
		return IDENTIFICADOR;
		case 8:
        ungetc(c,stdin);
		return ERROR_LEXICO;
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
	}while(!frenar(estado_actual));
	aceptarToken(estado_actual);
	estado_actual = 0;
}

