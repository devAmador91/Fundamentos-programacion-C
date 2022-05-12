/*Base de Datos
 * Amador Aguilar Rodriguez*/

//Cabecera:

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Constantes:

FILE* Archivo;

//Estructura:

struct baseDatos{
	char Nombre[40];
	char Direccion[40];
	char Telefono[20];
	char Ocupacion[40];
}info[100];

//Prototipo:

void Menu();
int capturar();
int guardar_archivo(char nombre_copiado[20],int ubicacion);
int consultar();
int cambiar_nombre();
int eliminar();
int salir();

//Funcion Principal:

int main()
{
		
Menu();

return 0;
}

//Funciones y Procedimientos:

void Menu()
{
int opc=0;	
for(int i = 0;i <= 30;i++){
printf("*");
}
do
{
printf("\n");
printf("\n\t---MENU---\n");
printf("\n");
printf("1.- Capturar Informacion\n");
printf("2.- Consultar Informacion\n");
printf("3.- Cambiar Nombre\n");
printf("4.- Eliminar Registro\n");
printf("5.- Salir\n");
printf("\n");
for(int i = 0;i <= 30;i++){
printf("*");
}
printf("\nIngrese una opcion: ");scanf("%i",&opc);
switch(opc){
	case 1: capturar();break;
	case 2: consultar();break;
	case 3: cambiar_nombre();break;
	case 4: eliminar();break;
	case 5: salir();
}
}while(opc != 5);
}

int capturar()
{
	int num_registros=0,ubicacion=0;
	char resp[3],nombre_copiado[20] = {""};

	printf("¿A cuantas personas desea registrar?\n");scanf(" %i",&num_registros);
	
	for(int i=0;i<num_registros;i++){
		
setbuf(stdin,NULL);	
printf("Nombre: \n");fgets(info[i].Nombre, 40,stdin);
setbuf(stdin,NULL);
printf("Direccion: \n");fgets(info[i].Direccion, 40,stdin);
setbuf(stdin,NULL);
printf("Telefono: \n");fgets(info[i].Telefono, 20,stdin);
setbuf(stdin,NULL);
printf("Ocupacion: \n");fgets(info[i].Ocupacion, 40,stdin);
setbuf(stdin,NULL);
//Crear funcion para guardar archivo desde aqui
printf("\nDesea guardar la informacion capturada en un archivo? [s][n] ");fgets(resp, 3,stdin);
strcpy(nombre_copiado,info[i].Nombre);//Copia el nombre registrado a la variable nombre_copiado
strcat(nombre_copiado, ".txt");// concatena la extencion .txt a la variable nombre_copiado
if(strcmp(resp, "s\n")==0)
{
ubicacion = i;
guardar_archivo(nombre_copiado,ubicacion);//Se pasan los argumentos por valor a la funcion  guardar_archivo para que realice el guardado con los datos obtenidos aqui
}
else{
printf("La informacion se ha desechado");
return -1;
}
	}
return 0;
}
int guardar_archivo(char nombre_copiado[20],int ubicacion)
{
	
Archivo = fopen(nombre_copiado, "w");
if(Archivo == NULL)
{
puts("\nError al crear o abrir el Archivo\n");
return -1;
}
else{
fprintf(Archivo,"%s %s %s %s", info[ubicacion].Nombre, info[ubicacion].Direccion, info[ubicacion].Telefono, info[ubicacion].Ocupacion);
}
// Copia el arreglo de la estructura en el archivo por cada iteracion
if(fclose(Archivo)==0)
{
printf("\nArchivo cerrado correctamente\n");
}
else{
	printf("\nError al cerrar el Archivo\n");
	return -1;
}
return 0;
}

int consultar()
{
	char nombre_buscar[20] = {""},leer[40];
	int ubicacion,verificacion=1;
	setbuf(stdin,NULL);
printf("Ingrese el nombre de la persona a buscar: ");fgets(nombre_buscar,20,stdin);
strcat(nombre_buscar, ".txt");
printf("\n");
Archivo = fopen(nombre_buscar, "r");
if(Archivo == NULL)
{
printf("\nError al abrir o el Archivo no existe\n");
return -1;
}
else{
while(fgets(leer, 40, (FILE*) Archivo))
{
printf("%s\n",leer);
}
}
if(fclose(Archivo)==0)
{
printf("\nEl archivo se cerro correctamente\n");
}
else{
printf("\nError al cerrar el archivo\n");
return -1;
}
return 0;
}
int cambiar_nombre()
{
char nombre_actual[20]={""},nombre_nuevo[20]={""};
setbuf(stdin,NULL);
printf("Ingrese el nombre a cambiar: ");fgets(nombre_actual, 20,stdin);
setbuf(stdin,NULL);
printf("Ingrese el nuevo nombre: ");fgets(nombre_nuevo,20,stdin);
strcat(nombre_actual, ".txt");
strcat(nombre_nuevo, ".txt");
if(rename(nombre_actual,nombre_nuevo)==0)
{
printf("Se ha cambiado el nombre correctamente");
}
else{
	printf("Error al cambiar el nombre");
	return -1;
}
return 0;
}
int eliminar()
{
	char nom_borrar[20]={""};
	setbuf(stdin,NULL);
	printf("Ingrese el nombre de la persona a borrar del registro: ");fgets(nom_borrar, 20,stdin);
	strcat(nom_borrar,".txt");
if(remove(nom_borrar) == 0)
{
printf("El registro se ha borrado correctamente");
}
else{
printf("Error al intentar borrar el archivo");
return -1;
}
return 0;
}
int salir()
{
printf("\nHasta luego\n");
return 0;
}

