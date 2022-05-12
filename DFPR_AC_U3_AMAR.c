//Amador Aguilar Rodriguez
//Programa que clacula el mayor numero de contagios por estado
//DFPR_AC_U3_AMAR.

//Cabecera:
#include<stdio.h>

//Prototipos:
void entrada(int *arreglo);
int procesamiento(int *arreglo, int estado);
void salida(int *arreglo,int estado);

//Funcion proncipal:
int main()
{
  int arreglo[6],opc,estado;
  do
  {
    printf("\n\t\t\tMenu\n1.-Entrada\n2.-Procesamiento\n3.-Salida\n4.-Finalizar\n>> ");
    scanf("%i",&opc);
    switch(opc)
    {
      case 1: entrada(arreglo);break;
      case 2: estado =procesamiento(arreglo,estado);break;
      case 3: salida(arreglo,estado);
    }
  } while(opc != 4);

  return 0;
}

void entrada(int *arreglo)
{
int bajaCalifornia = 10649;
int sonora = 11220;
int ciudadMexico = 56602;
int estadoMexico = 41529;
int veracruz = 13293;
int tabasco = 13999;
int i = 0;
printf("\nAsignando datos al sistema.....\n");

  *(arreglo) = bajaCalifornia;
  *(arreglo+1) = sonora;
  *(arreglo+2) = ciudadMexico;
  *(arreglo+3) = estadoMexico;
  *(arreglo+4) = veracruz;
  *(arreglo+5) = tabasco;

}

int procesamiento(int *arreglo, int estado)
{
int i = 0,max = 0;
printf("\nBuscando el estado donde mayor contagios hubo......\n");
while( i < 6)
{
  if (arreglo[i] > max)
  {
  max = arreglo[i];
  estado = i+1;
  }

  i++;
}
printf("\n¡¡¡Encontrado!!!\n");
return estado;
}

void salida(int *arreglo, int estado)
{
  for(int i = 0;i < 34;i++)
  printf(".");
printf("\n    Estado\t     Confirmados\n");
for(int i = 0;i < 34;i++)
printf(".");
printf("\nBaja California: \t%d\n",*(arreglo));
for(int i = 0;i < 34;i++)
printf(".");
printf("\nSonora:   \t\t%i\n",*(arreglo+1));
for(int i = 0;i < 34;i++)
printf(".");
printf("\nCiudad de México:       %i\n",*(arreglo+2));
for(int i = 0;i < 34;i++)
printf(".");
printf("\nEstado de México:       %i\n",*(arreglo+3));
for(int i = 0;i < 34;i++)
printf(".");
printf("\nVeracruz:   \t\t%i\n",*(arreglo+4));
for(int i = 0;i < 34;i++)
printf(".");
printf("\nTabasco:   \t\t%i\n",*(arreglo+5));

switch(estado)
{
case 1: printf("\nLa entidad federativa que reporta el mayor número casos positivos es Baja California con: %i registrados\n",*(arreglo));break;
case 2: printf("\nLa entidad federativa que reporta el mayor número casos positivos es Sonora con: %i registrados\n",*(arreglo+1));break;
case 3: printf("\nLa entidad federativa que reporta el mayor número casos positivos es Ciudad de México con: %i registrados\n",*(arreglo+2));break;
case 4: printf("\nLa entidad federativa que reporta el mayor número casos positivos es Estado de México con: %i registrados\n",*(arreglo+3));break;
case 5: printf("\nLa entidad federativa que reporta el mayor número casos positivos es Veracruz con: %i registrados\n",*(arreglo+4));break;
case 6: printf("\nLa entidad federativa que reporta el mayor número casos positivos es Tabasco con: %i registrados\n",*(arreglo+5));
}
}
