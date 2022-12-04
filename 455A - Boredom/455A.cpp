#include <iostream>
using namespace std ;

int main(){
	long long n ;
	cin >> n ;
	long long a[n]; 
	long long maximo = 0 ;
	for(long long i=0 ; i<n ; i++){
		cin >> a[i] ;
		if(maximo< a[i]){
			maximo = a[i] ;
		}
	}

	long long frecuencias[maximo+1] ; // lista con las frecuencias de los valores que hay en a 
	for(long long i=0 ; i<=maximo ; i++){ // lo inicializamos en 0
		frecuencias[i] = 0 ;
	}
	for(long long i=0 ; i<n ; i++){
		long long numero_actual = a[i] ;
		frecuencias[numero_actual] += 1 ;
	}
	// probando test 49
	long long respuesta[n+1] ;
	respuesta[0] = 0 ;
	respuesta[1] = frecuencias[1] ;
	for(long long i=2 ; i<=maximo ; i++){
		respuesta[i] = max(respuesta[i-1],respuesta[i-2]+i*frecuencias[i]) ;
	}
	cout << respuesta[maximo] << "\n" ;
	return 0 ;
}