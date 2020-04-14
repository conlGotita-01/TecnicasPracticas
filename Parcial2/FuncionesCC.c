#include "FuncionesCC.h"
#include <stdlib.h>
#include <stdio.h>
/* Funcion de ejemplo que imprimiría la información de un local */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se válida si el número ingresado se encuentra dentro del rango.
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d ", centroComercial[numPiso][numLocalxPiso].idLocal);
	}
	// Hay que completarlo con los datos que puedan servir.
}
/*

	Esta función permite desplegar por consola
 	el nombre de todos los locales ocupados del centro comercial.

*/
void mostrarNombres(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	int i,j;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1)
				printf("%s\n",centroComercial[i][j].nombreLocal);


		}
	}
}

/*

	Esta función permite mostrar por consola la cantidad de locales
	ocupados por piso.

*/

void mostarLocalesxPiso(local_t ** centroComercial, int *localesPorPiso,int *filas,int **localesOcupados){
	int i,j,localxPiso ;
	for(i = 0; i < *filas;i++){
		localxPiso = 0;
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1)
				localxPiso++;
		}
		printf("en el piso %d hay %d locales\n",i+1,localxPiso);
	}
}

/*

	Esta función permite mostrar por consola la cantidad
	total  de locales en el centro comercial
	

*/
int calcularTotalLocales(int *localesPorPiso,int filas){
	if(filas == 0)
		return 0;
	
	else
		return localesPorPiso[(filas)-1]+calcularTotalLocales(localesPorPiso,(filas)-1);
	
}
