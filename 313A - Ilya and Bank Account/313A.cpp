#include <iostream>
using namespace std ;

int main(){
	int n ;
	cin >> n ;
	if(n<0){
		int primer_digito = n%10 ;
		int segundo_digito = (n/10)%10 ;
		if(primer_digito<=segundo_digito){
			n = n/10 ;
		}
		else{
			n = n/100 ;
			n = n*10 + primer_digito ;
		}
	}
	cout << n ;
	return 0;
}