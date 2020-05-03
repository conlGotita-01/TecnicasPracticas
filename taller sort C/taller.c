#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define maxN 100000+3 /* Maximo tamaño de arreglo de entrada. */

int a[maxN],tmp[maxN],acpy[maxN]; /* El arreglo "a" guarda el arreglo de la entrada.txt, "tmp" es el arreglo auxiliar 
para el merge sort, "acpy" es una copia del arreglo "a" para cuando se ordena volverlo a su estado original y volverlo
a ordenar con otro algoritmo distinto. */

unsigned long long int ifCnt,swapCnt; /* "ifCnt" cuenta cuantas veces se hace un condicional, "swapCnt" cuantas veces
se hace un intercambio de datos. */

void bubble_sort( int N ){
    int i, j, tmp2;
    for( i = 0; i < N-1;i++ ){
        for( j = 0;j < N-i-1;j++ ){
            if( a[ j ] > a [ j+1 ] ){
                tmp2 = a[ j+1 ];
                a[ j+1 ] = a[j];
                a[ j ] = tmp2;
                swapCnt++;
                
            }
            ifCnt++;
        }
    }

}

void bubble_sort2 ( int N ){ /*bubble sort mejorado*/
    int i, j, tmp2, swap;
    for( i = 0; i < N-1;i++ ){ /*cuando el arreglo esta ordenado o parcialmente ordenado
     no se hacen todas las veces el ciclo de adentro*/
        swap = 0;
        for( j = 0;j < N-i-1;j++ ){
            if( a[ j ] > a[ j+1 ] ){
                tmp2 = a[ j+1 ];
                a[ j+1 ] = a[ j ];
                a[ j ] = tmp2;
                swapCnt++;
                swap = 1;
                
            }
            ifCnt++;
        }
        if( swap == 0 ) break; /*si no se hizo ningun swap en el ciclo de adentro el arreglo esta ordenado*/
    }
    
}


void insertion_sort( int N ){
    int i, j, key;
    for( i = 1; i < N; i++ ){
        key = a[ i ];
        j = i-1;
        while( j >= 0 && a[ j ]>key ){
            a[ j+1 ] = a[ j ];
            j--;
            swapCnt++;

        } 
        a[ j+1 ] = key;
    }
}


void merge( int low,int mid,int hi ){
    int i = low, j = mid,k = 0;
    while( i < mid && j < hi ){
        if( a[ i ] <= a[ j ] ){
            tmp[ k ] = a [ i ];
            k++;
            i++;
        }
            
        else{
            tmp[ k ] = a[ j ];
            k++;
            j++;

        }
        swapCnt++;
        ifCnt++;
            
    }
    for( ; i < mid;i++,swapCnt++,k++) tmp[k] = a[i];
  
    for( ; j < hi;j++,swapCnt++,k++) tmp[k] = a[j];
    

    for( i = 0; low < hi;i++,low++,swapCnt++ )
        a[ low ] = tmp[ i ];
 

}

void merge_sort( int low,int hi ){
    int mid;
    ifCnt++;
    if ( low+1 < hi ){  
        mid = ( low+hi )/2;
        merge_sort( low,mid );
        merge_sort( mid,hi );
        merge( low,mid,hi );
    }
}


