#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

// FuncionesCC.h lo utilizo para hacer el llamado de las funciones
// Esta es la struct del local.
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Se calcula automáticamente por el programa.
	int pisoLocal;
	int numLocalxPiso;//Columnas
	// Se puede completar libremente :D
} local_t;

/* 
	local_t es el nombre que utilicé para renombrar la struct debido a que si
	se utiliza tal cual como se encuentra en la parte de arriba quedaría un poco más largo.

*/

/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);


void mostrarNombres(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

void mostarLocalesxPiso(local_t ** centroComercial, int *localesPorPiso,int *filas,int **localesOcupados);

int calcularTotalLocales(int *localesPorPiso,int filas);

#endif /* FUNCIONESCC_H_ */