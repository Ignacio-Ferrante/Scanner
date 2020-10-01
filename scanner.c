#include "scanner.h"

static int tabla[9][6] = {
  //{ 0 , 1 , 2 , 3 , 4 , 5},
  //{DIGITO, LETRA, OTRO, NUMERAL, FNC, ESPACIO}
    { 1 , 2 , 3 , 4 , 5 , 0},   // inicial
    { 1 , 6 , 6 , 6 , 6 , 6},   // Reconoce y almacena una constante entera
    { 2 , 2 , 7 , 7 , 7 , 7},   // Reconoce y almacena un identificador
    { 8 , 8 , 3 , 8 , 8 , 8},   // Reconoce y almacena un error
    {99 ,99 ,99 ,99 ,99 ,99},   // Reconoce un numeral
    {99 ,99 ,99 ,99 ,99 ,99},   // Se terminó la cadena
    {99 ,99 ,99 ,99 ,99 ,99},   // Se reconoció la constante entera
    {99 ,99 ,99 ,99 ,99 ,99},   // Se reconoció un identificador
    {99 ,99 ,99 ,99 ,99 ,99},   // Error léxico
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
  int estadoActual = 0;
  char caracter;

	do
	{
    caracter  = getchar();
    estadoActual = cambiarEstado(caracter, estadoActual);
    
	}while(estadoActual < 4);

  token = aceptarToken(caracter, estadoActual);
	return token;
}

/*
-----ERRORES-----

Si recibo un # debo ir directo a un estado final aceptor sin pasar por estados intermedios.
En el código está emparchado porque hacen ungetc cuando es numeral, pero resulta que numeral no lleva centinela por lo tanto no debe tener ungetc
En cambiarEstado porque usaron el número mágico 35 en lugar de '#' que es muchísimo más claro?
La última sentencia de scanner estadoActual = 0; no tiene sentido y además scanner devuelve token y no hay ningún return.
No tiene ningún sentido que estadoActual sea una variable global, debe ser local de scanner

*/