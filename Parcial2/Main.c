#include "FuncionesCC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Bool {False,True};  // Lo uso en el arreglo locales ocupados para marcar como True o False.

/*

	Malloc: La función malloc sirve para solicitar un bloque de memoria del tamaño suministrado como parámetro. 
	Devuelve un puntero a la zona de memoria concedida.

	De acuerdo al enunciado el programa debía manejar memoria dinámica, por lo que se ha decidido utilizar el malloc.
	
*/
int main(){
	int filas = 0, columna, fila, opcion , i, j, ids = 0;

/* 
	filas [Cantidad de filas]
	columnas [Cantidad de columnas]
	opciones 
	i [indice]
	j [indice]
	ids
*/
	int *localesPorPiso;
	local_t **centroComercial; /* Lo utilizo para indicar que es un tipo de matriz */
	int **localesOcupados;
	do{
		printf("Ingrese 0 para salir\n1.Para asignar el numero de pisos y locales por piso del centro centro comercial\n2.Para ingresar un nuevo local comercial\n3.Para ver los nombres de los locales\n4.Para ver cuantos locales hay ocupados por piso\n5.Para cambiar el nombre de un local\n6.Para eliminar un local\n7.Para recursivamente muestre cuantos locales hay en total en el centro comercial\n");
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
				while(localesOcupados[fila][columna] == 1){
					printf("Ingrese otro local ya que este esta ocupado\n");
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
				}
				localesOcupados[fila][columna] = True;
				printf("Ingrese el nombre del local\n");
				scanf("%s",centroComercial[fila][columna].nombreLocal);

				printf("%s\n",centroComercial[fila][columna].nombreLocal);
				centroComercial[fila][columna].idLocal = ids++;
				centroComercial[fila][columna].pisoLocal = fila;
				centroComercial[fila][columna].numLocalxPiso = columna;

				break;

			case 3:
				mostrarNombres(centroComercial, localesPorPiso, filas,localesOcupados);
				break;

			case 4:
				mostarLocalesxPiso(centroComercial, localesPorPiso, &filas,localesOcupados);
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
				break;

			case 6:
				printf("Ingrese el piso del local que quiere eliminar\n");
				scanf("%d",&fila);
				while(fila < 0 || fila >= filas){
					printf("Ingrese una fila entre 0 y %d\n",filas);
					scanf("%d",&fila);

					}
				printf("Ingrese la columna del local que quiere eliminar\n");
				scanf("%d",&columna);
				while(columna < 0 || columna > localesPorPiso[fila]){
					printf("Ingrese una columna entre 0 y %d\n",localesPorPiso[fila]);
					scanf("%d",&columna);
					}
				localesOcupados[fila][columna] = False;

				break;
			case 7:
				printf("Cantidad de locales totales %d\n",calcularTotalLocales(localesPorPiso,filas) );
				break;


			default:
				printf("Ingrese un digito entre 0 y 6!\n");


		}


	}while(opcion != 0);
		printf("Ha salido con exito");
	return 0; 
}
