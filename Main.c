#include "FuncionesCC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Bool {False,True}; // Lo uso en el arreglo locales ocupados para marcar como True o False.

/*

	Malloc: La función malloc sirve para solicitar un 
	bloque de memoria del tamaño suministrado como parámetro. 
	Devuelve un puntero a la zona de memoria concedida.

	De acuerdo al enunciado el programa debía manejar memoria dinámica,
	 por lo que se ha decidido utilizar el malloc.
	
*/

int main(){

	/*la variable filas guarda la cantidad de filas(pisos) que tiene el centro comercial,
	columna y fila es para guardar la columna y fila que elija el usuario para poner su local,
	opcion es para el do while donde la persona elige un numero segun las opciones mostradas,
	ids es para los identificadores unicos de cada local, totalLocales para guardar el total 
	de locales del centro comercial*/

	int filas = 0,columna,fila,opcion ,i,j,k,ids = 0,totalLocales; 

	/* 

	localesPorPiso es un arreglo que guarda cuantos locales hay en cada piso, informacionLocalesOcupadosBin es un arreglo
	para guardar la informacion de los archivos binarios sobre cuales locales estan libres y cuales ocupados.

	*/

	int *localesPorPiso,*informacionLocalesOcupadosBin;

	/*centroComercial es una matriz de locales para representa el centro comercial */

	local_t **centroComercial;

	/*locales ocupados es una matriz de 0s y 1s, si es un 0 es porque esta libre ese local, si hay un 1 es porque esta ocupado*/

	int **localesOcupados;

	/* informacionCCBin es un arreglo de locales para guardar la informacion del archivo binario donde esta guardado el centro comercial*/

	local_t *informacionCCBin;

	/*
	El archivo informacionCC es un archivo binario para guardar el centro comercial (todos los locales), 
	informacionTamano es un archivo para guardar el tamano de la matriz (filas) y cuantos locales hay por piso (no es binario)
	el archivo informacionLocalesOcupados es un archivo binario para guardar la matriz localesOcupados. 
	*/

	FILE *informacionCC,*informacionTamano,*informacionLocalesOcupados;
	
	do{
		printf("Ingrese 0 para salir"
		"\n 1.Para asignar el numero de pisos y locales por piso del centro centro comercial."
		"\n 2.Para ingresar un nuevo local comercial."
		"\n 3.Para ver los nombres de los locales."
		"\n 4.Para ver cuantos locales hay por piso."
		"\n 5.Para cambiar el nombre de un local."
		"\n 6.Para eliminar un local."
		"\n 7.Para recursivamente muestre cuantos locales hay en total en el centro comercial.\n");

		/*nuevas funciones*/

		printf(" 8.Para abrir un local."
		"\n 9.Para guardar la informacion del centro comercial actual."
		"\n 10.Para cargar la informacion del ultimo centro comercial guardado."
		"\n 11.Para ordenar la matriz de acuerdo a la cantidad de personas que caben por piso en cada local.(menor a mayor)"
		"\n 12.Para ordenar todos los locales de acuerdo a la cantidad de productos en inventario.(mayor a menor)\n");
		printf(" 13.Para ordenar todos los locales de acuerdo a las ventas por semana. (menor a mayor)"
		"\n 14.Para ordenar todos los locales de acuerdo a la cantidad de personas que caben.(mayor a menor)\n");

		/*nuevas funciones*/

		scanf("%d",&opcion);
		switch(opcion){
			case 0:
				break;
			case 1:
				printf("Ingrese la cantidad de pisos del centro comercial\n");
				localesPorPiso = malloc(filas*sizeof(int));
				centroComercial = malloc(filas* sizeof(local_t *));
				localesOcupados = malloc(filas*sizeof(int *));
				scanf("%d",&filas);
				for(i = 0; i < filas;i++){
					printf("Ingrese los locales disponibles en el piso %d\n",i+1);
					scanf("%d",&columna);
					localesPorPiso[i] = columna;
					centroComercial[i] = malloc(columna*sizeof(local_t));
					localesOcupados[i] = malloc(columna*sizeof(int));
					for(j = 0; j < columna;j++)
						localesOcupados[i][j] = False;
				}
				break;

			case 2:
				printf("Centro comercial: (0 esta libre, 1 esta ocupado)\n");
				mostrarLocalesParaSeleccionar(localesPorPiso,filas,localesOcupados);
				printf("Ingrese el piso donde quiere colocar el local\n");
				scanf("%d",&fila);
				while(fila < 0 || fila >= filas){
					printf("Ingrese una fila entre 0 y %d\n",filas);
					scanf("%d",&fila);

				}
				printf("Ingrese el local donde quiere poner el local comercial\n");
				scanf("%d",&columna);
				while(columna < 0 || columna > localesPorPiso[fila]){
					printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]);
					scanf("%d",&columna);

				}
				while(localesOcupados[fila][columna] == True){
					printf("Ingrese otro local ya que este esta ocupado\n");
					printf("Ingrese el piso donde quiere colocar el local\n");
					scanf("%d",&fila);
					while(fila < 0 || fila >= filas){
						printf("Ingrese una fila entre 0 y %d\n",filas-1);
						scanf("%d",&fila);
					}
					printf("Ingrese el local donde quiere poner el local comercial\n");
					scanf("%d",&columna);
					while(columna < 0 || columna > localesPorPiso[fila]){
						printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]-1);
						scanf("%d",&columna);

					}
				}
				localesOcupados[fila][columna] = True;
				printf("Ingrese el nombre del local\n");
				scanf("%s",centroComercial[fila][columna].nombreLocal);
				
				printf("%s\n",centroComercial[fila][columna].nombreLocal);
				centroComercial[fila][columna].idLocal = ids++;
				centroComercial[fila][columna].pisoLocal = fila;
				centroComercial[fila][columna].numLocalxPiso = columna;
				centroComercial[fila][columna].estadoActual = cerrado;
				centroComercial[fila][columna].capacidadLocal = (rand()%10)+10; //capacidad de 10 a 19 personas
				centroComercial[fila][columna].ventasSemanales = (rand()%200); //ventas entre 0 y 199
				printf("Ingrese la cantidad de productos en inventario\n");
				scanf("%d",&centroComercial[fila][columna].cantidadProductos);

				break;

			case 3:
				mostrarNombres(centroComercial, localesPorPiso, filas,localesOcupados);
				break;

			case 4:
				mostarLocalesxPiso(centroComercial, localesPorPiso, filas,localesOcupados);
				break;

			case 5:
				printf("Ingrese el piso del local que quiere cambiar el nombre\n");
				scanf("%d",&fila);
				while(fila < 0 || fila >= filas){
					printf("Ingrese una fila entre 0 y %d\n",filas);
					scanf("%d",&fila);

				}
				printf("Ingrese la columna del local que quiere cambiar el nombre\n");
				scanf("%d",&columna);
				while(columna < 0 || columna > localesPorPiso[fila]){
					printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]);
					scanf("%d",&columna);

				}
				while(localesOcupados[fila][columna] == 0){
					printf("Ingrese otro local que este ocupado\n");
					printf("Ingrese el piso del local que quiere cambiar el nombre\n");
					scanf("%d",&fila);
					while(fila < 0 || fila >= filas){
						printf("Ingrese una fila entre 0 y %d\n",filas);
						scanf("%d",&fila);
					}
					printf("Ingrese la columna del local que quiere cambiar el nombre\n");
					scanf("%d",&columna);
					while(columna < 0 || columna > localesPorPiso[fila]){
						printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]);
						scanf("%d",&columna);

					}
				}
				printf("nombre viejo %s\n",centroComercial[fila][columna].nombreLocal);
				printf("Ingrese nuevo nombre\n");
				scanf("%s",centroComercial[fila][columna].nombreLocal);
				fflush(stdin);
				break;

			case 6:
				printf("Ingrese el piso del local que quiere eliminar\n");
				scanf("%d",&fila);
				while(fila < 0 || fila >= filas){
					printf("Ingrese una fila entre 0 y %d\n",filas-1);
					scanf("%d",&fila);

					}
				printf("Ingrese la columna del local que quiere eliminar\n");
				scanf("%d",&columna);
				while(columna < 0 || columna > localesPorPiso[fila]){
					printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]-1);
					scanf("%d",&columna);
					}
				localesOcupados[fila][columna] = False;

				break;
			case 7:
				printf("Cantidad de locales totales %d\n",calcularTotalLocales(localesPorPiso,filas) );
				break;

			case 8:
				printf("Ingrese el piso del local que quiere abrir\n");
				scanf("%d",&fila);
				while(fila < 0 || fila >= filas){
					printf("Ingrese una fila entre 0 y %d\n",filas-1);
					scanf("%d",&fila);

					}
				printf("Ingrese la columna del local que quiere abrir\n");
				scanf("%d",&columna);
				while(columna < 0 || columna > localesPorPiso[fila]){
					printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]-1);
					scanf("%d",&columna);
					}
				centroComercial[fila][columna].estadoActual = abierto;
				break;

			case 9:
				informacionCC =fopen("info.txt","w");
				informacionTamano = fopen("tamano.txt","w");
				informacionLocalesOcupados = fopen("localesOc.txt","w");
				if(informacionCC && informacionTamano && informacionLocalesOcupados){
					fprintf(informacionTamano,"%d\n",filas);
					for(i = 0; i < filas;i++)
						fprintf(informacionTamano,"%d\n",localesPorPiso[i]);
					
					for(i = 0; i < filas;i++){
						fwrite(centroComercial[i],sizeof(local_t),localesPorPiso[i],informacionCC);
						fwrite(localesOcupados[i],sizeof(int),localesPorPiso[i],informacionLocalesOcupados);
					}
				}
				else
					printf("Error al abrir el archivo!\n");
				fclose(informacionCC);
				fclose(informacionTamano);
				fclose(informacionLocalesOcupados);
				
				break;
			
			case 10:
				informacionCC = fopen("info.txt","r");
				informacionTamano = fopen("tamano.txt","r");
				informacionLocalesOcupados = fopen("localesOc.txt","r");
				if(informacionCC && informacionTamano && informacionLocalesOcupados){
					totalLocales = 0;
										
					while(fscanf(informacionTamano,"%d",&filas) != EOF){
						localesPorPiso = malloc(filas*sizeof(int));
						for(i = 0; i < filas;i++){
							fscanf(informacionTamano,"%d",&localesPorPiso[i]);
							totalLocales += localesPorPiso[i];
						}
					}
					informacionCCBin = malloc(totalLocales*sizeof(local_t));
					informacionLocalesOcupadosBin = malloc(totalLocales*sizeof(int));

					for(i = 0; !feof(informacionCC);i++){
						fread(&informacionCCBin[i],sizeof(local_t),1,informacionCC);
					}
					for(i = 0; !feof(informacionLocalesOcupados);i++){
						fread(&informacionLocalesOcupadosBin[i],sizeof(int),1,informacionLocalesOcupados);
					}
					
					centroComercial = malloc(filas* sizeof(local_t *));
					localesOcupados = malloc(filas*sizeof(int *));
					for(i = 0; i < filas;i++){
						centroComercial[i] = malloc(localesPorPiso[i]*sizeof(local_t));
						localesOcupados[i] =  malloc(localesPorPiso[i]*sizeof(int));
					}

					k = 0;
					for(i = 0; i < filas;i++){
						for(j = 0; j < localesPorPiso[i];j++){
							centroComercial[i][j] = informacionCCBin[k];
							localesOcupados[i][j] = informacionLocalesOcupadosBin[k];
							k++;
						}
						
					}
					fclose(informacionCC);
					fclose(informacionTamano);
					fclose(informacionLocalesOcupados);
				}
				else
					printf("Error al abrir el archivo!\n");
				
				break;

			case 11:
				ordenarMatrizPorCapacidad(centroComercial,localesPorPiso,filas,localesOcupados);
				break;

			case 12:
				ordenarMatrizPorInventario(centroComercial, localesPorPiso,filas,localesOcupados);
				break;
			case 13:
				ordenarMatrizPorVentas(centroComercial, localesPorPiso,filas,localesOcupados);
				break;
			case 14:
				ordenarMatrizPorCapacidad2(centroComercial, localesPorPiso,filas,localesOcupados);
				break;
			default:
				printf("Ingrese un digito entre 0 y 14!\n");

		}


	}while(opcion != 0);
	
	return 0;
}
