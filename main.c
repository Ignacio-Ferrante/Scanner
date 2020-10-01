//////////////////////////////////////////////////////////////////////////////////////
/*
      TP1 - 2020
      "Un escaner elemental"

                                                                                    */
//////////////////////////////////////////////////////////////////////////////////////

#include "scanner.h"

int main()
{
  int cantIdentificadores = 0;
  int cantConstantes = 0;
  int cantErrores = 0;
  int cantNumerales = 0;

  int token;

  //TOKEN c;

  printf("Los resultados del datosPrueba.txt son: \n\n");
  do
  {
    token = scanner();
    //c = scanner();
    switch(token){    //switch(c)

      case CONSTANTE_ENTERA:
        printf("Constante entera\n");
        cantConstantes++;
        break;

      case IDENTIFICADOR:
        printf("Identificador\n");
        cantIdentificadores++;
        break;
      
      case NUMERAL:
        printf("Numeral\n");
        cantNumerales++;
        break;

      case ERROR:
        printf("error\n");
        cantErrores++;
        break;
        
      case FDT: //while(c!=FDT);
        break;
    }
    
  }while(token!=FDT);

  printf("----\n");
  printf("Totales:\n");
  printf("Identificadores %d\n",cantIdentificadores);
  printf("Constantes enteras %d\n",cantConstantes);
  printf("Numerales %d\n",cantNumerales);
  printf("Errores %d\n",cantErrores);

  return 0;
}