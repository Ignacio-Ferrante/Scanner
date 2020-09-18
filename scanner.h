#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

enum{DIGITO, LETRA, OTRO, UN_NUMERAL, FNC, ESPACIO};

enum{CONSTANTE_ENTERA, IDENTIFICADOR, NUMERAL, ERROR, FDT};

// ---------------------------------------

int scanner();

#endif // SCANNER_H_INCLUDED
