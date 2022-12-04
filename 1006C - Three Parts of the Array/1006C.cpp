#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int aux = 0 ;
	// Inicio de inputs
	long long int cantidad_elementos ;
	cin >> cantidad_elementos ;
	vector<long long int> elementos(cantidad_elementos) ;
	long long int min=0 ; // Este será el mínimo
	long long int suma_total=0 ; // Despúes suma_total será el máximo
	vector<long long int> sumas_parciales(cantidad_elementos) ;
	for(int i=0 ; i<cantidad_elementos ; i++){
		cin >> elementos[i] ;
		suma_total = suma_total + elementos[i] ;
		sumas_parciales[i] = suma_total ;
	}
	long long int respuesta=-1 ;
	for(int j=0 ; j<cantidad_elementos ; j++){
		long long int k = j + 1 ;
		long long int total = cantidad_elementos-1 ;
		while(k<total){
			if(k == total-1){
				if(sumas_parciales[j]<=sumas_parciales[cantidad_elementos-1]-sumas_parciales[total-1]){
					k = total ;
					break ;
				}
				break ;
			}
			long long int mitad = k + (total-k)/2 ;
			if(sumas_parciales[j]<=sumas_parciales[cantidad_elementos-1]-sumas_parciales[mitad-1]){
				k = mitad ;
			}
			else{
				total = mitad ;
			}
		}
		if(sumas_parciales[j]==suma_total-sumas_parciales[k-1]){
			respuesta = j ;
		}
	}
	if(respuesta == -1){
		cout << 0 << endl ;
	}
	else{
		cout << sumas_parciales[respuesta] << endl ;
	}
	// FINAL DEL PROGRAMA
	return 0 ;
}