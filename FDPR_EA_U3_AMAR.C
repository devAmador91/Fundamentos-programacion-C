//Amador Aguilar Rodriguez
//Programa que calcula el area de una figura geometrica seleccionada
//FDPR_EA_U3_amar.c

//Cabecera:
#include<stdio.h>
#define PI 3.1416

//Prototipos:
float trapecio(float *area);
float hexagono(float *area);
float pentagono(float *area);
float circulo(float *area);
float elipse(float *area);

//Funcion principal:
int main()
{
  int opc;
  float area[3];

  do
  {
    do
    {
    printf("\n\t\tMenu Area de Figuras Geometricas\n\n1.-Trapecio\n2.-Hexagono\n3.-Pentagono\n4.-Circulo\n5.-Elipse\n6.-Salir\n>> ");
    scanf("%i",&opc);
    if(opc > 6 || opc < 1)
    printf("\nOpcion incorrecta, introduzca una opcion del 1 al 6\n");
    }while(opc > 6 || opc < 1);
    switch(opc)
    {
      case 1:
      printf("\nIngrese la base mayor del trapecio:\n>> ");
      scanf("%f",&area[0]);
      printf("Ingrese la base menor del trapecio:\n>> ");
      scanf("%f",&area[1]);
      printf("Ingrese la altura del trapecio:\n>> ");
      scanf("%f",&area[2]);
      printf("\nFigura: Trapecio\nArea: %.2f\n",trapecio(area));break;
      case 2:
      printf("\nIngrese el perimetro del hexagono:\n>> ");
      scanf("%f",&area[0]);
      printf("Ingrese la apotema del hexagono:\n>> ");
      scanf("%f",&area[1]);
      printf("\nFigura: Hexagono\nArea: %.2f\n",hexagono(area));break;
      case 3:
      printf("\nIngrese el perimetro del pentagono:\n>> ");
      scanf("%f",&area[0]);
      printf("Ingrese la apotema del pentagono:\n>> ");
      scanf("%f",&area[1]);
      printf("\nFigura: Pentagono\nArea: %.2f\n",pentagono(area));break;
      case 4:
      printf("\nIngrese el radio del circulo:\n>> ");
      scanf("%f",&area[0]);
      printf("\nFigura: Circulo\nArea: %.2f\n",circulo(area));break;
      case 5:
      printf("\nIngrese el semieje menor de la elipse:\n>> ");
      scanf("%f",&area[0]);
      printf("Ingrese el semieje mayor de la elipse:\n>> ");
      scanf("%f",&area[1]);
      printf("\nFigura: Elipse\nArea: %.2f\n",elipse(area));
    }
  } while(opc != 6);


  return 0;
}

float trapecio(float *area)
{
  float Bm,bm,h;
  Bm = area[0];
  bm = area[1];
  h = area[2];

  return (Bm + bm)* h / 2;
}

float hexagono(float *area)
{
  float Perimetro,a;
  Perimetro = area[0];
  a = area[1];

  return (Perimetro * a) / 2;
}

float pentagono(float *area)
{
  float Perimetro,a;
  Perimetro = area[0];
  a = area[1];

  return (Perimetro * a) / 2;;
}

float circulo(float *area)
{
  float r;
  r = area[0];

  return PI * r * r;
}

float elipse(float *area)
{
  float a,b;
  a = area[0];
  b = area[1];

  return PI * a * b;
}
