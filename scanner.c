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

    case 6:
        ungetc(caracter,stdin);
		    return CONSTANTE_ENTERA;

		case 7:
        ungetc(caracter,stdin);
		    return IDENTIFICADOR;

		case 8:
        ungetc(caracter,stdin);
		    return ERROR;

    default:
        break;
	}
  return FDT;
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