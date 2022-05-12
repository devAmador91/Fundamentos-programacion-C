/*
Amador Aguilar Rodriguez
DFPR_A2_U3_AMAR.c
Programa verificador de numeros pares, impares y perfectos.
*/

//Directiva de preprocesador
#include<stdio.h>

//Prototipos
int par_impar(int, int);
int perfecto(int, int, int);

//Funcion Princiapl
int main()
{
  int num, contIteracion = 0, sumaDivisores = 0;

printf("Ingrese un numero: \n");
scanf("%d",&num);

if(par_impar(num, contIteracion) == 1)
printf("El numero es par\n");
else
printf("El numero es impar\n");

contIteracion = 1;

if(perfecto(num, contIteracion, sumaDivisores) == 1)
printf("El numero es perfecto\n");
else
printf("El numero no es perfecto\n");

  return 0;
}

/*Funcion recursiva que determina si un numero es par o impar, guardando en una
 variable contadora el numero de veces que se itera la funcion, aplicando a
esta la función mod para saber si el resto es par o impar, y disminuyendo en
uno el numero ingresado, hasta que la condicion del caso base sea falso.*/
int par_impar(int num, int contIteracion)
{
  if(num == 0 && contIteracion % 2 == 0) // Caso base verifica si es numero par
  return 1;
  else
  if(num == 0 && contIteracion % 2 != 0) // Caso base verifica si es numero impar
  return 0;
  if(num > 0) // Recursividad
  return par_impar(num - 1, contIteracion = contIteracion + 1);
}

/*Funcion recursiva que determina si un numero es perfecto haciendo uso de la
variable contadora inicializada en 1, que aumenta su valor en cada iteracion
recursiva tembien en 1, esto para para dividir el numero ingresado entre la
variable contadora, determinar si es una división exacta por medio de la
funcion MOD y encontrar todos sus divisores. Posteriormente se suman los divisores y se
determina si el numero es perfecto o no lo es comparando la totalidad de la suma
con el numero ingresado.
La recursividad termina cuando la condicion del caso base es falsa*/
int perfecto(int num, int contIteracion, int sumaDivisores)
{
  if(num % contIteracion == 0)
  sumaDivisores += contIteracion;
  if(sumaDivisores == num) // Caso base verifica si es numero perfecto
  return 1;
  else
  if(sumaDivisores > num) // Caso base verifica si no es numero perfecto
  return 0;
  if (sumaDivisores < num) //Recursividad
  return perfecto(num, contIteracion = contIteracion + 1, sumaDivisores);
}
