#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	
	int h;
	cin >> h;

	int arreglo[n];
	int n_final = n;
	for(int i=0; i<n; i+=1){
		cin >> arreglo[i];
		if(arreglo[i] >h){
			n_final +=1;
		}

	}

	cout << n_final << endl;
	return 0;

}