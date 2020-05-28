#include "FuncionesCC.h"
#include <stdlib.h>
#include <stdio.h>
#define maxN 100000
local_t auxMergeSort[maxN];
/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d ", centroComercial[numPiso][numLocalxPiso].idLocal);
	}
	//TODO completarlo con los datos que le sirvan en su caso
}
/*

	Esta función permite desplegar por consola
 	el nombre de todos los locales ocupados del centro comercial.

*/

void mostrarNombres(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	/* este procedimiento muestra todos los nombres de los locales ocupados */
	int i,j;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1) /* Revisar si esta ocupado el local antes de imprimir su nombre */
				printf("%s\n",centroComercial[i][j].nombreLocal);

		}
	}
}

/*

	Esta función permite mostrar por consola la cantidad de locales
	ocupados por piso.

*/

void mostarLocalesxPiso(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	/* este procedimiento muestra cuantos locales hay ocupados por piso*/
	int i,j,localxPiso ;
	for(i = 0; i < filas;i++){
		localxPiso = 0;
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1)
				localxPiso++;
		}
		printf("en el piso %d hay %d locales\n",i,localxPiso);
	}
}

/*

	Esta función permite mostrar por consola la cantidad
	total  de locales en el centro comercial
	

*/

int calcularTotalLocales(int *localesPorPiso,int filas){ 
	/* funcion recursiva para calcular el total de locales por piso (esten ocupados o no) */
	if(filas == 0)
		return 0;
	
	else
		return localesPorPiso[(filas)-1]+calcularTotalLocales(localesPorPiso,(filas)-1);
	
}



/* Funciones|Procedimientos NUEVOS */

void selectionSort(local_t *a,int N){
	/* Implementacion del selection sort para ordenar de menor a mayor las capacidades de los locales */

	int i,j,min_idx; /* min_idx -> Mínimo valor del arreglo.*/

	local_t tmp;
	for(i = 0; i < N-1;i++){
		min_idx = i;
		for(j = i+1; j < N;j++){
			if(a[j].capacidadLocal < a[min_idx].capacidadLocal)
				min_idx = j;
		}
		tmp = a[min_idx];
		a[min_idx] = a[i];
		a[i] = tmp;
	}
	for(i = 0; i < N;i++)
		printf("Nombre del local %s tiene capacidad %d\n",a[i].nombreLocal,a[i].capacidadLocal);
	


}

void insertionSort(local_t *a, int N){
	/*Implementacion del insertionSort para ordenar los locales de acuerdo a la cantidad de productos en inventario
		de mayor a menor */
	int i,j;
	local_t key;
	for(i = 1; i < N;i++){
		key = a[i];
		j = i-1;
		while(j >= 0 && a[j].cantidadProductos < key.cantidadProductos){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	for(i = 0; i < N;i++)
		printf("Nombre del local %s del piso %d con %d productos\n",a[i].nombreLocal,a[i].pisoLocal,a[i].cantidadProductos);
	
}

void merge(int low,int mid,int hi,local_t *a){
	/*funcion merge para ordenar un arreglo de locales de acuerdo a las ventas semanales (de menor a mayor)*/
    int i = low, j = mid,k = 0;
    while(i < mid && j < hi){
        if(a[i].ventasSemanales <= a[j].ventasSemanales){
            auxMergeSort[k] = a[i];
            k++;
            i++;
        }
            
        else{
            auxMergeSort[k] = a[j];
            k++;
            j++;

        }
            
    }
    for(; i < mid;i++,k++) auxMergeSort[k] = a[i];
  
    for(; j < hi;j++,k++) auxMergeSort[k] = a[j];
    

    for(i = 0; low < hi;i++,low++)
        a[low] = auxMergeSort[i];
}


void merge_sort(int low,int hi,local_t *a){
    int mid;
    if (low+1 < hi){  
        mid = (low+hi)/2;
        merge_sort(low,mid,a);
        merge_sort(mid,hi,a);
        merge(low,mid,hi,a);
    }
}


void ordenarMatrizPorCapacidad(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	/*Procedimiento que toma los locales ocupados por piso y por cada piso los ordena con el selectionSort */
	int i,j,k,N;
	local_t *localesOcupadosPorPiso;
	for(i = 0; i < filas;i++){
		N = 0;
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){
				/*printf("%d %d\n",i,j);*/
				N++;
			}
		}
		localesOcupadosPorPiso = malloc(N*sizeof(local_t));
		k = 0;
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){
				localesOcupadosPorPiso[k] = centroComercial[i][j]; 
				k++;
			}
		}
		printf("En el piso %d\n",i);
		selectionSort(localesOcupadosPorPiso,N);
		printf("\n");

	}
}



