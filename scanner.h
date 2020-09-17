#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum{DIGITO, LETRA, UN_NUMERAL, OTRO, FNC, ESPACIO} CARACTER;
typedef enum{IDENTIFICADOR,CONSTANTE_ENTERA, NUMERAL, ERROR, FDT} TOKEN;

// ---------------------------------------

TOKEN scanner();

#endif // SCANNER_H_INCLUDED
