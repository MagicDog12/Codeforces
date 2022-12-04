#include <iostream>
using namespace std ;
     
int main(){
    long long n ;
    cin >> n ; 
    string a,b ;
    cin >> a ;
    cin >> b ;
    long long respuesta = 0 ;
    long long contador = 0 ;
    
    while(contador < n){
    	if(a[contador] != b[contador]){
            if(contador!=n-1){ // llegamos al final
                if(a[contador+1] == b[contador+1]){
                    respuesta++ ;
                    contador = contador+2 ;
                }
                else{
                    if(a[contador] != a[contador+1]){
                        respuesta++ ;
                        contador = contador+2 ;
                    }
                    else{
                        respuesta++ ;
                        contador++ ;
                    }
                }
            }
            else{
                respuesta++ ;
                contador++ ;
            }
    	}
    	else{
            contador++ ;
    	}
   	}
   	cout << respuesta << "\n" ;
   	return 0 ;
}