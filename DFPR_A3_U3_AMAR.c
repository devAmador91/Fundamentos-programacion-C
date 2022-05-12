/*
 Amador Aguilar Rodriguez
 Programa que determina si las raices de un bonomio al cuadrado son reales o imaginarias
 DFPR_A3_U3_AMAR.c
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Prototipos:
int pedirDato();
int trinomio(int a, float *x1,float *x2);
void verificar(int);

//Funcion principal
int main()
{
  int a,discriminante;
  float x1,x2;

a = pedirDato();
printf("\n(x + %i)\n",a);

discriminante = trinomio(a,&x1,&x2);
printf("Raiz 1: %.0f\n",x1);
printf("Raiz 2: %.0f\n",x2);
printf("Discriminante: %i\n",discriminante);

verificar(discriminante);
system("pause");
  return 0;
}

int pedirDato()
{
  int num;

  do
  {
  printf("Ingrese un numero: \n\n>> ");
  scanf("%d",&num);
  if(num > 0)
    return num;
  else
    printf("Ingrese un numero mayor a cero: \n");
  }while(num < 0);
}

int trinomio(int a,float *x1,float *x2)
{
  int x=1,b,c,discriminante;

  b=2*a;
  c=a*a;
  printf("El tcp de (x + %i)^2 es : x^2 + %ix + %i\n",a,b,c);
  a=x;
  *x1= (-b + sqrt(pow(b,2)-4*a*c))/(2*a);
  *x2= (-b - sqrt(pow(b,2)-4*a*c))/(2*a);
  discriminante= sqrt(pow(b,2)-4*a*c)/(2*a);

  return discriminante;
}

void verificar(int discriminante)
{
  if(discriminante > 0)
    printf("Las raices son reales y distintas\n");
  if(discriminante == 0)
    printf("Las raices son iguales, reales y racionales\n");
  if(discriminante < 0)
    printf("Las raices son imaginarias\n");
}