int main(){
    FILE *f,*fOut; /* "f" es el archivo de entrada, "fOut" el archivo de salida. */
    int N, i;
    time_t tini, tfin; /* Tiempo de inicio y tiempo final */
    char *_timeS ; /*Para convertir a string los tiempos y escribirlos en el archivo de salida.*/
    f = fopen( "entrada.txt","r" );
    fOut = fopen( "salida.txt","w" );

    /* Maximo valor 17142860 aproximadamente. */
    
    if( f == NULL || fOut == NULL )
        printf( "Error abriendo el archivo\n" );
    else{
        while( fscanf( f,"%d",&N ) != EOF ){
            /*printf("%d\n",N);*/
            for( i = 0; i < N; i++ ){
               fscanf( f,"%d",&a[ i ] );
               acpy[ i ] = a[i];
            }
            fprintf(fOut,"Arreglo de tamano %d\n\n",N);

            
            /*Primer algoritmo*/
            ifCnt = 0,swapCnt = 0;
            tini = time( NULL );
            _timeS = ctime( &tini );
            _timeS[ ( strlen( _timeS ) ) -1 ] = '\0';
            fprintf( fOut,"%s\n",_timeS );
            insertion_sort( N );
            fprintf( fOut, " Cantidad de intercambios y comparaciones respectivamente %lli %lli insertion sort\n ", swapCnt, ifCnt );
             tfin = time( NULL );
            _timeS = ctime( &tfin );
            _timeS[ (strlen( _timeS ) )-1 ] = '\0';
            fprintf( fOut,"%s\n",_timeS );
            fprintf( fOut,"Los minutos transcurridos fueron %f\n\n", difftime( tfin,tini )/60 );

            /*Primer algoritmo*/

            /*Segundo algoritmo*/

            
            for( i = 0; i < N;i++ ) a[ i ] = acpy[ i ];

            ifCnt = 0, swapCnt = 0;
            tini = time( NULL );
            _timeS = ctime( &tini );
            _timeS[ ( strlen( _timeS ) ) -1 ] = '\0';
            fprintf( fOut,"%s\n",_timeS );
            merge_sort( 0,N );
            fprintf( fOut, " Cantidad de intercambios y comparaciones respectivamente %lli %lli merge sort\n ", swapCnt, ifCnt );
            tfin = time( NULL );
            _timeS = ctime( &tfin );
            _timeS[ ( strlen( _timeS ) ) -1 ] = '\0';
            fprintf( fOut,"%s\n",_timeS );
            fprintf( fOut, " Los minutos transcurridos fueron %f\n\n ", difftime( tfin,tini )/60 );

            /*Segundo algoritmo*/

            /*Tercer algoritmo*/

            for( i = 0; i < N;i++ ) a[ i ] = acpy[ i ];
            ifCnt = 0, swapCnt = 0;
            tini = time( NULL );
            _timeS = ctime( &tini );
            _timeS[ ( strlen ( _timeS ) ) -1 ] = '\0';
            fprintf( fOut, " %s\n ", _timeS );
          
            bubble_sort( N );
            fprintf( fOut, " Cantidad de intercambios y comparaciones respectivamente %lli %lli bubble sort\n ", swapCnt,ifCnt );
            tfin = time( NULL );
            _timeS = ctime( &tfin );
            _timeS[ ( strlen( _timeS ) )-1 ] = '\0';
            fprintf( fOut,"%s\n",_timeS );
            fprintf( fOut,"Los minutos transcurridos fueron %f\n\n", difftime( tfin,tini)/60 );

            /*Tercer algoritmo*/

            /*Cuarto algoritmo*/

            for( i = 0; i < N;i++ ) a[ i ] = acpy[ i ];
            ifCnt = 0,swapCnt = 0;
            tini = time( NULL );
            _timeS = ctime( &tini );
            _timeS[ ( strlen(_timeS ) ) -1 ] = '\0';
            fprintf(  fOut,"%s\n",_timeS );
            bubble_sort2( N );
            fprintf( fOut, " Cantidad de intercambios y comparaciones respectivamente %lli %lli bubble sort mejorado\n ", swapCnt, ifCnt );
            tfin = time( NULL );
            _timeS = ctime( &tfin );
            _timeS[ ( strlen(_timeS ) ) -1 ] = '\0';
            fprintf( fOut,"%s\n",_timeS );
            fprintf( fOut, " Los minutos transcurridos fueron %f\n\n\n ", difftime( tfin,tini )/60 );


            /*Cuarto algoritmo*/

        }
    }
    fclose(f);
    fclose(fOut);

    return 0;
}