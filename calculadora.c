#include<stdio.h>
#include<stdlib.h>
//Prototipo:
int Operaciones();

int main()
{
	int resultado;
	
	resultado = Operaciones();
	if(resultado == 0){
	printf("Hasta pronto AMADOR\n");
	}
	
	return 0;
}

int Operaciones(int operacion)
{
	int num1=0,num2=0,resultado=0,opcion=0;
	
	do
	{
		
		printf("\n\t\t***Bienvenido AMADOR***\n");
		printf("1.-Sumar");
                printf("2.-Restar");
                printf("3.-Multiplicar");
                printf("4.-Dividir");
                printf("5.-Salir");
                printf("Ingresa una opcion: ");scanf("%i",&opcion);
		setbuf(stdin,NULL);
		if(opcion == 5)
		{
			return 0;
		}
		printf("Ingresa dos numeros: ");scanf("%i %i",&num1,&num2);
		system("clear");	
	switch(opcion)
	{
	
		case 1:printf("Tu resultado es: %i\n", resultado = num1 + num2);break;
		case 2:printf("Tu resultado es: %i\n", resultado = num1 - num2);break;
		case 3:printf("tu resultado es: %i\n", resultado = num1 * num2);break;
		case 4:printf("Tu resultado es: %i\n", resultado = num1 / num2);
			
		
	}
	}while(opcion <5);	
}		
     	
	

