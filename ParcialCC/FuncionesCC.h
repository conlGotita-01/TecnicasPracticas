#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

enum estadoLocal{abierto = 1, cerrado = 0};
//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	enum estadoLocal estadoActual; /*si esta abierto o cerrado*/
	int capacidadLocal; /*cuantas personas caben*/
	int cantidadProductos; /*cantidad de productos en inventario*/
	int ventasSemanales; /*Entero que representa las ventas totales por semana*/
	// Completelo con lo que quiera
} local_t;

/* 
	local_t es el nombre que utilicé para renombrar la struct debido a que si
	se utiliza tal cual como se encuentra en la parte de arriba quedaría un poco más largo.

*/


/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);


void mostrarNombres(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

void mostarLocalesxPiso(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

int calcularTotalLocales(int *localesPorPiso,int filas);

/* Nuevas Funciones|Procedimientos */

void selectionSort(local_t *a,int N);

void ordenarMatrizPorCapacidad(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

void ordenarMatrizPorInventario(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

void merge(int low,int mid,int hi,local_t *a);

void merge_sort(int low,int hi,local_t *a);

void ordenarMatrizPorVentas(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

void mostrarLocalesParaSeleccionar(int *localesPorPiso,int filas,int **localesOcupados);

int partition(local_t *a, int low,int hi);

void quickSort(local_t *a,int low,int hi);


void ordenarMatrizPorCapacidad2(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados);

#endif /* FUNCIONESCC_H_ */