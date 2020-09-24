#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum{ENTERO, IDENTIFICADOR, ERROR_LEXICO, FDT, NUMERAL} TOKEN;

TOKEN scanner();
bool frenar(int e);
bool esEstadoFinal(int estado);
int cambiarEstado(char caracter);

#endif