void ordenarMatrizPorInventario(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	/*Procedimiento que toma todos los locales ocupados y los ordena usando insertion sort */
	int i,j,k,N = 0;
	local_t *locales; /*Para guardar todos los locales ocupados en un arreglo de 1 dimension y ordenarlo luego*/
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){ /*Contar cuantos locales hay ocupados*/
				/*printf("%d %d\n",i,j);*/
				N++;
			}
		}
	}
	locales = malloc(N*sizeof(local_t));
	k = 0;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){
				locales[k] = centroComercial[i][j];
				k++;
			}
		}
	}
	insertionSort(locales,N);

}



void mostrarLocalesParaSeleccionar(int *localesPorPiso,int filas,int **localesOcupados){
	/*Muestra la matriz de locales ocupados para que el usuario pueda elegir una posicion que este disponible*/
	int i,j;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++)
			printf("%d ",localesOcupados[i][j]);
		printf("\n");
	}
}


void ordenarMatrizPorVentas(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	/*procedimiento que toma todos los locales ocupados para ordenarlos con el merge_sort*/
	int i,j,k;
	int N = 0;
	local_t *locales;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){ /*Contar cuanto locales hay ocupados*/
				/*printf("%d %d\n",i,j);*/
				N++;
			}
		}
	}
	locales = malloc(N*sizeof(local_t));
	k = 0;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){
				locales[k] = centroComercial[i][j];
				k++;
			}
		}
	}
	merge_sort(0,N,locales);
	for(i = 0; i < N;i++)
		printf("Nombre del local %s del piso %d con %d ventas semanales\n",locales[i].nombreLocal,locales[i].pisoLocal,locales[i].ventasSemanales);

}


int partition(local_t *a, int low,int hi){
	/*FUncion auxiliar del quickSort para ordenar de mayor a menor las capacidades de todos los locales*/
	local_t pivote = a[hi],tmp;
	int i = low-1;
	int j;
	for(j = low; j <= hi-1;j++){
		if(a[j].capacidadLocal > pivote.capacidadLocal){
			i++;
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	tmp = a[i+1];
	a[i+1] = a[hi];
	a[hi] = tmp;
	return i+1;
}

void quickSort(local_t *a,int low,int hi){
	if(low < hi){
		int pi = partition(a,low,hi);
		quickSort(a,low,pi-1);
		quickSort(a,pi+1,hi);
	}
}

void ordenarMatrizPorCapacidad2(local_t ** centroComercial, int *localesPorPiso,int filas,int **localesOcupados){
	/*Procedimiento que toma todos los locales ocupados y los guarda en un arreglo para ordenarlo con quickSort*/
	int i,j,k;
	int N = 0;
	local_t *locales;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){
				/*printf("%d %d\n",i,j);*/
				N++;
			}
		}
	}
	locales = malloc(N*sizeof(local_t));
	k = 0;
	for(i = 0; i < filas;i++){
		for(j = 0; j < localesPorPiso[i];j++){
			if(localesOcupados[i][j] == 1){
				locales[k] = centroComercial[i][j];
				k++;
			}
		}
	}
	quickSort(locales,0,N-1);
	for(i = 0; i < N;i++)
		printf("Nombre del local %s del piso %d con %d de capacidad\n",locales[i].nombreLocal,locales[i].pisoLocal,locales[i].capacidadLocal);

}