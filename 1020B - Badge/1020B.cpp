#include <iostream>
using namespace std ;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i] ;
	}
	for(int i=0; i<n; i++){
		int aux[n];
		for(int j=0; j<n; j++){
			aux[j]=0;
		}
		aux[i]=1; //primero en recorrer
		int indice = i;
		while(aux[indice]!=2){
			indice = a[indice]-1;
			aux[indice]++;
		}
		cout << indice+1 << " ";
	}
	cout << "\n";
	return 0;
}